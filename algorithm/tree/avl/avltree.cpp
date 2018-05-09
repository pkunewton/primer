//
// Created by Administrator on 2018/5/8.
//

#include "avltree.h"
#include <cstdlib>
//#include <stdlib.h>

struct AvlTreeNode {
    ElementType element;
    AvlTree     left;
    AvlTree     right;
    int         height;
};

AvlTree createAvlTree(ElementType element){
    AvlTree tree = (AvlTree)std::malloc(sizeof(struct AvlTreeNode));
    if (tree != NULL) {
        tree->element = element;
        tree->height = 0;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    } else {
        std::free(tree);
    }
    return NULL;
}

AvlTree makeEmpty(AvlTree tree){
    if(tree != NULL) {
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        std::free(tree);
    }
    return NULL;
}

Position find(ElementType element, AvlTree tree){
    if (tree == NULL)
        return NULL;
    if (element < tree->element)
        return find(element, tree->left);
    else if(element > tree->element)
        return find(element, tree->right);
    else
        return tree;
}

Position findMin(AvlTree tree) {
    if(tree == NULL){
        return NULL;
    } else if (tree->left == NULL){
        return tree;
    } else{
        return findMin(tree->left);
    }
}

Position findMax(AvlTree tree){
    if (tree == NULL){
        return NULL;
    } else if (tree->right == NULL){
        return tree;
    } else{
        return findMax(tree->right);
    }
}

static int Height(Position positon){
    if (positon == NULL)
        return -1;
    return positon->height;
}

static int Max(int lhs, int rhs){
    return lhs > rhs ? lhs : rhs;
}

/*       节点插入 X子树 中导致 K2 左右子树 平衡被破坏
 *              K2                        K1
 *           K1     Z       ===>       X     K2
 *        X     Y                           Y     Z
 */
static Position singleRotateWithLeft(Position K2){
    Position K1 = K2->left;
    K2->left = K1->right;
    K1->right = K2;

    K2->height = Max(Height(K2->left), Height(K2->right)) + 1;
    K1->height = Max(Height(K1->left), K2->height) + 1;
    return K1;
}

static Position singleRotateWithRight(Position K1){
    Position K2 = K1->right;
    K1->right = K2->left;
    K2->left = K1;

    K1->height = Max(Height(K1->left), Height(K1->right)) + 1;
    K2->height = Max(Height(K2->left), K1->height) + 1;
    return K2;
}

/*   节点插入k2子树 导致 k3 左右子树平衡破坏
 *              k3                        k3                    k2
 *          k1      d     ===>         k2     d     ===>      k1      k3
 *        a    k2                   k1    c                 a   b   c   d
 *           b    c               a    b
 */
static Position doubleRotateWithLeft(Position K3){
    Position K2 = singleRotateWithRight(K3->left);
    K3->left = K2;
    return singleRotateWithLeft(K3);
}

static Position doubleRotateWithRight(Position K1){
    Position K2 = singleRotateWithRight(K1->right);
    K1->right = K2;
    return singleRotateWithLeft(K1);
}

AvlTree insertElement(ElementType element, AvlTree tree){
    if (tree == NULL) {
        tree = createAvlTree(element);
    } else if (element < tree->element) {
        tree->left = insertElement(element, tree->left);
        if (Height(tree->left) - Height(tree->right) == 2) {
            if (element < tree->left->element) {
                tree = singleRotateWithLeft(tree);
            } else {
                tree = doubleRotateWithLeft(tree);
            }
        }
    } else if (element > tree->element) {
        tree->right = insertElement(element, tree->right);
        if (Height(tree->right) - Height(tree->left) == 2) {
            if (element > tree->right->element) {
                tree = singleRotateWithRight(tree);
            } else {
                tree = doubleRotateWithRight(tree);
            }
        }
    }
    tree->height = Max(Height(tree->left), Height(tree->right)) + 1;
    return tree;
}

AvlTree deleteElement(ElementType element, AvlTree tree){
    if (tree == NULL){
        return NULL;
    } else if (element == tree->element) {
        if (tree->left == NULL && tree->right == NULL){
            std::free(tree);
            tree = NULL;
        } else {
            // 删除的不是叶节点
            if (Height(tree->left) > Height(tree->right)) {
                Position max = findMax(tree->left);
                tree->left = deleteElement(retrieve(max), tree->left);
                max->left = tree->left;
                max->right = tree->right;
                std::free(tree);
                tree = max;
            } else {
                Position min = findMin(tree->right);
                tree->right = deleteElement(retrieve(min), tree->right);
                min->left = tree->left;
                min->right = tree->right;
                std::free(tree);
                tree = min;
            }
        }
    } else if (element < tree->element) {
        tree->left = deleteElement(element, tree->left);
        if (Height(tree->right) - Height(tree->left) == 2){
            if (Height(tree->right->right) > Height(tree->right->left)){
                tree = singleRotateWithRight(tree);
            } else {
                tree = doubleRotateWithRight(tree);
            }
        }
    } else if (element > tree->element) {
        tree->right = deleteElement(element, tree->right);
        if (Height(tree->left) - Height(tree->right) == 2) {
            if (Height(tree->left->left) > Height(tree->left->right)) {
                tree = singleRotateWithLeft(tree);
            } else {
                tree = doubleRotateWithLeft(tree);
            }
        }
    }

    tree->height = Max(Height(tree->left), Height(tree->right)) + 1;
    return tree;
}