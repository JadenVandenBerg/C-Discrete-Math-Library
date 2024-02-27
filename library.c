#include "library.h"

void * memdup(void ** dest, const void * src, size_t n) {
    *dest = malloc(n);

    if (dest == NULL) {
        return NULL;
    }

    return memcpy(*dest, src, n);
}

void free2DArray(void ** array, int numRows) {
    for (int i = 0; i < numRows; i++) {
        free(array[i]);
    }

    free(array);
}

char * integerToString(unsigned long long int integer) {
    int lastDigit = 0;
    char * string = malloc(sizeof(char) + 1);

    if (integer == 0) {
        string[0] = '0';
        string[0] = '\0';

        return string;
    }

    int numDigits = 0;
    while (integer != 0)
    {
        lastDigit = integer % 10;
        integer = integer / 10;

        numDigits++;
        string = realloc(string, sizeof(char) * numDigits + 1);
        string[numDigits - 1] = digitToChar(lastDigit);
    }

    string[numDigits] = '\0';
    return reverseString(string);
}

char digitToChar(int digit) {
    return digit + '0';
}

char * reverseString(char * string) {
    int length = strlen(string);

    char * reversed = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        reversed[i] = string[length - i - 1];
    }

    reversed[length] = '\0';

    free(string);
    return reversed;
}

void print(char * string) {
    printf(string);
}

LL_node * LL_createLL(void * data) {
    return LL_createLLNode(data);
}

LL_node * LL_createLLNode(void * data) {
    LL_node * node = malloc(sizeof(LL_node));
    node->data = data;
    node->next = NULL;

    return node;
}

LL_node * LL_prependLLNode(LL_node ** head, LL_node * node) {
    LL_node * temp = *head;
    *head = node;

    (*head)->next = temp;

    return *head;
}

LL_node * LL_appendLLNode(LL_node * head, LL_node * node) {
    LL_node * headSave = head;
    LL_node * temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;

    return headSave;
}

void LL_freeLL(LL_node * head) {
    LL_node * temp = head;

    while(temp != NULL) {
        LL_node * temp2 = temp;
        temp2 = temp->next;

        free(temp->data);
        free(temp);

        temp = temp2;
    }
}

void LL_freeLLWithIterator(LL_node * head, void(*freeFunction)(void *)) {
    LL_node * temp = head;

    while(temp != NULL) {
        LL_node * temp2 = temp;
        temp2 = temp->next;

        freeFunction(temp->data);
        free(temp);

        temp = temp2;
    }
}

void LL_iterator(LL_node * head, void(*iterator)(void *)) {
    while (head != NULL)
    {
        iterator(head);
        head = head->next;
    }
}

CN_combination * CN_newCombination(int length, void * args, int type) {
    CN_combination * newCombination = (CN_combination *) malloc(sizeof(CN_combination));

    if (type == 0) {
        newCombination->type = 0;
        newCombination->length = length;
        newCombination->data = (int *) malloc(sizeof(int) * length);

        for (int i = 0; i < length; i++) {
            ((int *)newCombination->data)[i] = ((int *)args)[i];
        }
    }
    else {
        return NULL;
    }

    return CN_removeDuplicates(newCombination);
}

void CN_printCombination(CN_combination * combination) {
    if (combination == NULL || combination->data == NULL || combination->length == 0) {
        print("\n{}");
        return;
    }

    printf("\n{");
    for (int i = 0; i < combination->length; i++) {
        if (i == combination->length - 1) {
            printf("%d", (int) ((int *)combination->data)[i]);
        }
        else {
            printf("%d,", (int) ((int *)combination->data)[i]);
        }

    }
    printf("}");
}

int LIB_sizeofType(int type) {
    if (type == 0) {
        return sizeof(int);
    }

    return -1;
}

CN_combination * CN_removeDuplicates(CN_combination * combination) {
    int duplicatesFound = 0;

    if (combination->type == 0) {
        int dataLen = 0;
        int * data = malloc(sizeof(int));
        int found = 1;

        for (int i = 0; i < combination->length; i++) {
            for(int j = 0; j < dataLen; j++) {
                if ((int) ((int *)combination->data)[i] == data[j]) {
                    duplicatesFound++;
                    found = 0;

                    continue;
                }
            }

            if (found == 1) {
                dataLen++;
                data = realloc(data, sizeof(int) * dataLen);
                data[dataLen - 1] = (int)((int *)combination->data)[i];
            }

            found = 1;
        }

        free(combination->data);
        combination->data = (void *)data;
    }

    combination->length -= duplicatesFound;
    return combination;
}

