#include "BankServer.h"
#include "BankSession.h"
#include "Types.h"

#include <muduo/base/Logging.h>

#include <boost/bind.hpp>

// using namespace muduo;
// using namespace muduo::net;

BankServer::BankServer(muduo::net::EventLoop* loop,
                       const muduo::net::InetAddress& listenAddr)
  : loop_(loop),
    server_(loop, listenAddr, "BankServer")
{
  server_.setConnectionCallback(
      boost::bind(&BankServer::onConnection, this, _1));
  server_.setMessageCallback(
      boost::bind(&BankServer::onMessage, this, _1, _2, _3));
}

void BankServer::start()
{
  server_.start();
}

void BankServer::onConnection(const muduo::net::TcpConnectionPtr& conn)
{
  if (conn->connected())
  {
    conn->setContext(BankSession());	// TcpConnection与一个BankSession绑定
  }
}

void BankServer::onMessage(const muduo::net::TcpConnectionPtr& conn,
                           muduo::net::Buffer* buf,
                           muduo::Timestamp time)
{
   // 这里用while而不用if
    while (buf->readableBytes() >= kHeaderLen) // kHeaderLen == 4
    {
      const void* data = buf->peek();
      const RequestHead* rh = static_cast<const RequestHead*>(data);
      //uint16 cmd = muduo::net::sockets::networkToHost16(rh->cmd);
      uint16 len = muduo::net::sockets::networkToHost16(rh->len);
      if (buf->readableBytes() >= len + kHeaderLen)  // 达到一条完整的消息
      {
		BankSession* bs = boost::any_cast<BankSession>(conn->getMutableContext());
		bs->SetData(buf->peek(), kHeaderLen+len);
		bs->Process();

		//BankSession* bs = boost::any_cast<BankSession>(conn->getMutableContext());
		//bs->SetData(buf->peek(), kHeaderLen+len);
		//bs->Process();
		muduo::net::Buffer response;
		response.append(bs->GetJos().Data(), bs->GetJos().Length());
		bs->Clear();
		conn->send(&response);


        buf->retrieve(kHeaderLen+len);
      }
      else  // 未达到一条完整的消息
      {
        break;
      }
    }
}

