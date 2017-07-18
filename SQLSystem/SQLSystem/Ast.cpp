#include "Ast.h"
#include"AstNode.h"







void Ast::Insert(AstNode aNode,int aN)
{	

	AstNode* t = new AstNode;
	AstNode* parent;
	t->mOk = aN;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	
		AstNode* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->mOk > curr->mOk) curr = curr->right;
			else curr = curr->left;
		}

		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	


}

Ast::~Ast()
{
}
