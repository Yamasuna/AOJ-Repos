#include <iostream>

using namespace std;

int main(void)
{
	int H, W;

	while(true)
	{
		cin >> H >> W;

		if( (H==0) && (W==0) )
		{
			break;
		}

		for(int i = 0; i < H; i++)
		{
			if( (i % 2) == 0 )
			{
				for(int j = 0; j < W; j++)
				{
					if( (j % 2) == 0)
					{
						cout << "#";
					}
					else
					{
						cout << ".";
					}
				}
				cout << endl;
			}
			else
			{
				for(int j = 0; j < W; j++)
				{
					if( (j % 2) == 0 )
					{
						cout << ".";
					}
					else
					{
						cout << "#";
					}
				}
				cout << endl;
			}
		}
		cout << endl;
	}

	return 0;
}

