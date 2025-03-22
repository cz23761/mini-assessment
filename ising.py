import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

E = []
M = []

# read each data file
for i in range(1, 100):
    f = open(f"data/ising_{i}", "r")
    
    # energy and magnetisation are on the first two lines
    E.append(float(f.readline().strip()[3:]))
    M.append(float(f.readline().strip()[3:]))
    
    f.close()

# plot histograms of energy and magnetisation
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 8))

ax1.hist(E, bins=10)
ax2.hist(M, bins=10)

ax1.set_title("Energy")
ax1.set_xlabel("Energy")
ax1.set_ylabel("Count")

ax2.set_title("Magnetisation")
ax2.set_xlabel("Magnetisation")
ax2.set_ylabel("Count")

plt.show()