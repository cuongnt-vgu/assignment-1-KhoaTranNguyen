
struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node** p_head, struct Node* position, int data);
void pushBack(struct Node** p_head, int data);
void deleteNode(struct Node** p_head, struct Node* position);
void deleteList(struct Node** p_head);
int sizeOfList(struct Node* head);
void displayList(struct Node* head);
void displayListToString(struct Node* head, char* output);