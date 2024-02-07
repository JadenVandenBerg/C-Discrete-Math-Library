## General Algorithms
```
/**
 * This function finds the highest value in an integer array
 *
 * @param arr The array to search
 * @param arr The length of the array
 * @return The highest integer
 */
int LIB_findHighestInSet(int * arr, int arrLength);

/**
 * This function finds the lowest value in an integer array
 *
 * @param arr The array to search
 * @param arr The length of the array
 * @return The lowest integer
 */
int LIB_findSmallestInSet(int * arr, int arrLength);

/**
 * This function reverses a string
 *
 * @param string The string to reverse
 * @return The reversed string
 */
char * reverseString(char * string);
```
## Conversions
```
/**
 * This function converts a permutation to an array
 *
 * @param permutation The permutation to convert
 * @return An array containing the data of the permutation
 */
void * LIB_permutationToArray(PM_permutation * permutation);

/**
 * This function converts an integer to a string
 *
 * @param integer The integer to convert
 * @return The resulting string
 */
char * integerToString(unsigned long long int integer);

/**
 * This function converts an digit to a char
 *
 * @param digit The digit to convert (0-9)
 * @return The resulting char
 */
char digitToChar(int digit);
```
## Quality of Life Functions
```
/**
 * This function allocates memory for n bytes and copies them to (*dest)
 *
 * @param dest A double pointer to the destination
 * @param src The source
 * @param n Number of bytes to copy
 * @return A pointer to dest
 */
void * memdup(void ** dest, const void * src, size_t n);

/**
 * This function frees a 2D array
 *
 * @param array The array to free
 * @param numRows The number of rows in the 2D array
 * @return void
 */
void free2DArray(void ** array, int numRows);

/**
 * This function prints a string
 *
 * @param string String to print
 * @return void
 */
void print(char * string);
```