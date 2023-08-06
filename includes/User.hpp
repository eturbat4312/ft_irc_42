#pragma once

// #include "ircserv.hpp"

#include <iostream>

class Client;

class User
{
private:
    std::string _nick;
    std::string _name;
    std::string _host;
    std::string _realName;

public:
    User();
    User(std::string ip);
    ~User();

    void setHost(std::string &host);
};