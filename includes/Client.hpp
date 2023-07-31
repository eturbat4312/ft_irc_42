#pragma once

#include "ircserv.hpp"

#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

class Client;

class	Client{
private:
	struct sockaddr_in _sock;
	socklen_t	_size;
	int	_fd;
	std::string	_ip;
	// User	_user;
	// Buffer	_buffer;
	// Registration	_register;
	bool	_isClose;

public:
	Client(struct sockaddr_in &sock, int &fd);
	~Client();

};
