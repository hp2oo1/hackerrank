#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>


using namespace std;

/* A linked list node */
struct node {
    int data;
    struct node *next;
};

/* Function to push a node */
void push( struct node** head_ref, int new_data ) {
    node* new_node = new node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList( struct node *node ) {
    while(node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL");
}

void removeDuplicates( struct node* start ) {
    unordered_set<int> myset;
    struct node* node = start;
    struct node* node_previous = NULL;
    while( node != NULL ) {
        if( myset.count( node->data ) == 0 ) {
            myset.insert( node->data );
            node_previous = node;
            node = node->next;
        }
        else {
            node_previous->next = node->next;
            struct node node_to_delete;
            swap( node_to_delete, *node );
            node = node_previous->next;
        }
    }
}

int main() {
    
    struct node *start = NULL;
    
    /* The constructed linked list is:
    10->12->11->11->12->11->10*/
    push(&start, 10);
    push(&start, 11);
    push(&start, 12);
    push(&start, 11);
    push(&start, 11);
    push(&start, 12);
    push(&start, 10);
    
    printf("\n Linked list before removing duplicates ");
    printList(start);
    
    removeDuplicates(start);
    
    printf("\n Linked list after removing duplicates ");
    printList(start);
    
    getchar();
    
}