void CN_freeCombination(CN_combination * combination) {
    free(combination->data);
    free(combination);
}

CN_combination ** CN_findSubcombinations(CN_combination * combination, int * length) {
    if (combination == NULL) {
        return NULL;
    }

    CN_combination ** allSubCombinations = malloc(sizeof(CN_combination));
    *length = 0;

    int * data = LIB_permutationToArray(PM_combinationToPermutation(combination));
    int smallest = LIB_findSmallestInSet(data, combination->length);

    int * firstCombinationData = malloc(sizeof(int));
    firstCombinationData[0] = smallest;

    CN_combination * nextCombination = CN_newCombination(1, firstCombinationData, 0);
    allSubCombinations[*length] = nextCombination;
    (*length)++;

    while (nextCombination != NULL) {
        nextCombination = CN_findNextCombination(combination, nextCombination);
        allSubCombinations = realloc(allSubCombinations, sizeof(CN_combination) * (*length) + 1);
        allSubCombinations[*length] = nextCombination;

        (*length)++;
    }

    return allSubCombinations;
}

int LIB_findSmallestInSet(int * arr, int arrLength) {
    int lowest = arr[0];
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }

    return lowest;
}

CN_combination * CN_findNextCombination(CN_combination * parentCombination, CN_combination * currentCombination) {
    PM_permutation * permutation = PM_combinationToPermutation(currentCombination);

    int incrementTo = 0;
    int idx = LIB_rightmostIncrementableIndex(parentCombination, permutation, &incrementTo);

    PM_permutation * sorted = PM_combinationToPermutation(parentCombination);
    PM_sortPermutation(sorted, 0);

    if (idx == -1 && currentCombination->length == parentCombination->length) {
        return NULL;
    }
    else if (idx == -1) {
        int * data = malloc(sizeof(int) * (currentCombination->length + 1));
        for (int i = 0; i < (currentCombination->length + 1); i++) {
            data[i] = (int) ((int*)(sorted->data))[i];
        }

        return CN_newCombination(currentCombination->length + 1, data, 0);

    } else {
        ((int *) (permutation->data))[idx] = incrementTo;

        int * arr = (int *) LIB_permutationToArray(sorted);
        int index = idx;
        for (int i = 0; i < permutation->length - index - 1; i++) {
            for (int j = 0; j < sorted->length; j++) {
                int number = arr[j];
                int invalid = 0;
                for (int k = 0; k < idx + 1; k++) {
                    if (number == (int) ((int *) (permutation->data))[k]) {
                        invalid = 1;
                        break;
                    }
                }

                if (!invalid) {
                    ((int *) (permutation->data))[idx + 1] = number;
                    idx++;
                    break;
                }
            }
        }

        free(arr);
    }

    return CN_permutationToCombination(permutation);
}

int LIB_rightmostIncrementableIndex(CN_combination * allNumbers, PM_permutation * current, int * incrementTo) {
    int * arr = (int *) LIB_permutationToArray(current);
    int len = current->length;

    int num = 0;
    int * allowedNumbersNotInPermutation = LIB_findAllowedNumbersNotInPermutation(allNumbers, current, &num);

    int valid = -1;
    int returnVal = -1;
    for (int i = len - 1; i >= 0; i--) {
        valid = LIB_findNextHighestInSet(allowedNumbersNotInPermutation, num, arr[i], incrementTo);

        if (valid != -1) {
            returnVal = i;
            break;
        }
    }

    return returnVal;
}

int * LIB_findAllowedNumbersNotInPermutation(CN_combination * allNumbers, PM_permutation * current, int * lengthFound) {
    int * arr = (int *) LIB_permutationToArray(current);
    int * allowedNumbersNotInPermutation = malloc(sizeof(int));
    for (int i = 0; i < allNumbers->length; i++) {
        int found = 0;
        for (int j = 0; j < current->length; j++) {
            if (arr[j] == (int) ((int *)allNumbers->data)[i]) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            (*lengthFound)++;
            allowedNumbersNotInPermutation = realloc(allowedNumbersNotInPermutation, sizeof(int) * *lengthFound);
            allowedNumbersNotInPermutation[*lengthFound - 1] = (int) ((int *)allNumbers->data)[i];
        }
    }

    free(arr);

    return allowedNumbersNotInPermutation;
}

