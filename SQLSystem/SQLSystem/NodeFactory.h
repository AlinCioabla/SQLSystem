#pragma once
#include "IToken.h"
#include "AstNode.h"

class NodeFactory
{
public:
  NodeFactory() = default;
  AstNodePtr GetNode(string aNodeType, TokenPtr & aToken);
};
