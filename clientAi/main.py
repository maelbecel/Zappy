##
## EPITECH PROJECT, 2023
## endYearPorject
## File description:
## main
##

import src.exception.clientException as cException
import src.ai.evoli as evoli
import sys, traceback
from time import sleep

MAX_PORT = 65535


def help():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")


def parse(argv, graphic):
    client = None

    if int(argv[2]) > MAX_PORT or int(argv[2]) < 0:
        raise cException("Error: port is invalid")

    client = evoli.evoli(argv[4], argv[2], argv[6], graphic)
    return client


def main(client):

    try:
        if client is None:
            raise cException("Error: client is null")
        client.connect()
        client.run()
        client.disconnect()
    except Exception as e:
        raise e


def parseArg(argv):
    graphic = False
    machine = "localhost"
    port = 0
    name = ""
    for i in range(len(argv)):
        if argv[i] == "-p":
            port = argv[i + 1]
        elif argv[i] == "-n":
            name = argv[i + 1]
        elif argv[i] == "-h":
            machine = argv[i + 1]
        elif argv[i] == "-g":
            graphic = True
    if port == 0 or name == "":
        raise cException.clientException("Error: argument is missing")
    if int(port) > MAX_PORT or int(port) < 0:
        raise cException.clientException("Error: port is invalid")
    if machine == "localhost":
        machine = "127.0.0.1"
    client = evoli.evoli(name, port, machine, graphic)
    return client

if __name__ == "__main__":
    client = None

    if len(sys.argv) == 2 and sys.argv[1] == "-help":
        help()
        sys.exit(0)
    else:
        try:
            client = parseArg(sys.argv)
        except Exception as e:
            print(e)
            sys.exit(84)
        try:
            main(client)
        except Exception as e:
            print(e)
            # print(traceback.format_exc())
            sys.exit(84)
