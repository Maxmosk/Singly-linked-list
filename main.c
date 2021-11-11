#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"


void random_list (single_list list, size_t n);


int main ()
{
	size_t numb = 0;

	printf ("Please, input number of elements of list: ");
	scanf ("%d", &numb);


	single_list my_list = SLNGLE_LIST_INIT;

	int status = single_list_ctor (my_list, rand ());
	INTERCEPT_SLL_ERROR(status);

	random_list (my_list, numb - 1);

	single_list_print (my_list, stdout);

	status = single_list_bubble_sort (my_list,
		(int (*)(list_data_type *, list_data_type *)) list_data_type_compare);
	INTERCEPT_SLL_ERROR(status);

	single_list_print (my_list, stdout);

	status = single_list_dtor (&my_list);
	INTERCEPT_SLL_ERROR(status);


	return 0;
}


void random_list (single_list list, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		single_list_append (list, rand ());
	}
}

