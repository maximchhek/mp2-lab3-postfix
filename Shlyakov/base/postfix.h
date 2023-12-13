#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"

using namespace std;

class TPostfix
{
  string infix;
  string postfix;
  TStack <char> c = TStack <char> (100);
  TStack <int> d = TStack <int>(100);
public:
  TPostfix()
  {
    infix = "0";
  }
  TPostfix(string s)
  {
      infix = s;
      if (!this->isCorrect()) throw ("Error: no correct infix");
  }
  int Priority(char op);
  bool isCorrect();
  bool isCorrectStaples();
  int TPostfix::TypeOfArg(char sy);
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  void SetInfix(string s) { infix = s; isCorrect();}
  string ToPostfix();
  int Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
