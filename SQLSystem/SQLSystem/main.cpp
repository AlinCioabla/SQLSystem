#include "stdafx.h"
#include "Ast.h"
#include "AstNode.h"
#include "Lexer.h"
#include "LexerTester.h"
#include "Parser.h"
#include "SQLSystem.h"
#include "TestUnit.h"

int main()
{
  /*ifstream                     in("TestFile1.txt");
  unique_ptr<Parser>           parser = make_unique<Parser>();
  unique_ptr<ITokensTraversal> lexer  = make_unique<Lexer>();
  lexer->ReadFromFile(in);
  lexer->Tokenize();

  parser->Parse(lexer);

  Ast & ast = parser->GetAst();
  ast.Display(ast.GetRoot(), 20);*/

  ParserTests();

  return 0;
}
