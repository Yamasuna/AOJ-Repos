#include <iostream>
#include <string>

using namespace std;

class Dice
{
//              ----------
//		       | S[0]     |
//             |          |
//             |          |
//             |          |
//  --------------------------------------------
//  | S[3]     | S[1]     | S[2]     | S[4]    |
//  |          |          |          |         |
//  |          |          |          |         |
//  |          |          |          |         |
//  |-------------------------------------------
//             | S[5]     |
//             |          |
//             |          |
//             |          |
//              ----------
//
//
private:
	int S[6];		//$B%5%$%3%m$N3FLL$N@0?t$r3JG<$9$kG[Ns(B
	int top_id;		//$B%5%$%3%m>eLL$r<($9G[NsE:;z(B
	int left_id;	//$B%5%$%3%m:8B&LL$r<($9G[NsE:;z(B
	int right_id;	//$B%5%$%3%m1&B&LL$r<($9G[NsE:;z(B
	int front_id;	//$B%5%$%3%m<jA0$NLL$r<($9G[NsE:;z(B
	int back_id;	//$B%5%$%3%m1|B&$NLL$r<($9G[NsE:;z(B
	int bottom_id;	//$B%5%$%3%mDlLL$NLL$r<($9G[NsE:;z(B

public:

	//$B%3%s%9%H%i%/%?(B
	Dice()
	{
		//$B%5%$%3%m$N3FLL$N@0?t$rF~NO$9$k(B
		input_surface();

		//$B=i4|>uBV$NLL$r;X$9G[NsE:;z$r;XDj(B
		top_id = 0;
		left_id = 3;
		right_id = 2;
		front_id = 1;
		back_id = 4;
		bottom_id = 5;

		//output_surface();
	}

	//$B%5%$%3%m$N3FLL$N@0?t$rF~NO$9$k4X?t(B
	void input_surface(void)
	{
		for(int i = 0; i < 6; i++)
		{
			cin >> S[i];
		}
	}

	//$B%5%$%3%m$rE>$,$9L?Na$r<B9T(B
	void exec_operation(const string &opr)
	{
		for(int pos = 0; pos < opr.size(); pos++)
		{
			roll_dice( opr[pos] );
			//output_surface();
		}

		//$B>eLL$N%5%$%3%m$NCM$r=PNO(B
		cout << S[top_id] << endl;
	}

	//$B;XDj$7$?J}8~$K%5%$%3%m$rE>$,$9=hM}$r<B;\(B
	void roll_dice(const char direction)
	{
		int tmp;

		switch(direction)
		{
			//$BElJ}8~(B
			case 'E':
				tmp = top_id;
				top_id = left_id;		//left -> top
				left_id = bottom_id;	//bottom -> left
				bottom_id = right_id;	//right -> bottom
				right_id = tmp;			//top -> right
				break;
			//$BKLJ}8~(B
			case 'N':
				tmp = top_id;
				top_id = front_id;		//front -> top
				front_id = bottom_id;	//bottom -> front
				bottom_id = back_id;	//back -> bottom
				back_id = tmp;			//top -> back
				break;
			//$BFnJ}8~(B
			case 'S':
				tmp = top_id;
				top_id = back_id;		//back -> top
				back_id = bottom_id;	//bottom -> back
				bottom_id = front_id;	//front -> bottom
				front_id = tmp;			//top -> front
				break;
			//$B@>J}8~(B
			case 'W':
				tmp = top_id;
				top_id = right_id;		//right -> top
				right_id = bottom_id;	//bottom -> right
				bottom_id = left_id;	//left -> bottom
				left_id = tmp;			//top -> left
				break;
			default:
				cout << "[fail]invalid direction" << endl;
				break;
		}
	}
	
	//$B3NG'MQ(B
	void output_surface(void)
	{
		cout << "S[top] = " << S[top_id] << endl;
		cout << "S[left] = " << S[left_id] << endl;
		cout << "S[right] = " << S[right_id] << endl;
		cout << "S[bottom] = " << S[bottom_id] << endl;
		cout << "S[front] = " << S[front_id] << endl;
		cout << "S[back] = " << S[back_id] << endl;
		cout << "-----------------------------" << endl;
	}
	
};

int main(void)
{
	Dice dice;
	string operation;	//$BL?Na$r<($9J8;zNs(B

	cin >> operation;		//$BL?Na$rF~NO(B

	dice.exec_operation( operation );
	
	return 0;
}
