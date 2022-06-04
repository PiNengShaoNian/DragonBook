/*
同样，所给出的语法不能按规定使用，因为它不清楚当读到'0'时应该使用哪种生成式。
因为FIRST('0' S '1')与FIRST('0' '1')相交，这使得预测性分析器的前进方向不明确。
  一个解决方案是递归地尝试第一个生成式，如果不成功，就尝试第二个选择。
  这仍然会使它成为一个递归下降的分析器，但有一个更智能的方法。
  通过汇集那些 FIRST 为'0'语法可以消除这种不确定性。下面的语法
  相当于原来的语法，其优点是可以用预测分析器来实现。
  S -> '0' R
  R -> S '1' | '1' 。
  基本上，以'0'开头的规则被合并为一条规则，其余的工作则委托给R。
  因为现在S总是以'0'开头，所以这个调整后的版本实现一个预测分析器是很容易的。
*/

#include <stdio.h>

/* The lookahead symbol */
int token;

int gettoken(void) {
    return token = getchar();
}

void r(void);
void s(void) {
    if(token == '0') {
        gettoken();
        r();
    }
    else {
        fprintf(stderr, "Syntax error\n");
    }
}

void r(void) {
    switch(token) {
        case '0':
            s();
            if(token != '1') {
                fprintf(stderr, "Syntax error\n");
            }
            gettoken();
            break;
        case '1':
            gettoken();
            break;
        default:
            fprintf(stderr, "Syntax error\n");
    }
}

int main(void) {
  printf("Please enter expressions according to the following grammar:\n");
  printf("S -> '0' S '1' | '0' '1'\n");
  while (1) {
    printf("> ");
    fflush(stdout);
    gettoken();
    s();
  }
  return 0;
}