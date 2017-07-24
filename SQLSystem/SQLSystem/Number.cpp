#include "Number.h"

string Number::GetWord() const { return mWord; }

TokenType Number::GetType() const { return TokenType::NumberType; }

Number::~Number() {}
