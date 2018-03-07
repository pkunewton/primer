//
// Created by Administrator on 2018/3/7.
//

#ifndef PRIMER_SEQLIST_H
#define PRIMER_SEQLIST_H

//#define MAXNUM 100

struct DataType {
    int number;
    int age;
};

typedef struct DataType *Person;

struct SeqList {
    int n;
    int MAXNUM;
    DataType *element;
};

typedef struct SeqList *PSeqList;

PSeqList createNullList_seq(int m);

#endif //PRIMER_SEQLIST_H
