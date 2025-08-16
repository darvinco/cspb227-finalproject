/**
 * @file fenwick_tree.h
 * @brief Declaration of the FenwickTree class for efficient prefix sum queries and updates.
 *
 * A Fenwick Tree (Binary Indexed Tree) supports:
 * - Point updates in O(log n)
 * - Prefix sum queries in O(log n)
 *
 * Useful for real-time data aggregation tasks such as daily        salestracking.
 * @author Darvin Contreras (@darvinco) 
 */

#ifndef FENWICK_TREE_H
#define FENWICK_TREE_H

#include <vector>
#include <stdexcept>

/**
 * @class FenwickTree
 * @brief A class implementing a Fenwick Tree (Binary Indexed Tree) for integer values.
 */
class FenwickTree {
public:
    /**
     * @brief Constructor to initialize tree with a given size.
     * @param size The number of elements (1-based indexing).
     */
    explicit FenwickTree(int size);

    /**
     * @brief Adds a value (delta) to the element at the given index.
     * @param index 1-based index where the value is updated.
     * @param delta The amount to add.
     */
    void update(int index, int delta);

    /**
     * @brief Returns the prefix sum from index 1 to the given index.
     * @param index 1-based index to query prefix sum.
     * @return Sum from index 1 to index.
     */
    int prefixSum(int index) const;

    /**
     * @brief Returns the sum of elements in the range [left, right].
     * @param left 1-based start index.
     * @param right 1-based end index.
     * @return Sum in the range [left, right].
     */
    int rangeSum(int left, int right) const;

    /**
     * @brief Returns the size of the Fenwick Tree (number of elements).
     */
    int size() const;

private:
    std::vector<int> tree;
    int n;

    void validateIndex(int index) const;
};

#endif // FENWICK_TREE_H