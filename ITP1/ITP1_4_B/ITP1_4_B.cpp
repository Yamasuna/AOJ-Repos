#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void)
{
	double r;
	double area, circum;

	cin >> r;

	area = M_PI * r * r;
	circum = 2.0f * M_PI * r;

	printf("%f %f\n", area, circum);

	return 0;
}
