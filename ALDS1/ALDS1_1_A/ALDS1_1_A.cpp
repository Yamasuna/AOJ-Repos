#include <iostream>

using namespace std;

void dispVector(int *v, int n)
{
	for(int i = 0; i < n; i++)
	{
		if( i != (n-1) ) 
		{
			cout << v[i] << " ";
		}
		else
		{
			cout << v[i] << endl;
		}
	}
}

void insertionSort(int *v, int n)
{
	int tmp;

	dispVector(v, n);
	for(int i = 1; i <= n-1; i++)
	{
		tmp = v[i];
		int j = i - 1;

		while( (j >= 0) && (v[j] > tmp) )
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = tmp;
		dispVector(v, n);
	}
}

int main(void)
{
	int N;
	int *A;

	cin >> N;
	A = new int[N];

	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	insertionSort(A, N);

	return 0;
}
