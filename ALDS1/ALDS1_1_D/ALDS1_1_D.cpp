#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	int max_val;
	int min_val;

	cin >> n;
	vector<int> R(n);

	for(int i = 0; i < n; i++)
	{
		cin >> R[i];
	}

	max_val = R[1] - R[0];
	min_val = R[0];

	for(int j = 1; j < n; j++)
	{
		max_val = max_val > (R[j] - min_val) ? max_val : (R[j] - min_val);
		min_val = min_val < R[j] ? min_val : R[j];
	}
	cout << max_val << endl;
	return 0;
}
