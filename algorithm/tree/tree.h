//
// Created by Administrator on 2018/4/29 0029.
//

#ifndef PRIMER_TREE_H
#define PRIMER_TREE_H
typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

extern "C" {
    SearchTree createTreeNode(ElementType element);
    SearchTree makeEmpty(SearchTree tree);
    Position find(ElementType element, SearchTree tree);
    Position findMax(SearchTree tree);
    Position findMin(SearchTree tree);
    SearchTree insertElement(ElementType element, SearchTree tree);
    SearchTree deleteElement(ElementType element, SearchTree tree);
    ElementType retrieve(Position position);
};

#endif //PRIMER_TREE_H
