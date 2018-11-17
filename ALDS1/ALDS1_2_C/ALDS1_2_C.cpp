#include <iostream>
#include <string>

using namespace std;

#define IDX_TRUMP_DESIGN 0
#define IDX_TRUMP_NUMBER 1


//トランプ型
typedef struct {
	char design;
	int number;
} trump_t;

//トランプの要素を交換
void Swap(trump_t &t1, trump_t &t2)
{
	trump_t t_tmp;

	t_tmp = t1;
	t1 = t2;
	t2 = t_tmp;
}

void out_card_info(trump_t *t, int n)
{
	for(int i = 0; i < n-1; i++)
	{
		cout << t[i].design << t[i].number << " ";
	}
	cout << t[n-1].design << t[n-1].number << endl;
}

//バブルソート
void BubbleSort(trump_t *t, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = n-1; j >= i+1; j--)
		{
			if(t[j].number < t[j-1].number)
			{
				Swap(t[j], t[j-1]);
			}
		}
	}
}

//選択ソート
void SelectionSort(trump_t *t, int n)
{
	int minj;

	for(int i = 0; i < n; i++)
	{
		minj = i;
		for(int j = i; j < n; j++)
		{
			if(t[j].number < t[minj].number)
			{
				minj = j;
			}
		}
		Swap(t[i], t[minj]);
	}
}

//安定か判定
bool judgeStable(trump_t *original, trump_t *sorted, int n)
{
	int i, j, k, l;
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			for(k = 0; k < n; k++)
			{
				for(l = k+1; l < n; l++)
				{
					//カード内に同じ数字があった場合
					if( original[i].number == original[j].number )
					{
						if( ( original[i].design == sorted[l].design ) &&
							( original[i].number == sorted[l].number ) &&
							( original[j].design == sorted[k].design ) &&
							( original[j].number == sorted[k].number ) )
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

void output_stable_msg(bool isStable)
{
	if(isStable)
	{
		cout << "Stable" << endl;
	}
	else
	{
		cout << "Not stable" << endl;
	}
}

int main(void)
{
	bool isStable;
	int card_num;
	string card_info;
	trump_t* trump;
	trump_t* sorted_bubble;
	trump_t* sorted_selection;

	//カードの枚数
	cin >> card_num;
	trump = new trump_t[card_num];
	sorted_bubble = new trump_t[card_num];
	sorted_selection = new trump_t[card_num];

	for(int i = 0; i < card_num; i++)
	{
		cin >> card_info;
		trump[i].design = card_info[IDX_TRUMP_DESIGN];
		trump[i].number = card_info[IDX_TRUMP_NUMBER] - 0x30;

		sorted_bubble[i].design = trump[i].design;
		sorted_bubble[i].number = trump[i].number;
		sorted_selection[i].design = trump[i].design;
		sorted_selection[i].number = trump[i].number;
	}

	//バブルソート
	BubbleSort(&sorted_bubble[0], card_num);
	isStable = judgeStable(&trump[0], &sorted_bubble[0], card_num);
	out_card_info(&sorted_bubble[0], card_num);
	output_stable_msg(isStable);

	//選択ソート
	SelectionSort(&sorted_selection[0], card_num);
	isStable = judgeStable(&trump[0], &sorted_selection[0], card_num);
	out_card_info(&sorted_selection[0], card_num);
	output_stable_msg(isStable);

	delete trump;
	delete sorted_bubble;
	delete sorted_selection;
	return 0;
}
