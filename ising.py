import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

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
        for j in system[i].strip().split():# must be 2d array for sns heatmap
            state.append([int(j)])
    
    return E, M, B, np.array(state)


def plot_ising(E, M, B):
    """
    creates histograms of the energy and magnetisation
    """
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 8))
    
    ax1.hist(E, bins=10)
    ax2.hist(M, bins=10)
    
    ax1.set_title(f"Energy (Avg E={mean(E)})")
    ax1.set_xlabel("Energy")
    ax1.set_ylabel("Count")
    
    ax2.set_title(f"Magnetisation (Avg M={mean(M)})")
    ax2.set_xlabel("Magnetisation")
    ax2.set_ylabel("Count")
    
    fig.savefig(f"plots/hists/ising_{B}.png")
    plt.close(fig) # prevent overlapping plots
    

def plot_state(state, B):
    """
    create a heatmap of the state
    shows 1 and -1 as different colours
    """
    heatmap = sns.heatmap(state, cmap="viridis").set_title(f"State at Beta = {B}")
    fig = heatmap.get_figure()
    fig.savefig(f"plots/states/state_{B}.png")
    
    plt.close(fig) # prevent overlapping plots
    
def mean(l):
    """
    returns the mean of a list
    """
    return sum(l)/len(l)
    
        
# read text file
E = []
M = []

for i in range(1, 1001):
    energy, magnetisation, beta, state = read_spins(f"data/ising_{i}.txt")
    
    # create lists of the energy and magnetisation
    E.append(energy)
    M.append(magnetisation)
    
# plot the energies and magnetisations
plot_ising(E, M, beta)

# plot a state
plot_state(state, beta)