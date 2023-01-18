//
// Created by ammar on 18/01/2023.
//

#ifndef STIMATUCIL1_INPUTHANDLER_H
#define STIMATUCIL1_INPUTHANDLER_H

#include <sstream>
#include <random>

using namespace std;

/*
 * String to integer array. Converts a string to an array of integers.
 * It is ensured that the output always contains 4 integers.
 * @param out The array to store the integers in.
 */
int stoia(unsigned int out[4]) {
    string input;
    getline(cin >> ws, input);
    string const temp = input;
    for (auto c : temp) {
        switch (toupper(c)) {
            case 'A':
                input.replace(input.find(c), 1, "1");
                break;
            case 'J':
                input.replace(input.find(c), 1, "11");
                break;
            case 'Q':
                input.replace(input.find(c), 1, "12");
                break;
            case 'K':
                input.replace(input.find(c), 1, "13");
                break;
            default:
                continue;
        }
    }
    istringstream iss(input);
    for (int i = 0; i < 4; i++) {
        int t;
        iss >> t;
        if (t < 1 || t > 13) {
            cerr << "Masukan tidak sesuai" << endl;
            return 1;
        }
        out[i] = t;
    }
    return 0;
}

/*
 * Checks whether the user would like to input cards manually or randomly.
 */
void fill_array(unsigned int out[4]) {
    bool valid = false;
    do {
        cout << "Input manual atau random? (m/r): ";
        string input;
        getline(cin >> ws, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input == "m") {
            int result;
            do {
                result = stoia(out);
            } while (result != 0);
            valid = true;
        } else if (input == "r") {
            unsigned int card;
            __builtin_ia32_rdrand32_step(&card);
            for (int i = 0; i < 4; i++) {
                out[i] = (card % 13) + 1;
                __builtin_ia32_rdrand32_step(&card);
            }
            valid = true;
        } else {
            cout << "Masukan tidak sesuai" << endl;
        }
    } while (!valid);
}

#endif //STIMATUCIL1_INPUTHANDLER_H
