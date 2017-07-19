#include "Ast.h"
#include"AstNode.h"

AstNode* Ast::NewNode(IToken * aToken)
{

	AstNode *temp = new AstNode();
	temp->mToken = aToken;
	temp->left = temp->right = nullptr;
	return temp;

	//return AstNode();
}

AstNode* Ast::InsertNode(AstNode *aNode, IToken* aToken)
{
	// If the tree is empty, return a new node 
	if (aNode == nullptr) return NewNode(aToken);

	// Otherwise, recur down the tree 
	if (aToken->GetType() != KeywordType)
		aNode->left = InsertNode(aNode->left, aToken);
	else if (aToken->GetType() == KeywordType)
		aNode->right = InsertNode(aNode->right, aToken);

	// return the (unchanged) node pointer 
	return aNode;

}

void Ast::PrintInorder(AstNode *aRoot)
{
	// A utility function to do inorder traversal of BST
	if (aRoot != nullptr)
	{
		PrintInorder(aRoot->left);
		cout << aRoot->mToken->GetWord();
		PrintInorder(aRoot->right);
	}

}








Ast::~Ast()
{
}
