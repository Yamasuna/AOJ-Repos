#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

//要素数n個分入力を行う
void input_vector( vector<int> &v, int n)
{
	int tmp;

	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
}

//ミンコフスキー距離を計算
double calc_minkovski(int p, int n, const vector<int> &vx, const vector<int> &vy)
{
	double distance;
	double power;
	double sum = 0;

	if( p != 0)
	{
		power = (double)1 / p;

		for(int i = 0; i < n; i++)
		{
			sum += pow( abs(vx[i] - vy[i]), p);
		}
		distance = pow(sum, power);
	}
	else	//p = 0の時，p = ∞として計算
	{
		double dist_max = 0;
		double tmp;
		for(int i = 0; i < n; i++)
		{
			tmp = abs(vx[i] - vy[i]);

			if(tmp > dist_max)
			{
				dist_max = tmp;
			}
		}
		distance = dist_max;
	}

	return distance;
}

int main(void)
{
	int n;					//ベクトルの要素数
	double dist_manhattan;	//マンハッタン距離(p = 1)
	double dist_euclid;		//ユークリッド距離(p = 2)
	double dist_chebyshev;	//チェビシェフ距離(p = ∞)
	double dist_p3;			//p = 3の時のミンコフスキー距離

	vector<int> x;			//ベクトルx
	vector<int> y;			//ベクトルy

	cin >> n;	//要素数を入力

	//要素を入力
	input_vector(x, n);
	input_vector(y, n);

	//各ミンコフスキー距離を求める
	dist_manhattan = calc_minkovski(1, n, x, y);
	dist_euclid = calc_minkovski(2, n, x, y);
	dist_p3= calc_minkovski(3, n, x, y);
	dist_chebyshev = calc_minkovski(0, n, x, y);


	//計算結果出力
	cout << fixed << setprecision(12);
	cout << dist_manhattan << endl;
	cout << dist_euclid << endl;
	cout << dist_p3 << endl;
	cout << dist_chebyshev << endl;
	
	return 0;
}

