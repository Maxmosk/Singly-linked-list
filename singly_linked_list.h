#ifndef SINGLY_LINKED_LIST_H_INCLUDED
#define SINGLY_LINKED_LIST_H_INCLUDED


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/** @def SLNGLE_LIST_INIT
 *  @brief The macro for initialize variable by single_list type
 *  @warning Can return null-pointer
*/
#define SLNGLE_LIST_INIT calloc (1, sizeof (SLL *))

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
	{                                                   \
		return DUNGEON_CODE;                            \
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
 *	@note Can be setted by user
*/
typedef int list_data_type;

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

/** @fn single_list_index
 *  @brief The function to get value of element by index
 *  @param list List for indexing
 *  @param ret_ptr Pointer on addres of memory for output value
 *  @param index Index of element in list
 *  @warning Changes the value at the address ret_ptr
 *  @return Code from enum RETURN_CODES
*/
int single_list_index (single_list list, list_data_type *ret_ptr, size_t index);

#endif

