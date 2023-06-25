/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Server
*/

#include "Server.hpp"
#include <iostream>

namespace Network {
    /////////////////
    // Constructor //
    /////////////////

    Server::Server() : _isConnected(false), _machine("127.0.0.1") {};

    //////////////
    // Methods //
    /////////////

    void Server::Initialize()
    {
        try {
            _socket.create();
        } catch (Error::NetworkError &e) {
            throw Error::NetworkError("Failed to create socket");
        }
    }

    void Server::Connect()
    {
        try {
            _socket.connect(_machine, _port);

            setConnectionStatus(true);
        } catch (Error::NetworkError &e) {
            throw Error::NetworkError("Failed to connect to server");
        }
    }

    void Server::Run()
    {
        if (_socket.processSelect() == -1) {
            setConnectionStatus(false);

            throw Error::NetworkError("Failed to process select");
        }
        
        try {
            _socket.processClient();
        } catch (Error::NetworkError &e) {
            setConnectionStatus(false);

            throw Error::NetworkError("Failed to process client");
        }
    }

    void Server::sendCommand(const std::string &command)
    {
        _socket.send(command);
    }

    ///////////////////////
    // Setters & Getters //
    ///////////////////////

    void Server::setConnectionStatus(bool status)
    {
        _isConnected = status;
    }

    void Server::setPort(std::string port)
    {
        try {
            _port = std::stoi(port);
        } catch (const std::invalid_argument &e) {
            std::cerr << "Invalid port" << std::endl;
        }
    }

    void Server::setMachine(std::string machine)
    {
        if (machine.compare("localhost") == 0) {
            _machine = "127.0.0.1";
            return;
        }
        _machine = machine;
    }

    Socket &Server::getSocket()
    {
        return _socket;
    }

    bool Server::getConnectionStatus() const
    {
        return _isConnected;
    }

    std::string Server::getResponse() const
    {
        return _socket.response;
    }
};
