#include "stdafx.h"
#include "Presenter.h"

void Presenter::Present(DiagnosticInfo & aDiagInfo)
{
  switch (aDiagInfo.GetErrorCode())
  {
  // Lexer error
  case 123:
    cout << "Error 123: Invalid token '" << aDiagInfo.GetWord() << "' "
         << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
         << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  // Lexer error, failed to tokenize
  case 124:
    cout << "Error 124: Tokens don't match the initial string. " << endl;
  // Parser error
  case 204:
    cout << "Error 204: Invalid syntax. Unexpected token '" << aDiagInfo.GetWord()
         << "' at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
         << aDiagInfo.GetPosition().GetLine() << ". " << endl;
  }
}
