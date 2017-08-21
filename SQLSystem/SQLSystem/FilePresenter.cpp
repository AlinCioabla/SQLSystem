#include "stdafx.h"
#include "FilePresenter.h"

void FilePresenter::Present(DiagnosticInfo & aDiagInfo)

{
  // mOutputFile.open(mFile);
  switch (aDiagInfo.GetErrorCode())
  {
  // Lexer error
  case 123:

    mFile << "Error 123: Invalid token '" << aDiagInfo.GetWord() << "' "
          << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
          << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  // Parser error
  case 204:

    mFile << "Error 204: Invalid syntax. Unexpected token '" << aDiagInfo.GetWord()
          << "' at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
          << aDiagInfo.GetPosition().GetLine() << ". " << endl;
  }
}
