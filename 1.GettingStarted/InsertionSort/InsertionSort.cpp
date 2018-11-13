#include <iostream>
#include <vector>

using namespace std;

//配列を出力する
void Print(const vector<int> &A, int N)
{
	for(int i = 0; i < N; i++)
	{
		cout << A[i];
		cout << " ";
	}
	cout << endl;
}

//挿入ソート
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
	//空白区切りの標準入力は以下で入力可能
	for(int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	//挿入ソート
	insertionSort(A, N);
	return 0;
}
