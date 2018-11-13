/*
 * ITP1_6_A.cpp
 *
 *  Created on: 2016/05/15
 *      Author: suna
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	//要素数
	int n_element;

	//要素数の入力
	cin >> n_element;

	vector<int> array(n_element);

	//配列に値を入力する
	for(int i = 0; i < n_element; i++)
	{
		cin >> array[i];
	}

	//入力された配列の値を逆順に出力
	for(int i = 1; i <= n_element; i++)
	{
		if( (n_element-i) != 0)
		{
			cout << array[n_element-i] << " ";
		}
		else
		{
			cout << array[n_element-i] << endl;
		}
	}
	return 0;
}
