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