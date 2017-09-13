#include "stdafx.h"
#include "XmlRewriter.h"
#include "AstNode.h"
#include "TypeDeducer.h"
#include "WriterXml.h"
#include "XmlNodeAttributes.h"

void XmlRewriter::Serialize()
{
  mXmlWr.StartDocument();
  TraverseAst(mAst.GetRoot());
  mXmlWr.EndDocument();
  mXmlWr.Write();
}

void XmlRewriter::TraverseAst(AstNode * aNode)
{
  bool hasChildren = false;
  if (aNode != nullptr)
  {
    if (aNode->GetRight() != nullptr || aNode->GetLeft() != nullptr)
    {
      hasChildren = true;
    }

    TypeDeducer typeDeducer;
    aNode->Accept(typeDeducer);
    auto nodeAttr = GetNodeAttr(aNode);

    mXmlWr.AddNode(typeDeducer.GetOutput(), hasChildren, nodeAttr);

    TraverseAst(aNode->GetLeft().get());

    TraverseAst(aNode->GetRight().get());

    if (hasChildren)
      mXmlWr.CloseNode();
  }
}

vector<pair<string, string>> XmlRewriter::GetNodeAttr(AstNode * aNode)
{
  vector<pair<string, string>> temp;

  temp.push_back({ "Line"s, to_string(aNode->GetToken()->GetPosition().GetLine()) });
  temp.push_back({ "Column"s, to_string(aNode->GetToken()->GetPosition().GetColumn()) });
  temp.push_back({ "Word"s, aNode->GetToken()->GetWord() });

  return temp;
}
