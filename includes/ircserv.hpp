#pragma once

#include "Client.hpp"
#include "Channel.hpp"
#include "User.hpp"
#include "Buffer.hpp"

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdio.h>
#include <poll.h>
#include <unistd.h>
#include <vector>
#include <map>
#include <fcntl.h>
#include <algorithm>
#include <sstream>
#include <netdb.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <fnmatch.h>
#include <string.h>

typedef std::vector<std::string>	string_vec;

class Client;

typedef struct s_data
{
	int port;
	std::string servername;
	std::string oper[2];
	// commands_map	commands;
	std::vector<Client *> clients;
	std::vector<struct pollfd> pollfds;
	std::string password;
} t_data;

int data_init(int argc, char **argv, t_data *my_data);
int ft_atoi(const char *str);
Client	*getClient(t_data *data, int fd);
bool	ends(char *buffer);
void	parsing(t_data *data, Client *client, std::string buf);