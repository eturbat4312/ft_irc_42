#include "../../includes/Channel.hpp"

Channel::Channel() : _channel_name(), _topic(), _mode(), _clients(), _key(), chan_user_limit(), flag_key(), flag_channel_user_limit(), flag_invite_only(), flag_moderated() {}

Channel::Channel(const std::string name) : _channel_name(name), _topic(""), _mode(""), _clients(), _key(""), chan_user_limit(1000), flag_key(false), flag_channel_user_limit(false), flag_invite_only(false), flag_moderated(false) {}

Channel::~Channel() {}

Channel const &Channel::operator=(const Channel &rhs)
{
    this->_channel_name = rhs._channel_name;
    this->_topic = rhs._topic;
    this->_mode = rhs._mode;
    this->_clients = rhs._clients;
    this->_key = rhs._key;
    this->flag_key = rhs.flag_key;
    this->chan_user_limit = rhs.chan_user_limit;
    this->flag_channel_user_limit = rhs.flag_channel_user_limit;
    this->flag_channel_user_limit = rhs.flag_invite_only;
    this->flag_moderated = rhs.flag_moderated;
    return (*this);
}

const std::string &Channel::getChanName() const { return _channel_name; };
const std::string &Channel::getTopic() const { return _topic; };
const std::string &Channel::getMode() const { return _mode; };
std::vector<Client *> &Channel::getClients() { return _clients; };
const std::string &Channel::getKey() const { return _key; };