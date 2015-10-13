#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <memory>
#include <iostream>

using namespace std;

/* A linked list node */
struct Node {
    int data;
    Node *next;
    Node() : data(0), next(0) {};
    Node(const Node& other) : data(other.data), next(other.next) {}
    Node(Node&& other) noexcept : data(move(other.data)), next(move(other.next)) {}
    ~Node() { cout<<"~Node()"<<endl; }
};

/* Function to push a node */
void push( Node** head_ref, int new_data ) {
    Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

/* Function to print nodes in a given linked list */
void printList( Node *node ) {
    while(node != NULL) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void removeDuplicates( Node* start ) {
    unordered_set<int> myset;
    Node* node = start;
    Node* node_previous = NULL;
    while( node != NULL ) {
        if( myset.count( node->data ) == 0 ) {
            myset.insert( node->data );
            node_previous = node;
            node = node->next;
        }
        else {
            node_previous->next = node->next;
            //delete node;
            // use smart pointer to delete node
            // avoid using delete manually
            unique_ptr<Node> to_delete(node);
            node = node_previous->next;
        }
    }
}

int main() {
    
    Node *start = NULL;
    
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
