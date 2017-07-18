#pragma once

#include"stdafx.h"

string keywords[]{ "SELECT","DELETE","UPDATE","INSERT",
"FROM", "WHERE","LIKE","OR","AND","NOT" };
string operators[]{ "+", "-", "*", "/", ":", "=", "^", "%","<", ">" };
string punctuations[]{ ".", ",", "?", "&", "!", ";", ":", "_", "(" ")" };
string whitespaces[]{ "\n", " " };
string digits[]{ "1", "2", "3", "4", "5", "6", "7", "9", "8", "0" };


bool Lexer::IsAlphanumeric(char aC) const
{
	return (aC >= 'A' && aC <= 'z' || aC >= '0' && aC <= '9');
}

bool Lexer::IsOperator(char aC) const
{
	return (mOperators.find(aC) != string::npos);
}

bool Lexer::IsPunctuation(char aC) const
{
	return (mPunctuation.find(aC) != string::npos);
}