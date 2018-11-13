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
		else
		{
			for(int i = 0; i < H; i++)
			{
				//frame
				if( (i == 0) || (i == H-1) )
				{
					for(int j = 0; j < W; j++)
					{
						cout << '#';
					}
					cout << endl;
				}
				//Not frame
				else
				{
					cout << '#';
					for(int j = 1; j < W-1; j++)
					{
						cout << '.';
					}
					cout << '#' << endl;
				}
			}
			cout << endl;
		}
	}
	return 0;
}

