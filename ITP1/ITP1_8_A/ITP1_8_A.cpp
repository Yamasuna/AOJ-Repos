#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int length;
	string str;

	//input string
	//string$B$K(B">>"$B1i;;;R$GF~NO$7$F$b6uGr$G;_$^$C$F$7$^$&$?$a!$(Bgetline$B4X?t$r;H$&(B
	getline(cin, str);

	length = str.length();
	for(int i = 0; i < length; i++)
	{
		//$B<hF@$7$?J8;z$,>.J8;z$N%"%k%U%!%Y%C%H(B
		if( ('a' <= str[i]) && (str[i] <= 'z') )
		{
			//$BBgJ8;z$KJQ49$7$F99?7(B
			str[i] -= 0x20;
		}
		//$B<hF@$7$?J8;z$,BgJ8;z$N%"%k%U%!%Y%C%H(B
		else if( ('A' <= str[i]) && (str[i] <= 'Z') )
		{
			//$B>.J8;z$KJQ49$7$F99?7(B
			str[i] += 0x20;
		}
		else{}
	}
	
	cout << str << endl;

	return 0;
}
