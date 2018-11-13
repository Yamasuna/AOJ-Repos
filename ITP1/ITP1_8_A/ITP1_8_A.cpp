#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int length;
	string str;

	//input string
	//stringに">>"演算子で入力しても空白で止まってしまうため，getline関数を使う
	getline(cin, str);

	length = str.length();
	for(int i = 0; i < length; i++)
	{
		//取得した文字が小文字のアルファベット
		if( ('a' <= str[i]) && (str[i] <= 'z') )
		{
			//大文字に変換して更新
			str[i] -= 0x20;
		}
		//取得した文字が大文字のアルファベット
		else if( ('A' <= str[i]) && (str[i] <= 'Z') )
		{
			//小文字に変換して更新
			str[i] += 0x20;
		}
		else{}
	}
	
	cout << str << endl;

	return 0;
}
