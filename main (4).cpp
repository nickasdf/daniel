
#include "Header.h"

int main()
{
	int m, row_seq, seq_size;

	cout << "Enter m: ";
	cin >> m;
	cout << endl;

	int** Z = gen_matrix(m);
	output_matrix(Z, m);
	
	int* N = find_seq(Z, m, &row_seq, &seq_size);
	cout << "Row with the biggest sequence: " << row_seq << endl;
	output_arr(N, seq_size);

	switch_rows(Z, m, row_seq);
	output_matrix(Z, m);
	
	N = delete_minuses(N, &seq_size);
	output_arr(N, seq_size);
}
