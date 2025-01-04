

#include "graph.h"
/**
 * @brief Allocates and initializes a new entity.
 *
 * This function creates a new `entity_t` structure, initializes its fields,
 * and returns a pointer to the allocated memory. The caller is responsible
 * for deallocating the returned entity using the appropriate deallocation function.
 *
 * @param[in] name A null-terminated string representing the entity's name.
 * @param[in] type The type of the entity, specified as a value from `entityType_t`.
 * @param[in] ndata The number of data elements to allocate in the entity.
 * @return A pointer to the newly allocated `entity_t`, or `NULL` on failure.
 *
 * @note The `data` array is initialized to `NULL` pointers.
 * 
 * @see entity_t, deallocate_entity
 */
extern graph_t *build_first_topo();

int 
main(){

    graph_t *topo = build_first_topo();
    dump_graph(topo);
    return 0;
}
