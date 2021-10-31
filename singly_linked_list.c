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


int single_list_index_ptr (single_list list, SLL **ret_ptr, size_t index)
{
	CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(ret_ptr, NULL_POINTER_ERROR);
    *ret_ptr = NULL;
    
    SLL *this_elem = *list;
    
    while (index > 0)
    {
        CHECK_PTR_RET(this_elem, OUTRUN_ERROR);
        
        this_elem = (SLL *) this_elem->next;
        index--;
    }
    
    
    *ret_ptr = this_elem;
    
    
    return SUCCESS;
}

int single_list_index (single_list list, list_data_type *ret_ptr, size_t index)
{
	CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(ret_ptr, NULL_POINTER_ERROR);
    *ret_ptr = SINGLE_LIST_VENOM;
    
    SLL *elem = NULL;
    
    int status = single_list_index_ptr (list, &elem, index);
    CHECK_PTR_RET(elem, status);
    
    
    *ret_ptr = elem->data;
    
    
    return SUCCESS;
}

int single_list_dtor (single_list *list)
{
	CHECK_PTR_RET(list, NULL_POINTER_ERROR);
	CHECK_PTR_RET(*list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(**list, NULL_POINTER_ERROR);
    
	
	SLL *elem = NULL;
	int status = single_list_index_ptr (*list, &elem, 0);
    
    SLL *next_elem = NULL;
    
    do
    {
        next_elem = (SLL *) elem->next;
        
        free (elem);
        
        elem = next_elem;
        next_elem = NULL;
    }
    while (elem != NULL);

    free (*list);
    *list = NULL;
    

	return SUCCESS;
}

void single_list_print (single_list list, FILE *out)
{
    assert (list != NULL);
    assert (*list != NULL);
    assert (out != NULL);
    
    
    SLL *elem = *list;
    
    do
    {
        fprintf (out, "Pointer: %p;\tData: ", elem);
        single_list_print_elem (elem->data, out);
        fprintf (out, ";\tNext: %p;\n", elem->next);
        
        elem = (SLL *) elem->next;
    }
    while (elem != NULL);
}

int single_list_append (single_list list, list_data_type value)
{
    CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(*list, NULL_POINTER_ERROR);
    
    
    SLL *elem = *list;
    
    while (elem->next != NULL)
    {
        elem = elem->next;
    }
    
    elem->next = calloc (1, sizeof (SLL));
    CHECK_PTR_RET(elem->next, CALLOC_ERROR);
    
    elem = elem->next;
    elem->data = value;
    elem->next = NULL;
    
    return SUCCESS;
}

