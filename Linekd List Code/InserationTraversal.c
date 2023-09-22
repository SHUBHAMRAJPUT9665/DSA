#include <stdio.h>
#include<stdlib.h>

// creation of node or linked list
struct Node{
    int data;
    struct Node * next;
};

   // functionnnn forr traversal or display the element present in
void linkedListTraversal(struct Node * ptr){

    printf("\n Elements in Linked List\n ");

    while (ptr != NULL)
    {
       printf("Elements: %d \n",ptr->data);

       ptr = ptr->next;
    }
    
}
 // function for insert element at starting of linked list 
 // struct Nde * because it's returns a Struct Node type 
struct Node * insertAtFirst(struct Node * head , int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    printf("\n element inserted succedfully: ");
    return ptr;
}

// insert at start or insert element at starting of single linked list

int main(){

    int operation , element;

    // pointer creation of type struct node or pointer which stores addresses
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;


    // allocation of heap or dynamic memeroy for node or linked list
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

   /// insertion at head or start of linked list
    head->data = 3;
    head->next = second;


    second->data = 5;
    second->next = third;

    third->data =  8;
    // null beacsue ending of linked list
    third->next = fourth;


    fourth->data = 43;
    fourth->next = NULL;


    linkedListTraversal(head);

    // storing the Insertion in first return value in head
    linkedListTraversal(head);


    printf("\n Enter Opertion perform on LInked List\n 1.insert Element At Start\n");
    scanf("%d",&operation);


    switch (operation)
    {
    // case for Inseartion at Star of linked list
    case 1:
       printf("\n enter Data you want to insert At Start: ");
       scanf("%d ",  &element);
       head = insertAtFirst(head,element);
       linkedListTraversal(head);

     default:
        break;
    }


return 0 ;


}