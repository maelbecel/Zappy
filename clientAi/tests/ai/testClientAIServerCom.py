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
        client = clientAi("team1", 4242, "localhost")
        # client = clientAi("team1", 4242, "localhost")
        self.assertEqual(client.client.getPort(), 4242)
        self.assertEqual(client.client.getHost(), "localhost")

    def test_clientServer_connect(self):
        client = clientAi("team1", 4242, "localhost")
        # client = clientAi("team1", 4242, "localhost")
        client.connect()
        self.assertIsNotNone(client.getSocket())
        client.disconnect()

    # def test_clientServer_cmd_forward(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.forward()
    #     response = client.receive()
    #     # if response is None:
    #     #     self.fail("Error: response is null")
    #     # if response == "ko\n":
    #     #     self.fail("Error: response is not equal to test")
    #     client.disconnect()

    # def test_clientServer_cmd_left(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.left()
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response == "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     client.disconnect()

    # def test_clientServer_cmd_right(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.right()
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response == "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     client.disconnect()

    # def test_clientServer_cmd_look(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.look()
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response == "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     client.disconnect()

    # def test_clientServer_cmd_inventory(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.inventory()
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response == "ko\n":
    #         self.fail("Error: response is not equal to test")

    #     # need to check if the inventory is correct

    #     client.disconnect()

    # def test_clientServer_cmd_broadcast(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.broadcast("Hello\n")
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response == "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     client.disconnect()

    # def test_clientServer_cmd_connect_nbr(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.connect_nbr()
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response == "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     # if not isdigit(response):
    #     #     self.fail("Error: response is not a number")
    #     client.disconnect()

    # def test_clientServer_cmd_connect_fork(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.fork()
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response == "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     client.disconnect()

    # def test_clientServer_cmd_connect_eject(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.eject()
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response != "ok\n" and response != "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     client.disconnect()

    # def test_clientServer_cmd_take(self):
    #     response = None
    #     client = clientAi("team1", 4242, "localhost")
    #     client.connect()
    #     client.take("food")
    #     response = client.receive()
    #     if response is None:
    #         self.fail("Error: response is null")
    #     if response != "ok\n" and response != "ko\n":
    #         self.fail("Error: response is not equal to test")
    #     client.disconnect()
