#include "Parser.h"
#include"Ast.h"

bool Parser::StartParsing()
{

	return true;
}

bool Parser::isBegin(IToken * aToken)
{
	
	return find(mBegin.begin(), mBegin.end(), aToken->GetWord()) != mBegin.end();
		
	
}

bool Parser::isIntermediar(IToken * aToken)
{
	return (find(mIntermediar.begin(), mIntermediar.end(), aToken->GetWord()) != mIntermediar.end());
}

bool Parser::isFinal(IToken * aToken)
{
	return (find(mFinal.begin(), mFinal.end(), aToken->GetWord()) != mFinal.end());
}

const vector<IToken*> Parser::GetKeywords() 
{
	return mKeywords;
}

Parser::~Parser()
{
}
void Parser::SetCommands()
{
	AstNode prev(new Begin(*mKeywords.begin()));
	AstNode current(nullptr);
	Ast ast(prev);
	int ok = 1;
	
	
	for ( auto it:mKeywords)

	{
	
		if (isBegin(it))
		{
			AstNode aux=new Begin(it);
			current=move(aux);
			if (!prev.mCommand->ExpectedNext(current.mCommand))
			{
				cout << "Another command expected 1 " <<endl;

				return;
			}
			
			
		}
		else if (isIntermediar(it))
		{

			AstNode aux = new Intermediar(it);
			current = move(aux);
			if (!prev.mCommand->ExpectedNext(current.mCommand))
			{
				cout << "Another command expected 2 " << endl;
				
				return;
			}
			ok++;
			ast.Insert(current,ok);
		}
		else if (isFinal(it))
		{

			AstNode aux = new Final(it);
			current = move(aux);
			if (!prev.mCommand->ExpectedNext(current.mCommand))
			{
				cout << "Another command expected 3  "  << endl;
				return;
			}
			ok++;
			ast.Insert(current,ok);
		}
		else if (it->GetWord() != " ")
		{
			AstNode aux = new Word(it);
			ok++;
			ast.Insert(aux,ok);

		}
		
		
		prev = move(current);
		

	}

}