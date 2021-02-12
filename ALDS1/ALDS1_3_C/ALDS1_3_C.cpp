#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
	int key;
	Node *next;
	Node *prev;
};

Node *nil;

void initNode(void)
{
	nil = (Node *)malloc(sizeof(Node));
	nil->next = nil;
	nil->prev = nil;
}

//連結リストの先頭にキーkeyを持つ要素を追加する
void insert(int key)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->key = key;
	new_node->next = nil->next;
	nil->next->prev = new_node;
	nil->next = new_node;
	new_node->prev = nil;
}

//双方向リストの要素の探索
Node* listSearch(int key)
{
	Node *cur = nil->next;	//番兵の次の要素から辿る
	while( (cur != nil) && (cur->key != key) )
	{
		cur = cur->next;
	}
	return cur;
}

//指定したNodeを削除する
void deleteNode(Node *t)
{
	if (t == nil) 
	{
		return;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
}

//キーkeyを持つ最初の要素を連結リストから削除する
void deleteKey(int key)
{
	deleteNode(listSearch(key));
}

//連結リストの先頭の要素を削除する
void deleteFirst(void)
{
	deleteNode(nil->next);
}

//連結リストの末尾の要素を削除する
void deleteLast(void)
{
	deleteNode(nil->prev);
}

//リストの出力
void printList()
{
	Node *cur = nil->next;
	int ifs = 0;

	while (1)
	{
		if (cur == nil) break;
		if (ifs++ > 0)
		{
			printf(" ");
		}
		printf("%d", cur->key);
		cur = cur->next;
	}
	printf("\n");
}

int main(void)
{
	int key, n, i;
	int size = 0;
	int np = 0, nd = 0;
	char command[20];
	scanf("%d", &n);
	initNode();

	for( i = 0; i < n; i++)
	{
		scanf("%s%d", command, &key);
		if( command[0] == 'i')
		{
			insert(key);
			np++; size++;
		}
		else if (command[0] == 'd')
		{
			if (strlen(command) > 6 )
			{
				if (command[6] == 'F') deleteFirst();
				else if( command[6] == 'L' ) deleteLast();
			}
			else
			{
				deleteKey(key);
				nd++;
			}
			size--;
		}
		//printList();
	}
	printList();
	return 0;
}