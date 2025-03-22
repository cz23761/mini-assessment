#include "ising.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int IsingModel::generateSpin() {
    // generate a random 1 or 2
    int n = rand() % 2 + 1;

    // return 1 if n is 1 or -1 if n is 2
    if (n == 1) {
        return 1;
    } else {
        return -1;
    }
}

double IsingModel::generateRealNum() {
    return (double)rand() / RAND_MAX;
}

IsingModel::IsingModel(double J, double beta, int n){
    // srand(time(0));
    this->J = J;
    this->beta = beta;
    this->n = n;

    for (int i = 0; i < n; i++) {
        spins.push_back(generateSpin());
    }
}

double IsingModel::calcEnergy()
{
    double E = 0;

    // loop through the system keeping count of the energy
    for (int i = 0; i < n - 1; i++) {
        E += -J * spins[i] * spins[i + 1];
    }
    return E;
}

double IsingModel::calcEnergyChange(int n){
    double Ebefore = 0;
    double Eafter = 0;

    // calculate energy before
    Ebefore = calcEnergy();

    // flip the value of the selected particle
    spins[n] = -spins[n];

    // calculate energy after flipping
    Eafter = calcEnergy();

    // unflip the value of the selected particle
    spins[n] = -spins[n];

    // return the energy change that would result in the flipping of that particle
    return Eafter - Ebefore;
}

double IsingModel::calcProb(double dE, double beta){
    // calculate probability using boltzmann factor
    double p = exp(-beta * dE);
    if (p > 1) {
        return 1;
    } else {
        return p;
    }
}

double IsingModel::calcMag(){
    double M = 0;

    // sum all spins in the system
    for (int i = 0; i < n; i++) {
        M += spins[i];
    }
    return M;
}

void IsingModel::runSimulation(int n){
    // loop through the system n times
    for (int i = 0; i < n; i++) {
        // select particle
        int k = rand() % 100;

        // calculate energy change if that particle is flipped
        double dE = calcEnergyChange(k);

        // calculate probability of flipping that particle based on energy change
        double prob = calcProb(dE, beta);
        double rnum = generateRealNum();

        // flip the particle if the probability is large enough
        if (rnum < prob) {
            spins[k] = -spins[k]; // flip the particle
        }
    }
}

void IsingModel::save(const string &filename){    
    ofstream file(filename);

    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // loop through each element in the system and write its spin to the output file
    for (int i = 0; i < int(spins.size()); i++) {
        file << spins[i] << endl;
    }

    // close output file
    file.close();
}

void IsingModel::printE(){
    cout << "Energy: " << calcEnergy() << endl;
}

void IsingModel::printM(){
    cout << "Magnetization: " << calcMag() << endl;
}
