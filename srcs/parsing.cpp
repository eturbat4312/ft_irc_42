#include "../../includes/ircserv.hpp"

void	parsing(t_data *data, Client *client, std::string buf){
	string_vec recieved = seperate_lines(buf);
	string_vec::iterator recieved_it = recieved.begin();
	string_vec::iterator recieved_end = recieved.end();

	string_vec	replies;
	
}