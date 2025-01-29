# Data Structures and Algorithms Implementation in C (Batch 2023-27, 2nd Year, 3rd Sem)

This repository contains C implementations of various data structures and algorithms. These programs were part of the coursework for the 2nd year, 3rd semester, batch 2023-27.  They cover fundamental data structures and their applications.

## Contents

### 1. Student Data Management

*   **`student_management.c`**: Defines a `student` structure (name, USN, age, CGPA), creates an array of students, displays them, and filters students based on a user-provided CGPA.  *(Coursework Exercise)*

### 2. Recursive Programs

*   **`tower_of_hanoi.c`**: Solves the Tower of Hanoi puzzle using recursion. *(Coursework Exercise)*
*   **`fibonacci.c`**: Generates the Fibonacci series using recursion. *(Coursework Exercise)*

### 3. Stack Operations (Array Implementation)

*   **`stack_array.c`**: Implements a stack of integers using an array with a maximum size (`MAX`).  Provides a menu-driven interface for push, pop, palindrome check, overflow/underflow demonstration, display, and exit. *(Coursework Exercise)*

### 4. Infix to Postfix Conversion

*   **`infix_to_postfix.c`**: Converts a valid parenthesized infix arithmetic expression (single-character operands and `+`, `-`, `*`, `/` operators) to postfix using a stack. *(Coursework Exercise)*

### 5. Postfix Expression Evaluation

*   **`postfix_evaluation.c`**: Evaluates a valid postfix expression (single-digit operands and `+`, `-`, `*`, `/` operators) using a stack. *(Coursework Exercise)*

### 6. Process Scheduling (Queue Implementation)

*   **`process_scheduling.c`**: Simulates process scheduling in an operating system using a queue (FIFO). Provides options to add, remove, and display process IDs. *(Coursework Exercise)*

### 7. Circular Queue Operations (Array Implementation)

*   **`circular_queue_array.c`**: Implements a circular queue of characters using an array. Provides a menu-driven interface for insert, delete, full/empty checks, display, and exit. *(Coursework Exercise)*

### 8. Singly Linked List Operations

*   **`singly_linked_list.c`**: Implements various operations on a singly linked list: insert at front, delete at rear, search, and display. *(Coursework Exercise)*

### 9. Doubly Linked List Operations

*   **`doubly_linked_list.c`**: Implements a doubly linked list with a menu-driven interface for create (end insertion), display, insert/delete at front, search, and exit. *(Coursework Exercise)*

### 10. Stack using Linked List

*   **`stack_linked_list.c`**: Implements a stack data structure using a linked list. Provides options to add, remove, and display elements, with exception handling. *(Coursework Exercise)*

### 11. Queue using Linked List

*   **`queue_linked_list.c`**: Implements a queue data structure using a linked list. Provides options to add, remove, and display elements, with exception handling. *(Coursework Exercise)*

### 12. Binary Search Tree for Student Scores

*   **`bst_student_scores.c`**: Implements a Binary Search Tree (BST) to manage student scores (1-100).  Provides functionality to insert scores, display in ascending order, find highest/lowest scores, and search for a specific score. *(Coursework Exercise)*

## Compilation and Execution

To compile and run a specific program, navigate to the directory containing the `.c` file in your terminal and use a C compiler (like GCC):

```bash
cc <filename.c> 
./a.out
```                                  
