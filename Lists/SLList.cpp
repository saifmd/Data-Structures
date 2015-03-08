
#include "SLList.h"
#include <stdlib.h>

// Destructor
template <class T>
SLList<T>::~SLList()
{
	SLListNode<T>* current;
	while(head)
	{
		current = head->next;
		delete head;
		head = current;
	}
}
/* Queue function Add - adds the element
   at the end of the list */
template <class T>
SLList<T> & SLList<T>::Add(const T &x)
{
    SLListNode<T> *n = new SLListNode<T>;
    n->data = x;
    n->next = NULL;
    if(isEmpty())
        head = n;
    else
        tail->next = n;

    tail = n;
    length++;
    return *this;
}
/* Queue function Remove - Returns the first
    element from the list */
template <class T>
T SLList<T>::Remove()
{
    if(isEmpty())
        return NULL;
   T n = head->data;
   head = head->next;
   if(--length == 0) tail=NULL;
   return n;
}

/* Stack function Push - Adds the element
    at the begining of the list */
template <class T>
SLList<T> & SLList<T>::Push(const T &x)
{
    SLListNode<T> *n = new SLListNode<T>;
    n->data = x;
    n->next = head;
    head = n;
    if(length == 0) tail = n;
    length++;
    return *this;
}
/* Stack function Pop - Returns first element
    from the list */
template <class T>
T SLList<T>::Pop()
{
    if(isEmpty())
        return NULL;
    T x = head->data;
    if(--length == 0)
        head = tail = NULL;
    else
        head = head->next;
    return x;
}
template<class T>
void SLList<T>::output(std::ostream &out) const
{
    SLListNode<T> *node = head;
    //for(int i = 0; i< length; i++)
    while(node)
    {
        out<<node->data<<" ";
        node = node->next;
    }
}
template<class T>
std::ostream & operator<<(std::ostream &out, SLList<T> &sll)
{
    sll.output(out);
    return out;
}
/* Inserts the element at position k */
template <class T>
SLList<T>& SLList<T>::Insert(int k,const T &x)
{
	int index = 1;
	if(k<0)
		throw std::bad_alloc();
	SLListNode<T>* p = head;
	//move p to k'th element
	for(index = 1; index <k && p ;index++)
		p = p->next;

	//no k'th
	if(k>0 && !p)
		throw std::bad_alloc();
	//insert a new node
	SLListNode<T>* node = new SLListNode<T>;
	node->data = x;
	// if k is not the first position
	if(k)
	{
		node->next = p->next;
		p->next = node;
	}
	else
	{
		// if k is the first position i.e 0
		node->next = head;
		head = node;
	}
	length++;
	return *this;
}
/* Deletes the element at position k and returns
    it in reference variable x */
template <class T>
SLList<T>& SLList<T>::Delete(int k,T &x)
{
	int index = 1;
	// no k'th
	if(k<1 || isEmpty())
		throw std::bad_alloc();
	SLListNode<T>* p = head;
	if(k==1)
	{
		// p already at k'th
		head = head->next;
	}
	else
	{
		// prev pointer will be at k-1 and p will be at k
		SLListNode<T>* prev;
		while(index < k && p)
		{
			prev = p;
			p = p->next;
			index++;
		}
		// remove p from SLList
		prev->next = p->next;
	}
	x = p->data;
	delete p;
	length--;
	return *this;
}
/* Returns the position of the element */
template <class T>
int SLList<T>::Search(const T &x) const
{
	/* Find x and return its position */
	SLListNode<T>* p = head;
	int index = 1;
	while(p)
	{
		if(p->data == x)
			break;
		index++;
		p = p->next;
	}
	if(p)
	{
		return index;
	}
	return 0;
}
/* Returns true if the element exists at
    position k in reference variable x */
template <class T>
bool SLList<T>::Find(int k,T &x) const
{
	/* Find k'th element and set it to x */
	if(k<1)
		return false;
	SLListNode<T>* p = head;
	int index = 1;
	while(index < k && p)
	{
		index++;
		p = p->next;
	}
	if(p)
	{
		x = p->data;
		return true;
	}

	return false;
}
/* Overload [] operator to access list elements
    using an index */
template <class T>
T & SLList<T>::operator[](const int index)
{
    if(index<0 || index>Length() || isEmpty())
        throw std::bad_alloc();
    SLListNode<T>* p = head;
    for(int i=0; i<index; i++)
    {
            p=p->next;
    }

    if(p)
        return (p->data);
    else
        throw std::bad_alloc();
}
