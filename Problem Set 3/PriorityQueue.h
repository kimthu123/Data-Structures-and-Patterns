#pragma once

#include "SortablePair.h"
#include <optional>
#include <cassert>
#include <algorithm>

template<typename T, typename P>
class PriorityQueue
{
public:
    using value_type = SortablePair<P, T>;

    PriorityQueue() noexcept :
        fElements(new value_type[1]),
        fHead(0),
        fTail(0),
        fCapacity(1)
    {
    }

    ~PriorityQueue() noexcept
    {
        delete[] fElements;
    }

    PriorityQueue(const PriorityQueue&) = delete;
    PriorityQueue& operator=(const PriorityQueue&) = delete;

    size_t count() const noexcept
    {
        return fTail - fHead;
    }

    size_t capacity() const noexcept
    {
        return fCapacity;
    }

    std::optional<T> top() const noexcept
    {
        if (count() > 0)
        {
            return std::optional<T>(fElements[fHead].second());
        }

        return std::nullopt;
    }

    void push(const T& aValue, const P& aPriority) noexcept
    {
        ensure_capacity();

        // Construct in place using placement new
        new (&fElements[fTail++]) value_type(aPriority, aValue);

        sort();
    }

    void pop() noexcept
    {
        assert(count() > 0);

        fHead++;

        adjust_capacity();
    }

private:
    value_type* fElements;
    size_t fHead;
    size_t fTail;
    size_t fCapacity;

    void sort() noexcept
    {
        std::sort(&fElements[fHead], &fElements[fTail]);
    }

    void resize(size_t aCapacity)
    {
        assert(count() <= aCapacity);

        value_type* lNewElements = new value_type[aCapacity];

        // Copy elements from old to new, adjusted from fHead
        for (size_t i = 0; i < count(); i++)
        {
            lNewElements[i] = fElements[fHead + i];
        }

        delete[] fElements;

        fElements = lNewElements;
        fTail = count();   // reset tail to the end of new data
        fHead = 0;         // reset head to 0
        fCapacity = aCapacity;
    }

    void ensure_capacity()
    {
        if (fTail == fCapacity)
        {
            resize(fCapacity * 2);
        }
    }

    void adjust_capacity()
    {
        if (count() <= fCapacity / 4 && fCapacity > 1)
        {
            resize(fCapacity / 2);
        }
    }
};
