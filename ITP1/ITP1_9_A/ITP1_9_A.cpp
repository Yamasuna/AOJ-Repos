#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	//マッチした単語数
	int cnt = 0;

	//単語
	string W;

	//文章
	string T;

	string eot = "END_OF_TEXT";

	//単語を入力
	cin >> W;

	//単語Wは全て小文字に変換する
	transform(W.begin(), W.end(), W.begin(), ::tolower);

	//1行ずつ文章を入力
	while(getline(cin, T))
	{
		//"END_OF_TEXT"が入力されたら終了
		if(T == eot) break;

		string tmp;
		istringstream stream(T);

		//空白区切りで文字列を読み込む
		while(getline(stream, tmp, ' '))
		{
			//読み込んだ文字列tmpはすべて小文字に変換する
			transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

			//読み込んだ単語が入力した単語Wと一致
			if( tmp == W )
			{
				cnt++;
			}
		}
	}

	//マッチした単語数を出力
	cout << cnt << endl;

	return 0;
}

