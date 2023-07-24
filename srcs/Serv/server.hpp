#pragma once

#include <vector>
#include <string>
#include <poll.h>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_CONNECTION	1000
#define RECV_FLAGS	0

class	Server;

class	Server{
private:
	int	_socket;
	const std::string _host;
	const std::string	_port;
	// const std::string	_password;
	std::string	_serverName;

	std::vector<pollfd>	_pollfds;
	// std::vector<User *>	_users;
	// std::vector<Channel *>	_channels;
	// Invoker 	*_Invoker;

	int	createSocket();
	// int	recvMsg(User *user);

public:
	Server(const std::string host, const std::string port, const std::string password);
	~Server();

	void	start();
	void	action();
};