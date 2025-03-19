#include <iostream>
#include <cstdlib>
#include <ctime>
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

double calcEnergy(int p[]) {
    double J = 1;
    double E = 0;

    // calculate energy of system
    for(int i = 0; i < 99; i++) {
        E += -J * p[i] * p[i+1];
    }
    cout << E << endl;
    return E;
}

int main() {
    int sys[100];

    // create rng with seed dependent on time
    srand(time(0));

    // populate array with 1 or -1
    for (int i = 0; i < 100; i++) {
        sys[i] = generateRandomNumber();
    }

    calcEnergy(sys);

    return 0;
}