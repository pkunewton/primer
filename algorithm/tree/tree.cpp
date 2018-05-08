//
// Created by Administrator on 2018/4/29 0029.
//

#include <cstdlib>
#include "tree.h"

SearchTree createTreeNode(ElementType element){
    SearchTree tree = (SearchTree)std::malloc(sizeof(struct TreeNode));
    if (tree != NULL) {
        tree->element= element;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    } else {
        std::free(tree);
    }
    return NULL;
}

SearchTree makeEmpty(SearchTree tree){
    if (tree != NULL){
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        std::free(tree);
    }
}

Position find(ElementType element, SearchTree tree){
    if ( tree == NULL){
        return NULL;
    }
    if (element == tree->element){
        return tree;
    } else if(element > tree->element) {
        return find(element, tree->right);
    } else{
        return find(element, tree->left);
    }
}
