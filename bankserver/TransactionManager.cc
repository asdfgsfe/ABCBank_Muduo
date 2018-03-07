#include "TransactionManager.h"
#include "cmd/UserLogin.h"
#include "cmd/OpenAccount.h"
#include "cmd/CloseAccount.h"
#include "cmd/ChangePassword.h"
#include "cmd/Deposit.h"
#include "cmd/BalanceInquiry.h"
#include "cmd/Transfer.h"
#include "cmd/Withdrawal.h"
#include "cmd/QueryDayBill.h"
#include "cmd/QueryHistoryBill.h"
#include "cmd/QueryAccountHistoryBill.h"



TransactionManager::TransactionManager()
{
	m_actions[CMD_LOGIN] = new UserLogin;
	m_actions[CMD_OPEN_ACCOUNT] = new OpenAccount;
	m_actions[CMD_DEPOSIT] = new Deposit;
	m_actions[CMD_WITHDRAW] = new Withdrawal;
	m_actions[CMD_TRANSFER] = new Transfer;
	m_actions[CMD_BALANCE_INQUIRY] = new BalanceInquiry;
	m_actions[CMD_CHANGE_PASSWORD] = new ChangePassword;
	m_actions[CMD_DAY_BILL] = new QueryDayBill;
	m_actions[CMD_HISTORY_BILL] = new QueryHistoryBill;
	m_actions[CMD_ACCOUNT_HISTORY_BILL] = new QueryAccountHistoryBill;
	m_actions[CMD_CLOSE_ACCOUNT] = new CloseAccount;
}

TransactionManager::~TransactionManager()
{
	for (map<uint16, Transaction*>::iterator it=m_actions.begin();
		it!=m_actions.end();++it)
	{
			delete it->second;
	}
}

bool TransactionManager::DoAction(BankSession& session)
{
	uint16 cmd = session.GetCmd();
	if (m_actions.find(cmd) != m_actions.end())
	{
		m_actions[cmd]->Execute(session);
		return true;
	}

	return false;
}