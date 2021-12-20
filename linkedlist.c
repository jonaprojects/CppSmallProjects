#include <stdio.h>
#include <malloc.h>
typedef struct node {
    int value;
    struct node* next;
} node;

void print_nodes(node* head){
    node* current = head;
    while(current != NULL){
        printf("%d->",current->value);
        current = current->next;
    }
    printf("NULL\n");
}
int num_of_elements(node* head){
    unsigned int counter = 0;
    node* current = head;
    while(current != NULL){
        counter++;
        current = current->next;
    }
    return counter;
}
void append(node* head, int value){
    node* current = head;
    while(current->next != NULL){ // promote current to the end of the list
        current = current->next;
    }
    current->next = malloc(sizeof(node));
    current->next->value = value;
    current->next->next = NULL;
}
void remove_first(node** head){
    if(*head == NULL){
        return -1;
    }
    node* next = head->next;
    free(head);
    
}
int main()
{
    node* first = malloc(sizeof(node));
    first->value = 5;
    first->next = malloc(sizeof(node));
    first->next->value = 6;
    first->next->next = NULL;
    append(first,7);
    append(first,8);
    append(first,9);
    append(first,10);
    print_nodes(first);
    printf("The number of elements is %d\n",num_of_elements(first));
    printf("Value is %d\n",first->next->value);
    
    
    int* ptr = (int*)malloc(sizeof(int)*3); // Dynamic Memory Allocation On The Heap
    ptr[0] = 5;
    ptr[1] = 2;
    ptr[2] = 8;
    for(int i = 0; i<3 ; ++i){
        printf("Number on index %d is %d\n",i,ptr[i]);
    }
    free(ptr);
    return 0;
}
