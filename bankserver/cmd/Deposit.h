#ifndef _DEPOSIT_H_
#define _DEPOSIT_H_

#include "Transaction.h"

// ´æ¿î

class Deposit : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};

#endif // _DEPOSIT_H_
