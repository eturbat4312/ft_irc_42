#include "../includes/ircserv.hpp"
// #include "../includes/Client.hpp"
// #include "../includes/Buffer.hpp"

std::vector<Channel *> g_channels;

int main(int argc, char **argv)
{
	t_data my_data;

	if (data_init(argc, argv, &my_data) == -1)
		throw std::runtime_error("error! initialize data on main");

	// Socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	int option = 1;
	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
	if (socket_fd == -1)
		throw std::runtime_error("Error: Socket Creation");
	std::cout << "[Socket created ...] " << std::endl;

	// Server_address
	struct sockaddr_in server_address;
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(my_data.port);
	server_address.sin_addr.s_addr = htons(INADDR_ANY);

	// Bind
	if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
		throw std::runtime_error("Error: Binding");
	std::cout << "[Binding done ...]" << std::endl;

	listen(socket_fd, SOMAXCONN);
	std::cout << "[listening ...]" << std::endl;

	int nb_fds = 1;
	int recieved = 0;

	Client server(server_address, socket_fd);
	// Buffer buffer;
	my_data.clients.push_back(&server);

	struct pollfd s_poll;
	memset(&s_poll, 0, sizeof(s_poll));
	s_poll.fd = socket_fd;
	// std::cout << "socket_fd : " << socket_fd<< std::endl;
	s_poll.events = POLLIN;
	my_data.pollfds.push_back(s_poll);

	while (true)
	{
		int ret = poll(my_data.pollfds.data(), nb_fds, 0);
		// std::cout << "ret : " << ret << std::endl;
		if (ret == -1)
		{
			throw std::runtime_error("Error: Poll");
			break;
		}
		else
		{
			for (int i = 0; i < nb_fds; i++)
			{
				if (!my_data.pollfds[i].revents)
					continue;
				if (my_data.pollfds[i].fd == socket_fd)
				{
					bool add = true;
					while (add)
					{
						Client *new_client = new Client;
						new_client->setFd(accept(socket_fd, (struct sockaddr *)new_client->getSockAddress(), new_client->getSizeAddress()));
						if (new_client->getFd() > 0)
						{
							std::cout << "[new client connection on fd ]" << new_client->getFd() << std::endl;

							char tmp_buff[100] = {0};
							char *x = tmp_buff;
							x = inet_ntoa(new_client->getSocket().sin_addr);
							new_client->setIp(std::string(x));
							my_data.clients.push_back(new_client);

							struct pollfd new_s_poll;
							memset(&new_s_poll, 0, sizeof(new_s_poll));
							new_s_poll.fd = new_client->getFd();
							new_s_poll.events = POLLIN;
							my_data.pollfds.push_back(new_s_poll);

							nb_fds++;
						}
						else
						{
							add = false;
							delete (new_client);
						}
					}
				}
				else
				{
					std::cout << "[ in fd ]" << my_data.pollfds[i].fd << std::endl;

					Client *client = getClient(&my_data, my_data.pollfds[i].fd);
					if (!client)
						continue;
					if ((recieved = recv(client->getFd(), client->fillBuff(), 512, MSG_DONTWAIT)) == -1)
						continue;
					// else if (!recieved)
					// 	delete_client(my_data, i, nb_fds);
					else if (!ends(client->fillBuff()))
						client->updateBuf();
					else
					{
						parsing(&data, client, std::string(client->updateBuf()));
						client->clearBuf();
					}
				}
			}
		}
	}
}