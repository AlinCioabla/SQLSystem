#pragma once
#include "IToken.h"
#include "AstNode.h"

class NodeFactory
{
public:
  NodeFactory();
  AstNodePtr GetNode(string aNodeType, TokenPtr & aToken);
};
