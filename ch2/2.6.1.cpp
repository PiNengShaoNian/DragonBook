#include <iostream>
#include <string>

class Lexer {
    public:
        Token* scan() {
            for(;;peek = getchar()) {
                if(peek == ' ' || peek == '\t') {
                    continue;
                }
                else if(peek == '\n') {
                    line = line + 1;
                }
                else {
                    break;
                }
            }

            if(peek == '/') {
                peek = getchar();
                if(peek == '/') {
                    for(;;peek = getchar()) {
                        if(peek == '\n') {
                            break;
                        }
                    }
                }
                else if(peek == '*') {
                    for(;;) {
                        peek = getchar();
                        if(peek == '*') {
                            peek = getchar();
                            if(peek == '/') {
                                break;
                            }
                        }
                        else if(peek == '\n') {
                            line = line + 1;
                        }
                    }
                }
                else {
                    throw "invalid comment";
                }
            }

            if("<=!>".find(peek) != std::string::npos) {
                string s;
                s.push_back(peek);
                peek = getchar();
                if(peek == '=') {
                    s.push_back(peek);
                }
                return new Rel(s);
            }
            else if(isdigit(peek)) {
                string b;
                bool isDotExist = false;
                do {
                    if(peek == '.') {
                        isDotExist = true;
                    }
                    b.push_back(peek);
                    peek = getchar();
                } while(isDotExist == true ?  isdigit(peek) : isdigit(peek) || peek == '.');
                return new Num(b);
            }
            else if(isalpha(peek)) {
                std::string name;
                do {
                    name.push_back(peek);
                    peek = getchar();
                } while(isalnum(peek));
                Word* w = words.find(name);
                if(w == NULL) {
                    w = new Word(name);
                    words.insert(w);
                }
                return w;
            }
            else {
                peek = ' ';
                return new Token(peek);
            }
        }
}
         