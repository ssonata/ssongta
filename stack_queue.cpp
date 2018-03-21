#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);

	cout<<s.top()<<endl;
	s.pop();  //First Out
	cout<<s.top()<<endl;

	queue<int> q;
	q.push(1);
	q.push(2);

	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	q.pop();     //Last Out

	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
}
