#include "stdafx.h"
#include "XmlRewriter.h"
#include "AstNode.h"
#include "WriterXml.h"

namespace
{
vector<string> tag = { "SELECT",     "DISTINCT ",
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

vector<string> type = {
  "KeywordType",    "OperatorType", "PunctuationType", "WhiteSpaceType",
  "IdentifierType", "NumberType",   "PredicateType",   "TextualOperatorType"
};
}
void XmlRewriter::Serialize()
{
  TraverseAst(mAst.GetRoot());
  mOutputStream << endl << endl;
}

void XmlRewriter::TraverseAst(AstNode * aNode, int indent)
{
  WriterXml mXmlWr(mOutputStream);
  bool      hasChildren = 0;
  if (aNode != nullptr)
  {
    if (aNode->GetRight() != nullptr || aNode->GetLeft() != nullptr)
    {
      hasChildren = 1;
    }
    mXmlWr.AddNode(
      tag[static_cast<int>(aNode->GetType())], hasChildren,
      aNode->GetToken()->GetPosition().GetLine(), aNode->GetToken()->GetPosition().GetColumn(),
      type[static_cast<int>(aNode->GetToken()->GetType())], aNode->GetToken()->GetWord());

    mOutputStream << setw(indent) << "<" << tag[static_cast<int>(aNode->GetType())] << R"(  Line=")"
                  << aNode->GetToken()->GetPosition().GetLine() << R"(" Column=")"
                  << aNode->GetToken()->GetPosition().GetColumn() << R"(" Type=")"
                  << type[static_cast<int>(aNode->GetToken()->GetType())] << R"(")"
                  << R"( Word=")" << aNode->GetToken()->GetWord() << R"(")"
                  << ">";

    if (hasChildren)
    {
      mOutputStream << "\n";
    }

    TraverseAst(aNode->GetLeft().get(), indent + 3);

    TraverseAst(aNode->GetRight().get(), indent + 3);

    if (hasChildren)
    {
      mOutputStream << setw(indent) << "</" << tag[static_cast<int>(aNode->GetType())] << ">\n";
    }
    else
    {
      mOutputStream << "</" << tag[static_cast<int>(aNode->GetType())] << ">\n";
    }
  }
}
