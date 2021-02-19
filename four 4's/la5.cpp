//Jackson, Scott	003092073
/* This program computes all possible combinations of arithemtic operations using four 4's
and the five basic arithmetic operators +, x, /, - and ^.*/

#include<iostream>
#include"la5.h"
#include<stack>
#include<sstream>
#include<cstdlib>
#include<cmath>
#include<algorithm>


using namespace std;

string convertToPostfix (string s);
ExpNode* makeExpTree(string s);
convertOpToInt(char op);
string convertIntToOp(int op);
void selectionsort(ExpTree data[ ], size_t n);


int main( )
{

	ExpTree treearray[625];
	size_t i=0;

	for(int op1=0;op1<5;op1++){
		for(int op2=0;op2<5;op2++){
			for(int op3=0;op3<5;op3++){
				string temp1=convertIntToOp(op1);
				string temp2=convertIntToOp(op2);
				string temp3=convertIntToOp(op3);

				/*Creates the five trees for each combination of operators and stores the 
				prefix form, postfix form, and value into a struct.  If the value is a 
				nonnegative integer, than it is stored in the tree array*/

				ExpTree tree1;
				tree1.infix="(4"+temp1+"4)"+temp3+"(4"+temp2+"4)";
				ExpNode* expTree1 = new ExpNode;
				tree1.postfix = convertToPostfix ( tree1.infix ) ;
				expTree1 = makeExpTree( tree1.postfix );
				tree1.value = expTree1->Evaluate();

				if((tree1.value>=0)&&(tree1.value-floor(tree1.value)==0)){
					treearray[i]=tree1;
					i++;
				}

				ExpTree tree2;

				tree2.infix="((4"+temp1+"4)"+temp2+"4)"+temp3+"4";
				ExpNode* expTree2 = new ExpNode;
				tree2.postfix = convertToPostfix ( tree2.infix ) ;
				expTree2 = makeExpTree( tree2.postfix );
				tree2.value = expTree2->Evaluate();

				if((tree2.value>=0)&&(tree2.value-floor(tree2.value)==0)){
					treearray[i]=tree2;
					i++;
				}

				ExpTree tree3;
				tree3.infix="4"+temp3+"(4"+temp2+"(4"+temp1+"4))";
				ExpNode* expTree3 = new ExpNode;
				tree3.postfix = convertToPostfix ( tree3.infix ) ;
				expTree3 = makeExpTree( tree3.postfix );
				tree3.value = expTree3->Evaluate();

				if((tree3.value>=0)&&(tree3.value-floor(tree3.value)==0)){
					treearray[i]=tree3;
					i++;
				}

				ExpTree tree4;
				tree4.infix="(4"+temp2+"(4"+temp1+"4))"+temp3+"4";
				ExpNode* expTree4 = new ExpNode;
				tree4.postfix = convertToPostfix ( tree4.infix ) ;
				expTree4 = makeExpTree( tree4.postfix );
				tree4.value = expTree4->Evaluate();

				if((tree4.value>=0)&&(tree4.value-floor(tree4.value)==0)){
					treearray[i]=tree4;
					i++;
				}

				ExpTree tree5;
				tree5.infix="4"+temp3+"((4"+temp1+"4)"+temp2+"4)";
				ExpNode* expTree5 = new ExpNode;
				tree5.postfix = convertToPostfix ( tree5.infix ) ;
				expTree5 = makeExpTree( tree5.postfix );
				tree5.value = expTree5->Evaluate();

				if((tree5.value>=0)&&(tree5.value-floor(tree5.value)==0)){
					treearray[i]=tree5;
					i++;
				}


			}
		}
	}

	//sorts the expression trees stored in the array in numerical order by value
	selectionsort(treearray, i);

	int n;
	cout<<"Generate four fours up to what number: \n";
	cin>>n;

	//If the value of the expression tree is less than or equal to the user inputted number
	//then the postfix, infix and value of the tree are outputted to the screen
	for (int j= 0; j < i; j++){
		if(treearray[j].value<=n)
			cout<<treearray[j].postfix<<" ->  "<<treearray[j].infix<<" = "<<treearray[j].value<<endl;

	}
	cout << endl;


	//Counts how many times each value of each expression tree occurs and outputs it to screen
	for(int k=0;k<=n;k++){
		int ct=0;
		for(int j= 0; j < i; j++){
			if(treearray[j].value==k)
				ct++;
		}
		cout<<"There are "<<ct<<" ways of generating "<<k<<endl;
	}
}


