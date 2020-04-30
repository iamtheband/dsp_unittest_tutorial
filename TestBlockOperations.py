"""@package Python tests for the BlockOperations class
@author Andrea Martelloni (a.martelloni@qmul.ac.uk)

Provided as-is, use at own risk.
"""

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
        plt.figure()
        plt.plot(xaxis, x, xaxis, y, xaxis, z)
        plt.savefig("test_sum.png")

    def test_MonoGain(self):
        g = DSPPythonWrapper.MonoGain(0)
        x = np.arange(20)
        y = np.zeros(x.shape)
        gains = np.array([1, 2, 0.1, 0])
        pieces = 4
        stride = len(y) // pieces
        for chunk_n, chunk in enumerate(x.reshape(pieces, stride)):
            current_gain = gains[chunk_n]
            g.SetGain(current_gain)
            result = g.Process(chunk)
            y[chunk_n*stride:(chunk_n+1)*stride] = result
        plt.figure()
        plt.plot(x, x, x, y)
        plt.savefig("test_gain.png")


if __name__ == '__main__':
    unittest.main()
