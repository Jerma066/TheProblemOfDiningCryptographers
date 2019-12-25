#ifndef PROTOCOLSTAGES_H
#define PROTOCOLSTAGES_H

#include <QObject>
#include "generic.h"
#include <tuple>
#include <parcer.h>
#include <QGuiApplication>

class ProtocolStages : public QObject
{
    Q_OBJECT

public:
    ProtocolStages();
    ~ProtocolStages();

public:
    void SendSecrets();
    void MakeXORorNXOR();
    void GenerateProtocolAnswer();

private:
    void GenerateSecrets();
    void IncreaseNumbersOfSecrets();
    void ClearReusedElements();

public slots:
    void CatchBroadcastingWord(QString);
    void CaughtSelfBroadcastNumber(int broadcastNumber);
    void CaughtSelfDescriptionNumber(int number);
    void CaughtNumberOfMessages(int numOfMes);
    void CaughtDescriptionsOfGuests(QMap<int, QString>);
    void CatchMissingSecrets(int side_secrets);
    void CatchOthersXORorNXOR(int xOrNx_res);
    void CatchSideAnswerResult(int result);
    void FirstProtocolStage();
    void process_ProtocolStages();
    void ChangeIsPayerValue(bool state);
    void NewProtocolCycle(int result);

signals:
    void finished_PSMaker();
    void sendSecrets(QVector<int>);
    void sendXORorNXOR_Result(int);
    void sendProtocolAnswer(QString);
    void allSecretsWasGained();
    void allXorResultsWasGained();
    void gotMainProtocolAnswer(int);
    void gotAnswerWord(QString);
    void allRoundResultsWasGained();
    void endOfProtocol();
    void lineSignal();

private:    
    QMap<int, QString> descriptors_adresses;
    QVector<int> received_secrets;
    QVector<int> sendable_secrets;
    QVector<int> xorNxorResults;

    int selfDescriptionNumber = -1;

    int bitNumOfCurrentWord = 0;
    int currentNumOfWord = 0;
    int selfBroadcastPosition = -1;
    int numberOfMessages = 0;
    int num_of_round_answers = 0;
    int current_result;

    bool isPayer = false;

    bool allAnswersGaibed = false;

    QString broadCastingWord;
    QString answerBuffer;

    Parcer parce;
};

#endif // PROTOCOLSTAGES_H
