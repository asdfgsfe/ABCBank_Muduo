#ifndef _QUERY_HISTORY_BILL_H_
#define _QUERY_HISTORY_BILL_H_

#include "Transaction.h"


	class QueryHistoryBill : public Transaction
	{
	public:
		virtual void Execute(BankSession& session);
	};


#endif // _QUERY_HISTORY_BILL_H_