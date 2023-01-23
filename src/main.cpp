#include <iostream>
#include <chrono>
#include "inputhandler.h"
#include "solver.h"

using namespace std;

int main() {
    // Step 1: Input
    vector<int> out;
    fill_array(out);

    // Step 2: Ask if the user wants to save to file
    bool to_file;
    char dump;
    cout << "Apakah ingin menyimpan hasil ke file? (y/n): ";
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
    solve(out);
    auto duration = chrono::duration<double, milli>(chrono::high_resolution_clock::now() - start);

    if (!to_file) {
        print_solutions();
    }
    save(out, duration);

    cout << "Waktu eksekusi: " << duration.count() << " ms" << endl;
    return 0;
}