ExpNode* makeExpTree(string pf)
{
	//creates an expression tree from a string expression

	istringstream in(pf);

	char c;
	stack<ExpNode*> nodes;

	ExpNode* newRight = new ExpNode();
	ExpNode* newLeft = new ExpNode();

	ExpNode* newNode;
	while (in >> c)
	{


		if (c=='+' || c=='-' || c=='/' || c=='*' || c=='^')
		{
			newRight = nodes.top();
			nodes.pop();
			newLeft = nodes.top();
			nodes.pop();

			int intOp = convertOpToInt(c);
			newNode = new ExpNode(intOp,newLeft,newRight);	

		}
		if (c >= '0' && c <= '9')
		{
			in.putback(c);
			int n;
			in >> n;

			newNode = new ExpNode(n);

		}

		nodes.push(newNode);

	}

	ExpNode* root = nodes.top();
	nodes.pop();
	return root;
}


int priority ( char c )
{
	//sets precedence of order of operation

	if ( c == '^' ) return 3 ;/*Exponential operator*/
	if ( c == '*' || c == '/' || c == '%' )
	{
		return 2 ;
	}
	else {
		if ( c == '+' || c == '-' ) 
		{
			return 1 ;
		}
		else
		{
			return 0 ;
		}
	}
}

string convertToPostfix (string s)
{
	//converts a string expression to postfix form

	stack<char> operators;
	char opr;
	//string s;


	istringstream in(s);
	stringstream out;

	char c;

	while(in >> c){ //taking stuff into a stringstream for processing
		if (c=='+' || c=='-' || c=='/' || c=='*' || c=='^')
		{
			if ( !operators.empty() )
			{
				opr = operators.top();
				operators.pop();
				while ( priority ( opr ) >= 
					priority ( c  ) )
				{
					out << opr << " ";
					opr = operators.top(); 
					operators.pop();
				}
				operators.push( opr ) ;
				operators.push( c );
			}
			else 
			{
				operators.push(c);
			}
		}


		else if (c==('('))
		{
			operators.push(c);
		}
		else if (c==')')
		{
			opr = operators.top();
			operators.pop();
			while ( opr != '(' )
			{
				out << opr<< " ";

				opr =  operators.top();
				operators.pop();
			}
		}
		else if (c >= '0' && c <= '9')
		{
			in.putback(c);
			int n;
			in >> n;
			out << n<< " ";
		}

	}

	while (!operators.empty())
	{
		out << operators.top()<<" ";
		operators.pop();
	}

	return out.str();
}

convertOpToInt(char op)
{
	//converts an operator from an integer to a character
	switch (op)
	{
	case '+': return 0;
	case '-': return 1;
	case '*': return 2;
	case '/': return 3;
	case '^': return 4;
	default: return 0;
	}
}

string convertIntToOp(int op)
{
	//converts an operator from an integer to a string
	switch (op)
	{
	case 0: return "+";
	case 1: return "-";
	case 2: return "*";
	case 3: return "/";
	case 4: return "^";
	default: return 0;
	}
}

void selectionsort(ExpTree data[ ], size_t n)
{
	//sorts the expression tree in numerical order by its solution value
	size_t i, j, index_of_largest;
	double largest;

	if (n == 0)
		return; // No work for an empty array.

	for (i = n-1; i > 0; --i)
	{
		largest = data[0].value;
		index_of_largest = 0;
		for (j = 1; j <= i; ++j)
		{
			if (data[j].value > largest)
			{
				largest = data[j].value;
				index_of_largest = j;
			}
		}
		std::swap(data[i], data[index_of_largest]);
	}
}