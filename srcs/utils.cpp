#include "../includes/ircserv.hpp"

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	nbr = 0;
	int	neg = 1;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + str[i] - 48;
		i++;
	}
	return (nbr * neg);
}

Client *getClient(t_data *data, int fd){
	for (std::vector<Client*>::iterator it = data->clients.begin(); it != data->clients.end(); it++){
		if (fd == (*it)->getFd())
			return (*it);
	}
	return (NULL);

}

bool	ends(char *buffer){
	int i = 0;
	if (!buffer)
		return (false);
	while (buffer[i])
		i++;
	if (i > 1 && buffer[i - 1] == '\n' && buffer[i - 2] == 'r')
		return (true);
	if (i > 0 && (buffer[i - 1] == '\n' || buffer[i - 1] == 'r'))
		return (true);
	return (false);
}

string_vec seperate_lines(std::string s){
	string_vec lines;
	std::size_t nb = 0;
	std::size_t	store1 = 0;
	std::size_t	store2 = 0;
	std::size_t	previous = 0;
	while ((nb = s.find("\r\n", nb)) != std::string::npos
		|| (nb = s.find("\n", store1)) != std::string::npos
		|| (nb = s.find("\r", store2)) != std::string::npos)
	{
		lines.push_back(s.substr(previous, nb - previous));
		(s.substr(nb, 2) == std::string("\r\n")) ? previous = (nb += 2) : previous = ++nb;// +2 if \r\n, +1 if \n or \r
		store1 = nb;
		store2 = nb;
	}
	// if (lines.empty())
	// 	lines.push_back(s);
	return (lines);
}