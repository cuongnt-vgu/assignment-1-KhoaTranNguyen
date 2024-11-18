#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void insertNode(struct Node** p_head, struct Node* position, int data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (*p_head == position || *p_head == NULL){
        new_node->next = *p_head; // next(new_node)= old *p_head=head=pointer to the 1st element of the list
        *p_head = new_node; // new *p_head = new_node
    } else{
        struct Node* temp = *p_head;
        while (temp != NULL && temp->next !=position){
            temp=temp->next; //if next == position, the temp is right in front of the inserted-place
        }
        // Before: prev -> after
        // After:  prev -> new_node -> after
        new_node->next = temp->next; // link the -> of new_node to after
        temp->next = new_node; // link the -> of pre_node to new_node
    }
}

void pushBack(struct Node** p_head, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL; //fore-set the new_node next = null to be the last node

    if(*p_head == NULL){
        *p_head = new_node;
    }else{
        struct Node* temp = *p_head; // temp = current head, point to the 1st node
        while (temp->next != NULL){
            temp = temp->next; //temp = pointer to next node, reaching the last node (which has next=NULL)
        }
        temp->next = new_node; //pointer to the last node = new_node
    }
}

void deleteNode(struct Node** p_head, struct Node* position) 
{
    if(*p_head == NULL || position == NULL) return;

    if (*p_head == position){
        struct Node* temp = *p_head;
        *p_head = (*p_head)->next; //if *p_head->next, machine will *(p_head->next)
        free(temp);
    } else{
        struct Node* temp = *p_head;
        while (temp->next != NULL && temp->next != position){
            temp = temp->next; //temp will be the previous of the position
        } // prev -> position -> after
          // temp = prev

        if (temp->next == position){
            struct Node* to_del = temp->next; //to_del = prev->next = position
            temp->next = to_del->next; //prev->next = after
            free(to_del); //del position
        }
    }
}

int sizeOfList(struct Node* head) 
{
    int count = 0;
    struct Node* current = head; //current = head

    // head -> 1 -> 2 -> ...
    while (current != NULL){ //head != NULL (list not empty)
        count++; //count head, 1, 2, ...
        current = current->next; //current = 1
    }

    return count;
}

void deleteList(struct Node **p_head)
{
    struct Node* current = *p_head; //current = head
    struct Node* next;
    // head -> 1 -> 2 -> ...
    while (current != NULL){ //head != NULL (list not empty)
        next = current->next; //next = current+1
        free(current); //free(head)
        current = next; //current = 1
    }
    *p_head = NULL;
}

// Display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// display the linked list to a string output
void displayListToString(struct Node* head, char* output) {
    sprintf(output, "%s", "");
    struct Node* temp = head;
    while (temp != NULL) {
        char temp_str[100];
        sprintf(temp_str, "%d -> ", temp->data);
        strcat(output, temp_str);
        temp = temp->next;
    }
    // concatenate NULL to the output string
    sprintf(output, "%sNULL", output);
}