int LIB_findNextHighestInSet(int * arr, int arrLength, int num, int * incrementTo) {

    int highest = __INT_MAX__;
    int highestIdx = -1;
    int foundSoFar = -1;
    for (int i = 0; i < arrLength; i++) {
        if ((arr[i] > num && arr[i] < highest) || num >= highest) {
            if (num < highest) {
                foundSoFar = 1;
            }
            highest = arr[i];
            highestIdx = i;
        }
    }

    *incrementTo = highest;
    if (foundSoFar == -1) {
        return -1;
    }

    return highestIdx;
}

int LIB_findHighestInSet(int * arr, int arrLength) {
    int highest = arr[0];
    for (int i = 1; i < arrLength; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }

    return highest;
}

PM_permutation * PM_combinationToPermutation(CN_combination * combination) {
    PM_permutation * permutation = PM_newPermutation(combination->length, combination->data, 0);
    return permutation;
}

CN_combination * CN_permutationToCombination(PM_permutation * permutation) {
    CN_combination * combination = CN_newCombination(permutation->length, permutation->data, 0);
    return CN_removeDuplicates(combination);
}

void PM_freePermutation(PM_permutation * permutation) {
    free(permutation->data);
    free(permutation);
}

PM_permutation * PM_sortPermutation(PM_permutation * permutation, int sortOrder) {
    int * toSort = (int *) LIB_permutationToArray(permutation);

    if (sortOrder == 0) {
        qsort(toSort, permutation->length, sizeof(int), LIB_compareAsc);

        for (int i = 0; i < permutation->length; i++) {
            ((int *)(permutation->data))[i] = toSort[i];
        }
    }
    else {
        qsort(toSort, permutation->length, sizeof(int), LIB_compareDec);

        for (int i = 0; i < permutation->length; i++) {
            ((int *)(permutation->data))[i] = toSort[i];
        }
    }


    free(toSort);

    return permutation;
}

int LIB_compareAsc(const void *a, const void *b) {
    return (*(int*)a > *(int*)b);
}

int LIB_compareDec(const void *a, const void *b) {
    return (*(int*)a < *(int*)b);
}


void PM_printPermutation(PM_permutation * permutation) {
    if (permutation == NULL || permutation->data == NULL || permutation->length == 0) {
        print("\n()");
        return;
    }

    printf("\n(");
    for (int i = 0; i < permutation->length; i++) {
        if (i == permutation->length - 1) {
            printf("%d", (int) ((int *)permutation->data)[i]);
        }
        else {
            printf("%d,", (int) ((int *)permutation->data)[i]);
        }

    }
    printf(")");
}

PM_permutation * PM_newPermutation(int length, void * args, int type) {
    PM_permutation * newPermutation = (PM_permutation *) malloc(sizeof(PM_permutation));

    if (type == 0) {
        newPermutation->type = 0;
        newPermutation->length = length;
        newPermutation->data = (int *) malloc(sizeof(int) * length);

        for (int i = 0; i < length; i++) {
            ((int *)newPermutation->data)[i] = (int) ((int *)args)[i];
        }
    }
    else {
        return NULL;
    }

    return newPermutation;
}

void * LIB_permutationToArray(PM_permutation * permutation) {
    int * arr = malloc(LIB_sizeofType(permutation->type) * permutation->length);
    for (int i = 0; i < permutation->length; i++) {
        arr[i] = (int) ((int *)permutation->data)[i];
    }

    return arr;
}

PM_permutation * PM_findNextPermutation(PM_permutation * parentPermutation, PM_permutation * currentPermutation) {
    int * parentPermutationArr = LIB_permutationToArray(parentPermutation);
    int * currentPermutationArr = LIB_permutationToArray(currentPermutation);
    int highestP = LIB_findHighestInSet(parentPermutationArr, parentPermutation->length);

    int reallocA = 1;
    for (int i = 0; i < currentPermutation->length; i++) {
        if ((int) ((int *)currentPermutation->data)[i] != highestP) {
            reallocA = 0;
            break;
        }
    }

    int lowest = LIB_findSmallestInSet(parentPermutationArr, parentPermutation->length);
    if (reallocA && currentPermutation->length != parentPermutation->length) {
        int * newArr = malloc(sizeof(int) * (currentPermutation->length + 1));
        for (int i = 0; i < currentPermutation->length + 1; i++) {
            newArr[i] = lowest;
        }

        PM_permutation * newPermutation = PM_newPermutation(currentPermutation->length + 1, newArr, 0);
        return newPermutation;
    }
    else if (reallocA && currentPermutation->length == parentPermutation->length) {
        free(parentPermutationArr);
        return NULL;
    }

    for (int i = currentPermutation->length - 1; i >= 0; i--) {
        //printf("ITER %d", i);
        int num = (int) ((int *)currentPermutation->data)[i];
        if (num != highestP) {
            int nextL = 0;
            int next = LIB_findNextHighestInSet(parentPermutationArr, parentPermutation->length, num, &nextL);

            currentPermutationArr[i] = next;

            //printf("Changing index %d to %d", i, next);
            for (int j = i + 1; j < currentPermutation->length; j++) {
                currentPermutationArr[j] = lowest;
            }
            PM_permutation * newPermutation = PM_newPermutation(currentPermutation->length, currentPermutationArr, 0);
            return newPermutation;
        }
    }

    return NULL;
}

