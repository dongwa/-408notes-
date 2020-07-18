#include <iostream>
using namespace std;

#define MaxSize 100   //栈的最大容量
typedef int EleType;  //数据类型宏

typedef struct {
  EleType data[MaxSize];  //栈存放的数据，使用静态方式
  int top;  //栈顶指针的位置,这里采用的是初始位置为-1的方式
} SqStack;

bool InitStack(SqStack &s) {
  // s.data = (EleType *)malloc(MaxSize * sizeof(EleType));
  //这里不需要手动申请内存空间，静态栈使用数组存放数据，系统会为数组自动申请内存空间
  s.top = -1;
  return true;
}

// 元素e入栈
bool push(SqStack &s, EleType e) {
  if (s.top == MaxSize - 1) return false;  //栈已满
  s.data[++s.top] = e;
  return true;
}

//元素出栈，并将出栈的数据返回,e为返回值
bool pop(SqStack &s, EleType &e) {
  if (s.top == -1) return false;  //栈空
  e = s.data[s.top--];
  return true;
}

// 返回栈顶元素,e为返回值
bool getTop(SqStack s, EleType &e) {
  if (s.top == -1) return false;  //空栈
  e = s.data[s.top];
  return true;
}
//栈判空
bool IsEmpty(SqStack s) { return s.top == -1; }
void test() {
  SqStack s;
  InitStack(s);
  push(s, 1);
  EleType e = -1;
  getTop(s, e);
  cout << e << endl;
}
int main() {
  test();
  return 0;
}