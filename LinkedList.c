#include <stddef.h>
#include <stdlib.h> 
#include <stdio.h>

typedef struct NODE {
    int value;
    struct NODE* next;
} aNode;

aNode* head = NULL;

// problem: 
// 1. list can be NULL and this is not checked before using
// 2. changing the value of "freeSpot" does not change the pointer value in main (PASS BY VALUE)
void addToLinkedList_2(aNode* list, int value) {
    aNode* freeSpot;
    aNode* newNode;
    
    // find a free spot at the end to add the value
    freeSpot = list;
    while(freeSpot->next != NULL) {
        freeSpot = freeSpot->next;
    }
    
    newNode = (aNode*)malloc(sizeof(aNode));
    newNode->value = value;
    newNode->next = NULL;
    freeSpot->next = newNode;
}

void addToLinkedList_1(aNode** list, int value) {
    aNode *newNode = (aNode*)malloc(sizeof(aNode));
    newNode->value = value;
    newNode->next = NULL;
    
    aNode* freeSpot = *list;
    
    if(freeSpot == NULL) *list = newNode;
    else {
        while (freeSpot->next != NULL) {
            freeSpot = freeSpot->next;
        }
        freeSpot->next = newNode;
    }
}

aNode* addToLinkedList(aNode* list, int value) {
    aNode* freeSpot;
    aNode* newNode;
    freeSpot = list;
    
    if (list == NULL) {
        // first item added
        newNode = (aNode*)malloc(sizeof(aNode));
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }
    
    // find a free spot at the end to add the value
    while(freeSpot->next != NULL) {
        freeSpot = freeSpot->next;
    }
    
    newNode = (aNode*)malloc(sizeof(aNode));
    newNode->value = value;
    newNode->next = NULL;
    freeSpot->next = newNode;
    return list;
}

void printNodes(aNode* my_node) {
    printf(" %i ", my_node->value);
    if (my_node->next != NULL) {
        printNodes(my_node->next);
    }
}

void printLinkedList(aNode* list) {
    if(list != NULL) {
        printf("Content of the list is:");
        printNodes(list);
    }
    else {
        printf("List is empty.");
    }
    printf("\n");
}

int main(void){
    printf("----- method 1 -----");
    printf("before adding to the list:\n");
    printLinkedList(head);   
    head = addToLinkedList(head, 1);
    head = addToLinkedList(head, 2);
    printf("after adding to the list:\n");
    printLinkedList(head);
    
    printf("\n");
    printf("----- method 2 -----");
    printf("before adding to the list:\n");
    printLinkedList(head);   
    addToLinkedList_1(&head, 3);
    addToLinkedList_1(&head, 4);
    printf("after adding to the list:\n");
    printLinkedList(head);
    
    printf("\n");
    printf("----- method 3 -----");
    printf("before adding to the list:\n");
    printLinkedList(head);   
    addToLinkedList_2(head, 5);
    addToLinkedList_2(head, 6);
    printf("after adding to the list:\n");
    printLinkedList(head);
}