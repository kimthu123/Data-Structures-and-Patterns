
#include "FibonacciSequenceIterator.h"
#include <cassert>

FibonacciSequenceIterator::FibonacciSequenceIterator(FibonacciSequence* aSequence, uint64_t aStart) noexcept :
    fSequence(aSequence),
    fIndex(aStart)
{
    if (fSequence != nullptr)
    {
        fSequence->begin();  
    }
}

const uint64_t& FibonacciSequenceIterator::operator*() const noexcept
{
    assert(fSequence != nullptr);
    return *(*fSequence);  
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept
{
    assert(fSequence != nullptr);
    ++(*fSequence);  // Advance the Fibonacci sequence
    ++fIndex;        // Move to next index
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    FibonacciSequenceIterator temp = *this;
    ++(*this);  // Use prefix increment
    return temp;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept
{
    return fIndex == aOther.fIndex;
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept
{
    if (fSequence != nullptr)
    {
        fSequence->begin();  // Restart the sequence
    }
    return FibonacciSequenceIterator(fSequence, 0);
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept
{
    return FibonacciSequenceIterator(fSequence, MAX_FIBONACCI); 
}
