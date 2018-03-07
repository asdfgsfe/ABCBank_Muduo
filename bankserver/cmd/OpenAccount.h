#ifndef _OPEN_ACCOUNT_H_
#define _OPEN_ACCOUNT_H_

#include "Transaction.h"

// ¿ª»§
class OpenAccount : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};


#endif // _OPEN_ACCOUNT_H_
