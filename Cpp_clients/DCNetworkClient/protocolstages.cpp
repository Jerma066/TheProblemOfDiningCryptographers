#include "protocolstages.h"
//-----Коструктор и необходимая атрибутика-----//
ProtocolStages::ProtocolStages()
{

}
void ProtocolStages::CaughtNumberOfMessages(int numOfMes)
{
    this->numberOfMessages = numOfMes;
}

void ProtocolStages::CaughtDescriptionsOfGuests(QMap<int, QString> descriptors_adresses)
{
    this->descriptors_adresses = descriptors_adresses;
}
void ProtocolStages::CaughtSelfDescriptionNumber(int number)
{
    this->selfDescriptionNumber = number;
}
void ProtocolStages::CaughtSelfBroadcastNumber(int broadcastNumber)
{
    this->selfBroadcastPosition = broadcastNumber;
}

void ProtocolStages::CatchBroadcastingWord(QString word)
{
    this->broadCastingWord = word;
}

ProtocolStages::~ProtocolStages()
{
    qDebug() << "ProtocolStages: Good bye int thread";
    emit finished_PSMaker();
}

void ProtocolStages::process_ProtocolStages()
{
    qDebug() << "ProtocolStages: Start working in Thread";
}
//--------------------------------------------//

void ProtocolStages::ChangeIsPayerValue(bool state)
{
    isPayer = state;
}

void ProtocolStages::FirstProtocolStage()
{
    qDebug() << "First protocol stage begins. currentNumOfWOrd = " << currentNumOfWord << ", bitNumOfCurrentWord = " << bitNumOfCurrentWord;
    if(currentNumOfWord == selfBroadcastPosition){
        if(broadCastingWord.at(0) == '1'){
            ChangeIsPayerValue(true);
        }
        else{
            ChangeIsPayerValue(false);
        }
    }
    bitNumOfCurrentWord++;

    this->SendSecrets();
    qDebug() << "First protocol stage ends";
}

//-----Генерация отправка и получение секретов------//
static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

void ProtocolStages::GenerateSecrets()
{
    for (int i = selfDescriptionNumber + 1; i < descriptors_adresses.size(); i++) {
        sendable_secrets.push_back(randomBetween(0,1));
    }
}

void ProtocolStages::SendSecrets()
{
  if(currentNumOfWord < numberOfMessages){
    qDebug() << "Sending secrets begins.";

    GenerateSecrets();
    emit sendSecrets(sendable_secrets);
    this->IncreaseNumbersOfSecrets();

    qDebug() << "Sending secrets ends.";
  }
  else{
    emit endOfProtocol();
  }
}

void ProtocolStages::CatchMissingSecrets(int side_secret)
{
    received_secrets.push_back(side_secret);
    this->IncreaseNumbersOfSecrets();
}

//Изменение количества секретов
void ProtocolStages::IncreaseNumbersOfSecrets()
{
    if((sendable_secrets.size() + received_secrets.size()) == (descriptors_adresses.size() - 1)){
        emit allSecretsWasGained();
        this->MakeXORorNXOR();
    }
}
//-------------------------------------------------------------//
//-----Генерация и отправка и получение XOR или ~XOR рез-в-----//
void ProtocolStages::MakeXORorNXOR()
{
    qDebug() << "Making XORorNXOR begins.";
    int result = 0;
    bool res;
    QString answer = "3141 ";

    for(auto it = sendable_secrets.begin(); it != sendable_secrets.end(); it++){
        result += *it;
    }
    for(auto it = received_secrets.begin(); it != received_secrets.end(); it++){
        result += *it;
    }

    result %= 2;

    if(isPayer){
        res = !static_cast<bool>(result);
    }
    else {
        res = static_cast<bool>(result);
    }

    result = static_cast<int>(res);
    qDebug() << "isPayer: " << isPayer << ", result(of (N)XOR) = " << result;

    xorNxorResults.push_back(result);
    answer += QString::number(result);

    emit sendXORorNXOR_Result(answer);

    while(!beReseted) {
        if(xorNxorResults.size() == descriptors_adresses.size()){
            emit allXorResultsWasGained();
            break;
        }
        QGuiApplication::processEvents();
    }

    if(!beReseted){
        qDebug() << "Making XORorNXOR ends.";
        this->GenerateProtocolAnswer();
    }

    beReseted = false;
}

void ProtocolStages::CatchOthersXORorNXOR(int xOrNx_res)
{
    xorNxorResults.push_back(xOrNx_res);
}
//----------------------------------------------------------------//
//-----Генерация, получение и отправка ответа об оплате счета-----//
void ProtocolStages::GenerateProtocolAnswer(){
    int result = 0;

    for (auto it = xorNxorResults.begin(); it != xorNxorResults.end(); it++) {
        result += *it;
    }

    result %= 2;

    current_result = result;
    this->ClearReusedElements();
    emit gotMainProtocolAnswer(result);

    while(!beReseted) {
        if(num_of_round_answers == descriptors_adresses.size() - 1){
            emit allRoundResultsWasGained();
            break;
        }
        QGuiApplication::processEvents();
    }

    if(currentNumOfWord < numberOfMessages){
        num_of_round_answers = 0;
        this->NewProtocolCycle(current_result);
    }
}
//Получение сторонних ответов протокола
void ProtocolStages::CatchSideAnswerResult(int result)
{
    if(current_result != result)
    {
        qDebug() << "Protocol Violations!!!";
    }
    num_of_round_answers++;
}
//----------------------------------------------------------------//
//Новый цикл протокола
void ProtocolStages::NewProtocolCycle(int result){
    lineSignal();
    qDebug() << "New Protocol cycle begins. Answer buf = " << answerBuffer;
    answerBuffer.push_back(QString::number(result));                    //помещаем полученный бит в буфер

    if(answerBuffer.size() >= 6){
        QString current_end = answerBuffer.right(5);
        if(current_end == "00000"){                                     //проверим буффер на наличие символа конца слова
            QString answer = parce.decode(answerBuffer);                //Декодируем ответ
            gotAnswerWord(answer);                                      //Отправляем ответ
            answerBuffer.clear();                                       //Очищаем буффер слова
            currentNumOfWord++;                                         //Увеличиваем счетчик номера получаемого слова
            bitNumOfCurrentWord = 0;                                    //Обнуляем номер отправляемого бита
        }
    }

    if(currentNumOfWord == selfBroadcastPosition){
        if(broadCastingWord[bitNumOfCurrentWord] == '1'){
            isPayer = true;
        }
        else{
            isPayer = false;
        }
    }
    else{
        isPayer = false;
    }

    bitNumOfCurrentWord++;

    this->SendSecrets();
    qDebug() << "New protocol cycle ends";
}

void ProtocolStages::Reset()
{
    beReseted = true;

    descriptors_adresses.clear();
    received_secrets.clear();
    sendable_secrets.clear();
    xorNxorResults.clear();

    selfDescriptionNumber = -1;

    bitNumOfCurrentWord = 0;
    currentNumOfWord = 0;
    selfBroadcastPosition = -1;
    numberOfMessages = 0;
    num_of_round_answers = 0;
    current_result =-1;
    isPayer = false;
    allAnswersGaibed = false;

    broadCastingWord = "";
    answerBuffer = "";
}

//Очищение переиспользуемых ресурсов
void ProtocolStages::ClearReusedElements()
{
    qDebug() << "Clear Reused Elements begins.";

    sendable_secrets.clear();
    received_secrets.clear();
    xorNxorResults.clear();

    qDebug() << "Clear Reused Elements ends.";
}


