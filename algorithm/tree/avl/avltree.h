//
// Created by Administrator on 2018/5/8.
//

#ifndef PRIMER_AVLTREE_H
#define PRIMER_AVLTREE_H
typedef int ElementType;

struct AvlTreeNode;
typedef struct AvlTreeNode *Positon;
typedef struct AvlTreeNode *AvlTree;

//extern "C" {
    AvlTree createAvlTree(ElementType element);
    AvlTree makeEmpty(AvlTree tree);
    Positon find(ElementType element, AvlTree tree);
    Positon findMin(AvlTree tree);
    Positon findMax(AvlTree tree);
    AvlTree insertElement(ElementType element, AvlTree tree);
    AvlTree deleteElement(ElementType element, AvlTree tree);
    ElementType retrieve(Positon positon);
//}

#endif //PRIMER_AVLTREE_H
