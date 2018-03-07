#include "Server.h"
#include <memory>
#include <iostream>
#include <sstream>

Server::Server() : config_("server.conf")
{
	serverIp_ = config_.GetProperty("SERVER.SERVER_IP");
	string port = config_.GetProperty("SERVER.PORT");
	stringstream ss;
	ss<<port;
	ss>>port_;

	dbServerIp_ = config_.GetProperty("DB.IP");

	port = config_.GetProperty("DB.PORT");
	ss.clear();
	ss.str("");
	ss<<port;
	ss>>dbServerPort_;

	dbUser_ = config_.GetProperty("DB.USER");
	dbPass_ = config_.GetProperty("DB.PASS");
	dbName_ = config_.GetProperty("DB.NAME");

	ss.clear();
	ss.str("");
	string interetRate = config_.GetProperty("BANK.INTERATE");
	if (interetRate.empty())
	{
		interetRate_ = 0.0035;
	}
	else
	{
		ss<<interetRate;
		ss>>interetRate_;
	}
}

Server::~Server()
{
}
