#include "Ast.h"
#include "AstNode.h"

AstNode * Ast::NewNode(IToken * aToken)
{
  auto * temp = new AstNode();
  temp->SetToken(aToken);
  temp->SetLeft(nullptr);
  temp->SetRight(nullptr);
  return temp;
}

AstNode * Ast::InsertNode(AstNode * aNode, IToken * aToken)
{
  AstNode * prev(NewNode(aToken));
  // If the tree is empty, return a new node
  if (aNode == nullptr)
  {
    return NewNode(aToken);
  }

  // Otherwise, recur down the tree
  if (aToken->GetType() != KeywordType)
  {
    aNode->SetLeft(InsertNode(aNode->GetLeft(), aToken));
  }
  else if (aToken->GetType() == KeywordType)
  {
    aNode->SetRight(InsertNode(aNode->GetRight(), aToken));
  }
  // return the (unchanged) node pointer
  return aNode;
}

void Ast::PrintInorder(AstNode * aRoot)
{
  // A utility function to do inorder traversal of BST
  if (aRoot != nullptr)
  {
    PrintInorder(aRoot->GetLeft());
    cout << aRoot->GetToken()->GetWord();
    PrintInorder(aRoot->GetRight());
  }
}

void Ast::Display(AstNode * current, int indent)
{
  if (current != nullptr)
  {
    Display(current->GetLeft(), indent + 4);
    if (indent > 0)
    {
      cout << setw(indent) << " ";
    }
    cout << current->GetToken()->GetWord() << endl;
    Display(current->GetRight(), indent + 4);
  }
}

Ast::~Ast() = default;
