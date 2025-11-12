/*
   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/12: Initial implementation

   Developer: Yu-Teng Zhou
 */
#include <stdio.h>

/*
 * @brief: Hash function for integer keys
 * @param: key - the integer key to be hashed
 * @param: m - the size of the hash table
 * @return: the hash value for the given key
 */
int my_hash_int(int key, int m) {
    // TODO: implement hash function
    return key % m; 
}

/*
 * @brief: Hash function for string keys
 * @param: str - the string key to be hashed
 * @param: m - the size of the hash table
 * @return: the hash value for the given key
 */
int my_hash_string(const char *str, int m) {
    // TODO: implement hash function
    unsigned long hash = 0;
    return (int)(hash % m);
}
