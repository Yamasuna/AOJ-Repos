#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//関数名：sum_digit
//用途：引数に与えたnum_strの各桁の数値の合計を返す
//注意：num_strは全て数字で構成される文字列であること
int sum_digit(string num_str)
{
	int str_size = num_str.length();
	long sum = 0;

	for(int  i = 0; i < str_size; i++)
	{
		sum += num_str[i] - '0';
	}

	return sum;
}

int main(void)
{
	int ele_num;
	string input_str;
	vector<string> data_set;

	//0が入力されるまで，数値を格納する
	do{
		cin >> input_str;
		data_set.push_back(input_str);
	}while(input_str != "0");

	//要素数を取得　
	ele_num = data_set.size()-1;

	for(int i = 0; i < ele_num; i++)
	{
		cout << sum_digit(data_set[i]) << endl;
	}
	
	return 0;
}

