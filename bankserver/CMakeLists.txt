set(bankserver_SRCS
  main.cc
  BankServer.cc
  BankSession.cc
  cmd/BalanceInquiry.cc
  cmd/ChangePassword.cc
  cmd/CloseAccount.cc
  cmd/Deposit.cc
  cmd/OpenAccount.cc
  cmd/QueryAccountHistoryBill.cc
  cmd/QueryDayBill.cc
  cmd/QueryHistoryBill.cc
  cmd/Transfer.cc
  cmd/UserLogin.cc
  cmd/Withdrawal.cc
  dal/BankService.cc
  dal/MysqlDB.cc
  Idea.cc
  JInStream.cc
  JOutStream.cc
  JUtil.cc
  MD5.cc
  Server.cc
  StringUtil.cc
  SystemConfig.cc
  TransactionManager.cc
  )

add_executable(bankserver ${bankserver_SRCS})
target_link_libraries(bankserver muduo_net mysqlclient z m)
