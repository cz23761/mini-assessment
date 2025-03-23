#include "ising.h"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;

int main() {
    int configs = 1000; // number of configurations
    int monteCarloSteps = 10000; // number of times to pick a particle 

    cout << "Running simulation..." << endl;

    // run the simulation
    for (int config = 0; config < configs; config++) {
        // seed the random number generator based on time iteration number
        srand((int(time(0)) + config));

        // create an IsingModel object
        IsingModel model(1, 1, 100); // J, beta, N
        
        model.runSimulation(monteCarloSteps);

        // save the final system to a file
        string root = "data/ising_";
        model.save(root + to_string(config + 1) + ".txt");
    }

    cout << "Simulation complete." << endl;

    return 0;
}