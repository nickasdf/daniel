#include"Header.h"

int** gen_matrix(int m)
{
	int** Z = new int* [m];
	for (int i = 0; i < m; i++)
		Z[i] = new int[m];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			Z[i][j] = rand() % 1191 - 200;
	return Z;

	for (int i = 0; i < m; i++)
		delete[] Z[i];
	delete[] Z;
}


int* find_seq(int** Z, int m, int *row_seq, int* seq_size)
{
	int max_seq = 1;
	int count = 1;
	int max_i = 0;
	int start_j = 0;
	for (int i = 0; i < m; i++)
	{
		count = 0;
		for (int j = 0; j < m - 1; j++)
		{
			if (Z[i][j] < Z[i][j + 1])
			{
				count++;
				if (j == m - 2)
					j++;
			}
			if (Z[i][j] >= Z[i][j + 1] || (Z[i][j] < Z[i][j + 1] && j == m - 1))
			{
				if (count >= max_seq)
				{
					max_seq = count;
					max_i = i;
					start_j = j - count + 1;
					count = 0;
				}
				
			}
		}
	}
	*row_seq = max_i;
	int start = start_j;
	*seq_size = max_seq;
	int* N = new int[max_seq];
	for (int i = 0; i < max_seq; i++)
	{
		N[i] = Z[*row_seq][start_j + i];
	}
	return N;
	delete[] N;
}

void output_matrix(int** Z, int m)
{
	cout << "Matrix Z: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << Z[i][j] << "\t";
		cout << endl;
	}
}

void output_arr(int* N, int seq_size)
{
	cout << "Sequence N: ";
	for (int i = 0; i < seq_size; i++)
		cout << N[i] << " ";
	cout << endl;
}

void switch_rows(int** Z, int m, int row_seq)
{
	int* Temp = new int[m];
	for (int j = 0; j < m; j++)
	{
		Temp[j] = Z[0][j];
		Z[0][j] = Z[row_seq][j];
		Z[row_seq][j] = Temp[j];
	}
	delete[] Temp;
}

int* delete_minuses(int* N, int* seq_size)
{
	int count = 0;
	for (int i = 0; i < *seq_size; i++)
	{
		if (N[i] < 0)
		{
			count++;
			for (int j = i; j < *seq_size - 1; j++)
			{
				N[j] = N[j + 1];
			}
		}
	}
	*seq_size -= count;
	return N;
}
