#include <iostream>

using namespace std;

long func_gcd(long x, long y)
{
	long max_cnt;
	long val_gcd;
	long tmp;

	if( y == 0 )
	{
		val_gcd = x;
		return val_gcd;
	}

	if( y >= x )
	{
		tmp = x;
		x = y;
		y = tmp;
	}

	cout << "func_gcd(" << y << "," << (x%y) << ")" << endl;
	val_gcd = func_gcd( y, (x % y) );

	return val_gcd;
}

int main(void)
{
	long x, y;
	long gcd;
	
	cin >> x >> y;

	gcd = func_gcd(x, y);
	cout << gcd << endl;
	return 0;
}
