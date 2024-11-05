#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// test case 1: test pushBack
int test_case_1() {
    struct Node* head = NULL;
    pushBack(&head, 5);
    char output[100];
    displayListToString(head, output);
    assert(strcmp(output, "5 -> NULL") == 0);
    deleteList(&head);
    return 0;
}

// test case 2: test insertNode
int test_case_2() {
    struct Node* head = NULL;
    pushBack(&head, 5);
    insertNode(&head, head, 10);
    char output[100];
    displayListToString(head, output);
    assert(strcmp(output, "10 -> 5 -> NULL") == 0);
    deleteList(&head);
    return 0;
}

// test case 3: test deleteNode
int test_case_3() {
    struct Node* head = NULL;
    pushBack(&head, 5);
    insertNode(&head, head, 10);
    deleteNode(&head, head);
    char output[100];
    displayListToString(head, output);
    assert(strcmp(output, "5 -> NULL") == 0);
    deleteList(&head);
    return 0;
}

// test case 4: test sizeOfList
int test_case_4() {
    struct Node* head = NULL;
    pushBack(&head, 5);
    insertNode(&head, head, 10);
    insertNode(&head, head->next, 15);
    assert(sizeOfList(head) == 3);
    deleteList(&head);
    return 0;
}

int main()
{
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    return 0;
}
