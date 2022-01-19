#pragma once
#include <iostream>
using namespace std;

int** gen_matrix(int m);
int* find_seq(int** Z, int m, int* row_seq, int* seq_size);
void output_matrix(int** Z, int m);
void output_arr(int* N, int seq_size);
void switch_rows(int** Z, int m, int row_seq);
int* delete_minuses(int* N, int* seq_size);
