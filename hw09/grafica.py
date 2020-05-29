#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt

A = np.loadtxt("data.txt")

plt.figure()
plt.plot(A[:,0],A[:,1])
plt.grid()
plt.ylabel("posición [m]")
plt.xlabel("tiempo [s]")
plt.title("En mi codigo la gravedad ha evolucionado :), por eso da diferente jaja")

plt.savefig("grafico.pdf")
plt.close()

