#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"

Ast::Ast(const Ast & aAst)
{
}

Ast::Ast()
{
  mRoot = nullptr;
}

void Ast::Display(AstNode * aNode, int indent) const
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

void Ast::SetRoot(AstNodePtr aNode)
{
  if (mRoot == nullptr)
  {
    mRoot = move(aNode);
  }
}

void Ast::InsertLeft(AstNodePtr aNode, TokenPtr aToken)
{
  if (aNode != nullptr)
  {
    auto temp = aNode->GetLeft();
    aNode->SetLeft(Ast::GetNewNode(move(aToken)));
    aNode->GetLeft()->SetLeft(make_unique<AstNode>(temp));


    auto newNode = Ast::GetNewNode(move(aToken));
    newNode->SetLeft(move(aNode->ReleaseRight());
    aNode->SetLeft(newNode);


  }
}

void Ast::InsertRight(AstNodePtr aNode, TokenPtr aToken)
{
  if (aNode != nullptr)
  {
    auto temp = aNode->GetRight();
    aNode->SetRight(Ast::GetNewNode(aToken));
    aNode->GetRight()->SetRight(temp);
  }
}

Ast::~Ast()
{
}
