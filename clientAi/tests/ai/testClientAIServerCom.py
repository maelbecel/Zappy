##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## fileToTest
##

from unittest import TestCase

from ...src.ai.clientAi import *
from ...src.server.clientServer import *

class TryClientServerClass(TestCase):

    def test_clientServer_init(self):
        client = clientAi("team1", 4242, "localhost", False)
        self.assertEqual(client.client.getPort(), 4242)
        self.assertEqual(client.client.getHost(), "localhost")

    def test_clientServer_connect(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        self.assertIsNotNone(client.getSocket())
        client.disconnect()

    def test_clientServer_cmd_forward(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.forward()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_left(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.left()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_right(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.right()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_look(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.look()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_inventory(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.inventory()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_broadcast(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.broadcast("Hello\n")
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_connect_nbr(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.connectNbr()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        print("IS NUMBER : ", client.response , " yoyo -> ",client.response.isdigit())
        if not client.response[:-1].isdigit():
            self.fail("Error: response is not a number")
        client.disconnect()

    def test_clientServer_cmd_connect_fork(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.fork()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response == "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_connect_eject(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.eject()
        if client.response is None:
            self.fail("Error: response is null")
        if client.response != "ok\n" and client.response != "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()

    def test_clientServer_cmd_take(self):
        client = clientAi("team1", 4242, "localhost", False)
        client.connect()
        client.take("food")
        if client.response is None:
            self.fail("Error: response is null")
        if client.response != "ok\n" and client.response != "ko\n":
            self.fail("Error: response is not equal to test")
        client.disconnect()
