#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//$B4X?tL>!'(Bsum_digit
//$BMQES!'0z?t$KM?$($?(Bnum_str$B$N3F7e$N?tCM$N9g7W$rJV$9(B
//$BCm0U!'(Bnum_str$B$OA4$F?t;z$G9=@.$5$l$kJ8;zNs$G$"$k$3$H(B
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

	//0$B$,F~NO$5$l$k$^$G!$?tCM$r3JG<$9$k(B
	do{
		cin >> input_str;
		data_set.push_back(input_str);
	}while(input_str != "0");

	//$BMWAG?t$r<hF@!!(B
	ele_num = data_set.size()-1;

	for(int i = 0; i < ele_num; i++)
	{
		cout << sum_digit(data_set[i]) << endl;
	}
	
	return 0;
}

