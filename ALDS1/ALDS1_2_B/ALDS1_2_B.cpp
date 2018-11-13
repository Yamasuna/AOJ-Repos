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

void selectionSort(vector<int> &vec)
{
	int cmp_num = 0;
	int min_idx;
	int vec_size;

	vec_size = vec.size();

	for(int i = 0; i < vec_size; i++)
	{
		min_idx = i;
		for(int j = i+1; j < vec_size; j++)
		{
			if(vec[j] < vec[min_idx])
			{
				min_idx = j;
			}
		}
		if(i != min_idx)
		{
			swap(&vec[min_idx], &vec[i]);
			cmp_num++;
		}
	}

	for(int i = 0; i < vec_size-1; i++)
	{
		cout << vec[i] << " ";
	}
	cout << vec[vec_size-1] << endl;
	cout << cmp_num << endl;
}

int main(void)
{
	int n;

	cin >> n;
	vector<int> A(n);

	//データを入力
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	selectionSort(A);
}
