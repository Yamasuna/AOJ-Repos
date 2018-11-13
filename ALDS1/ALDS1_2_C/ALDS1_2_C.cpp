#include <iostream>
#include <string>

using namespace std;

#define IDX_TRUMP_DESIGN 0
#define IDX_TRUMP_NUMBER 1


//$B%H%i%s%W7?(B
typedef struct {
	char design;
	int number;
} trump_t;

//$B%H%i%s%W$NMWAG$r8r49(B
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

	//$B%+!<%I$NKg?t(B
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
