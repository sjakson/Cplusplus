#ifndef QQUEUE_H
#define QQUEUE_H

#include "llist.h"

template<typename T>
class qqueue
{
friend std::ostream& operator<<(std::ostream& os, qqueue<T>& q){
		os << q.source;
		return os;
	}

public:
	typedef T value_type;
	typedef typename llist<T>::size_type size_type;

	qqueue<T> & push(const value_type & v) {source.insert(NULL,v); return *this;}
	value_type pop() 
	{
		value_type temp = source.begin()->val;
		source.erase(source.begin());
		return temp;
	}

	value_type & front() {return source.begin()->val;}
	const value_type & front() const {return source.begin()->val;}

	value_type & back() {return source.last()->val;}
	const value_type & back() const {return source.last()->val;}

	size_type size() const {return source.size();}
	bool empty() const {return source.empty();}		
private:
	llist<T> source;
};

#endif


