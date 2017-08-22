#include "stdafx.h"
#include "ConsolePresenter.h"

void ConsolePresenter::Present(size_t aTestNumber, DiagnosticInfo & aDiagInfo)
{
  cout << "--------------------------------------------------" << endl << endl;

  cout << "Test number: " << aTestNumber << endl;

  switch (aDiagInfo.GetErrorCode())
  {
  case 0:
    cout << "SUCCES !" << endl;
    break;

  // Lexer error
  case 123:
    cout << "Error 123: Invalid token '" << aDiagInfo.GetWord() << "' "
         << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
         << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  case 50:
    cout << "Error 50: Cannot properly retrieve the initial query.";
    break;

  // Parser error
  case 204:
    cout << "Error 204: Invalid syntax. Unexpected token '" << aDiagInfo.GetWord()
         << "' at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
         << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  case 205:
    cout << "Error 205: The query formed from AST doesn't match the initial input." << endl;
    break;

  // General errors
  case 12:
    cout << "Error 12: Cannot open the given input file." << endl;
    break;

  case 14:
    cout << "Error 14: Cannot read from the given input file." << endl;
    break;
  }

  cout << "--------------------------------------------------" << endl << endl;
}
