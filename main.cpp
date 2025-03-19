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

double calcEnergy(int p[], double J = 1) { // set default J = 1 unless specified otherwise
    double E = 0;

    // calculate energy of system
    for(int i = 0; i < 99; i++) {
        E += -J * p[i] * p[i+1];
    }

    return E;
}

double calcEnergyChange(int arr[]){
    // "select" a random particle 
    int n = rand() % 100;

    double Ebefore = 0;
    double Eafter = 0;

    // calculate energy before
    Ebefore = calcEnergy(arr);

    // flip the value of the selected particle
    arr[n] = -arr[n];

    // calculate energy after flipping
    Eafter = calcEnergy(arr);

    double dE = Eafter - Ebefore;

    return dE;
}

double calcProb(double dE, double beta) {
    // calculate probability using boltzmann factor
    double p = exp(-beta * dE);
    cout << "p: " << p << endl;
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
    double J = 1;

    // create rng with seed dependent on time
    srand(time(0));

    // populate array with 1 or -1
    for (int i = 0; i < 100; i++) {
        sys[i] = generateRandomNumber();
    }

    // calculate energy of the system
    cout << "Energy of the system: " << calcEnergy(sys, J) << endl;

    // calculate energy change of the system
    cout << "Energy change: " << calcEnergyChange(sys) << endl;

    cout << "Probability: " << calcProb(calcEnergyChange(sys), beta) << endl;

    return 0;
}