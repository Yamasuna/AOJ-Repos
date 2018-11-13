#include <iostream>
#include <vector>

using namespace std;

//Swap a and b
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(vector<int> &vec)
{
	int cmp_num = 0;
	int vec_size;

	vec_size = vec.size()-1;

	for(int i = 1; i <= vec_size; i++)
	{
		for(int j = vec_size; j >= i; j--)
		{
			if( vec[j] < vec[j-1])
			{
				swap( &vec[j], &vec[j-1]);
				cmp_num++;
			}
		}
	}

	for(int i = 0; i < vec_size; i++)
	{
		cout << vec[i] << " ";
	}
	cout << vec[vec_size] << endl;
	cout << cmp_num << endl;

	return;
}

int main(void)
{
	int n;
	
	cin >> n;
	vector<int> A(n);

	//データ入力
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	bubbleSort(A);

	return 0;
}
