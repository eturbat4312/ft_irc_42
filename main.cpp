#include "srcs/Serv/server.hpp"

int	main(int argc, char **argv){
	try{
		if (argc < 2 || argc > 3)
			throw std::runtime_error("invalid arguments : error");
		if (argc == 3){
			Server ircserv("127.0.0.1", argv[1], argv[2]);
			ircserv.start();
		}
		else{
			throw std::runtime_error("Error: invalid number of arguments ");
		}

	}catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}