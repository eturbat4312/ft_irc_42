#include "../includes/ircserv.hpp"
#include "../includes/Client.hpp"

// std::vector<Channel *> g_channels;

int	main(int argc, char **argv){
	t_data	my_data;

	if (data_init(argc, argv, &my_data) == -1)
		throw std::runtime_error("error! initialize data on main");
	
	// Socket 
	int	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	int	option = 1;
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
	if (socket_fd == -1)
		throw std::runtime_error("Error: Socket Creation");
	std::cout << "[Socket created ...] " << std::endl;

	//Server_address
	struct sockaddr_in	server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(my_data.port);
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	//Bind
	if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1)
		throw std::runtime_error("Error: Binding");
	std::cout << "[Binding done ...]" << std::endl;

	listen(socket_fd, SOMAXCONN);
	std::cout << "[listening ...]" << std::endl;

	// int	nb_fds =1;
	// int	recieved = 0; 

	Client	server(server_address, socket_fd);
	my_data.clients.push_back(&server);


	struct pollfd	s_poll;
	memset(&s_poll, 0, sizeof(s_poll));
	s_poll.fd = socket_fd;
	// std::cout << "socket_fd : " << socket_fd<< std::endl;
	s_poll.events = POLLIN;
	my_data.pollfds.push_back(s_poll);
	

}