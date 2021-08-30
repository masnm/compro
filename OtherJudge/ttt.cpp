#include<bits/stdc++.h>
using namespace std;

struct Node {
	string s;
	struct Node* next;
};
typedef struct Node node;

struct cln {
	string name;
	string age;
	string city;
	struct cln* next;
};
typedef struct cln cln;

struct Node* create_link_list ( string s, struct Node* head )
{
	//printf("\n head %d",head);
	struct Node* newnode=NULL;
	struct Node* ptr=NULL;
	struct Node* save=NULL;
	newnode = (node*) malloc ( sizeof ( node ) );
	newnode->s=s;
	newnode->next=NULL;
	if(head==NULL) {
		head=newnode;
	} else {
		ptr=head;
		while(ptr!=NULL)
		{
			save=ptr;
			ptr=ptr->next;
		}
		save->next=newnode;
	}
	return head;
}

struct cln* create_link_list (
	string name,
	string age,
	string city,
	struct cln* head )
{
	struct cln* newnode=NULL;
	struct cln* ptr=NULL;
	struct cln* save=NULL;
	newnode = (cln*) malloc ( sizeof ( cln ) );
	newnode->name=name;
	newnode->age=age;
	newnode->city=city;
	newnode->next=NULL;
	if(head==NULL) {
		head=newnode;
	} else {
		ptr=head;
		while(ptr!=NULL)
		{
			save=ptr;
			ptr=ptr->next;
		}
		save->next=newnode;
	}
	return head;
}

void print_link_list(struct Node* head)
{
	struct Node* ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		cout << ptr->s << " ";
		ptr=ptr->next;
	}
}

void print_link_list(cln* head)
{
	struct cln* ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		cout << ptr->name << " " << 
		ptr->age << " " << ptr->city << endl;
		ptr=ptr->next;
	}
}

void insertion_sert ( cln** root, int n )
{
	if ( n == 0 || n == 1 ) {
		return;
	}
	cln** rt = root;
	while ( (*root) != NULL ) {
		root = &(*root)->next;
		if ( *root== NULL ) break;
		cln** pos = rt;
		while ( (*pos) != NULL && (*pos) != (*root) && ( (*pos)->city > (*root)->city ) ) {
			pos = &(*pos)->next;
		}
		while ( (*pos) != (*root) ) {
			swap ( (*pos)->name, (*root)->name );
			swap ( (*pos)->age, (*root)->age );
			swap ( (*pos)->city, (*root)->city );
			pos = &(*pos)->next;
		}
		swap ( (*pos)->name, (*root)->name );
		swap ( (*pos)->age, (*root)->age );
		swap ( (*pos)->city, (*root)->city );
	}
}

int main()
{
	int n,i;
	string item;
	struct Node* name = NULL;
	struct Node* age = NULL;
	struct Node* city = NULL;
	
	printf("\nEnter the size : ");
	cin >> n;
	
	cout << "Enter " << n << " names : ";
	for (i=1;i<=n;i++) {
		cin >> item;
		name = create_link_list ( item, name );
	}
	
	cout << "Enter " << n << " age : ";
	for (i=1;i<=n;i++) {
		cin >> item;
		age = create_link_list ( item, age );
	}
	
	cout << "Enter " << n << " city : ";
	for (i=1;i<=n;i++) {
		cin >> item;
		city = create_link_list ( item, city );
	}
	
	node* nm = name;
	node* ag = age;
	node* ct = city;
	cln* clients = NULL;
	
	for ( i = 0 ; i < n ; ++i ) {
		clients = create_link_list ( nm->s, ag->s, ct->s, clients );
		nm = nm->next;
		ag = ag->next;
		ct = ct->next;
	}
	
	cout << "The list before sorting : \n";
	print_link_list(clients);
	cout << endl;
	
	insertion_sert ( &clients, n );
	
	cout << "The list after sorting : \n";
	print_link_list(clients);
	
	
	return 0;
}

/*

5
namea nameb namec maned namee
12 56 21 90 65
Jessore Dhaka Khulna Rongpure Comilla

*/
