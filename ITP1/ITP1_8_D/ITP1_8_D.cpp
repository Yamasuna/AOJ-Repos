#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	//リング状の文字列
	string s;

	//作りたい文字列
	string p;

	string str2;

	//文字列入力
	cin >> s;
	cin >> p;

	//リング状の文字列を連結
	str2 = s + s;

	if( strstr(str2.c_str(), p.c_str()) != NULL)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}

