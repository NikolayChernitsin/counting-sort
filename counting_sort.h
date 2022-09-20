#pragma once

#include <cstddef>
#include <vector>

template <typename F, typename T>
concept function = std::is_invocable_v<F, T>;

template <typename C, typename F>
requires function<F, typename C::value_type>
void sort(C& data, F f1,
    const typename std::invoke_result_t<F, typename C::value_type> maxK,
    const typename std::invoke_result_t<F, typename C::value_type> minK = 0)
{
    if (data.empty()) {
        return;
    }

    auto f = [minK, f1](const auto& v) {
        return f1(v) - minK;
    };

    const size_t n = maxK - minK + 1;
    std::vector<size_t> idxs(n, 0);
    for (const auto& v : data) {
        ++idxs[f(v)];
    }
    for (size_t i = 1; i < idxs.size(); ++i) {
        idxs[i] += idxs[i - 1];
    }

    const auto endIdxs = idxs;
    for (size_t i = 1; i < idxs.size(); ++i) {
        idxs[idxs.size() - i] = idxs[idxs.size() - i - 1];
    }
    idxs[0] = 0;

    for (size_t k = 0; k < idxs.size(); ++k) {
        for (; idxs[k] < endIdxs[k];) {
            const size_t i = idxs[k];
            if (f(data[i]) != k) {
                const size_t fdi = f(data[i]);
                while (f(data[idxs[fdi]]) == fdi) {
                    ++idxs[fdi];
                }
                std::swap(data[i], data[idxs[fdi]++]);
            }
            if (f(data[i]) == k) {
                ++idxs[k];
            }
        }
    }
}

template <typename C>
void sort(C& data, const typename C::value_type maxK, const typename C::value_type minK = 0)
{
    sort(
        data, [](const auto& v) {
            return v;
        },
        maxK, minK);
}

template <typename C, typename F>
requires function<F, typename C::value_type>
void sort(C& data, F f)
{
    if (data.empty()) {
        return;
    }

    auto maxK = f(data.front());
    auto minK = maxK;
    for (const auto& v : data) {
        const auto k = f(v);
        maxK = std::max(maxK, k);
        minK = std::min(minK, k);
    }
    sort(data, f, maxK, minK);
}

template <typename C>
void sort(C& data)
{
    sort(data, [](const auto& v) {
        return v;
    });
}
