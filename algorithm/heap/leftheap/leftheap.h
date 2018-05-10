//
// Created by Administrator on 2018/5/10.
//

#ifndef PRIMER_LEFTHEAP_H
#define PRIMER_LEFTHEAP_H
typedef int ElementType;
typedef struct LeftHeapNode *Position;
typedef struct LeftHeapNode *LeftHeap;

struct LeftHeapNode {
    ElementType element;
    Position    left;
    Position    right;
    int         zeroPathLength;
};

/*        x                 a
 *     y      z         b      c
 *   c1 c2  c3 c4     c5 c6  c7 c8
 */
LeftHeap Merge(LeftHeap lhs, LeftHeap rhs);
ElementType retrieve(Position position);

#endif //PRIMER_LEFTHEAP_H
