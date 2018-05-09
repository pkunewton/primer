//
// Created by Administrator on 2018/5/9.
//

#ifndef PRIMER_BINQUEUE_H
#define PRIMER_BINQUEUE_H

typedef int ElementType;
typedef struct BinNode *Position;
typedef struct BinNode *BinQueue;

struct BinNode{
    ElementType element;
    Position    leftChild;
    Position     nextSibling;
};

#endif //PRIMER_BINQUEUE_H
