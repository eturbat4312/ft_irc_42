#include "../../includes/Client.hpp"

Client::Client() : _sock(),
                   _size(sizeof(_sock)),
                   _fd(-1),
                   _ip(),
                   _isClose(false)
{
    // Initialize the Client object with default values for its member variables.
    // The constructor is called when a new Client object is created.

    // Initialize the member variable _sock with its default constructor.
    // This likely represents a socket object used for network communication.

    // Initialize the member variable _size with the size of the _sock object.
    // The sizeof() operator determines the size of the object in bytes.

    // Initialize the member variable _fd with the value -1.
    // This may represent the file descriptor associated with the socket.

    // Initialize the member variable _ip with its default constructor.
    // This might represent the IP address associated with the client.

    // Initialize the member variable _isClose with the value false.
    // This flag indicates whether the client connection is open or closed.

    // The following lines of code are commented out and therefore not executed:
    // - _user(): Possibly a member variable related to the user information.
    // - _buf(): Possibly a member variable related to a buffer for data.
    // - _reg(): Possibly a member variable related to registration information.
    // - flag_oper(false): A flag that might indicate a specific operation status.
    // - flag_invisible(false): A flag that might indicate invisibility status.

    // Finally, an empty block {} is included in the constructor body.
    // Since all member variables are already initialized using their default constructors,
    // there is no additional initialization or action required here.
}

// Client constructor definition
Client::Client(struct sockaddr_in &sock, int &fd) : _sock(sock),          // Initialize the reference to the sockaddr_in object
                                                    _size(sizeof(_sock)), // Initialize the size of the sockaddr_in object
                                                    _fd(fd),              // Initialize the reference to the socket file descriptor
                                                    _ip(),                // Initialize the _ip string (Note: this might be empty or initialized elsewhere)
                                                    // _user(_ip),                 // Initialize the _user object with the _ip string (Note: _user might be a class or structure that accepts a string parameter)
                                                    _isClose(false) // Set _mustClose flag to false (Note: This flag might be used for indicating if the client connection should be closed)
// flag_oper(false),           // Set flag_oper to false (Note: This flag might be used for identifying if the client has operator privileges)
// flag_invisible(false)       // Set flag_invisible to false (Note: This flag might be used for identifying if the client is invisible or hidden)
{
    std::cout << "_size: " << _size << "_fd: " << _fd << "_isClose: " << _isClose << std::endl;
}

Client::~Client() {}

void Client::setFd(const int &fd)
{
    _fd = fd;
}

struct sockaddr_in *Client::getSockAddress()
{
    return (&_sock);
}

socklen_t *Client::getSizeAddress()
{
    return (&_size);
}

const int &Client::getFd() const
{
    return (_fd);
}

const struct sockaddr_in &Client::getSocket() const
{
    return (_sock);
}

void Client::setIp(const std::string &ip)
{
    _ip = ip;
    _user.setHost(_ip);
}