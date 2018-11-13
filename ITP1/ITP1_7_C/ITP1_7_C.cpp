/*
 * ITP1_7_C.cpp
 *
 *  Created on: 2016/05/21
 *      Author: suna
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int row;	//行数
	int col;	//列数

	//スプレッドシート
	vector< vector<int> > sheet;

	//行数，列数の入力
	cin >> row >> col;

	//スプレッドシートの作成
	sheet.resize(row+1);
	for(int i = 0; i < row+1; i++)
	{
		sheet[i].resize(col+1);
	}

	//スプレッドシートへのデータ入力
	for(int i = 0; i < row; i++)
	{
		int sum_col = 0;
		for(int j = 0; j < col; j++)
		{
			cin >> sheet[i][j];
			sum_col += sheet[i][j];
		}
		sheet[i][col] = sum_col;
	}

	//追加した行に対する合計を計算
	for(int j = 0; j <= col; j++)
	{
		int sum_row = 0;
		for(int i = 0; i < row; i++)
		{
			sum_row += sheet[i][j];
		}
		sheet[row][j] = sum_row;
	}

	//スプレッドシートデータ出力
	for(int i = 0; i < row+1; i++)
	{
		for(int j = 0; j < col+1; j++)
		{
			cout << sheet[i][j];
			if(j != col)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
