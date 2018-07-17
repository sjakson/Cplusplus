//003092073		Scott Jackson
//This is the implementation file, where the functions declared in the
//file "la4.h" are implemented

#include "llist.h"
#include "la4.h"
#include "qqueue.h"
#include <iostream>
#include <fstream>

namespace pic10b{

	//Default Constructor

	ladder::ladder(){}

	//Member functions
	void ladder::LoadWords(){

		std::ifstream fin;
		std::string next;

		fin.open("words5.txt");


		if(fin.fail()){      
			std::cout << "Input file opening failed.\n";        
			exit(1);
		}

		while(!fin.eof()){
			fin>>next;
			temp=new Wnode;
			temp->word=next;
			temp->prev=NULL;
			myWords.push_back(temp);
		}
	}

	bool ladder::FindLadder(const std::string & first,const std::string & target){

		for(int i=0;i<myWords.size()-1;i++){
			if(myWords[i]->word==target){
				begin=myWords[i];
				begin->prev=begin;
				break;
			}
		}


		end=new Wnode;
		temp=new Wnode;
		end->word=first;
		q.push(begin);
		bool again=true;


		do{
			temp=q.front();
			q.pop();
			for(int i=0;i<myWords.size()-1;i++){
				if(isOneApart(temp->word,myWords[i]->word)){
					if(myWords[i]->word==end->word){
						myWords[i]->prev=temp;
						end->prev=temp;
						again=false;
						return true;

					}
					else{ 
						if(myWords[i]->prev==NULL){
							myWords[i]->prev=temp;
							//std::cout<<myWords[i]->word;
							q.push(myWords[i]);
						}
					}
				}
			}

		}while(again && !q.empty());
		return false;
	}

	void ladder::Clear(){

		for(int i=0;i<myWords.size();i++)
			myWords[i]->prev=NULL;

	}

	void ladder::Print(){

		temp=new Wnode;
		temp->word=end->word;
		temp->prev=end->prev;

		do{
			std::cout<<temp->word<<std::endl;
			temp=temp->prev;

		}while(temp!=temp->prev);
		std::cout<<temp->word<<std::endl;
	}
	//Nonmember function
	bool isOneApart(const std::string & s1,const std::string & s2){

		int ct=0;

		for(int i=0;i<5;i++){
			if(s1[i]==s2[i])
				ct++;

		}

		if(ct==4)
			return true;
		else
			return false;


	}



}






