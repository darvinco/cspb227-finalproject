#include "fenwick_tree.h"

FenwickTree::FenwickTree(int size) : tree(size + 1, 0), n(size) {}

void FenwickTree::update(int index, int delta) {
    if (index < 1 || index > n) {
        throw std::out_of_range("Index out of bounds for Fenwick Tree.");
    }
    while (index <= n) {
        tree[index] += delta;
        index += index & -index;
    }
}

int FenwickTree::prefixSum(int index) const {
    if (index < 0 || index > n) {
        throw std::out_of_range("Index out of bounds for Fenwick Tree.");
    }
    
    // Handle the special case where index is 0
    if (index == 0) {
        return 0;
    }
    
    int result = 0;
    while (index > 0) {
        result += tree[index];
        index -= index & -index;
    }
    return result;
}

int FenwickTree::rangeSum(int left, int right) const {
    if (left > right) {
        throw std::invalid_argument("Left index cannot be greater than right index.");
    }
    return prefixSum(right) - prefixSum(left - 1);
}

int FenwickTree::size() const {
    return n;
}

void FenwickTree::validateIndex(int index) const {
    if (index < 1 || index > n) {
        throw std::out_of_range("Index out of bounds for Fenwick Tree.");
    }
}