#include "stdafx.h"
#include "ConsolePresenter.h"

void ConsolePresenter::Present(DiagnosticInfo & aDiagInfo)
{
  switch (aDiagInfo.GetErrorCode())
  {
  // Lexer error
  case 123:
    cout << "Error 123: Invalid token '" << aDiagInfo.GetWord() << "' "
         << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
         << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;

  // Parser error
  case 204:
    cout << "Error 204: Invalid syntax. Unexpected token '" << aDiagInfo.GetWord()
         << "' at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
         << aDiagInfo.GetPosition().GetLine() << ". " << endl;
  }
}
