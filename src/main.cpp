/**
 * @file main.cpp
 * @brief Demo of Fenwick Tree for tracking daily sales in a business analytics context.
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <iomanip>
#include "fenwick_tree.h"

// Hardcoded date mapping: maps "YYYY-MM-DD" to a 1-based index
std::unordered_map<std::string, int> dateToIndex = {
    {"2025-08-01", 1},
    {"2025-08-02", 2},
    {"2025-08-03", 3},
    {"2025-08-04", 4},
    {"2025-08-05", 5},
    {"2025-08-06", 6},
    {"2025-08-07", 7},
    {"2025-08-08", 8},
    {"2025-08-09", 9},
    {"2025-08-10", 10}
};

// Reverse mapping to print dates from indices (unused for now)
std::vector<std::string> indexToDate = {
    "", // unused for 1-based indexing
    "2025-08-01", "2025-08-02", "2025-08-03", "2025-08-04", "2025-08-05",
    "2025-08-06", "2025-08-07", "2025-08-08", "2025-08-09", "2025-08-10"
};

// Safe print utility for range queries
void printSalesQuery(const FenwickTree& tree, const std::string& startDate, const std::string& endDate) {
    if (dateToIndex.find(startDate) == dateToIndex.end() ||
        dateToIndex.find(endDate) == dateToIndex.end()) {
        std::cerr << "Invalid date(s) for query: " << startDate << " to " << endDate << "\n";
        return;
    }

    int start = dateToIndex.at(startDate);
    int end = dateToIndex.at(endDate);

    std::cout << "Total sales from " << startDate << " to " << endDate
              << ": " << tree.rangeSum(start, end) << "\n";
}

int main() {
    const int numDays = 10;
    FenwickTree salesTree(numDays);

    std::cout << "Updating sales data...\n";
    salesTree.update(dateToIndex.at("2025-08-01"), 5);   // 5 sales on Aug 1
    salesTree.update(dateToIndex.at("2025-08-02"), 8);   // 8 sales on Aug 2
    salesTree.update(dateToIndex.at("2025-08-05"), 12);  // 12 sales on Aug 5
    salesTree.update(dateToIndex.at("2025-08-07"), 3);   // 3 sales on Aug 7
    salesTree.update(dateToIndex.at("2025-08-10"), 10);  // 10 sales on Aug 10

    std::cout << "\nQuery results:\n";
    printSalesQuery(salesTree, "2025-08-01", "2025-08-01"); // single day
    printSalesQuery(salesTree, "2025-08-01", "2025-08-05"); // partial range
    printSalesQuery(salesTree, "2025-08-01", "2025-08-10"); // full range
    printSalesQuery(salesTree, "2025-08-06", "2025-08-10"); // another range

    // Safe handling of invalid query
    std::cout << "\nAttempting invalid query:\n";
    printSalesQuery(salesTree, "2025-08-01", "2025-08-15"); // will not crash

    return 0;
}