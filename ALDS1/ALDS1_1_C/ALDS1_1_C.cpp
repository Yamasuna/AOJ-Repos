#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
	int i = 3;

	if(x == 2)	return true;

	if( (x < 2) || (x % 2 == 0) ) return false;

	while( i <= (int)sqrt(x) )
	{
		if( (x % i) == 0)
		{
			return false;
		}
		i += 2;
	}

	return true;
}

int main(void)
{
	int n;
	int prime_num = 0;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int input_num;

		cin >> input_num;
		if( isPrime(input_num) )  prime_num++;
	}

	cout << prime_num << endl;
	return 0;
}
