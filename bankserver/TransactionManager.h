#ifndef _TRANSACTION_MANAGER_H_
#define _TRANSACTION_MANAGER_H_

#include <muduo/base/Singleton.h>
#include "BankSession.h"
#include "cmd/Transaction.h"
#include <map>
#include <string>
using namespace std;

class TransactionManager
{
	friend class muduo::Singleton<TransactionManager>;
public:
	bool DoAction(BankSession& session);

private:
	map<uint16, Transaction*> m_actions;
	TransactionManager();
	TransactionManager(const TransactionManager& rhs);
	~TransactionManager();

};

#endif // _TRANSACTION_MANAGER_H_
