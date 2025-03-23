import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

def read_spins(s):
    """
    takes a file, s, and returns the energy, magnetisation, beta and spins of the system
    """
    f = open(s, "r")
    system = f.readlines()
    
    E = float(system[0].strip()[3:])
    M = float(system[1].strip()[3:])
    B = float(system[2].strip()[5:])
    
    state = []
    for i in range(3, len(system)):
        row = []
        for j in system[i].strip().split(): # loop through each item in row to convert to float
            row.append(int(j))
        state.append(row)
    
    return E, M, B, np.array(state)


def plot_state(state, B):
    """
    create a heatmap of the state
    shows 1 and -1 as different colours
    """
    heatmap = sns.heatmap(state, cmap="viridis").set_title(f"State at Beta = {B}")
    fig = heatmap.get_figure()
    # fig.savefig(f"plots/states/state_{B}.png")
    plt.show()
    
    plt.close(fig) # prevent overlapping plots

e, m, b, state = read_spins("2d/data/ising_1.txt")
plot_state(state, b)