#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int generateRandomNumber() {
    // generate a random 1 or 2
    int n = rand() % 2 + 1;

    // return 1 if n is 1 or -1 if n is 2
    if (n == 1) {
        return 1;
    } else {
        return -1;
    }
}

double randReal() {
    // generate a random number between 0 and 1
    return (double)rand() / RAND_MAX;
}

double calcEnergy(int p[], double J = 1) { // set default J = 1 unless specified otherwise
    double E = 0;

    // calculate energy of system
    for(int i = 0; i < 99; i++) {
        E += -J * p[i] * p[i+1];
    }

    // return energy
    return E;
}

double calcEnergyChange(int arr[], int n){
    double Ebefore = 0;
    double Eafter = 0;

    // calculate energy before
    Ebefore = calcEnergy(arr);

    // flip the value of the selected particle
    arr[n] = -arr[n];

    // calculate energy after flipping
    Eafter = calcEnergy(arr);

    // unflip the value of the selected particle
    arr[n] = -arr[n];

    // return the energy change
    return Eafter - Ebefore;
}

double calcProb(double dE, double beta) {
    // calculate probability using boltzmann factor
    double p = exp(-beta * dE);
    if (p > 1) {
        return 1;
    } else {
        return p;
    }
}

int main() {
    // create system conditions
    int sys[100];
    double beta = 1;
    int n = 1000;

    // set seed for random numbers to be based off of the time
    srand(time(0));

    // populate array with 1 or -1
    for (int i = 0; i < 100; i++) {
        sys[i] = generateRandomNumber();
    }

    // output total energy of the system before running the simulation
    cout << "Energy before: " << calcEnergy(sys) << endl;   

    // main loop
    for (int i = 0; i < n; i++) {
        // select particle
        int k = rand() % 100;

        //calculate energy change if that particle is flipped
        double EChange = calcEnergyChange(sys, k);

        // calculate probability of flipping that particle based on the energy change
        double prob = calcProb(EChange, beta);
        double rnum = randReal();

        // flip the particle if the probability is large enough
        if (rnum < prob) {
            sys[k] = -sys[k]; // flip the particle
            // cout << "Particle " << k << " flipped" << endl;
        }
    }

    // output total energy of the system after running the simulation
    cout << "Energy after: " << calcEnergy(sys) << endl;

    return 0;
}