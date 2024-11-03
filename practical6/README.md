# this is practical6
# Explanation
- **matmult.c**: Defines the `matmult` function, which initializes matrix C to zero and performs matrix multiplication.

- **main.c**: Initializes matrices A and B according to the rules 
  \[
  A[i][j] = i + j
  \]
  and 
  \[
  B[i][j] = i - j,
  \]
  calls `matmult`, and prints all three matrices.

- **Makefile**: Specifies how to compile the program and links `main.c` and `matmult.c` into the final executable.
