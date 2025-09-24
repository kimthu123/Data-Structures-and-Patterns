// COS30008, Problem Set 4, 2025
#pragma once
#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

template<typename T>
class List
{
private:
    using node = typename DoublyLinkedList<T>::node;
    node fHead;
    node fTail;
    size_t fSize;

public:
    using iterator = DoublyLinkedListIterator<T>;

    // Default constructor
    List() noexcept;

    // Destructor
    ~List();

    // Copy semantics
    List(const List& aOther);
    List& operator=(const List& aOther);

    // Move semantics
    List(List&& aOther) noexcept;
    List& operator=(List&& aOther) noexcept;

    // Swap
    void swap(List& aOther) noexcept;

    // Basic operations
    size_t size() const noexcept;

    template<typename U>
    void push_front(U&& aData);

    template<typename U>
    void push_back(U&& aData);

    void remove(const T& aElement) noexcept;
    const T& operator[](size_t aIndex) const;

    // Iterator interface
    iterator begin() const noexcept;
    iterator end() const noexcept;
    iterator rbegin() const noexcept;
    iterator rend() const noexcept;
};


#include <stdexcept>

// Default constructor
template<typename T>
List<T>::List() noexcept : fHead(nullptr), fTail(nullptr), fSize(0) {}

// Destructor
template<typename T>
List<T>::~List()
{
    while (fTail)
    {
        node lNode = fTail->previous.lock();
        fTail->next.reset();
        fTail = lNode;
    }
}

// Copy constructor
template<typename T>
List<T>::List(const List& aOther) : List()
{
    for (const T& item : aOther)
    {
        push_back(item);
    }
}

// Copy assignment
template<typename T>
List<T>& List<T>::operator=(const List& aOther)
{
    if (this != &aOther)
    {
        List temp(aOther);
        swap(temp);
    }
    return *this;
}

// Move constructor
template<typename T>
List<T>::List(List&& aOther) noexcept
    : fHead(std::move(aOther.fHead)), fTail(std::move(aOther.fTail)), fSize(aOther.fSize)
{
    aOther.fSize = 0;
}

// Move assignment
template<typename T>
List<T>& List<T>::operator=(List&& aOther) noexcept
{
    if (this != &aOther)
    {
        swap(aOther);
    }
    return *this;
}

// Swap
template<typename T>
void List<T>::swap(List& aOther) noexcept
{
    std::swap(fHead, aOther.fHead);
    std::swap(fTail, aOther.fTail);
    std::swap(fSize, aOther.fSize);
}

// Size
template<typename T>
size_t List<T>::size() const noexcept
{
    return fSize;
}

template<typename T>
template<typename U>
void List<T>::push_front(U&& aData)
{
    node lNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));

    node nullNode; 
    lNode->link(nullNode, fHead);

    if (fHead)
        fHead->previous = lNode;
    else
        fTail = lNode;

    fHead = lNode;
    fSize++;
}


// Push back
template<typename T>
template<typename U>
void List<T>::push_back(U&& aData)
{
    node lNode = DoublyLinkedList<T>::makeNode(std::forward<U>(aData));

    node nullNode;
    lNode->link(fTail, nullNode);

    if (fTail)
        fTail->next = lNode;
    else
        fHead = lNode;

    fTail = lNode;
    fSize++;
}


// Remove first matching element
template<typename T>
void List<T>::remove(const T& aElement) noexcept
{
    for (node iter = fHead; iter != nullptr; iter = iter->next)
    {
        if (iter->data == aElement)
        {
            if (iter == fHead)
                fHead = fHead->next;
            if (iter == fTail)
                fTail = iter->previous.lock();

            iter->isolate();
            fSize--;
            return;
        }
    }
}

// Indexer
template<typename T>
const T& List<T>::operator[](size_t aIndex) const
{
    if (aIndex >= fSize)
        throw std::out_of_range("Index out of bounds");

    node iter = fHead;
    for (size_t i = 0; i < aIndex; ++i)
        iter = iter->next;

    return iter->data;
}

// Iterators
template<typename T>
typename List<T>::iterator List<T>::begin() const noexcept
{
    return iterator(fHead, fTail).begin();
}

template<typename T>
typename List<T>::iterator List<T>::end() const noexcept
{
    return iterator(fHead, fTail).end();
}

template<typename T>
typename List<T>::iterator List<T>::rbegin() const noexcept
{
    return iterator(fHead, fTail).rbegin();
}

template<typename T>
typename List<T>::iterator List<T>::rend() const noexcept
{
    return iterator(fHead, fTail).rend();
}
