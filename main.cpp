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

int main() {
    int data[100];

    // create rng with seed dependent on time
    srand(time(0));

    // populate array with 1 or -1
    for (int i = 0; i < 100; i++) {
        data[i] = generateRandomNumber();
    }

    return 0;
}