#include "../../includes/Client.hpp"

// Client constructor definition
Client::Client(struct sockaddr_in &sock, int &fd) : 
    _sock(sock),                // Initialize the reference to the sockaddr_in object
    _size(sizeof(_sock)),       // Initialize the size of the sockaddr_in object
    _fd(fd),                    // Initialize the reference to the socket file descriptor
    _ip(),                      // Initialize the _ip string (Note: this might be empty or initialized elsewhere)
    // _user(_ip),                 // Initialize the _user object with the _ip string (Note: _user might be a class or structure that accepts a string parameter)
    _isClose(false)          // Set _mustClose flag to false (Note: This flag might be used for indicating if the client connection should be closed)
    // flag_oper(false),           // Set flag_oper to false (Note: This flag might be used for identifying if the client has operator privileges)
    // flag_invisible(false)       // Set flag_invisible to false (Note: This flag might be used for identifying if the client is invisible or hidden)
{
    std::cout << "_size: " << _size << "_fd: " << _fd << "_isClose: " << _isClose << std::endl;
}

Client::~Client(){}

