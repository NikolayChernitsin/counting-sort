#include "../counting_sort.h"
#include <gtest/gtest.h>

#include <array>
#include <vector>

namespace {
template <typename C>
void expectSorted(const C& c)
{
    for (size_t i = 1; i < c.size(); ++i) {
        EXPECT_LE(c[i - 1], c[i]);
    }
}

template <typename C, typename F>
void expectSorted(const C& c, F f)
{
    for (size_t i = 1; i < c.size(); ++i) {
        EXPECT_LE(f(c[i - 1]), f(c[i]));
    }
}
}

TEST(CountingSort, empty)
{
    std::vector<int> d;
    sort(d, 9);
    EXPECT_TRUE(d.empty());
}

TEST(CountingSort, emptyAuto)
{
    std::vector<int> d;
    sort(d);
    EXPECT_TRUE(d.empty());
}

TEST(CountingSort, sorted)
{
    std::vector d = {
        0, 0, 1, 1, 2, 2, 3, 3, 4, 4,
        5, 5, 6, 6, 7, 7, 8, 8, 9, 9
    };
    sort(d, 9);
    expectSorted(d);
}

TEST(CountingSort, uniqueValues)
{
    std::vector d = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    sort(d, 9);
    expectSorted(d);
}

TEST(CountingSort, sameValues)
{
    std::vector<int> d(10, 5);
    sort(d, 9);
    expectSorted(d);
}

TEST(CountingSort, sameValuesAuto)
{
    std::vector<int> d(10, 5);
    sort(d);
    expectSorted(d);
}

TEST(CountingSort, normalSimple)
{
    std::vector d = {
        6, 2, 3, 8, 3, 2, 7, 9, 4, 7,
        8, 1, 1, 2, 3, 4, 8, 1, 1, 4,
        3, 5, 2, 1, 2, 7, 2, 9, 3, 0,
        1, 9, 7, 9, 3, 6, 9, 5, 4, 7,
        3, 7, 6, 2, 2, 8, 8, 4, 6, 5,
        8, 6, 4, 5, 8, 4, 6, 9, 8, 0,
        5, 3, 0, 1, 4, 6, 7, 0, 0, 7,
        0, 0, 7, 1, 5, 9, 2, 4, 5, 5,
        6, 5, 5, 2, 1, 9, 7, 3, 9, 8,
        4, 0, 3, 0, 9, 1, 0, 6, 6, 8
    };

    sort(d, 9);
    expectSorted(d);
}

TEST(CountingSort, normalSimpleNegative)
{
    std::vector d = {
        -6, 2, -3, 8, 3, -2, 7, 9, -4, 7,
        -8, 1, -1, 2, 3, -4, 8, 1, -1, 4,
        -3, 5, -2, 1, 2, -7, 2, 9, -3, 0,
        -1, 9, -7, 9, 3, -6, 9, 5, 4, 7,
        -3, 7, -6, 2, 2, -8, 8, 4, -6, 5,
        -8, 6, -4, 5, 8, -4, 6, 9, -8, 0,
        -5, 3, 0, 1, 4, 6, -7, 0, 0, 7,
        0, 0, -7, 1, 5, 9, -2, 4, -5, 5,
        -6, 5, -5, 2, 1, 9, -7, 3, -9, 8,
        -4, 0, -3, 0, 9, 1, 0, 6, 6, 8
    };

    sort(d, 9, -9);
    expectSorted(d);
}

TEST(CountingSort, normalSimpleNegativeAuto)
{
    std::vector d = {
        -6, 2, -3, 8, 3, -2, 7, 9, -4, 7,
        -8, 1, -1, 2, 3, -4, 8, 1, -1, 4,
        -3, 5, -2, 1, 2, -7, 2, 9, -3, 0,
        -1, 9, -7, 9, 3, -6, 9, 5, 4, 7,
        -3, 7, -6, 2, 2, -8, 8, 4, -6, 5,
        -8, 6, -4, 5, 8, -4, 6, 9, -8, 0,
        -5, 3, 0, 1, 4, 6, -7, 0, 0, 7,
        0, 0, -7, 1, 5, 9, -2, 4, -5, 5,
        -6, 5, -5, 2, 1, 9, -7, 3, -9, 8,
        -4, 0, -3, 0, 9, 1, 0, 6, 6, 8
    };

    sort(d);
    expectSorted(d);
}

TEST(CountingSort, normalSimpleArray)
{
    std::array d = {
        6, 2, 3, 8, 3, 2, 7, 9, 4, 7,
        8, 1, 1, 2, 3, 4, 8, 1, 1, 4,
        3, 5, 2, 1, 2, 7, 2, 9, 3, 0,
        1, 9, 7, 9, 3, 6, 9, 5, 4, 7,
        3, 7, 6, 2, 2, 8, 8, 4, 6, 5,
        8, 6, 4, 5, 8, 4, 6, 9, 8, 0,
        5, 3, 0, 1, 4, 6, 7, 0, 0, 7,
        0, 0, 7, 1, 5, 9, 2, 4, 5, 5,
        6, 5, 5, 2, 1, 9, 7, 3, 9, 8,
        4, 0, 3, 0, 9, 1, 0, 6, 6, 8
    };

    sort(d, 9);
    expectSorted(d);
}

TEST(CountingSort, normal100)
{
    std::vector d = {
        106, 102, 103, 108, 103, 102, 107, 109, 104, 107,
        108, 101, 101, 102, 103, 104, 108, 101, 101, 104,
        103, 105, 102, 101, 102, 107, 102, 109, 103, 100,
        101, 109, 107, 109, 103, 106, 109, 105, 104, 107,
        103, 107, 106, 102, 102, 108, 108, 104, 106, 105,
        108, 106, 104, 105, 108, 104, 106, 109, 108, 100,
        105, 103, 100, 101, 104, 106, 107, 100, 100, 107,
        100, 100, 107, 101, 105, 109, 102, 104, 105, 105,
        106, 105, 105, 102, 101, 109, 107, 103, 109, 108,
        104, 100, 103, 100, 109, 101, 100, 106, 106, 108
    };

    sort(d, 109, 100);
    expectSorted(d);
}

TEST(CountingSort, normalAuto)
{
    std::vector d = {
        106, 102, 103, 108, 103, 102, 107, 109, 104, 107,
        108, 101, 101, 102, 103, 104, 108, 101, 101, 104,
        103, 105, 102, 101, 102, 107, 102, 109, 103, 100,
        101, 109, 107, 109, 103, 106, 109, 105, 104, 107,
        103, 107, 106, 102, 102, 108, 108, 104, 106, 105,
        108, 106, 104, 105, 108, 104, 106, 109, 108, 100,
        105, 103, 100, 101, 104, 106, 107, 100, 100, 107,
        100, 100, 107, 101, 105, 109, 102, 104, 105, 105,
        106, 105, 105, 102, 101, 109, 107, 103, 109, 108,
        104, 100, 103, 100, 109, 101, 100, 106, 106, 108
    };

    sort(d);
    expectSorted(d);
}

TEST(CountingSort, normalStruct)
{
    struct ValueType {
        int key;
        int payload;
    };

    auto make = [](int m) {
        return ValueType(m, 0);
    };

    std::vector d = {
        make(6), make(2), make(3), make(8), make(3),
        make(2), make(7), make(9), make(4), make(7)
    };
    auto f = [](const ValueType& v) {
        return v.key;
    };
    sort(d, f, 9);
    expectSorted(d, f);
}
