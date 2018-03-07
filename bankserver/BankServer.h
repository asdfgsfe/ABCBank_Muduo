#ifndef BANK_SERVER_H
#define BANK_SERVER_H

#include <muduo/net/TcpServer.h>

class BankServer  : boost::noncopyable
{
 public:
  BankServer(muduo::net::EventLoop* loop,
             const muduo::net::InetAddress& listenAddr);

  void start();  // calls server_.start();

 private:
  void onConnection(const muduo::net::TcpConnectionPtr& conn);

  void onMessage(const muduo::net::TcpConnectionPtr& conn,
                 muduo::net::Buffer* buf,
                 muduo::Timestamp time);

  muduo::net::EventLoop* loop_;
  muduo::net::TcpServer server_;
  const static size_t kHeaderLen = 4;		// 请求包头4个字节cmd(2)+len(2)
};

#endif  // BANK_SERVER_H
