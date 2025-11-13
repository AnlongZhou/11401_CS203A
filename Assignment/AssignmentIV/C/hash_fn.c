/*
   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/12: Initial implementation
    - 2025/11/13: Enhanced string hash function and exception handling.

    TODO: Enhance Integer Hash Function.
    TODO: Collision handling.

   Developer: Yu-Teng Zhou
 */
#include <stdio.h>
#include <string.h>

/*
 * @brief: Hash function for integer keys
 * @param: key - the integer key to be hashed
 * @param: m - the size of the hash table
 * @return: the hash value for the given key
 */
int my_hash_int(int key, int m) {

    if (m <= 0) {
        fprintf(stderr, "Error: Table size must be greater than 0.\n");
        return -1;
    }

    unsigned long hash = key;
    const long hash_constant =
        2654435761; // From Knuth’s multiplicative hashing (golden ratio).

    hash *= hash_constant;

    return (int)(hash % m);
}

/*
 * @brief: Hash function for string keys
 * @param: str - the string key to be hashed
 * @param: m - the size of the hash table
 * @return: the hash value for the given key
 */
int my_hash_string(const char *str, int m) {

    if (m <= 0) {
        fprintf(stderr, "Error: Table size must be greater than 0.\n");
        return -1;
    }

    if (str == NULL) {
        return 0;
    }

    //Implementing DJB2 hash function by Daniel J. Bernstein
    unsigned long hash = 5381;

    for (int i = 0; i < strlen(str); i++) {
        hash = ((hash << 5) + hash) + (unsigned char)str[i]; // hash * 33 + c
    }

    return (int)(hash % m);
}
