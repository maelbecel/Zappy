from unittest import TestCase

class TryTesting(TestCase):
    def test_always_true_1(self):
        self.assertTrue(False)

    def test_always_true_2(self):
        self.assertFalse(False)
