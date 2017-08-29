#include "stdafx.h"
#include "XmlRewriter.h"
#include "AstNode.h"
#include "WriterXml.h"
#include "XmlNodeAttributes.h"

namespace
{
const vector<string> tag = { "SELECT",     "DISTINCT ",
                             "UPDATE",     "FROM",
                             "ALL",        "COLUMN",
                             "TABLE",      "WHERE",
                             "DELETE",     "INSERT",
                             "INTO",       "VALUES",
                             "VALUE",      "OR",
                             "AND",        "LIKE",
                             "NOTLIKE",    "EQUALS",
                             "PLUSOP",     "MINUS",
                             "DIVISIONOP", "MULTIPLICATIONOP",
                             "NUMBER",     "PREDICATE",
                             "COMMA",      "INVALID" };

const vector<string> type = { "KeywordType",    "OperatorType",       "PunctuationType",
                              "WhiteSpaceType", "IdentifierType",     "NumberType",
                              "PredicateType",  "TextualOperatorType" };
}
void XmlRewriter::Serialize()
{
  TraverseAst(mAst.GetRoot());
  mOutputStream << endl << endl;
}

void XmlRewriter::TraverseAst(AstNode * aNode)
{
  bool hasChildren = 0;
  if (aNode != nullptr)
  {
    if (aNode->GetRight() != nullptr || aNode->GetLeft() != nullptr)
    {
      hasChildren = true;
    }

    mXmlWr.AddNode(tag[static_cast<int>(aNode->GetType())],
                   aNode->GetToken()->GetPosition().GetLine(),
                   aNode->GetToken()->GetPosition().GetColumn(),
                   type[static_cast<int>(aNode->GetToken()->GetType())],
                   aNode->GetToken()->GetWord(), hasChildren);

    TraverseAst(aNode->GetLeft().get());

    TraverseAst(aNode->GetRight().get());

    mXmlWr.CloseNode(tag[static_cast<int>(aNode->GetType())],
                     aNode->GetToken()->GetPosition().GetLine(),
                     aNode->GetToken()->GetPosition().GetColumn(),
                     type[static_cast<int>(aNode->GetToken()->GetType())],
                     aNode->GetToken()->GetWord(), hasChildren);
  }
}
