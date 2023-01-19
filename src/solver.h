//
// Created by ammar on 19/01/2023.
//

#ifndef TUCIL1_13521136_SOLVER_H
#define TUCIL1_13521136_SOLVER_H

#include <iostream>
#include <vector>

using namespace std;

#define TARGET 24

void permutations(vector<vector<int>>& result, vector<int>& cards, int start, int end);
vector<vector<int>> get_all_permutations(vector<int>& cards);
void solve(vector<int>& permutation, bool to_file);

#endif
