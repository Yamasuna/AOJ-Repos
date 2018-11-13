#include <iostream>
#include <vector>

using namespace std;

//$BG[Ns$r=PNO$9$k(B
void Print(const vector<int> &A, int N)
{
	for(int i = 0; i < N; i++)
	{
		cout << A[i];
		cout << " ";
	}
	cout << endl;
}

//$BA^F~%=!<%H(B
void insertionSort( vector<int> &A, int N)
{
	int j, v;
	Print(A, N);
	for(int i = 1; i <= N-1; i++)
	{
		v = A[i];
		j = i-1;
		
		while ( (j >= 0) && (A[j] > v) )
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1] = v;
		Print(A, N);
	}
}

int main(void)
{
	int N;
	
	cin >> N;
	vector<int> A(N);
	//$B6uGr6h@Z$j$NI8=`F~NO$O0J2<$GF~NO2DG=(B
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	//$BA^F~%=!<%H(B
	insertionSort(A, N);
	return 0;
}
