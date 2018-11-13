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
	}

	//$B%5%$%3%m$N3FLL$N@0?t$rF~NO$9$k4X?t(B
	void input_surface(void)
	{
		for(int i = 0; i < 6; i++)
		{
			cin >> S[i];
		}
	}

	//$B;XDj$7$?J}8~$K%5%$%3%m$rE>$,$9=hM}$r<B;\(B
	void roll_dice(const char direction)
	{
		int tmp;

		switch(direction)
		{
			//$BElJ}8~(B
			case 'E':
				tmp = S[top_id];
				S[top_id] = S[left_id];		//left -> top
				S[left_id] = S[bottom_id];	//bottom -> left
				S[bottom_id] = S[right_id];	//right -> bottom
				S[right_id] = tmp;			//top -> right
				break;
			//$BKLJ}8~(B
			case 'N':
				tmp = S[top_id];
				S[top_id] = S[front_id];	//front -> top
				S[front_id] = S[bottom_id];	//bottom -> front
				S[bottom_id] = S[back_id];	//back -> bottom
				S[back_id] = tmp;			//top -> back
				break;
			//$BFnJ}8~(B
			case 'S':
				tmp = S[top_id];
				S[top_id] = S[back_id];		//back -> top
				S[back_id] = S[bottom_id];	//bottom -> back
				S[bottom_id] = S[front_id];	//front -> bottom
				S[front_id] = tmp;			//top -> front
				break;
			//$B@>J}8~(B
			case 'W':
				tmp = S[top_id];
				S[top_id] = S[right_id];		//right -> top
				S[right_id] = S[bottom_id];		//bottom -> right
				S[bottom_id] = S[left_id];		//left -> bottom
				S[left_id] = tmp;				//top -> left
				break;
			//$B2#J}8~(B
			case 'M':
				tmp = S[left_id];
				S[left_id] = S[front_id];
				S[front_id] = S[right_id];
				S[right_id] = S[back_id];
				S[back_id] = tmp;
				break;
			default:
				cout << "[fail]invalid direction" << endl;
				break;
		}
	}

	//$B%5%$%3%m>eLL$N?t$HA0LL$N?t$K9gCW$9$k$h$&%5%$%3%m$r2sE>$5$;$k(B
	void RotateDice_match_top_front(int top_val, int front_val)
	{
		//$BFnKLJ}8~$K2sE>$5$;$F0lCW$9$k%@%$%9LL$,$"$k$+3NG'(B
		for(int i = 0; i < 3; i++)
		{
			if( S[top_id] != top_val )
			{
				roll_dice('S');	
			}
			else
			{
				break;
			}
		}

		//$BFnKLJ}8~$K2sE>$5$;$F$b0lCW$9$k%@%$%9LL$,L5$$>l9g$O(B
		//$BEl@>J}8~$K2sE>$5$;$F$_$k(B
		if( S[top_id] != top_val)
		{
			//$BEl@>J}8~$K2sE>(B
			for(int i = 0; i < 3; i++)
			{
				roll_dice('W');
				if( S[top_id] == top_val) break;
			}
		}

		//$B>eLL$,3NDj$7$?$iA0LL$K0lCW$9$k%@%$%9LL$rC5$9(B
		for(int i = 0; i < 3; i++)
		{
			if( S[front_id] != front_val)
			{
				roll_dice('M');
			}
			else
			{
				break;
			}	
		}
		cout << S[right_id] << endl;
	}
};

int main(void)
{
	int q;				//$B<ALd$N?t(B
	Dice dice;

	//$B<ALd$N?t$rF~NO(B
	cin >> q;
	
	//q$B9TJ,!$<ALd$H2sEz$r<B;\(B
	for(int i = 0; i < q; i++)
	{
		int top_val;	//$B%5%$%3%m>eLL$N?t(B
		int front_val;	//$B%5%$%3%mA0LL$N?t(B

		cin >> top_val >> front_val;
		dice.RotateDice_match_top_front(top_val, front_val);
	}
	return 0;
}
