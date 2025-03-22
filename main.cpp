#include <iostream>
#include <ctime>
#include "ising.h"
using namespace std;

int main() {
    // seed the random number generator
    srand(time(0));

    // create an IsingModel object
    IsingModel model(1, 1, 100); // J, beta, n

    // print intital system energy and magnetisation
    model.printE();
    model.printM();

    // run the simulation
    cout << "\nRunning simulation..." << endl;
    model.runSimulation(1000);
    cout << "Simulation complete.\n" << endl;

    // print final system energy and magnetisation
    model.printE();
    model.printM();

    return 0;
}