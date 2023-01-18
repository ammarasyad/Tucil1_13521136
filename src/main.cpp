#include <iostream>
#include "inputhandler.h"
#include <chrono>

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

#define TARGET 24

using namespace std;

int main() {
    // Step 1: Input
    unsigned int out[4];
    fill_array(out);


//    int result;
//    do {
//        result = stoia(out);
//    } while(result != 0);

    auto start = chrono::high_resolution_clock::now();

    for (unsigned int i : out) {
        cout << i << endl;
    }

    auto duration = chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - start);
    cout << "Time taken: " << duration.count() << " seconds" << endl;
    return 0;
}
