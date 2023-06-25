##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## fileToTest
##

from unittest import TestCase

from ...src.ai.evoli import *
from ...src.server.clientServer import *

class TryClientServerClass(TestCase):

    def test_clientEvoli_init(self):
        client = evoli("team1", 4242, "localhost", False)
        self.assertEqual(client.client.getPort(), 4242)
        self.assertEqual(client.client.getHost(), "localhost")

    def test_clientEvoli_connect(self):
        client = evoli("team1", 4242, "localhost", False)
        client.connect()
        self.assertIsNotNone(client.getSocket())
        client.disconnect()

    def test_clientEvoli_CountPlayer(self):

        count = 0

        client = evoli("team1", 4242, "localhost", False)
        client.connect()
        client.look()
        count = client.countPlayerOnCase()

        if (count != 1):
            self.fail("Error: count is not equal to 1")
        client.disconnect()

    def test_clientEvoli_cmd_compareDict0(self):

        dict1 = {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}
        dict2 = {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}

        client = evoli("team1", 4242, "localhost", False)
        client.connect()

        if not (client.compareDict(dict1, dict2)):
            self.fail("Error: compareDict is not equal to true")

        client.disconnect()

    def test_clientEvoli_cmd_compareDict1(self):

        dict1 = {"linemate": 4, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}
        dict2 = {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}

        client = evoli("team1", 4242, "localhost", False)
        client.connect()

        if not (client.compareDict(dict1, dict2)):
            self.fail("Error: compareDict is not equal to true")

        client.disconnect()

    def test_clientEvoli_cmd_compareDict2(self):

        dict1 = {"linemate": 4, "deraumere": 0, "sibur": 1, "mendiane": 0, "phiras": 5, "thystame": 0}
        dict2 = {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}

        client = evoli("team1", 4242, "localhost", False)
        client.connect()

        if not (client.compareDict(dict1, dict2)):
            self.fail("Error: compareDict is not equal to true")

        client.disconnect()

    def test_clientEvoli_cmd_compareDict3(self):

        dict1 = {"linemate": 0, "deraumere": 0, "sibur": 1, "mendiane": 0, "phiras": 5, "thystame": 0}
        dict2 = {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 2, "thystame": 0}

        client = evoli("team1", 4242, "localhost", False)
        client.connect()

        if (client.compareDict(dict1, dict2)):
            self.fail("Error: compareDict is not equal to true")

        client.disconnect()

    def test_clientEvoli_cmd_compareDict4(self):

        dict1 = {"linemate": 2, "deraumere": 0, "sibur": 1, "mendiane": 3, "phiras": 5, "thystame": 0}
        dict2 = {"linemate": 1, "deraumere": 0, "sibur": 1, "mendiane": 2, "phiras": 3, "thystame": 0}

        client = evoli("team1", 4242, "localhost", False)
        client.connect()

        if not (client.compareDict(dict1, dict2)):
            self.fail("Error: compareDict is not equal to true")

        client.disconnect()

    def test_clientEvoli_cmd_getDictFromCase(self):

        temp = dict()

        client = evoli("team1", 4242, "localhost", False)
        client.connect()

        client.look()
        print(client.lookResult)
        client.look()
        print("AAAAAA", client.lookResult)

        temp = client.getDictFromCase(0)

        for element in temp:
            if not element in REQUIRED[0]:
                self.fail("Error: element is not in REQUIRED")

        for element in REQUIRED[0]:
            if not element in temp:
                self.fail("Error: element is not in temp")

        client.disconnect()

    def test_GoTo(self):

        client = evoli("team1", 4242, "localhost", False)
        client.connect()
        client.look()
        client.getGoTo(0)
        self.assertEqual(client.getQueue(), [])
        client.disconnect()

    def test_GoTo2(self):

        client = evoli("team1", 4242, "localhost", False)

        client.connect()
        client.look()
        client.getGoTo(1)
        self.assertEqual(client.getQueue(), [client.forward, client.left, client.forward])

    def test_GoTo3(self):

        client = evoli("team1", 4242, "localhost", False)

        client.connect()
        client.look()
        client.getGoTo(2)
        self.assertEqual(client.getQueue(), [client.forward])

    def test_GoTo4(self):

        client = evoli("team1", 4242, "localhost", False)

        client.connect()
        client.look()
        client.getGoTo(3)
        self.assertEqual(client.getQueue(), [client.forward, client.right, client.forward])
