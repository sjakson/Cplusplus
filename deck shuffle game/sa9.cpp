//003092073		Scott Jackson
//This is the implementation file, where the functions declared in the
//file "sa9.h" are implemented

#include "llistTemplate.h"
#include "sa9.h"
#include "sa8.h"
#include "sa7.h"
#include <iostream>

namespace pic10b{

	//Default Constructor
	rowOfCards::rowOfCards(){}

	//Overloaded Operator function
	std::ostream& operator <<(std::ostream& os, rowOfCards& r){

		const node<Card> * cursor = r.source.last();

		while(cursor!=NULL)
		{
			os<<cursor->val<<" ";
			cursor=cursor->prev;
		}

		return os;
	}


//Member function
	bool rowOfCards::consolidate(){

		node<Card> * cursor = source.begin();

		if(cursor->next!=NULL){
			if((cursor->val)==((cursor->next)->val)){
				source.erase(cursor->next);
				return true;
			}

			else if(source.size()>=5){
				if((cursor->val)==((cursor->next->next->next->next)->val)){

					cursor = cursor->next->next->next->next;

					source.insert(cursor,source.begin()->val);

					source.erase(cursor);
					source.erase(source.begin());

					return true;
				}
			}

			else
				return false;

		}
		else
			return false;



	}

}



