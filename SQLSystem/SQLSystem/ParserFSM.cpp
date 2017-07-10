#include "ParserFSM.h"



ParserFSM::ParserFSM()
{
}

void ParserFSM::Start(vector<IToken*>& tokens)
{

	for_each(tokens.begin(), tokens.end(), [&](IToken *token)
	{
		switch (mCurrentState)
		{
		case ALL:
			break;
		case AND:
			break;
		case BETWEEN:
			break;
		case CREATE_TABLE:
			break;
		case DELETE:
			break;
		case FROM:
			break;
		case IN:
			break;
		case INSERT:
			break;
		case INSERT_INTO:
			break;
		case LIKE:
			break;
		case OR:
			break;
		case ORDER_BY:
			break;
		case NOT:
			break;
		case STAR:
			break;
		case SET:
			break;
		case SELECT:
			break;
		case UPDATE:
			break;
		case WHERE:
			break;
		case NAME:
			break;
		default:
		{
			cout << "";
			break;
		}
		}
	});
}



ParserFSM::~ParserFSM()
{
}
