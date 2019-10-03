/*
3. Write a program that reads the NxM dimensions of a two-dimensional array of doubles. If user enters 0  or less for either N or M,
the program exits. After reading the size of array from user, i.e. N for rows and M for columns, it allocates memory as required.
Then, it reads the numbers from user and puts these in appropriate 'cells' for the matrix. It then displays the numbers read and
Free's up memory before exiting.
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


int main()
{
  int N{}, M{};
	cout << "Please enter number of rows and columns: ";
	cin >> N >> M;
	if (N <= 0 || M <= 0)
	{
		cout<<"\nPLEASE ENTER POSITIVE NUMBERS ONLY!!";
		exit(0);
	}
	double** twoDMatrix{ new double*[N] };
	for (int i = 0; i < N; i++)
		twoDMatrix[i] = new double[M];
	for (int i = 0; i < N; i++)
	{
		cout << "Enter row " << i + 1 << " elements\n";
		for (int j = 0; j < M; j++) {
			cin >> twoDMatrix[i][j];
		}
		system("CLS");
	}
	system("CLS");
	cout << "Matrix of Size " << N << " (rows) and " << M << " (cols): "<<endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			cout<< twoDMatrix[i][j]<<" ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++)
		delete[] twoDMatrix[i];
	delete[] twoDMatrix;
	return 0;
}
