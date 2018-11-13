#include <iostream>
#include <cmath>

using namespace std;

//点を定義するクラス
class Point
{
public:
	double x, y;	//座標

public:
	void setPoint(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};

//距離を計算する
double distance(Point P1, Point P2)
{
	double dist;

	dist = sqrt( pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2) );

	return dist;
}

int main(void)
{
	double x1, y1;
	double x2, y2;

	Point P1;
	Point P2;

	//座標入力
	cin >> x1 >> y1 >> x2 >> y2;
	P1.setPoint(x1, y1);
	P2.setPoint(x2, y2);
	
	cout << distance(P1, P2) << endl;

	return 0;
}

