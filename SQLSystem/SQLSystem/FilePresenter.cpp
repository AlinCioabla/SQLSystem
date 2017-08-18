#include "stdafx.h"
#include "FilePresenter.h"

void FilePresenter::Present(DiagnosticInfo & aDiagInfo) const

{
  switch (aDiagInfo.GetErrorCode())
  {
  // Lexer error
  case 123:
    // mFile.open("FilePresenter.txt", ios::out | ios::ate | ios::app);
    mFile << "Error 123: Invalid token '" << aDiagInfo.GetWord() << "' "
          << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
          << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  // Parser error
  case 204:
    // mFile.open("FilePresenter.txt", ios::out | ios::app | ios::ate);
    mFile << "Error 204: Invalid syntax. Unexpected token '" << aDiagInfo.GetWord()
          << "' at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
          << aDiagInfo.GetPosition().GetLine() << ". " << endl;
  }
}
