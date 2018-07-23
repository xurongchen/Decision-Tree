//
// Created by new on 2018/2/6.
//
#include <list>
#include <iostream>
#include <sstream>

#include <stddef.h>

extern "C" {
    #include "sort_rec_list.h"
    #include "array.h"
}

struct sort_rec_list {
    std::list<IndexSortRec*> list;
};

struct IndexSortRec{
    void* data;
    int index;
};


sort_rec_list * new_sort_rec_list(){
    return new sort_rec_list;
}
int get_sort_rec_index(struct IndexSortRec const * sc){
    return sc->index;
}

void  delete_sort_rec_list (sort_rec_list *l){
    if(l != NULL) {
        while(!sort_rec_list_empty(l)){
            IndexSortRec* pToFree = sort_rec_list_back(l);
            sort_rec_list_pop_back(l);
            delete pToFree;
        }
        delete l;
    }
}

size_t sort_rec_list_size (sort_rec_list *l){
    return l->list.size();
}

int sort_rec_list_empty(sort_rec_list *l){
    return l->list.empty();
}

IndexSortRec* sort_rec_list_front(sort_rec_list *l) {
    return l->list.front();
}

IndexSortRec* sort_rec_list_back(sort_rec_list *l) {
    return l->list.back();
}

void sort_rec_list_push_front(sort_rec_list *l, void *val, int index){
    IndexSortRec* pData = new IndexSortRec;
    pData->data = val;
    pData->index = index;
    l->list.push_front(pData);
}

void sort_rec_list_push_back(sort_rec_list *l, void *val,int index){
    IndexSortRec* pData = new IndexSortRec;
    pData->data = val;
    pData->index = index;
    l->list.push_back(pData);
}


void  sort_rec_list_pop_front(sort_rec_list *l){
    l->list.pop_front();
}

void sort_rec_list_pop_back(sort_rec_list *l) {
    l->list.pop_back();
}

void sort_rec_list_print(sort_rec_list *l){

    if(l == NULL) {
        std::cout << "NULL" << std::endl;
        return;
    }

    std::stringstream out;

    out << "[";

    size_t i;
    std::list<IndexSortRec*>::iterator it;
    for(i = 0, it = l->list.begin(); it != l->list.end(); it++, i++) {
        out << "[" << (*it)->index //<< ","<< (*it)->data->V << ","<< (*it)->data->T << "," << (*it)->data->W
            << "]" << (i < l->list.size() - 1 ? ", " : "");
    }

    out << "]";

    std::cout << out.str() << std::endl;

}

struct array * sort_rec_list_to_array (struct sort_rec_list const *l){

    if (l == NULL) {
        return NULL;
    }

    array * a = new_array (l->list.size());

    int i=0;
    for (std::list<IndexSortRec*>::const_iterator it = l->list.begin(); it != l->list.end(); it++) {

        a->entries[i] = (*it)->index;
        i++;

    }

    return a;

}

