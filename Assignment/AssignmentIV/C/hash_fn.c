/*
   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/12: Initial implementation
    TODO: Enhance Integer Hash Function.
    TODO: Enchance String Hash Function.
    TODO: More error handling.


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

    unsigned long hash = 0;
    char first_char, last_char;

    if (str == NULL) {
        return 0;
    }

    int length = strlen(str);
    first_char = str[0];
    last_char = str[length - 1];

    hash += (int)first_char;
    hash += (int)last_char;

    return (int)(hash % m);
}
