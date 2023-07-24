#include "server.hpp"

Server::Server(std::string host, std::string port, std::string password){
	_socket = createSocket();
	_serverName = _host;
	

}

Server::~Server(){}

int	Server::createSocket(){
	addrinfo	hints, *servinfo;

	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	if (getaddrinfo(_host.c_str(), _port.c_str(), &hints, &servinfo) != 0)
		throw std::runtime_error("getaddrinfo :error");
	
	addrinfo *pointer;
	int	sock, flag = 1;

	for (pointer = servinfo; pointer != nullptr; pointer = pointer->ai_next){
		sock = socket(pointer->ai_family, pointer->ai_socktype, pointer->ai_protocol);

		if (sock == -1)
			continue;
		
		if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int)) == -1)
		{
			close(sock);
			freeaddrinfo(servinfo);
			throw std::runtime_error("setockopt funcion: error");
		}

		if (bind(sock, pointer->ai_addr, pointer->ai_addrlen) == -1){
			close(sock);
			continue;
		}
		break;
	}
	freeaddrinfo(servinfo);
	if (pointer == nullptr)
		throw std::runtime_error("could not find address: error");
	if (listen(sock, MAX_CONNECTION) == -1)
		throw std::runtime_error("listen: error");

	return sock;
}

void	Server::start(){
	pollfd	newPollfd = {_socket, POLLIN, 0};
	if (fcntl(_socket, F_SETFL, 0, O_NONBLOCK) == -1)
		throw std::runtime_error("fcntl: error");

	std::vector<pollfd>::iterator it;
	_pollfds.push_back(newPollfd);
	// _Invoker = new Invoker(this);

	std::cout << "Server started " << std::endl;
	while (true){
		it = _pollfds.begin();
		if (poll(&(*it), _pollfds.size(), -1) == -1)
			throw std::runtime_error("POll :error ");

		// this->action();
	}
}
