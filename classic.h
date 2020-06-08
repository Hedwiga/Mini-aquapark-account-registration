/*
 * Filename: classic.h
 */

#ifndef CLASSIC_H
#define CLASSIC_H

#include "membership.h"

class Classic : virtual public Membership
{
private:
    int teammates;
protected:
    virtual void setTime();
    virtual void setPrice();
public:
    Classic();
    virtual ~Classic() {};
    Classic(const QString & theName, const QDate & theBday, int amount = 4);
    int getAmount() const;
};

#endif // CLASSIC_H
