#include "stdafx.h"
#include "ReWriterXml.h"
#include "AstNode.h"

vector<string> tag = { "SELECT",     "DISTINCT ",
                       "UPDATE",     "FROM ",
                       "ALL",        "COLUMN ",
                       "TABLE",      "WHERE ",
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

void ReWriterXml::Serialize()
{
  TraverseAst(mAst.GetRoot());
}

void ReWriterXml::TraverseAst(AstNode * aNode, int indent)
{
  if (aNode != nullptr)
  {
    mOutputStream << setw(indent) << "<" << tag[(int)aNode->GetType()] << " at=\"line "
                  << aNode->GetToken()->GetPosition().GetLine() << ", column "
                  << aNode->GetToken()->GetPosition().GetColumn() << "\" Type=\""
                  << type[(int)aNode->GetToken()->GetType()] << "'"
                  << ">\n";

    TraverseAst(aNode->GetLeft().get(), indent + 3);

    TraverseAst(aNode->GetRight().get(), indent + 3);

    mOutputStream << setw(indent) << "<\\" << tag[(int)aNode->GetType()] << ">\n";
  }
}
