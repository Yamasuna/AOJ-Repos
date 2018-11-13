/*
 * ITP1_7_B.cpp
 *
 *  Created on: 2016/05/21
 *      Author: suna
 */

#include <iostream>

using namespace std;

//1〜limitの間で，3つの数の合計がtargetになるような，重複のない
//3つの数の組み合わせの数を返す関数
int countWay(int limit, int target)
{
	int counter = 0;

	for(int i = 1; i <= limit-2; i++)
	{
		for(int j = i+1; j <=limit-1; j++)
		{
			for(int k = j+1; k <= limit; k++)
			{
				if(i+j+k == target)
				{
					counter++;
				}
			}
		}
	}
	return counter;
}

int main(void)
{
	//上限値
	int upper_limit;

	//3つの数を合計した数
	int target_sum_value;

	while(1)
	{
		//入力
		cin >> upper_limit >> target_sum_value;

		if( (upper_limit == 0) && (target_sum_value == 0) )
		{
			break;
		}
		//組み合わせ数の出力
		cout << countWay(upper_limit, target_sum_value) << endl;
	}
	return 0;
}
