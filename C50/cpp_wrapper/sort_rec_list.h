//
// Created by new on 2018/2/6.
//

#ifndef C50_SORT_REC_LIST_H
#define C50_SORT_REC_LIST_H
// Includes
#include "array.h"
//#include "../defns.i"

// Forward declaration of the clist
struct sort_rec_list;
struct IndexSortRec;

struct sort_rec_list * new_sort_rec_list();

int get_sort_rec_index(struct IndexSortRec const * sc);

void delete_sort_rec_list (struct sort_rec_list *);

size_t sort_rec_list_size (struct sort_rec_list *);

int sort_rec_list_empty(struct sort_rec_list *);

// Calling this function on an empty container causes undefined behavior.
struct IndexSortRec* sort_rec_list_front(struct sort_rec_list *);

// Calling this function on an empty container causes undefined behavior.
struct IndexSortRec* sort_rec_list_back(struct sort_rec_list *);

void sort_rec_list_push_front(struct sort_rec_list *, void*, int );

void sort_rec_list_push_back(struct sort_rec_list *, void*, int );

void sort_rec_list_pop_front(struct sort_rec_list *);

void sort_rec_list_pop_back(struct sort_rec_list *);

void sort_rec_list_print(struct sort_rec_list *);

// Copies the content of the list into an array
struct array * sort_rec_list_to_array (struct sort_rec_list const *);

#endif //C50_SORT_REC_LIST_H
