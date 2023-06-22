##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## fileToTest
##

from unittest import TestCase

from ...src.ai.bouftou import *
from ...src.server.clientServer import *

class TryClientServerClass(TestCase):

    def test_clientBouftou_init(self):
        client = bouftou("team1", 4242, "localhost", "food", False)
        self.assertEqual(client.client.getPort(), 4242)
        self.assertEqual(client.client.getHost(), "localhost")

    def test_clientBouftou_connect(self):
        client = bouftou("team1", 4242, "localhost", "food", False)
        client.connect()
        self.assertIsNotNone(client.getSocket())
        self.assertEqual(client.getElementToGrab(), "food")
        client.disconnect()

    def test_checkElementToGrab(self):
        client = bouftou("team1", 4242, "localhost", "food", False)
        client.connect()
        self.assertEqual(client.checkElementToGrab(), True)
        self.assertEqual(client.getProcess(), 3)
        client.disconnect()

    def test_checkElementToGrab2(self):
        client = bouftou("team1", 4242, "localhost", "linemate", False)
        client.connect()
        self.assertEqual(client.checkElementToGrab(), True)
        self.assertEqual(client.getProcess(), 2)
        client.disconnect()

    def test_checkElementToGrab3(self):
        client = bouftou("team1", 4242, "localhost", "thystame", False)
        client.connect()
        self.assertEqual(client.checkElementToGrab(), True)
        self.assertEqual(client.getProcess(), 3)
        client.disconnect()

    def test_checkElementToGrab4(self):
        client = bouftou("team1", 4242, "localhost", "AgaAga", False)
        client.connect()
        self.assertFalse(client.checkElementToGrab())
        client.disconnect()
