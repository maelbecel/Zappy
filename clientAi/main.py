##
## EPITECH PROJECT, 2023
## endYearPorject
## File description:
## main
##

import src.exception.clientException as cException
import src.ai.clientAi as cAi
import sys

MAX_PORT = 65535


def help():
    print("USAGE: ./zappy_ai -p port -n name -h machine")
    print("\tport\tis the port number")
    print("\tname\tis the name of the team")
    print("\tmachine\tis the name of the machine; localhost by default")


def parse(argv):
    client = None

    if int(argv[2]) > MAX_PORT or int(argv[2]) < 0:
        raise cException("Error: port is invalid")

    client = cAi.clientAi(argv[4], argv[2], argv[6])
    return client


def main(client):
    try:
        if client is None:
            raise cException("Error: client is null")
        client.connect()
        client.inventory()
        client.disconnect()
    except Exception as e:
        raise e


if __name__ == "__main__":
    client = None

    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        help()
        sys.exit(0)
    elif (
        len(sys.argv) == 7
        and sys.argv[1] == "-p"
        and sys.argv[3] == "-n"
        and sys.argv[5] == "-h"
    ):
        try:
            client = parse(sys.argv)
        except Exception as e:
            print(e)
            sys.exit(84)
        try:
            main(client)
        except Exception as e:
            print(e)
            sys.exit(84)
