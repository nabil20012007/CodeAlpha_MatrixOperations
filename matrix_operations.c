/*
 * ============================================================================
 *  CodeAlpha C Programming Internship - Task 2 : Matrix Operations
 * ============================================================================
 *  Operations : Addition | Multiplication | Transpose   (menu driven)
 *  Concepts   : functions, 2D arrays, input validation
 *  Design     : the size of matrix B is derived from matrix A, so incompatible
 *               dimensions can never be entered.
 *
 *  Run        : ./matrix         (Windows: matrix.exe)
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 10                              /* max rows / columns */

typedef double Matrix[MAX_DIM][MAX_DIM];

/* ------------------------------ Input helpers ------------------------------ */

/* Prompts and reads one line safely: handles EOF and discards over-long input. */
static void readLine(const char *prompt, char *buf, int size) {
    printf("%s", prompt);
    fflush(stdout);
    if (!fgets(buf, size, stdin)) { puts(""); exit(EXIT_SUCCESS); }
    if (!strchr(buf, '\n')) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
    buf[strcspn(buf, "\n")] = '\0';
}

/* Reads an integer in [min, max], re-prompting until the input is valid. */
static int readInt(const char *prompt, int min, int max) {
    char buf[32], *end;
    for (;;) {
        readLine(prompt, buf, sizeof buf);
        long v = strtol(buf, &end, 10);
        if (end != buf && *end == '\0' && v >= min && v <= max) return (int)v;
        printf("  Please enter a number between %d and %d.\n", min, max);
    }
}

/* Reads a real number, re-prompting until the input is valid. */
static double readNumber(const char *prompt) {
    char buf[64], junk;
    double v;
    for (;;) {
        readLine(prompt, buf, sizeof buf);
        if (sscanf(buf, "%lf %c", &v, &junk) == 1) return v;
        puts("  Invalid number, please try again.");
    }
}

/* ----------------------------- Matrix functions ---------------------------- */

static void readMatrix(const char *name, Matrix m, int rows, int cols) {
    char prompt[32];
    printf("Enter the elements of matrix %s (%d x %d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            snprintf(prompt, sizeof prompt, "  %s[%d][%d] = ", name, i + 1, j + 1);
            m[i][j] = readNumber(prompt);
        }
}

static void printMatrix(const char *title, Matrix m, int rows, int cols) {
    printf("\n%s  (%d x %d)\n", title, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) printf("%10g", m[i][j]);
        putchar('\n');
    }
}

/* out = a + b        (all matrices are rows x cols) */
static void addMatrices(Matrix a, Matrix b, Matrix out, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) out[i][j] = a[i][j] + b[i][j];
}

/* out = a x b        (a is r x n, b is n x c, out is r x c) */
static void multiplyMatrices(Matrix a, Matrix b, Matrix out, int r, int n, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            out[i][j] = 0;
            for (int k = 0; k < n; k++) out[i][j] += a[i][k] * b[k][j];
        }
}

/* out = transpose of a   (a is rows x cols, out is cols x rows) */
static void transposeMatrix(Matrix a, Matrix out, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) out[j][i] = a[i][j];
}

/* ---------------------------------- Main ----------------------------------- */

int main(void) {
    for (;;) {
        puts("\n============== MATRIX OPERATIONS ==============");
        puts(" 1. Addition\n 2. Multiplication\n 3. Transpose\n 4. Exit");

        int choice = readInt("Enter your choice: ", 1, 4);
        if (choice == 4) break;

        Matrix a, b, result;
        int r = readInt("Rows of A    : ", 1, MAX_DIM);
        int c = readInt("Columns of A : ", 1, MAX_DIM);
        readMatrix("A", a, r, c);

        switch (choice) {
            case 1:                                     /* B must match A's size */
                readMatrix("B", b, r, c);
                addMatrices(a, b, result, r, c);
                printMatrix("A + B", result, r, c);
                break;
            case 2: {                                   /* B must be (cols of A) x c2 */
                printf("Matrix B must have %d row(s).\n", c);
                int c2 = readInt("Columns of B : ", 1, MAX_DIM);
                readMatrix("B", b, c, c2);
                multiplyMatrices(a, b, result, r, c, c2);
                printMatrix("A x B", result, r, c2);
                break;
            }
            case 3:
                transposeMatrix(a, result, r, c);
                printMatrix("Transpose of A", result, c, r);
                break;
        }
    }
    puts("Goodbye!");
    return EXIT_SUCCESS;
}
