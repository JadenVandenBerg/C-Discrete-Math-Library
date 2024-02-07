## Combinations

### Structure Defenition
```
typedef struct {
    void * data;
    int type;
    int length;
} CN_combination;
```
type:
    - 0: int

    Support for more coming soon!

### Functions

```
/**
 * This function creates a new combination
 *
 * @param length How long the data is in terms of elements (not bytes)
 * @param args An array of elements
 * @param type The datatypes index
 * @return The new combination
 */
CN_combination * CN_newCombination(int length, void * args, int type);

/**
 * This function prints a combination
 *
 * @param combination The combination to print
 */
void CN_printCombination(CN_combination * combination);

/**
 * This function gets an array of all subCombinations
 *
 * @param combination The parent combination
 * @param length A pass-by-reference value that is be the length of the return value
 * @return An array of combinations
 */
CN_combination ** CN_findSubcombinations(CN_combination * combination, int * length);

/**
 * This function converts a permutation to a combination
 *
 * @param permutation The permutation to convert (WARNING: NOT freed)
 * @return A combination that has the same data as the permutation
 */
CN_combination * CN_permutationToCombination(PM_permutation * permutation);

/**
 * This function finds the next combination in lexicographic order
 *
 * @param parentCombination A combination containing every allowed number
 * @param currentCombination The combination you want to find the next one after
 * @return A combination that has the same data as the permutation
 */
CN_combination * CN_findNextCombination(CN_combination * parentCombination, CN_combination * currentCombination);

/**
 * This function frees a combination
 *
 * @param combination The combination to free
 */
void CN_freeCombination(CN_combination * combination);
```