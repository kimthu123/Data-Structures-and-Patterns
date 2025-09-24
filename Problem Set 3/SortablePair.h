#pragma once
#include <ostream>

template<typename K, typename V>
class SortablePair
{
public:
    SortablePair(const K& aFirst = K{}, const V& aSecond = V{}) noexcept
        : fFirst(aFirst), fSecond(aSecond) {
    }

    const K& first() const noexcept {
        return fFirst;
    }

    const V& second() const noexcept {
        return fSecond;
    }

    bool operator==(const SortablePair& aOther) const noexcept {
        return fFirst == aOther.fFirst && fSecond == aOther.fSecond;
    }

    bool operator<(const SortablePair& aOther) const noexcept {
        return fFirst > aOther.fFirst;
    }

    friend std::ostream& operator<<(std::ostream& aOStream, const SortablePair& aPair) {
        return aOStream << '(' << aPair.fFirst << ',' << aPair.fSecond << ')';
    }

private:
    K fFirst;
    V fSecond;
};