PM_permutation ** PM_findSubPermutations(PM_permutation * permutation, int * length) {
    if (permutation == NULL) {
        return NULL;
    }

    PM_permutation ** allSubPermutations = malloc(sizeof(PM_permutation));
    *length = 0;

    int * arr = LIB_permutationToArray(permutation);
    int smallest = LIB_findSmallestInSet(arr, permutation->length);
    int * arr2 = malloc(sizeof(int));
    arr2[0] = smallest;

    PM_permutation * startPermutation = PM_newPermutation(1, arr2, 0);
    (*length)++;
    allSubPermutations[0] = startPermutation;

    while (startPermutation != NULL) {
        startPermutation = PM_findNextPermutation(permutation, startPermutation);

        allSubPermutations = realloc(allSubPermutations, sizeof(PM_permutation) * (*length));
        allSubPermutations[*length] = startPermutation;
        (*length)++;
    }

    free(arr);
    return allSubPermutations;
}

VE_vector * VE_newVector(int length,  void * data, int type) {
    VE_vector * newVector = malloc(sizeof(VE_vector));

    newVector->length = length;
    newVector->data = data;
    newVector->type = type;

    return newVector;
}

VE_vector * VE_addVectors(VE_vector * v1, VE_vector * v2) {
    if (v1->length != v2->length) {
        return NULL;
    }

    int * data = malloc(sizeof(int) * v1->length);
    for (int i = 0; i < v1->length; i++) {
        data[i] = (int) ((int*)v1->data)[i] + (int) ((int*)v2->data)[i];
    }

    return VE_newVector(v1->length, data, 0);
}

VE_vector * VE_scalarMultiply(VE_vector * vector, int scalar) {
    int * data = malloc(sizeof(int) * vector->length);
    for (int i = 0; i < vector->length; i++) {
        data[i] = (int) ((int *)vector->data)[i] * scalar;
    }

    return VE_newVector(vector->length, data, 0);
}

void VE_printVector(VE_vector * vector) {
    printf("\n(");
    for (int i = 0; i < vector->length; i++) {
        if (i != vector->length - 1) {
            printf("%d,", (int) ((int *)vector->data)[i]);
        }
        else {
            printf("%d", (int) ((int *)vector->data)[i]);
        }
    }

    printf(")");
}

void * VE_dotProduct(VE_vector * v1, VE_vector * v2) {
    int * dot = malloc(sizeof(int));
    dot = 0;

    if (v1->length != v2->length) {
        return NULL;
    }

    for (int i = 0; i < v1->length; i++) {
        dot += (int) ((int *) v1->data)[i] * (int) ((int *) v2->data)[i];
    }

    return dot;
}

VE_vector * VE_crossProduct(VE_vector * v1, VE_vector * v2) {
    if (v1->length != 3 || v2->length != 3) {
        return NULL;
    }

    // - C1 = A2 * B3 - A3 * B2
    // - C2 = A3 * B1 - A1 * B3
    // - C3 = A1 * B2 - A2 * B1

    int * v3 = malloc(sizeof(int) * 3);
    v3[0] = (int) ((int *) v1->data)[1] * (int) ((int *) v2->data)[2] - (int) ((int *) v1->data)[2] * (int) ((int *) v2->data)[1];
    v3[1] = (int) ((int *) v1->data)[2] * (int) ((int *) v2->data)[0] - (int) ((int *) v1->data)[0] * (int) ((int *) v2->data)[2];
    v3[2] = (int) ((int *) v1->data)[0] * (int) ((int *) v2->data)[1] - (int) ((int *) v1->data)[1] * (int) ((int *) v2->data)[0];

    return VE_newVector(3, v3, 0);
}

