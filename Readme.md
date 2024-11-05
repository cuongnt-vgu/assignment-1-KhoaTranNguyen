### Objective

The goal of this assignment is to create and manipulate a singly linked list in C. The program should include functions to perform basic operations on the linked list, such as inserting a node at a specific position, adding a node to the end, deleting a node by position, deleting the entire list, and calculating the size of the list.

### Assignment Requirements

1. **Define the Linked List Node Structure**
    - Create a `struct Node` that will contain:
        - An `int` data element.
        - A pointer to the next node.
2. **Functions to Implement**
    
    Write the following functions:
    
    - **Insert a node at a specified position**
        - Function: `void insertNode(struct Node** p_head, struct Node* position, int data);`
        - Description: Insert a new node with the given `data` before the specified `position` node.
    - **Add a node to the end of the list**
        - Function: `void pushBack(struct Node** p_head, int data);`
        - Description: Insert a new node with the given `data` at the end of the list. If the list is empty, the new node becomes the head.
    - **Delete a node at a specified position**
        - Function: `void deleteNode(struct Node** p_head, struct Node* position);`
        - Description: Delete the node at the specified `position`.
            - If `position` is the head node, update the head pointer to the next node in the list.
    - **Delete the entire linked list**
        - Function: `void deleteList(struct Node** p_head);`
        - Description: Delete all nodes in the linked list, free allocated memory, and set the head pointer to `NULL`.
    - **Calculate the size of the linked list**
        - Function: `int sizeOfList(struct Node* head);`
        - Description: Return the total number of nodes currently in the linked list.

### Function Prototypes

- `void insertNode(struct Node** p_head, struct Node* position, int data);`
- `void pushBack(struct Node** p_head, int data);`
- `void deleteNode(struct Node** p_head, struct Node* position);`
- `void deleteList(struct Node** p_head);`
- `int sizeOfList(struct Node* head);`

---

### Tip: Why We Use `struct Node** p_head` Instead of `struct Node* head` in `insertNode`, `deleteNode`, and `deleteList`

In functions where we need to potentially modify the head of the list itself, we use a **pointer to a pointer** (`struct Node** p_head`) instead of a **pointer** (`struct Node* head`). This allows us to directly modify the original head pointer in the calling function:

- **Direct Modification of Head**: When `head` is passed as `struct Node* head`, changes made to `head` inside the function only affect a local copy. To make changes visible outside the function, we use `struct Node** p_head`, which gives us access to the original head pointer.
- This is crucial for operations like:
    - Inserting at the head of the list.
    - Deleting the head node.
    - Deleting the entire list.

This ensures that any modifications to the list’s head node persist outside the function.

### Makefile Usage Guide

This `Makefile` provides targets for compiling, running, and cleaning up a C project that involves running sample test cases for a linked list.

### Makefile Targets

1. **`clean`**
    - **Usage**: `make clean`
    - **Description**: Removes all compiled object files (`$(OBJS)`) and the final executable (`$(TARGET)`).
    - **Example**:
        
        ```bash
        make clean
        ```
        
2. **`check-%`**
    - **Usage**: `make check-<test_case>`
    - **Description**: Runs a specific test case with the compiled executable, `$(TARGET)`.
        - Replace `<test_case>` with the desired test case argument.
        - Displays messages indicating the start and success of each test.
    - **Example**:
        
        ```bash
        make check-1  # Runs test case 1
        make check-2  # Runs test case 2
        ```
        
3. **`sample`**
    - **Usage**: `make sample`
    - **Description**: Compiles the main source files (`$(OBJS)`), along with `sample_test_case.o`, and generates an executable called `test_sample`.
    - **Example**:
        
        ```bash
        make sample
        ./test_sample  # Runs the compiled sample test executable
        ```
        

---

### Notes

- Ensure `$(CC)` (compiler), `$(CFLAGS)` (compiler flags), `$(OBJS)` (object files), and `$(TARGET)` (target executable) are defined either within the `Makefile` or as environment variables for this `Makefile` to run correctly.