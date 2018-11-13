/*
 * ITP1_6_B.cpp
 *
 *  Created on: 2016/05/16
 *      Author: suna
 */

#include <iostream>
#include <vector>

using namespace std;

typedef struct Card
{
	char card_picture;	//カードの絵柄
	int card_val;		//カードの数字
};

//不足しているカードの出力
void output_ShortageCard(char type, bool card[])
{
	for(int i = 0; i < 13; i++)
	{
		if(card[i] == false)
		{
			cout << type << " " << (i+1) << endl;
		}
	}
}

int main(void)
{
	//持っているカードの数
	int card_num;

	//カードの種類及び，所持の有無
	bool card_Spade[13] = {false};
	bool card_Heart[13] = {false};
	bool card_Club[13] = {false};
	bool card_Dia[13] = {false};

	//持っているカードの数を入力
	cin >> card_num;
	vector<Card> HaveCard;

	//持っているカードの種類を入力
	//種類と数字を入力
	for(int i = 0; i < card_num; i++)
	{
		char picture;
		int value;
		Card tmp;
		cin >> picture >> value;
		tmp.card_picture = picture;
		tmp.card_val = value;

		HaveCard.push_back(tmp);
	}

	//所持しているカードをチェックする
	for(int i = 0; i < card_num; i++)
	{
		char picture;
		char value;
		picture = HaveCard[i].card_picture;
		value = HaveCard[i].card_val;

		if(picture == 'S')
		{
			card_Spade[value-1] = true;
		}
		else if(picture == 'H')
		{
			card_Heart[value-1] = true;
		}
		else if(picture == 'C')
		{
			card_Club[value-1] = true;
		}
		else if(picture == 'D')
		{
			card_Dia[value-1] = true;
		}
	}

	//不足しているカードを出力
	output_ShortageCard('S', card_Spade);
	output_ShortageCard('H', card_Heart);
	output_ShortageCard('C', card_Club);
	output_ShortageCard('D', card_Dia);

	return 0;
}

