//
// Created by ammar on 18/01/2023.
//

#ifndef STIMATUCIL1_INPUTHANDLER_H
#define STIMATUCIL1_INPUTHANDLER_H

#include <sstream>
#include <vector>

using namespace std;

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

/*
 * String to integer array. Converts a string to an array of integers.
 * It is ensured that the output always contains 4 integers.
 * Could just use a single cin and then split the string, but this is more fun.
 * @param out The array to store the integers in.
 */
int stoia(vector<int>& out) {
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
            cerr << "Masukan tidak sesuai. Hanya menerima (A, 2-10, J, Q, K)." << endl;
            return 1;
        }
        out.push_back(t);
    }
    return 0;
}

ostream& operator<<(ostream& out, const vector<int>& cards) {
    for (auto& i : cards) {
        switch (i) {
            case ACE:
                out << "A ";
                break;
            case JACK:
                out << "J ";
                break;
            case QUEEN:
                out << "Q ";
                break;
            case KING:
                out << "K ";
                break;
            default:
                out << i << " ";
                break;
        }
    }
    return out;
}

/*
 * Checks whether the user would like to input cards manually or randomly.
 */
void fill_array(vector<int>& out) {
    bool valid = false;
    do {
        cout << "Input manual atau random? (m/r): ";
        string input;
        getline(cin >> ws, input);
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input == "m") {
            int result;
            cout << "Masukkan 4 kartu (A, 2-10, J, Q, K): ";
            do {
                result = stoia(out);
            } while (result != 0);
            valid = true;
        } else if (input == "r") {
            unsigned int card;
            __builtin_ia32_rdrand32_step(&card);
            for (int i = 0; i < 4; i++) {
                out.push_back((card % 13) + 1);
                __builtin_ia32_rdrand32_step(&card);
            }
            valid = true;
            cout << "Nomor-nomor kartu: " << out << endl;
        } else {
            cout << "Masukan tidak sesuai" << endl;
        }
    } while (!valid);
}

#endif