double VE_vectorLength(VE_vector * vector) {
    if (vector->length != 2) {
        return -1;
    }

    return sqrt(square((int) ((int *)vector->data)[0]) + square((int) ((int *)vector->data)[1]));
}

VE_vector * VE_normalizeVector(VE_vector * vector) {
    if (vector->length != 2) {
        return NULL;
    }

    int * data = malloc(sizeof(int) * 2);
    data[0] = (int) ((int)((int *) vector->data)[0]) / VE_vectorLength(vector);
    data[1] = (int) ((int)((int *) vector->data)[1]) / VE_vectorLength(vector);

    return VE_newVector(2, data, 0);
}

int square (int num) {
    return num * num;
}

MA_matrix * MA_newMatrix(int rows, int cols, void * data, int type) {
    MA_matrix * matrix = malloc(sizeof(MA_matrix));
    matrix->cols = cols;
    matrix->rows = rows;
    matrix->data = data;
    matrix->type = type;

    return matrix;
}

void MA_printMatrix(MA_matrix * A) {
    if (A == NULL) {
        printf("\n[]");
        return;
    }

    printf("\n[");
    for (int i = 0; i < A->rows; i++) {
        printf("\n [");
        for (int j = 0; j < A->cols; j++) {
            if (j != A->cols - 1) {
                printf("%d, ", ((int **) A->data)[i][j]);
            }
            else {
                printf("%d]", ((int **) A->data)[i][j]);
            }
        }
    }

    printf("\n]");
}

MA_matrix * MA_addMatrix(MA_matrix * A, MA_matrix * B) {
    if (A->cols != B->cols || A->rows != B->rows) {
        return NULL;
    }

    MA_matrix * matrix = malloc(sizeof(MA_matrix));
    matrix->rows = A->rows;
    matrix->cols = A->cols;
    int ** arr = (int **) malloc(sizeof(int *) * A->rows);
    for (int i = 0; i < A->rows; i++) {
        arr[i] = (int *) malloc(sizeof(int) * A->cols);
        for (int j = 0; j < A->cols; j++) {
            arr[i][j] = ((int **) A->data)[i][j] + ((int **) B->data)[i][j];
        }
    }

    matrix->data = arr;

    return matrix;
}

MA_matrix * MA_scalarMultiply(MA_matrix * A, double scalar) {
    MA_matrix * matrix = malloc(sizeof(MA_matrix));
    matrix->rows = A->rows;
    matrix->cols = A->cols;
    int ** arr = (int **) malloc(sizeof(int *) * A->rows);
    for (int i = 0; i < A->rows; i++) {
        arr[i] = (int *) malloc(sizeof(int) * A->cols);
        for (int j = 0; j < A->cols; j++) {
            arr[i][j] = ((int **) A->data)[i][j] * scalar;
        }
    }

    matrix->data = arr;

    return matrix;
}

MA_matrix * MA_matrixMultiply(MA_matrix * A, MA_matrix * B) {
    if (A->rows != B->cols) {
        return NULL;
    }

    MA_matrix * matrix = malloc(sizeof(MA_matrix));
    matrix->rows = A->rows;
    matrix->cols = A->cols;
    int ** arr = (int **) malloc(sizeof(int *) * A->rows);
    for (int i = 0; i < A->rows; i++) {
        arr[i] = (int *) malloc(sizeof(int) * A->cols);
        for (int j = 0; j < B->cols; j++) {
            arr[i][j] = 0;
            for (int k = 0; k < A->cols; k++) {
                arr[i][j] += ((int **) A->data)[i][k] * ((int **) B->data)[k][j];
            }
        }
    }

    matrix->data = arr;

    return matrix;
}

MA_matrix * MA_transpose(MA_matrix * A) {
    MA_matrix * matrix = malloc(sizeof(MA_matrix));
    matrix->rows = A->cols;
    matrix->cols = A->rows;
    int ** arr = (int **) malloc(sizeof(int *) * A->rows);
    for (int i = 0; i < A->rows; i++) {
        arr[i] = (int *) malloc(sizeof(int) * A->cols);
        for (int j = 0; j < A->cols; j++) {
            arr[i][j] = ((int **) A->data)[j][i];
        }
    }

    matrix->data = arr;
    return matrix;
}
