#include "stdafx.h"
#include "FilePresenter.h"

void FilePresenter::Present(DiagnosticInfo & aDiagInfo) const

{
  ostream mOutputFile(mFile, ios::out | ios::ate | ios::app);
  switch (aDiagInfo.GetErrorCode())
  {
  // Lexer error
  case 123:

    mOutputFile << "Error 123: Invalid token '" << aDiagInfo.GetWord() << "' "
                << "at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
                << aDiagInfo.GetPosition().GetLine() << ". " << endl;
    break;
  // Parser error
  case 204:

    mOutputFile << "Error 204: Invalid syntax. Unexpected token '" << aDiagInfo.GetWord()
                << "' at position " << aDiagInfo.GetPosition().GetColumn() << " on line "
                << aDiagInfo.GetPosition().GetLine() << ". " << endl;
  }
}
