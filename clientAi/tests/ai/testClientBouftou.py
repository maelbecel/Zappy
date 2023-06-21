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
        client = bouftou("team1", 4242, "localhost")
        self.assertEqual(client.client.getPort(), 4242)
        self.assertEqual(client.client.getHost(), "localhost")

    def test_clientBouftou_connect(self):
        client = bouftou("team1", 4242, "localhost")
        client.connect()
        self.assertIsNotNone(client.getSocket())
        client.disconnect()
