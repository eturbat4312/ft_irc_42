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