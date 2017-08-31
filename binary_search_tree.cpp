#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *BST;

struct node* newNode(int data)
{
	BST = (struct node*)malloc(sizeof(BST));
	BST->data = data;
	return BST;
}

int bst_search(struct node *root, int is_search)
{
	if(root == NULL)
	{
		cout<<"검색할 것이 없습니다."<<endl;
		return -1;
	}
	if(root->data == is_search) // 찾고 있는 data가 맞다면 현재 data return
	{
		return root->data;
	}
	if(root->data > is_search)	return bst_search(root->left, is_search);
	else						return bst_search(root->right, is_search);
}
struct node *bst_insert(struct node * root, int data)
{
	if(root == NULL)	
	{
		//cout<<"BST가 Null입니다."<<endl;
		root = newNode(data);
	}
	else
	{
		if(root != NULL)
		{
			if(root->data < data)	root->right = bst_insert(root->right, data);
			else					root->left = bst_insert(root->left, data);
		}
	}
	return root;
}
struct node *bst_findmax(struct node* max)
{
	if(max->right) return bst_findmax(max->right);
	else	       return max;
}
struct node *bst_findmin(struct node* min)
{
	if(min->left)  return bst_findmin(min->left);
	else           return min;
}
struct node *bst_delete(struct node * parent, struct node* root, int del)
{
	if(root == NULL)
	{
		//cout<<"삭제할 데이터가 없습니다."<<endl;
		return NULL;
	}
	else if(root->data > del)	root->left = bst_delete(root, root->left, del);
	else if(root->data < del)	root->right = bst_delete(root, root->right, del);
	else // 삭제할 데이터 발견 root->data == del
	{
		if(root->left || root->right) //자식이 2개라면
		{
			struct node* temp = NULL;
			if(root->left)
			{
				temp = bst_findmax(root->left);
				root->data = temp->data;
				root->left = bst_delete(root, root->left, root->data);
			}
			if(root->right)
			{
				temp = bst_findmin(root->right);
				root->data = temp->data;
				root->right = bst_delete(root, root->right, root->data);
			}
		}
		else // leaf노드
		{
			if(parent->left == root) parent->left = NULL;
			else if(parent->right == root) parent->right = NULL;
			free(root);
			return NULL;
		}
	}
}
int main()
{
	int c,in,del,s;
	BST = newNode(100);
	if(BST == NULL)
	{
		cout<<"NULL"<<endl;
		return 0;
	}
	while(1)
	{
		cout<<"1..search"<<endl;
		cout<<"2..insert"<<endl;
		cout<<"3..delete"<<endl;
		cout<<"4..quit"<<endl;
		cin>>c;
		if(c == 4) break;
		switch(c)
		{
			case 1:
				cin >> s;
				if(bst_search(BST, s) != -1)		cout<<"해당 값이 있습니다."<<endl;
				break;
			case 2:
				cin >> in;
				BST = bst_insert(BST, in);
				break;
			case 3:
				cin >> del;
				BST = bst_delete(BST, BST, del);
				break;
		}
	}
	return 0;
}
