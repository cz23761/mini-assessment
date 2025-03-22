#ifndef ISING_H
#define ISING_H

#include <iostream>
#include <vector>

class IsingModel {
    private:
        std::vector<int> spins;
        double J;
        double beta;
        int n;

        int generateSpin();
        double generateRealNum();

    public:
        IsingModel(double J, double beta, int n);
        double calcEnergy();
        double calcEnergyChange(int n);
        double calcProb(double dE, double beta);
        double calcMag();
        void runSimulation(int n);
        void printE();
        void printM();
};

#endif