//
// Created by Administrator on 2018/3/7.
//

#include <cstdlib>
#include "seqlist.h"

using std::malloc;
using std::free;

PSeqList createNullList_seq(int m){
    PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
    if(palist != nullptr){
        palist->element = (Person)malloc(sizeof(struct DataType) * m);
        if(palist->element){
            palist->n = 0;
            palist->MAXNUM = m;
            return palist;
        } else{
            free(palist);
        }
    }
    return NULL;
}

