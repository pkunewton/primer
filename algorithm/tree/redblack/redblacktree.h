//
// Created by Administrator on 2018/5/10.
//

#ifndef PRIMER_REDBLACKTREE_H
#define PRIMER_REDBLACKTREE_H
/*
 * 1、每个节点着色
 * 2、根是黑色
 * 3、红色节点的子节点必是黑色节点
 * 4、从一个节点到一个NULL指针的每一条路径必须包含相同的黑色节点
 * 红黑树的高度 <= 2log(N+1)
 */
typedef int ElementType;
struct RedBlackNode;
typedef struct RedBlackNode *Position;
typedef struct RedBlackNode *RedBlackTree;

RedBlackTree makeEmpty(RedBlackTree tree);

#endif //PRIMER_REDBLACKTREE_H
