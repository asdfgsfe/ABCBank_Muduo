#ifndef _WITHDRAWAL_H_
#define _WITHDRAWAL_H_

#include "Transaction.h"

// È¡¿î

class Withdrawal : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};

#endif // _WITHDRAWAL_H_
