// COS30008, Problem Set 2, 2025
#pragma once

#include <string>
#include <cstdint>
#include <concepts>    // Required for std::forward_iterator

constexpr uint64_t MAX_FIBONACCI = 93;

class FibonacciSequence
{
private:
    uint64_t fPrevious; // initially 0
    uint64_t fCurrent;  // initially 1

public:
    using iterator = FibonacciSequence;
    using difference_type = std::ptrdiff_t;
    using value_type = uint64_t;

    FibonacciSequence() noexcept;

    const uint64_t& operator*() const noexcept;
    FibonacciSequence& operator++() noexcept;     // Prefix
    FibonacciSequence operator++(int) noexcept;   // Postfix

    bool operator==(const FibonacciSequence& aOther) const noexcept;

    void begin() noexcept;
    void end() noexcept;
};

// ✅ THIS LINE requires C++20 to compile!
static_assert(std::forward_iterator<FibonacciSequence>);
