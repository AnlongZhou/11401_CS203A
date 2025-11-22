# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

- Developer: [周育騰](https://github.com/AnlongZhou)
- Email: [s1133518@mail.yzu.edu.tw](mailto:s1133518@mail.yzu.edu.tw)
- Environment: Linux (Ubuntu 24.04)

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
  ```text
    unsigned long hash = key;
    const long hash_constant = 2654435761;

    hash *= hash_constant;

    return (int)(hash % m);
    ```
- Rationale: Implementing **Knuth’s multiplicative hashing** . It use a constant derived from the Golden Ratio (ϕ). Because ϕ is the **most irrational number** , this constant creates a hash distribution that is most resistant to clustering, ensuring data is spread evenly across the table.

### Non-integer Keys
- Formula / pseudocode:
  ```text
  unsigned long hash = 5381;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }

    return (int)(hash % m);
  ```
- Rationale: Implementing **DJB2** (created by Daniel Julius Bernstein). It uses the prime number 5381, which has a **noisy** binary pattern, to initialize hash. By multiplying by 33 (implemented efficiently as(hash << 5) + hash), it spread the influence of every character to the final hash value.

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
  - Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
  - Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Step size | Observation         |
|----------------|------------------------|-----------|---------------------|
| 10             | 1, 2, 3, 4, ...        |    +1     | In sequence         |
| 11             | 1, 0, 10, 9, ...       |    -1     | More scattered      |
| 37             | 5, 9, 11, 13, ...      |    +2     | More scattered      |

## Compilation, Build, Execution, and Output

### Compilation
- Command for C:
  ```bash
  gcc -std=c23 -o hash_function.o main.c
  ```
- Command for C++:
  ```bash
  g++ -std=c++23 -o hash_function_cpp.o main.cpp
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

  <img width="677" height="1282" alt="Image" src="https://github.com/user-attachments/assets/8c654b1c-2d85-48bd-add4-c31d8a81e15c" />
  <img width="589" height="718" alt="Image" src="https://github.com/user-attachments/assets/a4f9685c-06e9-477c-97b2-433310f54e91" />
  <img width="686" height="1251" alt="Image" src="https://github.com/user-attachments/assets/8a0c690b-80c0-41a3-b1c3-fec5a355c8a3" />
  <img width="589" height="718" alt="Image" src="https://github.com/user-attachments/assets/a4f9685c-06e9-477c-97b2-433310f54e91" />

- Example output for integers:
  ```
  Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
  Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
  ```

- Observations: When `m = 10`, the indices form a sequential result of keys, causing **Primary Clustering**. But for the prime table sizes `m = 11` and `m = 37`, keys result in more random numbers.

- Example output for strings:
  ```
  Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
  Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
  Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
  ```
- Observations: The testing data revealed a critical failure case at Table Size `m = 11`, where the hash index was determined solely by the last letter of the input string (e.g., "cat" and "bat" collided).

## Analysis
- **Mathematical Resonance**: The catastrophic failure at `m = 11` proved that if the table size divides the hash multiplier `33`, the modular arithmetic cancels out string history, resulting in collisions based solely on the last character.
- **Structural Distribution**: The comparison between `m = 10` and `m = 37` demonstrated that prime table sizes are essential to introduce **stride** (gaps) between sequential inputs, effectively breaking the linear clustering chains caused by composite numbers.
- **Input Sensitivity**: The unexpected collisions with short strings (e.g., at `m = 37`) revealed that the DJB2 algorithm requires a minimum input length to generate a sufficient **avalanche effect**, otherwise the output remains too correlated to the raw ASCII values.

## Reflection
1. The experiment demonstrated that lightweight algorithms like DJB2 **_trade some collision resistance for speed_**, requiring the engineer to manually ensure that the constants do not resonate with the table dimensions.
2. The hash multiplier and table size must be **_coprime_** to ensure that the modular arithmetic preserves the history of the input string.
3. Comparing the linear clustering at m=10 versus the gaps at m=37 highlighted that **_prime table_** sizes are mechanically necessary to introduce non-sequential strides that break up collision chains.
