#include <stdio.h>
#include<stdlib.h>

// creation of node or linked list
struct Node{
    int data;
    struct Node * next;
};

   // functionnnn forr traversal or display the element present in
void linkedListTraversal(struct Node * ptr){

    printf("\nElements in Linked List");

    while (ptr != NULL)
    {
       printf("\nElements: %d ",ptr->data);

       ptr = ptr->next;
    }
    
}

 // function for insert element at starting of linked list 

 // struct Nde * because it's returns a Struct Node type 
struct Node * insertAtFirst(struct Node * head , int data){

    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
        
    ptr->data = data;
    ptr->next = head;

    printf("\n element inserted succedfully: ");
    return ptr;
}

// function to insert node at index 

struct Node * insertAtIndex(struct Node *head ,int data, int index){
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p = head;

    int i = 0 ;
    while (i!= index-1)
    {
       p = p->next;
       i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
    
}


  // function for insert a node at end of linked list

  struct Node* insertAtEnd(struct Node *head,int data){
      struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));

      ptr->data = data;

      struct Node * p = head;

      while (p->next!= NULL)
      {
        p=p->next;
      }
      p->next  = ptr;
      ptr->next = NULL;

      return head;  
    }

    // function for insert after a node 

    struct Node * insertAfterNode(struct Node *head,struct Node *prevNode,int data){
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));


        ptr->data = data;
        ptr->next = prevNode->next;
        prevNode->next = ptr;


        return head;

    }

int main(){

    int operation , element,index;

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

   // element in linked list 


    linkedListTraversal(head);

    printf("\n");
    printf("\n Enter Opertion perform on LInked List\n 1.insert Element At Start: \n 2.Insert at between: \n 3.Insert At End:\n 4.Insert a node After\n");
    scanf("\n %d",&operation);


    switch (operation)
    {
    // case for Inseartion at Star of linked list
    case 1:
       printf("\n enter Data you want to insert At Start: ");
       scanf("%d ",  &element);
       head = insertAtFirst(head,element);
       printf("\n Element inserted At Start");
       linkedListTraversal(head);


    // case for insertion at between positon of linked list 
    case 2: 
        printf("\n enter data and index: ");
        scanf("%d %d",&element,&index);
        head = insertAtIndex(head,element,index);
        printf("\n Element inserted at Between");

        linkedListTraversal(head);
        break;

    case 3:
        printf("\n enter Data you want to insert At End: ");
        scanf("%d ",  &element);
        head = insertAtEnd(head,element);
        printf("\n Element inserted At End");
        linkedListTraversal(head);

    case 4:
        printf("\n Node After new Node Inserted and data in Node");
        scanf("%d",&element);
        insertAfterNode(head,second,element);
        printf("\n Node inserted:");
        linkedListTraversal(head);

     default:
        break;
    }


return 0 ;


}