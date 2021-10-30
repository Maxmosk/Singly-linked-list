#include "singly_linked_list.h"


int single_list_ctor (single_list list, list_data_type init)
{
	CHECK_PTR_RET(list, NULL_POINTER_ERROR);


	SLL *elem = calloc (1, sizeof (SLL));

	CHECK_PTR_RET(elem, CALLOC_ERROR);

	
	elem->next = NULL;
	elem->data = init;
	

	*list = elem;


	return SUCCESS;
}


int single_list_index (single_list list, list_data_type *ret_ptr, size_t index)
{
	CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(ret_ptr, NULL_POINTER_ERROR);
    
    
    SLL *this_elem = *list;
    
    while (index > 0)
    {
        CHECK_PTR_RET(this_elem, OUTRUN_ERROR);
        
        this_elem = (SLL *) this_elem->next;
        index--;
    }
    
    
    *ret_ptr = this_elem->data;
    
    
    return SUCCESS;
}

