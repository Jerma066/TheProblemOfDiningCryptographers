#include "parcer.h"

Parcer::Parcer()
{

}

QString Parcer::encode(const QString& message)
{
    int flag = 0;
    QString answer;
    for(int i = 0; i < message.size(); i++){
        answer.push_back(message[i]);

        if(message[i] == '0'){
            flag++;
        }
        else{
            flag = 0;
        }

        if(flag == 4){
            answer.push_back('1');
            flag = 0;
        }
    }

    return (answer + "100000");
}

QString Parcer::decode(const QString& message)
{
    int flag = 0;
    QString answer;
    for(int i = 0; i < message.size() - 6; i++){
        if(flag != 4){
            answer.push_back(message[i]);
        }

        if(message[i] == '0'){
            flag++;
        }
        else{
            flag = 0;
        }
    }
    return answer;
}
