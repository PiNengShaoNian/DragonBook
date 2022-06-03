//下面代码的打印结果为：
#define a (x+1)
int x = 2;
void b() { x = a; printf("%d\n", x);  }
void c() { int x = 1; printf("%d\n", a);  }
void main() { b(); c(); }

//输出为: 3,2