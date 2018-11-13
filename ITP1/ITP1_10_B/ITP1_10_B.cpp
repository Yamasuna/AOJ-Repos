#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void)
{
	int a, b;		//三角形の辺の長さ
	double c;		//残る辺の長さ
	int C;			//辺a, bの間の角度

	double S;		//三角形の面積
	double L;		//三角形の周の長さ
	double h;		//aを底辺とした時の高さ
	double rad;		//角度をラジアンに変換

	//データ入力
	cin >> a >> b >> C;
	rad = (M_PI/180.0)*C;

	//cの長さ　余弦定理
	c = sqrt(pow(a, 2) + pow(b, 2) - 2*a*b*cos(rad));

	L = a + b + c;
	S = 0.5 * a * b * sin(rad);
	h = b * sin(rad);

	cout << fixed << setprecision(12);
	cout << S << endl;
	cout << L << endl;
	cout << h << endl;

	return 0;
}
