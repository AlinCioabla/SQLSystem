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

void Ast::printTree(AstNode * current) throw()
{
  if (current->GetRight() != nullptr)
  {
    printTree(true, "");
  }
  printNodeValue(current);
  if (current->GetLeft() != nullptr)
  {
    printTree(false, "");
  }
}
void Ast::printNodeValue(AstNode * current) throw()
{
  if (current->GetToken() == nullptr)
  {
    cout << "null";
  }
  else
  {
    cout << current->GetToken()->GetWord();
  }
  cout << endl;
}
// use string and not stringbuffer on purpose as we need to change the indent at each recursion
void Ast::printTree(bool isRight, string indent) throw()
{
  if (right != nullptr)
  {
    printTree(true, indent + (isRight ? "        " : " |      "));
  }
  cout << indent;
  if (isRight)
  {
    cout << " /";
  }
  else
  {
    cout << " \\";
  }
  cout << "----- ";
  ////
  if (left != nullptr)
  {
    printTree(false, indent + (isRight ? " |      " : "        "));
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

Ast::~Ast()
{
}
