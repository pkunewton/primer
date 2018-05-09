//
// Created by Administrator on 2018/5/8.
//

#ifndef PRIMER_AVLTREE_H
#define PRIMER_AVLTREE_H
typedef int ElementType;

struct AvlTreeNode;
typedef struct AvlTreeNode *Position;
typedef struct AvlTreeNode *AvlTree;

//extern "C" {
    AvlTree createAvlTree(ElementType element);
    AvlTree makeEmpty(AvlTree tree);
    Position find(ElementType element, AvlTree tree);
    Position findMin(AvlTree tree);
    Position findMax(AvlTree tree);
    AvlTree insertElement(ElementType element, AvlTree tree);
    AvlTree deleteElement(ElementType element, AvlTree tree);
    ElementType retrieve(Position positon);
//}

#endif //PRIMER_AVLTREE_H
