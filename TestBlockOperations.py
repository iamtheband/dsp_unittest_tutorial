import DSPPythonWrapper
import unittest
import numpy as np
from matplotlib import pyplot as plt

class TestBlockOperations(unittest.TestCase):

    def test_SumTwoArrays(self):
        x = np.array([1, 2, 3, 4, 5])
        y = 10 * np.ones(x.shape)
        z = DSPPythonWrapper.SumTwoArrays(x, y)
        xaxis = np.arange(len(x))
        plt.plot(xaxis, x, xaxis, y, xaxis, z)
        plt.savefig("test_sum.png")


if __name__ == '__main__':
    unittest.main()
