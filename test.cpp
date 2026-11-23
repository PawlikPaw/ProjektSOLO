#include "pch.h"
#include <vector>
#include <algorithm>
#include <random>
#include "../ProjektSOLO/mergesort.h" 

TEST(MergeSortTest, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, ReverseSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, RandomOrder) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42, 7, 19, 3, 88, 12, 1 };
    std::vector<int> expected = { 1, 3, 7, 12, 19, 42, 88 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, OnlyNegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -3, -15, -1, -42, -7 };
    std::vector<int> expected = { -42, -15, -7, -3, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, MixedPositiveAndNegative) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 10, -5, 0, 3, -12, 7 };
    std::vector<int> expected = { -12, -5, 0, 3, 7, 10 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, EmptyArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};
    sorter.sort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTest, SingleElement) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 99 };
    std::vector<int> expected = { 99 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, WithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 4, 2, 4, 1, 2, 3, 1 };
    std::vector<int> expected = { 1, 1, 2, 2, 3, 4, 4 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, NegativeWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -2, -5, -8, -2, -1 };
    std::vector<int> expected = { -8, -5, -5, -2, -2, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, MixedWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 3, -2, 0, 3, -2, 5, 0, -1 };
    std::vector<int> expected = { -2, -2, -1, 0, 0, 3, 3, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, DoubleValues) {
    MergeSort<double> sorter;
    std::vector<double> arr = { 3.5, -1.2, 0.0, 2.75, -1.2, 1.1 };
    std::vector<double> expected = { -1.2, -1.2, 0.0, 1.1, 2.75, 3.5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, LargeArray) {
    MergeSort<int> sorter;
    std::vector<int> arr(200);
    for (int i = 0; i < 200; ++i) {
        arr[i] = 200 - i;
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, LargeMixedArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    std::mt19937 gen(42);
    std::uniform_int_distribution<int> dist(-50, 50);

    for (int i = 0; i < 250; ++i) {
        arr.push_back(dist(gen));
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}