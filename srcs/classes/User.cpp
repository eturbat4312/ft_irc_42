#include "../../includes/ircserv.hpp"
#include "../../includes/User.hpp"

User::User() : _nick(), _name(), _host(), _realName() {}

User::User(std::string ip) : _nick(), _name(), _host(ip), _realName() {}

User::~User() {}

void User::setHost(std::string &host)
{
    _host = host;
}