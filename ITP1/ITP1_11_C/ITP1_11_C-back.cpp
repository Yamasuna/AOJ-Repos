
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
	int S[6];		//サイコロの各面の整数を格納する配列
	int top_id;		//サイコロ上面を示す配列添字
	int left_id;	//サイコロ左側面を示す配列添字
	int right_id;	//サイコロ右側面を示す配列添字
	int front_id;	//サイコロ手前の面を示す配列添字
	int back_id;	//サイコロ奥側の面を示す配列添字
	int bottom_id;	//サイコロ底面の面を示す配列添字

enum{
	TOP,
	BACK,
	BOTTOM,
	RIGHT,
	LEFT,
	FRONT,
};

public:

	//コンストラクタ
	Dice()
	{
		//サイコロの各面の整数を入力する
		input_surface();

		//初期状態の面を指す配列添字を指定
		top_id = 0;
		left_id = 3;
		right_id = 2;
		front_id = 1;
		back_id = 4;
		bottom_id = 5;
	}

	//サイコロの各面の整数を入力する関数
	void input_surface(void)
	{
		for(int i = 0; i < 6; i++)
		{
			cin >> S[i];
		}
	}

	//指定した方向にサイコロを転がす処理を実施
	void roll_dice(const char direction)
	{
		int tmp;

		switch(direction)
		{
			//東方向
			case 'E':
				tmp = S[top_id];
				S[top_id] = S[left_id];		//left -> top
				S[left_id] = S[bottom_id];	//bottom -> left
				S[bottom_id] = S[right_id];	//right -> bottom
				S[right_id] = tmp;			//top -> right
				break;
			//北方向
			case 'N':
				tmp = S[top_id];
				S[top_id] = S[front_id];	//front -> top
				S[front_id] = S[bottom_id];	//bottom -> front
				S[bottom_id] = S[back_id];	//back -> bottom
				S[back_id] = tmp;			//top -> back
				break;
			//南方向
			case 'S':
				tmp = S[top_id];
				S[top_id] = S[back_id];		//back -> top
				S[back_id] = S[bottom_id];	//bottom -> back
				S[bottom_id] = S[front_id];	//front -> bottom
				S[front_id] = tmp;			//top -> front
				break;
			//西方向
			case 'W':
				tmp = S[top_id];
				S[top_id] = S[right_id];		//right -> top
				S[right_id] = S[bottom_id];		//bottom -> right
				S[bottom_id] = S[left_id];		//left -> bottom
				S[left_id] = tmp;				//top -> left
				break;
			//横方向
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

	//ダイス面の値を返す
	int diceAt(int surface)
	{
		switch(surface)
		{
			case TOP:
				return S[top_id];
			case BACK:
				return S[back_id];
			case BOTTOM:
				return S[bottom_id];
			case RIGHT:
				return S[right_id];
			case LEFT:
				return S[left_id];
			case FRONT:
				return S[front_id];
			defGault:
				cout << "invalid parameter diceAt" << endl;
				return 999;
				break;
		}
	}

	//入力されたダイスが同じものか判定する
	void checkDice(Dice ref_dice)
	{
		int ref_top = ref_dice.diceAt(TOP);
		int ref_front = ref_dice.diceAt(FRONT);
		int ref_back = ref_dice.diceAt(BACK);
		int ref_bottom = ref_dice.diceAt(BOTTOM);
		int ref_left = ref_dice.diceAt(LEFT);
		int ref_right = ref_dice.diceAt(RIGHT);

		roll_dice('S');
		for(int i = 0; i < 3; i++)
		{
			if( S[top_id] != ref_top )
			{
				roll_dice('S');
			}
			else
			{
				break;
			}
		}

		for( int i = 0; i < 3; i++)
		{
			if( S[top_id] != ref_top)
			{
				roll_dice('W');
				if( S[top_id] == ref_top ) break;
			}
		else
			{
				break;
			}
		}

		if( S[top_id] != ref_top)
		{
			//この段階で上面に一致する値は無いことになるため終了
			cout << "No" << endl;
			return;
		}
		
		//前面に一致するダイス面を探す
		for(int i = 0; i < 3; i++)
		{
			if( S[front_id] != ref_front)
			{
				roll_dice('M');
				if( S[front_id] == ref_front) break;
			}
			else
			{
				break;
			}
		}
		
		if (S[front_id] != ref_front)
		{
			//この段階で前面に一致する値は無いことになるため終了
			cout << "No" << endl;
			return;
		}

		//他の面の値も同じかチェックする
		if( (S[right_id] == ref_right) &&
			(S[left_id]  == ref_left)  &&
			(S[bottom_id] == ref_bottom) &&
			(S[back_id] == ref_back) )
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

		return;
	}

	void checkDice(Dice ref_dice)
	{
		
	}
};

int main(void)
{
	Dice dice1, dice2;

	dice1.checkDice(dice2);

	return 0;
}
