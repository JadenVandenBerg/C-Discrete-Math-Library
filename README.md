# Jaden's C Library

## Linked Lists

### Structure Defenition
```
typedef struct {
    void * data;
    void * next;
} LL_node;
```

### Functions

```
/**
 * This function creates a new linked list
 *
 * @param data The data to add to the node
 * @return LL_node * which acts as the head
 */
LL_node * LL_createLL(void * data);

/**
 * This function creates a new linked list node
 *
 * @param data The data to add to the node
 * @return LL_node * (new node)
 */
LL_node * LL_createLLNode(void * data);

/**
 * This function appends a node to the end of a linked list referred to by head
 *
 * @param head A pointer that points to some node in the list (does not have to be the first)
 * @param node A pointer to the LL_node to add
 * @return LL_node * (head)
 */
LL_node * LL_appendLLNode(LL_node * head, LL_node * node);

/**
 * This function prepends a node to the start of a linked list referred to by head
 *
 * @param head A pointer that points to head (must be the first element)
 * @param node A pointer to the LL_node to add
 * @return LL_node * (The new head)
 */
LL_node * LL_prependLLNode(LL_node ** head, LL_node * node);

/**
 * This function frees the linked list
 *
 * @param head A pointer that points to head
 */
void LL_freeLL(LL_node * head);

/**
 * This function frees the linked list, calling freeFunction on LL_node->data every iteration
 * Use if you have a secondary data structure that requires freeing inside LL_node->data
 *
 * @param head A pointer that points to head
 * @param freeFunction A function pointer to the freeing handling function
 */
void LL_freeLLWithIterator(LL_node * head, void(*freeFunction)(void *));

/**
 * This function calls iterator on every element in the linked list
 *
 * @param head A pointer that points to head
 * @param freeFunction A function pointer to the freeing handling function
 */
void LL_iterator(LL_node * head, void(*iterator)(void *));
```

/*
* Types
*
* 0: Int
*/
typedef struct {
    void * data;
    int type;
    int length;
} CN_combination;

typedef struct {
    void * data;
    int type;
    int length;
} PM_permutation;

/*
* Library Helper Functions
*/
int LIB_sizeofType(int type);
int LIB_compare(const void *a, const void *b);
void * LIB_permutationToArray(PM_permutation * permutation);
int LIB_rightmostIncrementableIndex(CN_combination * allNumbers, PM_permutation * current, int * incrementTo);
int LIB_findNextHighestInSet(int * arr, int arrLength, int num, int * incrementTo);
int LIB_findHighestInSet(int * arr, int arrLength);
int LIB_findSmallestInSet(int * arr, int arrLength);
int * LIB_findAllowedNumbersNotInPermutation(CN_combination * allNumbers, PM_permutation * current, int * lengthFound);

/*
* QOL
*/
void * memdup(void ** dest, const void * src, size_t n);
void free2DArray(void ** array, int numRows);
void print(char * string);

/*
* Algorithms
*/
char * integerToString(unsigned long long int integer);
char digitToChar(int digit);
char * reverseString(char * string);

/*
* Linked List
*/


/*
* Combination
*/
CN_combination * CN_newCombination(int length, void * args, int type);
CN_combination * CN_removeDuplicates(CN_combination * combinaton);
void CN_printCombination(CN_combination * combination);
CN_combination ** CN_findSubcombinations(CN_combination * combination, int * length);
CN_combination * CN_permutationToCombination(PM_permutation * permutation);
CN_combination * CN_findNextCombination(CN_combination * parentCombination, CN_combination * currentCombination);
void CN_freeCombination(CN_combination * combination);

/*
* Permutation
*/
PM_permutation * PM_combinationToPermutation(CN_combination * combination);
void PM_printPermutation(PM_permutation * permutation);
void PM_freePermutation(PM_permutation * permutation);
PM_permutation * PM_newPermutation(int length, void * args, int type);
PM_permutation * PM_sortPermutation(PM_permutation * permutation, int sortOrder); //0: Asc 1: Dec