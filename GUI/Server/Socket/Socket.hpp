/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
    #define SOCKET_HPP_

    #include "NetworkError.hpp"

    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <strings.h>
    #include <unistd.h>
    #include <string>
    #include <sstream>

namespace Network {

    /**
     * @brief The Socket class
     * This class is used to manipulate socket
     */
    class Socket {

        // Constructor and Destructor
        public:

            /**
             * @brief Construct a new Socket object
             *
             */
            Socket();

            /**
             * @brief Destroy the Socket object
             *
             */
            ~Socket();

        // Methods
        public:

            /**
             * @brief Create a Socket object
             *
             * @Throw NetworkError if the socket failed to create
             */
            void create();

            /**
             * @brief Bind the socket to a port
             *
             * @param port The port to bind
             * 
             * @Throw NetworkError if the socket failed to bind
             */
            void bind(int port);

            /**
             * @brief Listen to the socket
             *
             * @param maxClient The maximum number of client
             * 
             * @Throw NetworkError if the socket failed to listen
             */
            void listen(int maxClient);

            /**
             * @brief Accept a client
             *
             * @param client The client to accept
             * 
             * @Throw NetworkError if the socket failed to accept
             */
            void accept(Socket &client);

            /**
             * @brief Connect to a server
             *
             * @param machine The ip address of the server
             * @param port    The port of the server
             * 
             * @Throw NetworkError if the socket failed to connect
             */
            void connect(std::string const &machine, int port);

            /**
             * @brief Receive data from the socket
             * Function template to receive data from the socket
             * @param buffer   A buffer to store the data (template) => char * or std::string
             * @param lenght   The lenght of the data to receive
             * @return ssize_t The number of bytes received
             */
            template<typename T>
            ssize_t receive(T &buffer, size_t lenght);

            /**
             * @brief Clear the socket
             * Close the socket
             * Reset it to 0
             */
            void clear();

            /**
             * @brief Process the select
             * Function that allows to have non-blocking sockets
             * @return int The number of socket ready
             */
            int processSelect();

            /**
             * @brief Process the client
             * Function that handle read and write socket of the client
             */
            void processClient();

            /**
             * @brief Send data to the socket
             *
             * @param message The message/data to send
             */
            void send(const std::string &message);

        // Setter
        public:
            /**
             * @brief Set the Socket object
             *
             * @param socket The fd socket to set
             */
            void setSocket(int socket);

        // Private Methods
        private:

            /**
             * @brief Read and parse information that the server read
             * 
             * @return std::string The information read by the server
             */
            void readClient();

            /**
             * @brief Write the response of the information given
             */
            void writeClient();

        // Attributes
        private:
            int _socket;          /*!< The fd of the socket */
            sockaddr_in _address; /*!< The address of the socket */
            int _maxSocket;       /*!< The maximum number of socket */
            fd_set _read;         /*!< The read socket of the socket */
            fd_set _write;        /*!< The write socket of the socket */

        // Accessible Attribute
        public:
            std::string response; /*!< The response of the server */
    };
};

#endif /* !SOCKET_HPP_ */
