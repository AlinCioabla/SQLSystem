#include "stdafx.h"
#include "XmlRewriter.h"
#include "AstNode.h"
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
  if (aNode != nullptr)
  {
    mOutputStream << setw(indent) << "<" << tag[static_cast<int>(aNode->GetType())]
                  << R"( At Line=")" << aNode->GetToken()->GetPosition().GetLine()
                  << R"(", Column=")" << aNode->GetToken()->GetPosition().GetColumn()
                  << R"(" Type=")" << type[static_cast<int>(aNode->GetToken()->GetType())] << R"(")"
                  << R"( Word=")" << aNode->GetToken()->GetWord() << R"(")"
                  << ">";

    if (aNode->GetRight() != nullptr || aNode->GetLeft() != nullptr)
    {
      mOutputStream << "\n";
    }

    TraverseAst(aNode->GetLeft().get(), indent + 3);

    TraverseAst(aNode->GetRight().get(), indent + 3);

    if (aNode->GetRight() != nullptr || aNode->GetLeft() != nullptr)
    {
      mOutputStream << setw(indent) << "</" << tag[static_cast<int>(aNode->GetType())] << ">\n";
    }
    else
    {
      mOutputStream << "</" << tag[static_cast<int>(aNode->GetType())] << ">\n";
    }
  }
}
