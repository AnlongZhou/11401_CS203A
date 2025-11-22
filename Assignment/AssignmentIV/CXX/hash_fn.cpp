/*
   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/12: Initial implementation
    - 2025/11/13: Enhanced string hash function and exception handling.


   Developer: Yu-Teng Zhou
 */
#include <iostream>
#include <string>

/*
 * @brief: Hash function for integer keys
 * @param: key - the integer key to be hashed
 * @param: m - the size of the hash table
 * @return: the hash value for the given key
 */
int myHashInt(int key, int m) {

    if (m <= 0) {
        std::cerr << "Error: Table size must be greater than 0." << std::endl;
        return -1;
    }

    unsigned long hash = key;
    const long hash_constant = 2654435761;
    // From Knuth’s multiplicative hashing (golden ratio).

    hash *= hash_constant;

    return (int)(hash % m);
}

/*
 * @brief: Hash function for string keys
 * @param: str - the string key to be hashed
 * @param: m - the size of the hash table
 * @return: the hash value for the given key
 */
int myHashString(const std::string &str, int m) {

    if (m <= 0) {
        std::cerr << "Error: Table size must be greater than 0." << std::endl;
        return -1;
    }

    if (str.empty()) {
        return 0;
    }

    // Implementing DJB2 hash function by Daniel J. Bernstein
    unsigned long hash = 5381;

    for (unsigned char c : str) {
        hash = ((hash << 5) + hash) + c;
        // hash * 33 + c (using bitwise operation for efficiency)
    }

    return (int)(hash % m);
}
