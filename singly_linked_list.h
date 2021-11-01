#ifndef SINGLY_LINKED_LIST_H_INCLUDED
#define SINGLY_LINKED_LIST_H_INCLUDED


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "settings.h"


/** @def SLNGLE_LIST_INIT
 *  @brief The macro for initialize variable by single_list type
 *  @warning Can return null-pointer
*/
#define SLNGLE_LIST_INIT calloc (1, sizeof (SLL *))

#define SINGLE_LIST_VENOM -1

/** @def CHECK_PTR_RET
 *  @brief The macro for checking of null-pointer
 *  @param FISTING_ASS_PTR Pointer for checking
 *  @param DUNGEON_CODE Code to return in null-pointer case
 *  @warning Use only in functions with return
 *  @note Only gachi, only hardcore
*/
#define CHECK_PTR_RET(FISTING_ASS_PTR, DUNGEON_CODE)    \
    assert ((FISTING_ASS_PTR) != NULL);                 \
	if ((FISTING_ASS_PTR) == NULL)                      \			
	{						                            \
		return DUNGEON_CODE;			                \
	}


/**
 *	@enum RETURN_CODES
 *	@brief return codes of functions for list
*/
enum RETURN_CODES
{
	SUCCESS = 0,
	NULL_POINTER_ERROR = 1,
	CALLOC_ERROR = 2,
	OUTRUN_ERROR = 3
};


/**	@typedef list_data_type
 *	@brief Type of data if list
 *	@note Can be setted by user in file "settings.h"
*/
typedef SLL_TYPE list_data_type;

/*	@typedef SLL
 *	@brief The structure of singly linked list
*/
typedef struct
{
	char *next;
	list_data_type data;
} SLL;

/**	@typedef single_list
 *	@brief Typr of singly linked list for easy processing
*/
typedef SLL **single_list;


/**	@fn single_list_ctor
 *	@brief The function for singly linked list constructing
 *	@details The function creates list in 'list', initialize by init
 *      and null-pointer
 *  @param list List to construct
 *  @param init Value to initialize
 *  @warning Changes the value at the address list
 *  @return Code from enum RETURN_CODES
*/
int single_list_ctor (single_list list, list_data_type init);

/** @fn single_list_index_ptr
 *  @brief The function to get pointer of element by index
 *  @param list List for indexing
 *  @param ret_ptr Pointer on addres of memory for output pointer
 *  @param index Index of element in list
 *  @warning Changes the value at the address ret_ptr
 *  @return Code from enum RETURN_CODES
*/
int single_list_index_ptr (single_list list, SLL **ret_ptr, size_t index);

/** @fn single_list_index
 *  @brief The function to get value of element by index
 *  @param list List for indexing
 *  @param ret_ptr Pointer on addres of memory for output value
 *  @param index Index of element in list
 *  @warning Changes the value at the address ret_ptr
 *  @return Code from enum RETURN_CODES
*/
int single_list_index (single_list list, list_data_type *ret_ptr, size_t index);

/** @fn single_list_dtor
 *  @brief The function for singly linked list destructing
 *  @param list List for destructing
 *  @warning Chanes thy value by addres
 *  @return Code from enum RETURN_CODES
*/
int single_list_dtor (single_list *list);

/** @fn single_list_print
 *  @brief The function for printing value of all elements of list
 *  @param list The list for printing
 *  @param out File stream for printing
*/
void single_list_print (single_list list, FILE *out);

/** @fn single_list_print_elem
 *  @brief The function for printing value of element of list
 *  @param value The value of element for printing
 *  @param out File stream for printing
 *  @note User of list must wrinte this function in file "print_elem.c"
*/
void single_list_print_elem (list_data_type value, FILE *out);

/** @fn single_list_append
 *  @brief The function to add element to the end of list
 *  @param list List variable to append element
 *  @param value Value of new element
*/
int single_list_append (single_list list, list_data_type value);

/** @fn single_list_insert
 *  @brief The function for inserting of element on the some place
 *  @param list List for inserting
 *  @param value Data for inserting at the this place
 *  @param index Number of new element
 *  @return Code from enum RETURN_CODES
*/
int single_list_insert (single_list list, list_data_type value, size_t index);

/** @fn single_list_assign
 *  @brief The fubction for assignment of element of list
 *  @param list List for assignment
 *  @param value New value of element
 *  @param index Index of element for assignment
 *  @return Code from enum RETURN_CODES
 *  @note ASSign, only gachi, only hardcore
*/
int single_list_assign (single_list list, list_data_type value, size_t index);

/** @fn single_list_pop
 *  @brief The function to delete element and return is's value
 *  @param list List for poping
 *  @param ret_ptr Adress of memory for returnimg of value
 *  @param index Index of element for poping
 *  @return Code from enum RETURN_CODES
 *  @warning Changes the value at the address ret_ptr
 *  @note If you needn't to get this value, pass null pointer in ret_ptr
*/
int single_list_pop (single_list list, list_data_type *ret_ptr, size_t index);

#endif

