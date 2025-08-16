# cspb2270-final_project
#Data Structure Implemented
Final project for CSPB 2270. Implementation of a Fenwick Tree (Binary Indexed Tree) in C++, demonstrating its use in real-time business analytics scenarios - such as tracking daily
sales, transactions, or user reviews. 

#Description of the Data Structure 
A Fenwick tree is a data structure that supports efficient prefix sum and point update operations in O(logn) time. The Fenwick Tree 
uses binary index manipulation to aggregate and query data quickly. 

In this project the Fenwick Tree is used to: 
- Increment the value for any given day (e.g. record a sale)
- Compute the total count over any time interval efficiently
- Support range sum queries via the difference of two prefix sums.

The project includes helper methods to map real-world labels (e.g., dates) to array indices, as well as error handling for edge cases and out-of-bounds access.
