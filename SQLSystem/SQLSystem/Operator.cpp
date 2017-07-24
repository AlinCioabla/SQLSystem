#include "Operator.h"

string Operator::GetWord() const {
  string s_word;
  s_word += mWord;
  return s_word;
}

TokenType Operator::GetType() const { return TokenType::OperatorType; }

Operator::~Operator() {}
