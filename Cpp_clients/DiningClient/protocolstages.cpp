#include "protocolstages.h"



ProtocolStages::ProtocolStages(const int &selfDescriptionNumber, const QMap<int, QString> &descriptors_adresses, bool isPayer)
{
    this->selfDescriptionNumber = selfDescriptionNumber;
    this->descriptors_adresses = descriptors_adresses;
    this->isPayer = isPayer;

    xorNxorResults.resize(descriptors_adresses.size());
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

void ProtocolStages::ChangeIsPayerValue(bool state)
{
    isPayer = state;
}

//-----Генерация и отправка секретов----------------//
static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

void ProtocolStages::GenerateSecrets()
{
    secrets.resize(descriptors_adresses.size());

    for (int i = selfDescriptionNumber + 1; i < descriptors_adresses.size(); i++) {
        secrets[i] = (randomBetween(0,1));
    }
}

void ProtocolStages::SendSecrets()
{
    GenerateSecrets();
    sendSecrets(secrets);

    for (int i = selfDescriptionNumber + 1; i < descriptors_adresses.size(); i++) {
        this->IncreaseNumbersOfSecrets();
    }
}
//--------------------------------------------------//
//-----Получение сторонних секретов-----------------//
void ProtocolStages::CatchMissingSecrets(int descriptor, int side_secrets)
{
    secrets[descriptor] = side_secrets;
    this->IncreaseNumbersOfSecrets();
}

//Изменение количества секретов
void ProtocolStages::IncreaseNumbersOfSecrets()
{
    current_num_of_secrets++;

    if(current_num_of_secrets == descriptors_adresses.size() - 1){
        emit allSecretsWasGained();
        this->MakeXORorNXOR();
    }
}
//--------------------------------------------------//
//-----Выполнение и отправка XOR или ~XOR рез-в-----//
void ProtocolStages::MakeXORorNXOR()
{
    int result = 0;
    bool res;
    QString answer = "3141 ";
    for (int i = 0; i < descriptors_adresses.size(); i++) {
        if(i != selfDescriptionNumber){
            result += secrets[i];
        }
    }

    result %= 2;

    if(isPayer){
        res = !static_cast<bool>(result);
    }
    else {
        res = static_cast<bool>(result);
    }

    result = static_cast<int>(res);
    xorNxorResults[selfDescriptionNumber] = result;
    this->IncreaseNumberOfXorResults();

    answer += QString::number(result);
    sendXORorNXOR_Result(answer);
}
//--------------------------------------------------//
//-----Получение чужих XOR/NXOR результатов---------//
void ProtocolStages::CatchOthersXORorNXOR(int sender_descriptor, int xOrNx_res)
{
    xorNxorResults[sender_descriptor] = xOrNx_res;
    this->IncreaseNumberOfXorResults();
}

//--------------------------------------------------//
//-----Получение ответа об оплате счета-------------//
void ProtocolStages::GenerateProtocolAnswer(){
    int result = 0;

    for (auto it = xorNxorResults.begin(); it != xorNxorResults.end(); it++) {
        result += *it;
    }

    result %= 2;

    gotMainProtocolAnswer(result);
}

//Изменение количества сторонних XOR результатов
void ProtocolStages::IncreaseNumberOfXorResults()
{
    current_side_xor_results++;

    if(current_side_xor_results == descriptors_adresses.size()){
        emit allXorResultsWasGained();
        this->GenerateProtocolAnswer();
    }
}
