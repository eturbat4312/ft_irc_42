#include "../includes/ircserv.hpp"



int	data_init(int argc, char **argv, t_data *my_data){
	if (argc != 3)
		throw std::runtime_error("Error: Wrong number of arguments");
	int	port = ft_atoi(argv[1]);
	my_data->port = port;
	my_data->password = std::string(argv[2]);
	my_data->servername = "ircserv";
	my_data->oper[0] = "operator";
	my_data->oper[1] = "password";
	return 1;
}