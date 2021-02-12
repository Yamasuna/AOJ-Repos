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

//�A�����X�g�̐擪�ɃL�[key�����v�f��ǉ�����
void insert(int key)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->key = key;
	new_node->next = nil->next;
	nil->next->prev = new_node;
	nil->next = new_node;
	new_node->prev = nil;
}

//�o�������X�g�̗v�f�̒T��
Node* listSearch(int key)
{
	Node *cur = nil->next;	//�ԕ��̎��̗v�f����H��
	while( (cur != nil) && (cur->key != key) )
	{
		cur = cur->next;
	}
	return cur;
}

//�w�肵��Node���폜����
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

//�L�[key�����ŏ��̗v�f��A�����X�g����폜����
void deleteKey(int key)
{
	deleteNode(listSearch(key));
}

//�A�����X�g�̐擪�̗v�f���폜����
void deleteFirst(void)
{
	deleteNode(nil->next);
}

//�A�����X�g�̖����̗v�f���폜����
void deleteLast(void)
{
	deleteNode(nil->prev);
}

//���X�g�̏o��
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