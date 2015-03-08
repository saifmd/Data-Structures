#ifndef SLLIST_H
#define SLLIST_H
#include <iostream>

template <class T>
class SLList;
template <class T>
class SLListNode
{
  T data;
  SLListNode<T> *next;
  friend class SLList<T>;
};

template <class T>
class SLList
{
    int length;
    SLListNode<T> *head;
    SLListNode<T> *tail;
public:
    SLList():length(0), head(NULL), tail(NULL){}
    ~SLList();
    int Length() const
    {
        return length;
    }
    bool isEmpty() const
    {
     if(Length() == 0)
        return true;
     return false;
    }
    SLList<T> & Add(const T &x);
    T Remove();
    SLList<T> & Push(const T &x);
    T Pop();
    void output(std::ostream &out) const;
    SLList<T>& Insert(int k,const T &x);
    SLList<T>& Delete(int k,T &x);
    int Search(const T& x) const;
    bool Find(int k,T& x) const;
    T & operator[](const int index);

};
template <class T>
std::ostream & operator<<(std::ostream &out, const SLList<T> &sll);

#endif SLLIST_H
