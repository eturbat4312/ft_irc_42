#include "../../includes/Channel.hpp"

Channel::Channel() : _channel_name(), _topic(), _mode(), _clients(), _key(), chan_user_limit(), flag_key(), flag_channel_user_limit(), flag_invite_only(), flag_moderated() {}

Channel::Channel(const std::string name) : _channel_name(name), _topic(""), _mode(""), _clients(), _key(""), chan_user_limit(1000), flag_key(false), flag_channel_user_limit(false), flag_invite_only(false), flag_moderated(false) {}

Channel::~Channel() {}
