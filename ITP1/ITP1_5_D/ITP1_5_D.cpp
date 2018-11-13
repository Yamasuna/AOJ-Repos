/*
 * ITP1_5_D.cpp
 *
 *  Created on: 2016/05/15
 *      Author: suna
 */

#include <iostream>

using namespace std;

//関数定義
//1からnまでの中で，3で割り切れる数，もしくは1桁目が3である数を出力する
//3で割り切れる数を先に判定．
void call(int n)
{
	int x;
	for(int i=1; i <= n; i++)
	{
		x = i;
		//3で割り切れるかどうか
		if( (x % 3) == 0 )
		{
			cout << " " << i;
		}
		//1桁目の数が3であるかどうか
		else
		{
			do{
				if( (x % 10) == 3)
				{
					cout << " " << i;
					break;
				}
				else
				{
					x /= 10;
				}
			}while(x);
		}
	}
	cout << endl;
}

int main(void)
{
	//キーボードから入力する値
	int input_num;

	//値の入力
	cin >> input_num;

	call(input_num);
	return 0;
}
