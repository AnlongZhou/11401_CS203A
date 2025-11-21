# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: [周育騰](https://github.com/AnlongZhou)
Email: [s1133518@mail.yzu.edu.tw](mailto:s1133518@mail.yzu.edu.tw)

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
    unsigned long hash = key;
    const long hash_constant = 2654435761;

    hash *= hash_constant;

    return (int)(hash % m);
    ```
- Rationale: Implementing *Knuth’s multiplicative hashing* . It use a constant derived from the Golden Ratio (ϕ). Because ϕ is the *most irrational number* , this constant creates a hash distribution that is most resistant to clustering, ensuring data is spread evenly across the table.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  unsigned long hash = 5381;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return (int)(hash % m);
  ```
- Rationale: Implementing *DJB2* (created by Daniel Julius Bernstein). It uses the prime number 5381, which has a *noisy* binary pattern, to initialize hash. By multiplying by 33 (implemented efficiently as(hash << 5) + hash), it spread the influence of every character to the final hash value.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- Command for C:
  ```bash
  gcc -std=c23 -o hash_function.o main.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++14 -o hash_function_cpp.o main.cpp
  ```

### Make Binary
- Use the following `Makefile` to automate the build process:
  ```makefile
  all:
      gcc -std=c23 -o hash_function.o main.c
      g++ -std=c++23 -o hash_function_cpp.o main.cpp
  clean:
      rm -f hash_function.o hash_function_cpp.o
  ```

### Execution
- Run the compiled binary:
  ```bash
  ./hash_function.o
  ```
  or
  ```bash
  ./hash_function_cpp.o
  ```

### Result Snapshot
- Example output:
  ```
  
    === Hash Function Observation (C Version) ===

    === Table Size m = 10 ===
    Key     Index
    -----------------
    21      1
    22      2
    23      3
    24      4
    25      5
    26      6
    27      7
    28      8
    29      9
    30      0
    51      1
    52      2
    53      3
    54      4
    55      5
    56      6
    57      7
    58      8
    59      9
    60      0

    === Table Size m = 11 ===
    Key     Index
    -----------------
    21      1
    22      0
    23      10
    24      9
    25      8
    26      7
    27      6
    28      5
    29      4
    30      3
    51      4
    52      3
    53      2
    54      1
    55      0
    56      10
    57      9
    58      8
    59      7
    60      6

    === Table Size m = 37 ===
    Key     Index
    -----------------
    21      5
    22      7
    23      9
    24      11
    25      13
    26      15
    27      17
    28      19
    29      21
    30      23
    51      28
    52      30
    53      32
    54      34
    55      36
    56      1
    57      3
    58      5
    59      7
    60      9

    === Hash Function Observation (C++ Version) ===

    === Table Size m = 10 ===
    Key     Index
    -----------------
    21      1
    22      2
    23      3
    24      4
    25      5
    26      6
    27      7
    28      8
    29      9
    30      0
    51      1
    52      2
    53      3
    54      4
    55      5
    56      6
    57      7
    58      8
    59      9
    60      0

    === Table Size m = 11 ===
    Key     Index
    -----------------
    21      1
    22      0
    23      10
    24      9
    25      8
    26      7
    27      6
    28      5
    29      4
    30      3
    51      4
    52      3
    53      2
    54      1
    55      0
    56      10
    57      9
    58      8
    59      7
    60      6

    === Table Size m = 37 ===
    Key     Index
    -----------------
    21      5
    22      7
    23      9
    24      11
    25      13
    26      15
    27      17
    28      19
    29      21
    30      23
    51      28
    52      30
    53      32
    54      34
    55      36
    56      1
    57      3
    58      5
    59      7
    60      9

    ```

- Example output for strings:
  ```
    === Hash Function Observation (C Version) ===

    === String Hash (m = 10) ===
    Key     Index
    -----------------
    cat     5
    dog     3
    bat     6
    cow     0
    ant     6
    owl     1
    bee     3
    hen     6
    pig     3
    fox     8

    === String Hash (m = 11) ===
    Key     Index
    -----------------
    cat     6
    dog     4
    bat     6
    cow     9
    ant     6
    owl     9
    bee     2
    hen     0
    pig     4
    fox     10

    === String Hash (m = 37) ===
    Key     Index
    -----------------
    cat     29
    dog     13
    bat     13
    cow     13
    ant     19
    owl     14
    bee     19
    hen     13
    pig     7
    fox     25

    === Hash Function Observation (C++ Version) ===

    === String Hash (m = 10) ===
    Key     Index
    -----------------
    cat     5
    dog     3
    bat     6
    cow     0
    ant     6
    owl     1
    bee     3
    hen     6
    pig     3
    fox     8

    === String Hash (m = 11) ===
    Key     Index
    -----------------
    cat     6
    dog     4
    bat     6
    cow     9
    ant     6
    owl     9
    bee     2
    hen     0
    pig     4
    fox     10

    === String Hash (m = 37) ===
    Key     Index
    -----------------
    cat     29
    dog     13
    bat     13
    cow     13
    ant     19
    owl     14
    bee     19
    hen     13
    pig     7
    fox     25

  ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```
- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.
