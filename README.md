# Jaden's C Library
```

/*
* Library Helper Functions
*/
void * LIB_permutationToArray(PM_permutation * permutation);
int LIB_findHighestInSet(int * arr, int arrLength);
int LIB_findSmallestInSet(int * arr, int arrLength);

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
* Permutation
*/
PM_permutation * PM_combinationToPermutation(CN_combination * combination);
void PM_printPermutation(PM_permutation * permutation);
void PM_freePermutation(PM_permutation * permutation);
PM_permutation * PM_newPermutation(int length, void * args, int type);
PM_permutation * PM_sortPermutation(PM_permutation * permutation, int sortOrder); //0: Asc 1: Dec
```