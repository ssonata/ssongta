#include <iostream>
using namespace std;

typedef struct node
{
	string data;
	struct node *next;
}NODE;
void linkedList()
{
	NODE *head = NULL;
	head = new NODE;		//header 선언
	head->data = "Monday";
	head->next = NULL;

	NODE *q = new NODE;
	q->data = "Friday";
	q->next = NULL;
	head->next = q;			//header 다음 data 넣기

	NODE *p = new NODE;
	p->data = "Sunday";
	p->next = head;
	head = p;

	NODE *q1 = head;
	while(q1 != NULL)
	{
		cout<< q1->data <<endl;
		q1 = q1->next;
	}
	return;
}
int main()
{
	linkedList();
	return 0;
}
