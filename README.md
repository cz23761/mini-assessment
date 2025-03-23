# Ising model simulation - Jack Rogerson

This project simulates the Ising model which simulates a system of interacting particles with a statistical mechanics approach.

## Python dependencies
numpy
matplotlib
seaborn

install dependencies with pip:
pip install numpy matplotlib seaborn

## Running the code
There is a makefile that compiles the c++ code. Run the command "make" in the command line to compile. This will create an executable called "ising".

Run the executable with "./ising" in the console.
This will run a monte carlo simulation with 10,000 steps and create 1,000 configurations. This was to ensure the ability to study how the system behaves on average at a certain temperature (beta value).
The results are saved in /data

## Visulising results
After running the simulation, run the python script. This will create histograms of the energy and magnetisation of the system in /plots/hists as well as an illustration of a single configuration at that temperature in /plots/states.