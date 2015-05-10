// Implementation of a dictionary
#include <iostream>
#include <stdlib.h>
#include<string.h>
using namespace std;
struct node {
	node * left;
	node * right;
       char * word;
};
struct bucket {
	node *root;
}A[26];

void treedisp(node *p)
{
	if(p==NULL) 
		return;
	treedisp(p->left);
	cout<<"\n"<<p->word;
	treedisp(p->right);
}
void display()
{
	int i;
	for(i=0;i<26;i++)
	{
		treedisp(A[i].root);
	}
}
		

void insert( char *input)
{
	int b = input[0]-'a';
	cout<<b;
	if( A[b].root ==NULL)
	{
		A[b].root = (node *) malloc(sizeof(node));
		A[b].root->word= (char *) malloc (sizeof(input));
		A[b].root->left=NULL;
		A[b].root->right=NULL;
		strcpy(A[b].root->word, input);
		cout<<"\n added "<<A[b].root->word<<endl;
	}
	else
	{	
			node *p= A[b].root;
			node *q = p;
		do
		{
			cout<<"\n Inside filed insert";
			if (strcmp(p->word, input) >0) // p->word > input or input comes to the left
			{
				q=p;
				p=p->left;
			}
			else if (strcmp(p->word, input) <0)
			{
				q=p;
				p=p->right;
			}
			else
				cout<<"\n String "<<input<<" already present in dictionary !\n";
		}while(p!=NULL);
		if(p==NULL)
		{
			if(strcmp(q->word, input) >0)
			{
			node *l= new(node);
			l->word=(char *) malloc( sizeof(input));
			q->left=l;
			}
			else
			{
				node *r= new(node);
				r->word= (char *) malloc(sizeof(input));
				q->right=r;
			}
		}
	}
}
main()
{

	int i;
	for(i=0;i<26;i++)
		A[i].root=NULL;
	// Insertion
	char input[30];
	do{
	cout<<"\n enter the string to be inserted, type @ to exit\t";
	cin>>input;
	if(strcmp(input, "@"))
	insert(input);
	} while(strcmp(input,"@"));
	display();



	
}
