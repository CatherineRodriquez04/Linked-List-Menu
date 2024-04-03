# Linked-List-Menu
This C program implements a simple singly linked list with menu-driven functionalities. Here's how the code works:

### Node Structure: 
- The program defines a Node struct to represent each element in the linked list. Each node contains a data field (of any non-pointer data type) and a pointer to the next node in the list.
### Menu Interface: 
- Upon execution, the program presents a menu interface to the user, allowing them to select various operations to perform on the linked list.
### Operations Supported:
Users can:
- Add a node to the end of the list.
- Add a node to a specified location in the list.
- Remove a node at a specified location.
- Remove a node by its value (removing the first instance only).
- View the value of the node at a certain position (0-indexed).
### Dynamic Memory Allocation:
- All nodes in the linked list are dynamically allocated and freed using malloc() and free() functions to ensure proper memory management.
### Execution:
- The program executes in a loop, allowing users to perform multiple operations until they choose to quit.
### Termination:
- Users can exit the program at any time by selecting the appropriate option from the menu.

### Example:
     gcc -o linked_list linked_list.c
     ./linked_list
