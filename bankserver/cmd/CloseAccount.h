#ifndef _CLOSE_ACCOUNT_H_
#define _CLOSE_ACCOUNT_H_

#include "Transaction.h"

// Ïú»§
class CloseAccount : public Transaction
{
public:
	virtual void Execute(BankSession& session);
};


#endif // _CLOSE_ACCOUNT_H_
