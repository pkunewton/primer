//
// Created by Administrator on 2018/5/10.
//
#include <cstdlib>
#include "leftheap.h"

/*
 *
 */
static int ZeroPathLength(Position position) {
    if (position == NULL)
        return -1;
    return position->zeroPathLength;
}

static LeftHeap Mergel(LeftHeap lhs, LeftHeap rhs) {
    if ( lhs->left == NULL )
        lhs->left = rhs;
    else {
        lhs->right = Mergel(rhs, lhs->right);
        if (ZeroPathLength(lhs->left) < ZeroPathLength(lhs->right)) {
            LeftHeap temp;
            temp = lhs->right;
            lhs->right = lhs->left;
            lhs->left = temp;
        }
        lhs->zeroPathLength = ZeroPathLength(lhs->right) + 1;
    }
    return lhs;
}

LeftHeap Merge(LeftHeap lhs, LeftHeap rhs){
    LeftHeap res;
    if (lhs == NULL) {
        return rhs;
    } else if (rhs == NULL) {
        return lhs;
    } else {
//        if (retrieve(lhs) > retrieve(rhs)) {
//            if ( ZeroPathLength(rhs) > ZeroPathLength(lhs->right) ) {
//                lhs->left = Merge(lhs->right, rhs);
//                res = lhs;
//            } else {
//                rhs->right = Merge(rhs->right, lhs);
//                res = rhs;
//            }
//        } else {
//            if ( ZeroPathLength(lhs) > ZeroPathLength(res->right) ) {
//                rhs->left = Merge(rhs->left, lhs);
//                res = rhs;
//            } else {
//                lhs->right = Merge(lhs->right, rhs);
//                res = lhs;
//            }
//        }
        if (retrieve(lhs) < retrieve(rhs)) {
            res = Mergel(lhs, rhs);
        } else {
            res = Mergel(rhs, lhs);
        }
    }
//    res->zeroPathLength = Min(ZeroPathLength(res->left), ZeroPathLength(res->right)) + 1;
    return res;
}

ElementType retrieve(Position position){
    if (position == NULL) {
        return NULL;
    }
    return position->element;
}