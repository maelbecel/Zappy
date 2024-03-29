/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include "Socket.hpp"

namespace Network {

    /**
     * @brief The server class
     * This class is used to connect the GUI Client to the server and send the commands to the server
     * but also to get the response of the server
     */
    class Server {

        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Server object
             */
            Server();

            ~Server() = default;

        // Methods
        public:
            /**
             * @brief Initialize the server
             *
             * @Throw NetworkError if the socket failed to create
             */
            void Initialize();

            /**
             * @brief Connect to a server
             * Connect the GUI Client to the server
             * @param machine The IP address of the server
             * @param port    The port of the server
             * 
             * @Throw NetworkError if the socket failed to connect
             */
            void Connect();

            /**
             * @brief Run the server
             */
            void Run();

            /**
             * @brief Send the command to the server
             *
             * @param command The command to send
             */
            void sendCommand(const std::string &command);

        // Setters & Getters
        public:

            /**
             * @brief Set the Connection Status object
             *
             * @param status The new status
             */
            void setConnectionStatus(bool status);

            /**
             * @brief Set the Port object
             *
             * @param port The new port
             */
            void setPort(std::string port);

            /**
             * @brief Set the Machine object
             * 
             * @param machine The new machine
             */
            void setMachine(std::string machine);

            /**
             * @brief Get the Socket object
             *
             * @return Socket The socket
             */
            Socket &getSocket();

            /**
             * @brief Get the Connection Status object
             *
             * @return true  The client is connected to the server
             * @return false The client is not connected to the server
             */
            bool getConnectionStatus() const;

            /**
             * @brief Get the response message from the server
             *
             * @return std::string The response of the server
             */
            std::string getResponse() const;

        // Attributes
        private:
            Socket _socket;       /*!< The socket */
            bool _isConnected;    /*!< True if the client is connected to the server */
            int _port;            /*!< The port */
            std::string _machine; /*!< The IP address */
    };
};

#endif /* !SERVER_HPP_ */
