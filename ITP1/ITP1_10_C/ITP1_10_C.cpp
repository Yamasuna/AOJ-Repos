#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int	n;				//学生の人数
	cin >> n;			//学生の数を入力
	double average;		//平均
	double variance;	//分散
	double deviation;	//標準偏差
	vector<int> s;		//学生の得点を格納する配列
	double sum_d;		//合計値を記録(作業用)

	while( n != 0)
	{
		//得点の入力
		for(int i = 0; i < n; i++)
		{
			int tmp_s;
			cin >> tmp_s;

			s.push_back(tmp_s);
		}

		//得点の平均を計算
		sum_d = 0;
		for(int i = 0; i < n; i++)
		{
			sum_d += s[i];
		}
		average = sum_d / n;

		//分散を計算
		sum_d = 0;
		for(int i = 0; i < n; i++)
		{
			sum_d += pow( s[i] - average, 2.0f);
		}
		variance = (double)(sum_d / n);

		//標準偏差を計算
		deviation = sqrt(variance);

		cout << fixed << setprecision(12);
		cout << deviation << endl;

		//配列削除
		vector<int>().swap(s);

		//再度学生の数を入力
		//0の場合は終了となる
		cin >> n;
	}

	return 0;
}
