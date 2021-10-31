#include "singly_linked_list.h"

void single_list_print_elem (list_data_type value, FILE *out)
{
    assert (out != NULL);
    
    
    fprintf (out, "%d", value);
}

