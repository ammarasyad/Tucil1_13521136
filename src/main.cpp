#include <iostream>
#include <chrono>
#include "inputhandler.h"
#include "solver.h"

using namespace std;

int main() {
    // Step 1: Input
    vector<int> out;
    fill_array(out);

    // Step 2: Ask if user wants to save to file
    bool to_file;
    char dump;
    cout << "Apakah ingin di save ke file? (y/n): ";
    cin >> dump;
    if (dump == 'y') {
        to_file = true;
    } else {
        if (dump != 'n') {
            cout << "Input tidak valid. Program akan tidak akan save file." << endl;
        }
        to_file = false;
    }

    // Step 3: Solve
    auto start = chrono::high_resolution_clock::now();
    solve(out, to_file);
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);

    cout << "Time taken: " << duration.count() << " milliseconds" << endl;
    return 0;
}
