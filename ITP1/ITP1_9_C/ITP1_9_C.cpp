#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	//カード枚数
	int card_num;

	int pt_taro = 0;	//太郎のポイント
	int pt_hanako = 0;	//花子のポイント

	//太郎のカードに書かれている文字列
	string card_taro;

	//花子のカードに書かれている文字列
	string card_hanako;

	//カード枚数を入力
	cin >> card_num;

	for(int i = 0; i < card_num; i++)
	{
		//カード情報を入力
		cin >> card_taro >> card_hanako;

		if( card_taro > card_hanako)	//太郎の勝ち
		{
			pt_taro += 3;
		}
		else if(card_taro < card_hanako)	//花子の勝ち
		{
			pt_hanako += 3;
		}
		else
		{	
			//引き分けの場合は両者に１ポイント
			pt_taro++;
			pt_hanako++;
		}
	}

	//得点を出力
	cout << pt_taro << " " << pt_hanako << endl;

	return 0;
}

