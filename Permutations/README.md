## Permutations

### Structure Defenition
```
typedef struct {
    void * data;
    int type;
    int length;
} PM_permutation;
```
type:
    - 0: int

    Support for more coming soon!

### Functions

```
/**
 * This function converts a permutation to a combination
 *
 * @param combination The combination to convert
 * @return A permutation with the same data as the combination
 */
PM_permutation * PM_combinationToPermutation(CN_combination * combination);

/**
 * This function prints a permutation
 *
 * @param permutation The permutation to print
 * @return void
 */
void PM_printPermutation(PM_permutation * permutation);

/**
 * This function frees a permutation
 *
 * @param permutation The permutation to free
 * @return void
 */
void PM_freePermutation(PM_permutation * permutation);

/**
 * This function creates a new permutation
 *
 * @param length The length of the permutation in elements (Not bytes)
 * @param args An array of elements to add to the permutation
 * @param type The datatype index of the elements
 * @return A new permutation of length length with args as the data
 */
PM_permutation * PM_newPermutation(int length, void * args, int type);

/**
 * This function creates a new permutation
 *
 * @param permutation The permutation to be sorted
 * @param sortOrder The order in which to sort
    * 0: Ascending
    * 1: Descending
 * @return The same permutation that was passed. Data changed via pass by reference
 */
PM_permutation * PM_sortPermutation(PM_permutation * permutation, int sortOrder);
```