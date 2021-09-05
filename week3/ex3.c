#include <stdio.h>
#include <stdlib.h>
 
 
struct Node {
    int data;
    struct Node* next;
};
 
struct Node* head;
void  print_list()
{
    struct Node* temp = head;
  printf("Element on LinkedList:\n");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
  printf("\n");
    
}
void insert_node(int data, int pst)
{
    int i;
    struct Node* temp1  = (struct Node*) malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;
    if(pst == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node* temp2 = head;
    for(i=0;i<pst-2;i++)
    {
        temp2 = temp2->next;
    }
 
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void delete_node(struct Node** head_ref, int key) {
  struct Node *temp = *head_ref, *prev;

  if (temp != NULL && temp->data == key) {
  *head_ref = temp->next;
  free(temp);
  return;
  }
  
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  if (temp == NULL) return;

  prev->next = temp->next;

  free(temp);
}
 
int main()
{
   	head = NULL;
    	insert_node(2,1);
    	insert_node(3,2);
    	insert_node(4,3);
	print_list();
   	insert_node(5,4);
	insert_node(6,3);
	insert_node(7,2);
	delete_node(&head, 7);
	print_list();
 
    return 0;
}