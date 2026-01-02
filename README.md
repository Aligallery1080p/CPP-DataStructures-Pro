Data Structures & Algorithms Library (C++)

A comprehensive, template-based C++ library implementing fundamental data structures from scratch. This project demonstrates high-level OOP concepts, including template classes, inheritance, and manual memory management.
🛠 Features
Core Data Structures

    Doubly Linked List: A full-featured implementation including node insertion, deletion, searching, and list reversal.

    Dynamic Array: A flexible array implementation with automatic resizing, element shifting, and bounds checking.

Derived Structures

    Queues & Stacks (List-Based): Implementations utilizing the Doubly Linked List for efficient O(1) head/tail operations.

    Queues & Stacks (Array-Based): Alternative implementations utilizing the Dynamic Array for contiguous memory management.

Real-World Applications

    Undo/Redo System: A string management class that uses dual stacks to track state history and restore values.

    Ticket Queue System: A simulation of a service center line, managing ticket prefixes, waiting clients, and estimated serve times.

📂 File Summary
File	Description
clsDblLinkedList.h	Template doubly linked list with node-level control.
clsDynamicArray.h	Custom dynamic array with manual new/delete management.
clsMyStack.h	Stack implementation using list-based logic (LIFO).
clsMyQueue.h	Queue implementation using list-based logic (FIFO).
clsMyString.h	Practical Undo/Redo logic using Stack structures.
clsQueueLine.h	Service queue simulation with ticket issuing and client tracking.

📝 License

Distributed under the MIT License. See LICENSE for more information.
