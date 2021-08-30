#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* create_link_list(int item, Node* head)
{
//printf("\n head %d",head);
    Node* newnode=NULL;
    Node* ptr=NULL;
    Node* save=NULL;
    newnode= new Node();
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
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

void print_link_list(Node* head)
{
    Node* ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

bool is_prime(int n){

//    for(int i=2; i<n; i++){
//    for(int i=2; i<n/2 + 1; i++){
    for(int i=2; i<sqrt(n) + 1; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void print_prime_numbers(Node* head)
{
    Node* ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        if(is_prime(ptr->data))
        {
            printf("%d ",ptr->data);
        }
        ptr=ptr->next;
    }
}

//void print_prime_numbers(Node* head)
//{
//    Node* ptr=NULL;
//    ptr=head;
//    while(ptr!=NULL)
//    {
//        printf("%d : ",ptr->data);
//
//        if(is_prime(ptr->data))
//        {
//            printf("Prime!\n");
//        }
//        else{
//            printf("Not Prime!\n");
//        }
//        ptr=ptr->next;
//    }
//}

void no_of_items(Node* head)
{
    int count = 0;
    Node* ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    cout<<endl<<"The number of items in Linked List: "<<count<<endl;
}

int main()
{
    int n,i,item,key,loc;
    struct Node* head=NULL;
    printf("\nEnter the number of elements of the list:");
    scanf("%d",&n);
    printf("\nEnter the elements of the list:\n");
    for (i=1; i<=n; i++)
    {
        cin>>item;
        head=create_link_list(item,head);
    }
    printf("\nThe list is: ");
    print_prime_numbers(head);

}
