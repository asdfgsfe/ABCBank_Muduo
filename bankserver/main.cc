#include "BankServer.h"
#include "Server.h"

#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

// using namespace muduo;
// using namespace muduo::net;

int main()
{
  //LOG_INFO << "pid = " << getpid();
  muduo::net::EventLoop loop;
  muduo::net::InetAddress listenAddr(muduo::Singleton<Server>::instance().GetPort());
  BankServer server(&loop, listenAddr);
  server.start();
  loop.loop();
}

