/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Socket
*/

#include "Socket.hpp"
#include <iostream>

namespace Network {

    //////////////////////////////
    // Constructor & Destructor //
    //////////////////////////////

    Socket::Socket() : _socket(0), _maxSocket(0) {};

    Socket::~Socket()
    {
        this->clear();
    }

    /////////////
    // Methods //
    /////////////

    void Socket::create()
    {
        _socket = socket(AF_INET, SOCK_STREAM, 0);

        if (_socket == -1)
            throw Error::NetworkError("Failed to create socket");
    }

    void Socket::bind(int port)
    {
        bzero(&_address, sizeof(_address));

        _address.sin_family = AF_INET;
        _address.sin_addr.s_addr = htonl(INADDR_ANY);
        _address.sin_port = htons(port);

        if (::bind(_socket, reinterpret_cast<struct sockaddr *>(&_address), sizeof(_address)) == -1)
            return throw Error::NetworkError("Failed to bind socket");
    }

    void Socket::listen(int maxClient)
    {
        if (::listen(_socket, maxClient) == -1)
            return throw Error::NetworkError("Failed to listen socket");
    }

    void Socket::accept(Socket &client)
    {
        socklen_t clientAddressLength = sizeof(_address);

        int clientSockfd = ::accept(_socket, reinterpret_cast<struct sockaddr *>(&_address), &clientAddressLength);

        if (clientSockfd == -1)
            throw Error::NetworkError("Failed to accept client");
        client.setSocket(clientSockfd);
    }

    void Socket::connect(const std::string &machine, int port)
    {
        bzero(&_address, sizeof(_address));

        _address.sin_family = AF_INET;
        _address.sin_addr.s_addr = inet_addr(machine.c_str());
        _address.sin_port = htons(port);

        if (::connect(_socket, reinterpret_cast<struct sockaddr *>(&_address), sizeof(_address)) == -1)
            throw Error::NetworkError("Failed to connect to server");
        _maxSocket = _socket;
    }

    template <typename T>
    ssize_t Socket::receive(T &buffer, size_t length)
    {
        return ::recv(_socket, &buffer, length, 0);
    }

    void Socket::clear()
    {
        if (_socket != 0)
            close(_socket);
        _socket = 0;
    }

    int Socket::processSelect()
    {
        FD_ZERO(&_read);
        FD_SET(STDIN_FILENO, &_read);
        FD_SET(_socket, &_read);
    
        FD_ZERO(&_write);
        FD_SET(STDIN_FILENO, &_write);
        FD_SET(_socket, &_write);

        return select(_socket + 1, &_read, &_write, NULL, NULL);
        //return select(_socket + 1, &_read, NULL, NULL, NULL);
    }

    void Socket::processClient()
    {
        if (FD_ISSET(_socket, &_read)) {
            this->readClient();
            this->writeClient();
        }
    }

    void Socket::readClient()
    {
        std::string buffer;
        char c;

        while (::recv(_socket, &c, 1, 0) > 0) {
            buffer += c;

            if (c == '\n')
                break;
        }
        response = buffer;
    }


    void Socket::writeClient()
    {
        if (response.compare("") == 0 || response.compare("\n") == 0 || response.compare("ko\n") == 0)
            return;

        // Connexion response
        if (response.compare("WELCOME\n") == 0)
            ::send(_socket, "GRAPHIC\n", 9, 0);
    }

    void Socket::send(const std::string &command)
    {
        std::string tmp = command + "\n";

        ::send(_socket, tmp.c_str(), tmp.size(), 0);
    }

    ////////////
    // Setter //
    ////////////

    void Socket::setSocket(int socket)
    {
        _socket = socket;
    }
}
