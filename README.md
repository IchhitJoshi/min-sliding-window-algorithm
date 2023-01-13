# Minimum Sliding Window Algorithm

First, this C++ program constructs a MinQueue priority queue template class using heaps. It supports the following implementation:

MinQueue() - constructors

insert(x),
min(),
extract_min(),
decrease_key(i,k),
heapify(i),
build_min_heap(),
heapsort(A),

Then, it is used to solve minimum sliding window problem:

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left
of the array to the very right. You can only see the k numbers in the window. Each time the sliding window
moves right by one position. Return the min sliding window.

Example 1

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

Output: [-1,-3,-3,-3,3,3]

Explanation:

<img width="240" alt="image" src="https://user-images.githubusercontent.com/112485986/212212724-43f54249-e63a-4ddb-a19c-cf77b8009a32.png">


Example 2

Input: nums = [1], k = 1

Output: [1]

This is implemented in the usecase file.

## Why this implementation?

There is a simple way of solving this problem using 2 for loops which is the brute force method. This will take time complexity O(n^2) to run.

Using this min queue implementation, the run time improves from O(n^2) to O(nlogn), making this solution faster.

## Makefile:
The command ./test will run all the unit tests in the test_minqueue.cpp file evaluating the MinQueue class. 
The command ./usecase will run the example test case in my main.cpp file demonstrating the accuracy of the sliding window solution.


