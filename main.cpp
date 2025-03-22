#include "ising.h"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <random>
#include <ctime>

using namespace std;

int main() {
    // number of monte carlo simulations
    int sweeps = 100;

    for (int sweep = 0; sweep < sweeps; sweep++) {
        // seed the random number generator based on time and MCS number
        srand((int(time(0)) + sweep));

        // create an IsingModel object
        IsingModel model(1, 0.2, 100); // J, beta, n

        // print intital system energy and magnetisation
        model.printE();
        model.printM();

        // run the simulation
        cout << "\nRunning simulation " << sweep + 1 << "..." << endl;
        model.runSimulation(1000);
        cout << "Simulation complete.\n" << endl;

        // print final system energy and magnetisation
        model.printE();
        model.printM();
        cout << "*****" << endl;

        // save the final system to a file
        string root = "data/ising_";
        model.save(root + to_string(sweep + 1));
    }

    return 0;
}