# Data Structures & Algorithms Library (C++) 🚀

A comprehensive, template-based C++ library implementing fundamental data structures from scratch. This project demonstrates high-level OOP concepts, including template classes, inheritance, and manual memory management.

---

## 🛠 Features & Core Structures

### 🔗 Linear Data Structures
* **Doubly Linked List:** A full-featured implementation including node insertion, deletion, searching, and list traversal.
* **Dynamic Array:** A flexible array implementation with automatic resizing, element shifting, and bounds checking.

### 🏗 Derived Structures
* **Queues & Stacks (List-Based):** Implementations utilizing the Doubly Linked List for efficient $O(1)$ head/tail operations.
* **Queues & Stacks (Array-Based):** Alternative implementations utilizing the Dynamic Array for contiguous memory benefits.

### 🌟 Real-World Applications
* **Undo/Redo System:** A string management class that uses dual stacks to track state history and restore values.
* **Ticket Queue System:** A simulation of a service center line, managing ticket prefixes, waiting clients, and serving order.

---

## 📁 File Summary

| File Name | Description |
| :--- | :--- |
| `clsDblLinkedList.h` | Template doubly linked list with node-level control. |
| `clsDynamicArray.h` | Custom dynamic array with manual new/delete management. |
| `clsMyStack.h` | Stack implementation using list-based logic (LIFO). |
| `clsMyQueue.h` | Queue implementation using list-based logic (FIFO). |
| `clsMyString.h` | Practical Undo/Redo logic using Stack structures. |
| `clsQueueLine.h` | Service queue simulation with ticket issuing and client tracking. |

---

## 🚀 Getting Started

### Prerequisites
* A C++ compiler supporting **C++11** or higher (e.g., GCC, Clang, or MSVC).

### Usage
Since this is a template-based header-only library, you can simply include the desired header file in your project:

```cpp
#include "clsMyStack.h"

int main() {
    clsMyStack<int> stack;
    stack.push(10);
    stack.push(20);
    
    // Your logic here
    return 0;
}

📄 License

Distributed under the MIT License. See LICENSE for more information.
