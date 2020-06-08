/*
 * Filename: premium.h
 */

#ifndef PREMIUM_H
#define PREMIUM_H

#include "daily.h"
#include "classic.h"

class Premium : public Classic, public Daily
{
protected:
    virtual void setTime();
    virtual void setPrice();
public:
    Premium();
    virtual ~Premium() {};
    Premium(const QString & theName, const QDate & theBday, int amount = 4);
};

#endif // PREMIUM_H
