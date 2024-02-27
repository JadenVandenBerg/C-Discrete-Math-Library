#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    void * data;
    void * next;
} LL_node;

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

typedef struct {
    void * data;
    int length;
    int type;
} VE_vector;

typedef struct matrix {
    int cols;
    int rows;
    void * data;
    int type;
} MA_matrix;

/*
* Library Helper Functions
*/
int LIB_sizeofType(int type);
int LIB_compareAsc(const void *a, const void *b);
int LIB_compareDec(const void *a, const void *b);
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
LL_node * LL_createLL(void * data);
LL_node * LL_createLLNode(void * data);
LL_node * LL_appendLLNode(LL_node * head, LL_node * node);
LL_node * LL_prependLLNode(LL_node ** head, LL_node * node);
void LL_freeLL(LL_node * head);
void LL_freeLLWithIterator(LL_node * head, void(*freeFunction)(void *));
void LL_iterator(LL_node * head, void(*iterator)(void *));

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
PM_permutation * PM_findNextPermutation(PM_permutation * parentPermutation, PM_permutation * currentPermutation);
PM_permutation ** PM_findSubPermutations(PM_permutation * permutation, int * length);

/*
* Vector
*/


//Undocumented
PM_permutation * PM_findNextPermutation(PM_permutation * parentPermutation, PM_permutation * currentPermutation);
PM_permutation ** PM_findSubPermutations(PM_permutation * permutation, int * length);
VE_vector * VE_newVector(int length,  void * data, int type);
VE_vector * VE_addVectors(VE_vector * v1, VE_vector * v2);
VE_vector * VE_scalarMultiply(VE_vector * vector, int scalar);
void VE_printVector(VE_vector * vector);
void * VE_dotProduct(VE_vector * v1, VE_vector * v2);
VE_vector * VE_crossProduct(VE_vector * v1, VE_vector * v2);
double VE_vectorLength(VE_vector * vector);
int square(int num);
VE_vector * VE_normalizeVector(VE_vector * vector);
