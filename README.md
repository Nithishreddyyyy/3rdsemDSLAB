# Data Structures and Algorithms Implementation in C

This repository contains C implementations of various data structures and algorithms.  Each program addresses a specific problem or demonstrates the functionality of a particular data structure.

## Contents

### 1. Student Data Management

*   **`student_management.c`**: Defines a `student` structure (name, USN, age, CGPA), creates an array of students, displays them, and filters students based on a user-provided CGPA.

### 2. Recursive Programs

*   **`tower_of_hanoi.c`**: Solves the Tower of Hanoi puzzle using recursion.
*   **`fibonacci.c`**: Generates the Fibonacci series using recursion.

### 3. Stack Operations (Array Implementation)

*   **`stack_array.c`**: Implements a stack of integers using an array with a maximum size (`MAX`).  Provides a menu-driven interface for push, pop, palindrome check, overflow/underflow demonstration, display, and exit.

### 4. Infix to Postfix Conversion

*   **`infix_to_postfix.c`**: Converts a valid parenthesized infix arithmetic expression (single-character operands and `+`, `-`, `*`, `/` operators) to postfix using a stack.

### 5. Postfix Expression Evaluation

*   **`postfix_evaluation.c`**: Evaluates a valid postfix expression (single-digit operands and `+`, `-`, `*`, `/` operators) using a stack.

### 6. Process Scheduling (Queue Implementation)

*   **`process_scheduling.c`**: Simulates process scheduling in an operating system using a queue (FIFO). Provides options to add, remove, and display process IDs.

### 7. Circular Queue Operations (Array Implementation)

*   **`circular_queue_array.c`**: Implements a circular queue of characters using an array. Provides a menu-driven interface for insert, delete, full/empty checks, display, and exit.

### 8. Singly Linked List Operations

*   **`singly_linked_list.c`**: Implements various operations on a singly linked list: insert at front, delete at rear, search, and display.

### 9. Doubly Linked List Operations

*   **`doubly_linked_list.c`**: Implements a doubly linked list with a menu-driven interface for create (end insertion), display, insert/delete at front, search, and exit.

### 10. Stack using Linked List

*   **`stack_linked_list.c`**: Implements a stack data structure using a linked list. Provides options to add, remove, and display elements, with exception handling.

### 11. Queue using Linked List

*   **`queue_linked_list.c`**: Implements a queue data structure using a linked list. Provides options to add, remove, and display elements, with exception handling.

### 12. Binary Search Tree for Student Scores

*   **`bst_student_scores.c`**: Implements a Binary Search Tree (BST) to manage student scores (1-100).  Provides functionality to insert scores, display in ascending order, find highest/lowest scores, and search for a specific score.

## Compilation and Execution

To compile and run a specific program, navigate to the directory containing the `.c` file in your terminal and use a C compiler (like GCC):

```bash
gcc <filename.c> -o <executable_name>
./<executable_name>
