#pragma once

#include "ircserv.hpp"

#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

class Client;
class User;

class Client
{
private:
	struct sockaddr_in _sock;
	socklen_t _size;
	int _fd;
	std::string _ip;
	User _user;
	// Buffer	_buffer;
	// Registration	_register;
	bool _isClose;

public:
	Client();
	Client(struct sockaddr_in &sock, int &fd);
	~Client();

	void setFd(const int &fd);
	struct sockaddr_in *getSockAddress();
	socklen_t *getSizeAddress();
	const int &getFd() const;
	const struct sockaddr_in &getSocket() const;
	void setIp(const std::string &ip);
};
