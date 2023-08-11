#pragma once

#include "ircserv.hpp"
#include <vector>
#include <string>

class Client;

class Channel
{
private:
    std::string _channel_name;
    std::string _topic;
    std::string _mode;
    std::vector<Client *> _clients;
    std::string _key;
    std::vector<Client *> _voiced;
    std::vector<Client *> _invited;

public:
    std::vector<Client *> _operator;
    size_t chan_user_limit;
    bool flag_key;
    bool flag_channel_user_limit;
    bool flag_invite_only;
    bool flag_moderated;

    Channel();
    Channel(const std::string channel_name);

    ~Channel();

    Channel const &operator=(const Channel &obj);

    const std::string &getChanName() const;
    const std::string &getTopic() const;
    const std::string &getMode() const;
    std::vector<Client *> &getClients();
    const std::string &getKey() const;

    void setChanName(const std::string &name);
    void setMode(const std::string &mode);
    void setTopic(const std::string &topic);
    void setChannelKey(const std::string &key);
    void setChannelLimit(const size_t limit);
    void setChannelInviteOnly(void);
    void setChannelModerated(void);
};