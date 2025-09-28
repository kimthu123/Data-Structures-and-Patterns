# Data Structures and Patterns (C++)

This repository contains my coursework and implementations for **Data Structures and Patterns** at Swinburne University of Technology.  
It demonstrates my skills in **C++ programming, object-oriented design, templates, iterators, and algorithm efficiency**.

---

## 📂 Repository Structure
- **ProblemSet1/** → Vector & Matrix Abstract Data Types (ADTs)  
- **ProblemSet2/** → Iterators and Vigenère Cipher (AutoKey)  
- **ProblemSet3/** → Priority Queue (Template-based)  
- **ProblemSet4/** → List ADT using Doubly Linked Lists  

Additional files:
- `Vector2D.h / Vector2D.cpp` – Implementation of 2D vector operations  
- `Vector3D.h / Vector3D.cpp` – Implementation of 3D vector operations  
- `Matrix3x3.h / Matrix3x3.cpp` – Matrix operations including determinant, inversion, multiplication  
- `Main.cpp` – Sample driver program for testing  

---

## 📝 Problem Sets Overview

### 🔹 Problem Set 1: Vector & Matrix ADTs
- Implemented **Vector2D, Vector3D, Matrix3x3** classes.  
- Applied **operator overloading** (`==`, `<<`, `*`) for clean mathematical operations.  
- Practiced **constructors, assignment operators, and template basics**.  

### 🔹 Problem Set 2: Iterators & Vigenère Cipher
- Built **ForwardIterator and BidirectionalIterator** following STL conventions.  
- Implemented **AutoKey iterator** to dynamically extend cipher keys.  
- Created an **encoder/decoder** for the Vigenère Cipher using iterators.  

### 🔹 Problem Set 3: Priority Queue
- Implemented a **template-based Priority Queue** with dynamic resizing.  
- Supported operations: `push`, `pop`, `top` while maintaining **stable ordering**.  
- Practiced **operator<, comparators, and dynamic memory management**.  

### 🔹 Problem Set 4: List ADT (Doubly Linked List)
- Designed a **doubly linked list** with `shared_ptr` and `weak_ptr` for safe memory management.  
- Implemented **copy/move semantics** for efficient object handling.  
- Provided iterators for **forward and reverse traversal**.  

---

## ⚙️ Build & Run
1. Clone this repository:
   ```bash
   git clone https://github.com/kimthu123/Data-Structures-and-Patterns.git
   cd Data-Structures-and-Patterns
