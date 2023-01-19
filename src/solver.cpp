//
// Created by ammar on 19/01/2023.
//

#include <fstream>
#include "solver.h"

const vector<char> operators = {'+', '-', '*', '/'};

/*
 * Evaluates an expression.
 * @param a The first operand.
 * @param op The operator.
 * @param b The second operand.
 */
float operate(const float& a, const char& op, const float& b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

/*
 * Solves the 24 game.
 * @param cards The input cards.
 * @param to_file Whether to save the output to a file.
 */
void solve(vector<int>& cards, bool to_file = false) {
    int count = 1;
    vector<vector<int>> permutations = get_all_permutations(cards);
    vector<string> solutions;
    for (auto& p : operators) {
        for (auto& q : operators) {
            for (auto& r : operators) {
                for (auto& perm : permutations) {
                    int &a = perm[0];
                    int &b = perm[1];
                    int &c = perm[2];
                    int &d = perm[3];

                    // (a b) c d
                    float result = operate(operate(a, p, b), q, operate(c, r, d));
                    if (result == TARGET) {
                        solutions.push_back("(" + to_string(a) + p + to_string(b) + ")" + q + to_string(c) + r + to_string(d));
//                        cout << count << ". " << "(" << a << p << b << ")" << q << c << r
//                             << d << endl;
                        count++;
                    }
                    // a (b c) d
                    result = operate(a, p, operate(operate(b, q, c), r, d));
                    if (result == TARGET) {
                        solutions.push_back(to_string(a) + p + "(" + to_string(b) + q + to_string(c) + ")" + r + to_string(d));
//                        cout << count << ". " << a << p << "(" << b << q << c << ")" << r
//                             << d << endl;
                        count++;
                    }
                    // a b (c d)
                    result = operate(a, p, operate(b, q, operate(c, r, d)));
                    if (result == TARGET) {
                        solutions.push_back(to_string(a) + p + to_string(b) + q + "(" + to_string(c) + r + to_string(d) + ")");
//                        cout << count << ". " << a << p << b << q << "(" << c << r << d
//                             << ")" << endl;
                        count++;
                    }
                    // a b c d
//                    result = operate(perm[0], p, operate(perm[1], q, operate(perm[2], r, perm[3])));
//                    if (result == TARGET) {
//                        cout << count << ". " << perm[0] << p << perm[1] << q << perm[2] << r << perm[3] << endl;
//                        count++;
//                    }
                    // (a b c) d
                    result = operate(operate(operate(a, p, b), q, c), r, d);
                    if (result == TARGET) {
                        solutions.push_back("(" + to_string(a) + p + to_string(b) + q + to_string(c) + ")" + r + to_string(d));
//                        cout << count << ". " << "(" << a << p << b << q << c << ")" << r
//                             << d << endl;
                        count++;
                    }
                    // a (b c d)
                    result = operate(a, p, operate(operate(b, q, c), r, d));
                    if (result == TARGET) {
                        solutions.push_back(to_string(a) + p + "(" + to_string(b) + q + to_string(c) + r + to_string(d) + ")");
//                        cout << count << ". " << a << p << "(" << b << q << c << r << d
//                             << ")" << endl;
                        count++;
                    }
                    // (a b) (c d)
                    result = operate(operate(a, p, b), q, operate(c, r, d));
                    if (result == TARGET) {
                        solutions.push_back("(" + to_string(a) + p + to_string(b) + ")" + q + "(" + to_string(c) + r + to_string(d) + ")");
//                        cout << count << ". " << "(" << a << p << b << ")" << q << "(" << c
//                             << r << d << ")" << endl;
                        count++;
                    }
                    // ((a b) c) d
                    result = operate(operate(operate(a, p, b), q, c), r, d);
                    if (result == TARGET) {
                        solutions.push_back("((" + to_string(a) + p + to_string(b) + ")" + q + to_string(c) + ")" + r + to_string(d));
//                        cout << count << ". " << "(" << "(" << a << p << b << ")" << q << c
//                             << ")" << r << d << endl;
                        count++;
                    }
                    // a ((b c) d)
                    result = operate(a, p, operate(operate(b, q, c), r, d));
                    if (result == TARGET) {
                        solutions.push_back(to_string(a) + p + "((" + to_string(b) + q + to_string(c) + ")" + r + to_string(d) + ")");
//                        cout << count << ". " << a << p << "(" << "(" << b << q << c << ")"
//                             << r << d << ")" << endl;
                        count++;
                    }
                    // a (b (c d))
                    result = operate(a, p, operate(b, q, operate(c, r, d)));
                    if (result == TARGET) {
                        solutions.push_back(to_string(a) + p + "(" + to_string(b) + q + "(" + to_string(c) + r + to_string(d) + "))");
//                        cout << count << ". " << a << p << "(" << b << q << "(" << c << r
//                             << d << ")" << ")" << endl;
                        count++;
                    }
                }
            }
        }
    }
    if (to_file) {
        try {
            ofstream file("solutions.txt");
            if (file.is_open()) {
                for (auto& s : solutions) {
                    file << s << endl;
                }
                file.close();
            } else {
                cout << "File handle tidak bisa dibuka." << endl;
            }
        } catch (exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    } else {
        for (auto& s : solutions) {
            cout << s << endl;
        }
    }
}

/*
 * Swaps the values of two integers.
 * @param a The first integer
 * @param b The second integer
 */
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
 * Helper function to do permutations from a given array of cards.
 * @param result The multidimensional vector to store the permutations
 * @param cards The array of cards
 * @param start The starting index of the array
 * @param end The ending index of the array
 */
void permutations(vector<vector<int>>& result, vector<int>& cards, int start, int end) {
    if (start == end) {
        result.push_back(cards);
    } else {
        for (int i = start; i <= end; i++) {
            swap(cards[start], cards[i]);
            permutations(result, cards, start + 1, end);
            swap(cards[start], cards[i]);
        }
    }
}

/*
 * Get all permutations from a given array of cards.
 * @param cards The set of cards
 */
vector<vector<int>> get_all_permutations(vector<int>& cards) {
    vector<vector<int>> result;
    permutations(result, cards, 0, cards.size() - 1);
    return result;
}