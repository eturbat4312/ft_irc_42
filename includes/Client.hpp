#pragma once
#include "ircserv.hpp"
#include "Buffer.hpp" // Include the full definition of Buffer class here

#include "User.hpp"

#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

// class Buffer;  // You can still have the forward declaration here if needed

class Client
{
private:
	struct sockaddr_in _sock;
	socklen_t _size;
	int _fd;
	std::string _ip;
	User _user;
	Buffer _buffer; // Now the full definition of Buffer is available
	// Registration    _register;
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

	char *fillBuff();
};
