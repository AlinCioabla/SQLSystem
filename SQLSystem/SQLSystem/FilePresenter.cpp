#include "stdafx.h"
#include "FilePresenter.h"

void FilePresenter::Present(size_t aTestNumber, DiagnosticInfo & aDiagInfo)
{
  mFile << "--------------------------------------------------" << endl;

  mFile << "Test number: " << aTestNumber << endl;

  switch (aDiagInfo.GetErrorCode())
  {
  case 0:
    mFile << "SUCCES" << endl;
    break;
  // Lexer error
  case 123:
    mFile << "Error 123: Invalid token '" << aDiagInfo.GetWord() << "' "
          << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
          << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  case 50:
    mFile << "Error 50: Cannot properly retrieve the initial query.";
    break;

  // Parser error
  case 204:

    mFile << "Error 204: Invalid syntax. Unexpected token '" << aDiagInfo.GetWord()
          << "' at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
          << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  case 205:
    mFile << "Error 205: The query formed from AST doesn't match the initial input." << endl;
    break;

  // General errors
  case 12:
    mFile << "Error 12: Cannot open the given input file." << endl;
    break;

  case 14:
    mFile << "Error 14: Cannot read from the given input file." << endl;
    break;
  }

  mFile << "--------------------------------------------------" << endl << endl;
}
