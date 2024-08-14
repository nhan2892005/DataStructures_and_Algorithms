#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include "ArrayList.h"
#include "standard.h"

template <typename PHUCNHAN>
struct SegNode {
    PHUCNHAN min, max, sum, average;
    SegNode(const PHUCNHAN& value) {
        min = value;
        max = value;
        sum = value;
        average = value;
    }
    const SegNode& operator=(const PHUCNHAN& other) {
        SegNode result;
        result.min = other;
        result.max = other;
        result.sum = other;
        result.average = other;
        return result;
    }
};

template <typename PHUCNHAN>
class SegmentTree {
private:
    ArrayList<SegNode<PHUCNHAN>> tree;
    int size;
public:
    SegmentTree(int size) {
        this->size = size;
        tree = ArrayList<PHUCNHAN>(4 * size);
    }
    SegmentTree(const ArrayList<PHUCNHAN>& list) {
        this->size = list.size();
        tree = ArrayList<PHUCNHAN>(4 * size);
        build(list, 0, 0, size - 1);
    }
    // copy constructor
    SegmentTree(const SegmentTree& other) {
        this->size = other.size;
        this->tree = other.tree;
    }
    // assignment operator
    SegmentTree& operator=(const SegmentTree& other) {
        this->size = other.size;
        this->tree = other.tree;
        return *this;
    }
    // destructor
    ~SegmentTree() {
        tree.clear();
    }
    SegNode& mergeNode(SegNode& a, const SegNode& b) {
        SegNode result;
        result.min = Min(a.min, b.min);
        result.max = Max(a.max, b.max);
        result.sum = a.sum + b.sum;
        result.average = (a.average + b.average) / 2;
        return result;
    }
    void build(const ArrayList<PHUCNHAN>& list, int index, int left, int right) {
        if (left == right) {
            tree[index] = list[left];
            return;
        }
        int mid = (left + right) / 2;
        build(list, 2 * index + 1, left, mid);
        build(list, 2 * index + 2, mid + 1, right);
        tree[index] = mergeNode(tree[2 * index + 1], tree[2 * index + 2]);
    }
    PHUCNHAN query(int index, int left, int right, int l, int r) {
        if (l > right || r < left) {
            return 0;
        }
        if (l <= left && right <= r) {
            return tree[index];
        }
        int mid = (left + right) / 2;
        return query(2 * index + 1, left, mid, l, r) + query(2 * index + 2, mid + 1, right, l, r);
    }
    void update(int index, int left, int right, int pos, PHUCNHAN value) {
        if (left == right) {
            tree[index] = value;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) {
            update(2 * index + 1, left, mid, pos, value);
        } else {
            update(2 * index + 2, mid + 1, right, pos, value);
        }
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
};

#endif