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
	for(int i = 0; i < n; i++)
	{
		cout << "trump[" << i << "]=" << t[i].design << t[i].number << endl;
	}
}

int main(void)
{
	int card_num;
	string card_info;
	trump_t* trump;

	//カードの枚数
	cin >> card_num;
	trump = new trump_t[card_num];

	for(int i = 0; i < card_num; i++)
	{
		cin >> card_info;
		trump[i].design = card_info[IDX_TRUMP_DESIGN];
		trump[i].number = card_info[IDX_TRUMP_NUMBER] - 0x30;
	}
	
	out_card_info(&trump[0], card_num);
	Swap(trump[0], trump[2]);
	out_card_info(&trump[0], card_num);
	return 0;
}
