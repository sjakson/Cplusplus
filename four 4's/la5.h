//Jackson, Scott	003092073
/*This is the header file that stores the expression tree node struct and the 
expression tree struct*/

#ifndef EXPRNODE_H
#define EXPREODE_H

const int NUMBER = 0,    // Values representing two kinds of nodes.
OPERATOR = 1;

#include<string>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<cstdlib>

struct ExpNode {  // A node in an expression tree.

	int kind;        // Which type of node is this?
	//   (Value is NUMBER or OPERATOR.)           
	double number;   // The value in a node of type NUMBER.            
	int op, op1, op2, op3;         // The operator in a node of type OPERATOR.            
	ExpNode *left;   // Pointers to subtrees,            
	ExpNode *right;  //     in a node of type OPERATOR.

	ExpNode *GetLeftSubtree() const { return left; }
	ExpNode *GetRightSubtree() const { return right; }

	ExpNode(){}

	ExpNode( double val ) 
	{                  
		// Constructor for making a node of type NUMBER.
		// The are only allowed to me leaves
		kind = NUMBER;              
		number = val; 
		this->left = NULL;
		this->right = NULL;
	}

	ExpNode( int op, ExpNode *left, ExpNode *right ) 
	{
		// Constructor for making a node of type OPERATOR.               
		kind = OPERATOR;               
		this->op = op;               
		this->left = left;               
		this->right = right;           
	}

	std::string ToString() const
	{
		//Converts the value in the node from an integer to a string
		if (kind == NUMBER)
		{
			std::stringstream s;
			s << int(number);

			return s.str();
		}
		else 
		{
			switch (op)
			{      
			case 0: return "+";
			case 1: return "-";
			case 2: return "*";
			case 3: return "/";
			case 4: return "^";
			}

			return "?";
		}
	}


	double Evaluate() const
	{
		//computes the solution to the expression tree
		if (kind == NUMBER)
		{
			return number;
		}
		else
		{
			double lhs = GetLeftSubtree()->Evaluate();
			double rhs = GetRightSubtree()->Evaluate();

			switch (op)
			{
			case 0: return lhs + rhs;
			case 1: return lhs - rhs;
			case 2: return lhs * rhs;
			case 3: return lhs / rhs;
			case 4: return pow(lhs, rhs);
			}

		}

	}

}; 

struct ExpTree{

	//stores the infix form , postfix form and solution for each expression tree
	std::string infix;
	std::string postfix;
	double value;
};


#endif
