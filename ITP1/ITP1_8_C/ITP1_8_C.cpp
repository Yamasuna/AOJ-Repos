#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	int alpha_count[26] = {0};
	
	//文字列入力
	while(getline(cin, str))
	{

		//文字数のカウント
		for(int i = 0; i < str.length(); i++)
		{
			if( (str[i] >= 'a') && (str[i] <= 'z') )
			{
				int idx = str[i] - 'a';
				alpha_count[idx]++;
			}
			else if( (str[i] >= 'A') && (str[i] <= 'Z') )
			{
				int idx = str[i] - 'A';
				alpha_count[idx]++;
			}
		}
	}

	//文字数の出力
	for(int i = 0; i < sizeof(alpha_count)/sizeof(int); i++)
	{
		cout << char(i + 'a') << " : " << alpha_count[i] << endl;
	}

	return 0;
}

