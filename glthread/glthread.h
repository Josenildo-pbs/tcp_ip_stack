/** \addtogroup Glthread
 * @brief This library provide the gluethread function.
 * 
 * Glue linked list is variation of traditional linked list. In this case the data is not apartof the list.
 * The node is a element inside the data and all members of the data can be access by memory offset.
 * This kind of linked list is usefull in case of multiples link at the same data.
 * manipulation functions are easily implemented.
 * 
 *  @{
 */

#ifndef __GLTHREAD__
#define __GLTHREAD__

#define IS_GLTHREAD_LIST_EMPTY(glthreadptr)         \
    ((glthreadptr)->right == 0 && (glthreadptr)->left == 0)

#define GLTHREAD_TO_STRUCT(fn_name, structure_name, field_name)                        \
    static inline structure_name * fn_name(glthread_t *glthreadptr){                   \
        return (structure_name *)((char *)(glthreadptr) - (char *)&(((structure_name *)0)->field_name)); \
    }

/* delete safe loop*/
/*Normal continue and break can be used with this loop macro*/

#define BASE(glthreadptr)  ((glthreadptr)->right)

#define ITERATE_GLTHREAD_BEGIN(glthreadptrstart, glthreadptr)                                      \
{                                                                                                  \
    glthread_t *_glthread_ptr = NULL;                                                              \
    glthreadptr = BASE(glthreadptrstart);                                                          \
    for(; glthreadptr!= NULL; glthreadptr = _glthread_ptr){                                        \
        _glthread_ptr = (glthreadptr)->right;

#define ITERATE_GLTHREAD_END(glthreadptrstart, glthreadptr)                                        \
        }}

#define GLTHREAD_GET_USER_DATA_FROM_OFFSET(glthreadptr, offset)  \
    (void *)((char *)(glthreadptr) - offset)


/** @brief Glthread node struct.
 *  
 * Glthreads are bidirectional, so it is necessary store two pointers
 */
typedef struct _glthread{

    struct _glthread *left;  /**< Pointer to left neighbor */
    struct _glthread *right; /**< Pointer to right neighbor */
} glthread_t;

/**
 * @brief Add a neighbot on the right.
 *
 * @param[in] base_glthread Node that you want add a new neighbor.
 * @param[in] new_glthread Node that will be add in the list.
 */

void
glthread_add_next(glthread_t *base_glthread, glthread_t *new_glthread);

/**
 * @brief Add a neighbot on the left.
 *
 * @param[in] base_glthread Node that you want add a new neighbor.
 * @param[in] new_glthread Node that will be add in the list.
 */

void
glthread_add_before(glthread_t *base_glthread, glthread_t *new_glthread);

/**
 * @brief Remove a node from the list.
 *
 * @param[in] glthread Node that you want remove from the list.
 */
void
remove_glthread(glthread_t *glthread);

/**
 * @brief Inicialize a new node pre allocated.
 *
 * This function only inicialize the pointer with null value.
 * 
 * @param[in] glthread Node that you want initialize.
 */
void
init_glthread(glthread_t *glthread);

/**
 * @brief Add a neighbot on the tail of the list
 * 
 * This function will traverses the list an add the new node in the end of it.
 *
 * @param[in] base_glthread Head(First node) of the list.
 * @param[in] new_glthread Node that will be add in the end of the list.
 */
void
glthread_add_last(glthread_t *base_glthread, glthread_t *new_glthread);

/**
 * @brief Remove all node from the list.
 *
 * @param[in] glthread Head(fisrt node) that you want remove all sub sequents elements.
 */
void
delete_glthread_list(glthread_t *base_glthread);

/**
 * @brief Count all elements in the list.
 *
 * @param[in] glthread Head(fisrt node) start point to the counter.
 * @return Number of node in the list.
 */
unsigned int 
get_glthread_list_count(glthread_t *base_glthread);

/**
 * @brief Add the node conditionally with tha value present in the data and the implemetation of comp_fn.
 *
 * @param[in] base_glthread Head(fisrt node) start point.
 * @param[in] glthread The node the will be added.
 * @param[in] comp_fn The function the provite the rule to add.
 * @param[in] offset offset that identifies the position of the node in relation to the other elements in the data structure.
 */
void
glthread_priority_insert(glthread_t *base_glthread,     
                         glthread_t *glthread,
                         int (*comp_fn)(void *, void *),
                         int offset);


#if 0
void *
gl_thread_search(glthread_t *base_glthread,
        void *(*thread_to_struct_fn)(glthread_t *),
        void *key,
        int (*comparison_fn)(void *, void *));

#endif
#endif /* __GLUETHREAD__ */

/**  }@ */