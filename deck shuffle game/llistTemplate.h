#ifndef LLIST_H
#define LLIST_H

#include <cstdlib>
#include <iostream>

template<typename T>
class node
{
public:
    typedef T value_type;

	value_type val;
	node<T> * prev;
	node<T> * next;
};

template<typename T>
class llist
{
public:
        typedef typename node<T>::value_type value_type;
        typedef int size_type;

	llist();
	llist(const llist & the_list);
	~llist() {clear();}

	llist<T>& operator=(const llist & the_list);

	node<T>* begin() {return head;}
	const node<T> * begin() const {return head;}

	node<T>* last() {return tail;}
	const node<T>* last() const {return tail;}
	
	node<T>* find(const value_type & v,const size_type & which_one = 1);

	node<T>* insert(node<T>* where = NULL,const value_type & v = value_type());
	node<T>* erase(node<T>* where = NULL);
	void clear();

	size_type size() const;
	bool empty() const {return head==NULL;}
private:
	node<T> * head;
	node<T> * tail;
};

template<typename T>
std::ostream & operator<<(std::ostream & os,const llist<T> & the_list);

#include "llist.template"

#endif


