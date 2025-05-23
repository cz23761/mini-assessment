#ifndef ISING_H
#define ISING_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class IsingModel {
    private:
        vector<vector<int>> spins; // use vector instead of array for increased functionality 
        double J;
        double beta;
        int rows;
        int cols;

        int generateSpin();
        double generateRealNum();

    public:
        IsingModel(double J, double beta, int rows, int cols);
        double calcEnergy();
        double calcEnergyChange(int row, int col);
        double calcProb(double dE, double beta);
        double calcMag();
        void runSimulation(int n);
        void printE();
        void printM();
        void save(const string &filename);
};

#endif