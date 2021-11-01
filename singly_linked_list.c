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
    
    fprintf (out, "========================================\n");
    fprintf (out, "Printing list by adress %p\n", list);
    
    SLL *elem = *list;
    
    size_t index = 0;
    do
    {
        fprintf (out, "Index: %d;\tPointer: %p;\tData: ", index, elem);
        single_list_print_elem (elem->data, out);
        fprintf (out, ";\tNext: %p;\n", elem->next);
        
        elem = (SLL *) elem->next;
        
        index++;
    }
    while (elem != NULL);
    
    fprintf (out, "========================================\n");
}

int single_list_append (single_list list, list_data_type value)
{
    CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(*list, NULL_POINTER_ERROR);
    
    
    SLL *elem = *list;
    
    while (elem->next != NULL)
    {
        elem = (SLL *) elem->next;
    }
    
    elem->next = calloc (1, sizeof (SLL));
    CHECK_PTR_RET(elem->next, CALLOC_ERROR);
    
    elem = (SLL *) elem->next;
    elem->data = value;
    elem->next = NULL;
    
    return SUCCESS;
}

int single_list_insert (single_list list, list_data_type value, size_t index)
{
    CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(*list, NULL_POINTER_ERROR);
    
    
    //  Special case: insertion at the beginning of the list
    if (index == 0)
    {
        SLL *new_elem = (SLL *) calloc (1, sizeof (SLL));
        CHECK_PTR_RET(new_elem, CALLOC_ERROR);
        
        new_elem->data = value;
        new_elem->next = (char *) *list;
        
        *list = new_elem;
        
        
        return SUCCESS;
    }
    
    
    SLL *prev = NULL;
    
    int status = single_list_index_ptr (list, &prev, index - 1);
    CHECK_PTR_RET(prev, status);
    
    SLL *new_elem = (SLL *) calloc (1, sizeof (SLL));
    CHECK_PTR_RET(new_elem, CALLOC_ERROR);
    
    new_elem->data = value;
    new_elem->next = prev->next;
    
    prev->next = (char *) new_elem;
    
    
    return SUCCESS;
}

int single_list_assign (single_list list, list_data_type value, size_t index)
{
    CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(*list, NULL_POINTER_ERROR);
    
    
    SLL *elem = NULL;
    
    int status = single_list_index_ptr (list, &elem, index);
    CHECK_PTR_RET(elem, status);
    
    elem->data = value;
    
    
    return SUCCESS;
}

int single_list_pop (single_list list, list_data_type *ret_ptr, size_t index)
{
    CHECK_PTR_RET(list, NULL_POINTER_ERROR);
    CHECK_PTR_RET(*list, NULL_POINTER_ERROR);
    
    
    //  Special case: poping at the beginning of the list
    if (index == 0)
    {
        SLL *elem = *list;
        
        if (ret_ptr != NULL)
        {
            *ret_ptr = elem->data;
        }
        
        *list = (SLL *) elem->next;
        
        free (elem);
        
        
        return SUCCESS;
    }
    
    
    SLL *prev = NULL;
    
    int status = single_list_index_ptr (list, &prev, index-1);
    CHECK_PTR_RET(prev, status);
    
    SLL *elem = (SLL *) prev->next;
    CHECK_PTR_RET(elem, OUTRUN_ERROR);
        
    if (ret_ptr != NULL)
    {
        *ret_ptr = elem->data;
    }
    
    prev->next = elem->next;
    
    
    free (elem);
    
    
    return SUCCESS;
}

