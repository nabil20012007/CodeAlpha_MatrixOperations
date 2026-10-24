# CodeAlpha_MatrixOperations

[![C Programming](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A robust, menu-driven C program developed as **Task 2** for the **CodeAlpha C Programming Internship**. This application performs core matrix calculations with an emphasis on safety, clean user interface design, and rigorous input validation.

---

## 🚀 Features

* **Matrix Addition (`A + B`)**: Computes the sum of two matrices of matching dimensions.
* **Matrix Multiplication (`A × B`)**: Computes the product of two matrices while enforcing dimension compatibility rules by design.
* **Matrix Transpose**: Flips a matrix across its diagonal (converting $rows \times cols$ to $cols \times rows$).
* **Robust Input Validation**: Safely handles non-numeric inputs, whitespace, buffer overflows, and ensures all dimensions and elements fall within expected ranges.
* **Smart Dimension Constraints**: The dimensions of Matrix B are programmatically derived from Matrix A where applicable, preventing incompatible dimensions from ever being entered.

---

## 🛠️ Concepts & Technologies

* **Language**: C 
* **Data Structures**: 2D Arrays (`double Matrix[MAX_DIM][MAX_DIM]`, where `MAX_DIM = 10`)
* **Key Programming Concepts**: 
  * Modular function design
  * Safe string and number parsing (`fgets`, `strtol`, `sscanf`)
  * Defensive programming against malformed user input

---

## ⚙️ Getting Started

### Prerequisites
Ensure you have a C compiler installed on your system (such as `gcc`, `clang`, or MinGW for Windows).

### Compilation
Clone or download the repository, open your terminal in the project directory, and compile the source code:

```bash
gcc matrix_operations.c -o matrix
./matrix
matrix.exe
============== MATRIX OPERATIONS ==============
 1. Addition
 2. Multiplication
 3. Transpose
 4. Exit
Enter your choice:
Select an operation by entering the corresponding number (1 through 4).

Specify dimensions for Matrix A (up to 10 × 10).

Input elements when prompted. The program handles row and column indexing cleanly.

View the formatted output matrix directly in your console.
📜 License
This project is open-source and available under the MIT License.
