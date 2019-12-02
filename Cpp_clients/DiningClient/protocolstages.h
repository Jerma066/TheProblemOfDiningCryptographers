#ifndef PROTOCOLSTAGES_H
#define PROTOCOLSTAGES_H

#include <QObject>
#include "generic.h"
#include <tuple>

class ProtocolStages : public QObject
{
    Q_OBJECT

public:
    ProtocolStages(const int& selfDescriptionNumber = 0, const QMap<int, QString>& descriptors_adresses = {}, bool isPayer = false);
    ~ProtocolStages();

public:
    void SendSecrets();
    void MakeXORorNXOR();
    void GenerateProtocolAnswer();

private:
    void GenerateSecrets();
    void IncreaseNumbersOfSecrets();
    void IncreaseNumberOfXorResults();


public slots:
    void process_ProtocolStages();
    void ChangeIsPayerValue(bool state);
    void CatchMissingSecrets(int descriptor, int side_secrets);
    void CatchOthersXORorNXOR(int sender_descriptor, int xOrNx_res);

signals:
    void finished_PSMaker();
    void sendSecrets(QVector<int>);
    void sendXORorNXOR_Result(QString);
    void sendProtocolAnswer(QString);
    void allSecretsWasGained();
    void allXorResultsWasGained();
    void gotMainProtocolAnswer(int);

private:
    int selfDescriptionNumber;
    QMap<int, QString> descriptors_adresses;
    QVector<int> secrets;
    QVector<int> xorNxorResults;
    bool isPayer;
    int current_num_of_secrets = 0;
    int current_side_xor_results = 0;

};

#endif // PROTOCOLSTAGES_H
