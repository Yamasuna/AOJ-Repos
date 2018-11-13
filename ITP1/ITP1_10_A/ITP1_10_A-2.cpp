#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//距離を計算する
double distance(double x1, double y1, double x2, double y2)
{
	double dist;

	dist = sqrt( pow(x2 - x1, 2) + pow(y2 - y1, 2) );

	return dist;
}

int main(void)
{
	double x1, y1;
	double x2, y2;
	double dist;

	//座標入力
	cin >> x1 >> y1 >> x2 >> y2;
	
	cout << fixed;
	cout << setprecision(6) << distance(x1, y1, x2, y2) << endl;

	return 0;
}

