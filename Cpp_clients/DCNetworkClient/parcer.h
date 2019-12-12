#ifndef PARCER_H
#define PARCER_H

#include <QString>

class Parcer
{
public:
    Parcer();
public:
    QString encode(const QString& message);
    QString decode(const QString& message);
};

#endif // PARCER_H
