#include "BankSession.h"

#include "TransactionManager.h"

#include <muduo/net/Endian.h>
#include <muduo/base/Exception.h>
#include <muduo/base/Singleton.h>

#include <stdio.h>
BankSession::BankSession()
{
}

BankSession::~BankSession()
{
}

void BankSession::SetData(const char* data, size_t len)
{
	memcpy(buffer_, data, len);
}

void BankSession::Process()
{
	Parse();
	//DoAction();
	
	try
	{
		DoAction();
	}
	catch (muduo::Exception& e)
	{
		LOG_INFO<<e.what();
	}
	
}

/*
void BankSession::Send(const char* buf, size_t len)
{
	socket_->SendN(buf, len);
}
*/

void BankSession::Parse()
{
	requestPack_= (RequestPack*)(buffer_);
	uint16 cmd = muduo::net::sockets::networkToHost16(requestPack_->head.cmd);
	uint16 len = muduo::net::sockets::networkToHost16(requestPack_->head.len);
	
	// 计算hash
	unsigned char hash[16];
	MD5 md5;
	md5.MD5Make(hash, reinterpret_cast<unsigned char const *>(buffer_), sizeof(RequestHead)+len-8);
	for (int i=0; i<8; ++i)
	{
		hash[i] = hash[i] ^ hash[i+8];

		//unsigned char’转换自‘int’时可能改变值

		hash[i] = hash[i] ^ (static_cast<unsigned char>((cmd >> (i%2)) & 0xff));
	}

	if (memcmp(hash, buffer_+sizeof(RequestHead)+len-8, 8))
		throw muduo::Exception("错误的数据包");

	requestPack_->head.cmd = cmd;
	requestPack_->head.len = len;

}

void BankSession::DoAction()
{
	muduo::Singleton<TransactionManager>::instance().DoAction(*this);
}

