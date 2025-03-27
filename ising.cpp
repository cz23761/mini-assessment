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

IsingModel::IsingModel(double J, double beta, int rows, int cols){
    this->J = J;
    this->beta = beta;
    this->rows = rows;
    this->cols = cols;

    spins = vector<vector<int>>(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            spins[i][j] = generateSpin();
        }
    }
}

double IsingModel::calcEnergy() {
    double E = 0;

    // loop through the system keeping count of the energy
    // only need to look at the right and bottom neighbors for each particle. this avoids double counting of energies.
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            E += -J * spins[i][j] * spins[i + 1][j]; // bottom
            E += -J * spins[i][j] * spins[i][j + 1]; // right
        }
    }
    return E;
}

double IsingModel::calcEnergyChange(int row, int col){
    double dE = 0;

    // select the spin at the given row and column
    int spin = spins[row][col];

    // calculate the energy change if that particle is flipped
    if (row > 0){ // top neighbour
        dE += J * spin * spins[row - 1][col];
    }
    if (row < rows - 1){ // bottom neighbour
        dE += J * spin * spins[row + 1][col];
    }
    if (col > 0){ // left neighbour
        dE += J * spin * spins[row][col - 1];
    }
    if (col < cols -1){ // right neighbour
        dE += J * spin * spins[row][col + 1];
    }
    
    return 2 * dE;
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
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M += spins[i][j];
        }
    }
    return M;
}

void IsingModel::runSimulation(int n){
    // loop through the system n times
    for (int i = 0; i < n; i++) {
        // srand(int(time(0)) + i);
        // select particle
        int kRow = rand() % rows;
        int kCol = rand() % cols;

        // calculate energy change if that particle is flipped
        double dE = calcEnergyChange(kRow, kCol);

        // calculate probability of flipping that particle based on energy change
        double prob = calcProb(dE, beta);
        double rnum = generateRealNum();

        // flip the particle if the probability is large enough
        if (rnum < prob) {
            spins[kRow][kCol] = -spins[kRow][kCol]; // flip the particle
        }
    }
}

void IsingModel::save(const string &filename){    
    ofstream file(filename);

    // exit if file is oppen
    if(!file.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    file << "E: " << calcEnergy() << endl;
    file << "M: " << calcMag() << endl;
    file << "Beta: " << beta << endl;

    // loop through each element in the system and write its spin to the output file
    for (int i = 0; i < int(spins.size()); i++) {
        for (int j = 0; j < int(spins[i].size()); j++) {
            file << spins[i][j] << " ";
        }
        file << endl;
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
