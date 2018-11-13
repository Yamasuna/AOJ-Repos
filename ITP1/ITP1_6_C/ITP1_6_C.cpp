/*
 * ITP1_6_C.cpp
 *
 *  Created on: 2016/05/18
 *      Author: suna
 */

#include <iostream>

using namespace std;

int main(void)
{
	int kensu;	//件数
	static char SPACE = ' ';
	static int number_of_rooms_floor = 10; //1フロアあたりの部屋数
	static int kaisu = 3;					//公舎の階数
	static int munesu = 4;					//公舎の棟数
	static int min_nyukyosha = 0;			//1部屋あたりの最少人数
	int nyukyosha[munesu][kaisu][number_of_rooms_floor]; //入居者数

	int input_mune;  		//入力された棟番号
	int input_kaisu; 		//入力された階
	int input_room;  		//入力された部屋番号
	int input_nyukyosha; 	//入力された入居者数

	//入居者数の初期化
	for(int i = 0; i < munesu; i++)
	{
		for(int j = 0; j < kaisu; j++)
		{
			for(int k = 0; k < number_of_rooms_floor; k++)
			{
				nyukyosha[i][j][k] = min_nyukyosha;
			}
		}
	}

	//件数入力
	cin >> kensu;

	//入居者数入力
	for(int i = 0; i < kensu; i++)
	{
		cin >> input_mune >> input_kaisu >> input_room >> input_nyukyosha;
		nyukyosha[input_mune-1][input_kaisu-1][input_room-1] += input_nyukyosha;
	}

	//出力
	for(int i = 0; i < munesu; i++)
	{
		if(i != 0)
		{
			cout << "####################" << endl;
		}

		for(int j = 0; j < kaisu; j++)
		{
			for(int k = 0; k < number_of_rooms_floor; k++)
			{
				cout << SPACE << nyukyosha [i][j][k];
			}
			cout << endl;
		}
	}
	return 0;
}
