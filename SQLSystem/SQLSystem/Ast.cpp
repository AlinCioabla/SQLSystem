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

void Ast::Display(AstNode * aNode, int indent)
{
  if (aNode != nullptr)
  {
    if (aNode->GetRight())
    {
      Display(aNode->GetRight(), indent + 4);
    }
    if (indent)
    {
      cout << setw(indent) << " ";
    }
    if (aNode->GetRight())
      cout << " /\n" << setw(indent) << ' ';
    cout << aNode->GetToken()->GetWord() << "\n ";
    if (aNode->GetLeft())
    {
      cout << setw(indent) << ' ' << " \\\n";
      Display(aNode->GetLeft(), indent + 4);
    }
  }
}

void Ast::PrintQuery(AstNode * aNode)
{
  if (aNode != nullptr)
  {
    if (aNode->GetToken()->GetType() == KeywordType)
    {
      cout << aNode->GetToken()->GetWord() << " ";
    }
    PrintQuery(aNode->GetLeft());
    if (aNode->GetToken()->GetType() != KeywordType)
    {
      cout << aNode->GetToken()->GetWord() << " ";
    }
    PrintQuery(aNode->GetRight());
  }
}

Ast::~Ast()
{
}
