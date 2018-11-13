#include <iostream>
#include <cstdio>

using  namespace std;

int main(void)
{
	int a, b;
	int r;
	int d;
	double f;

	//Input a, b
	cin >> a >> b;

	d = a / b;
	r = a % b;
	f = (double)a / b;

	printf("%d %d %f\n", d, r, f);

	return 0;
}
