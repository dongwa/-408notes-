#include <string.h>
/**
 * 计算后缀表达式的值
 * */
#include <iostream>
using namespace std;

typedef double EleType;
//带头结点的链式栈
typedef struct LinkNode {
  EleType data;
  struct LinkNode *next;
} * LiStack;

//全局变量
LiStack numStack;  //用于存放数字
LiStack opStack;   //用于存放操作符

bool InitLiStack(LiStack &s) {
  s = (LiStack)malloc(sizeof(LinkNode));
  if (s == NULL) return false;  //分配内存空间失败
  s->next = NULL;
  return true;
}
bool IsEmpty(LiStack numStack) { return numStack->next == NULL; }
//新元素入栈，链式栈本质上是操作受限制的单链表，限制只能在同一端出栈和入栈，我们限制只能在表头出栈和入栈，因为表头好找
bool push(LiStack &s, EleType e) {
  LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));  //创建新的结点
  if (newNode == NULL) return false;  //分配内存空间失败
  newNode->data = e;                  //将e存入新节点中
  newNode->next = s->next;            //将新节点放在表头
  s->next = newNode;
  return true;
}
//元素出栈并将出栈的数据返回，e为返回值
bool pop(LiStack &s, EleType &e) {
  if (s->next == NULL) return false;  //栈空
  e = s->next->data;                  //返回栈顶的数据
  LinkNode *t = s->next;
  if (t->next != NULL) s->next = t->next;
  free(t);
  return true;
}
//获取栈顶元素
bool getTop(LiStack numStack, EleType &e) {
  if (numStack->next == NULL) return false;  //栈空
  e = numStack->next->data;
  return true;
}

/**
 *  @brief Function isdigitstr() 判断传入字符串是否全数字
 *  @param[in]   char *str     字符串
 *  @retval  true: 全字符串，false:非全字符串
 *  strspn返回的是str中有多少字符与参数"0123456789"中相同，而全数字时正好与strlen相同
 *
 */
bool isDigitStr(char const *str) {
  return (strspn(str, "0123456789") == strlen(str));
}

//计算普通表达式
double calculate(double a, double b, char const *op) {
  char s = (char)op[0];
  switch (s) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    default:
      return 0;
  }
}
//计算机后缀表达式的值
double calPosfix(char const *str[], int len) {
  for (int i = 0; i < len; i++) {
    char const *item = str[i];
    if (isDigitStr(item)) {
      double t = atof(item);
      push(numStack, t);
    } else {
      double a = 0, b = 0, c = 0;
      pop(numStack, b);
      pop(numStack, a);
      c = calculate(a, b, item);
      push(numStack, c);
    }
  }
  double e = 0;
  pop(numStack, e);
  return e;
}

//将中缀表达式转化为后缀表达式
void infix2postfix() {}
int main() {
  //计算后缀表达式的值
  const char *postfix[15] = {"15", "7", "1", "1", "+", "-", "/", "3",
                             "*",  "2", "1", "1", "+", "+", "-"};
  InitLiStack(numStack);
  cout << "后缀表达式的值为：" << calPosfix(postfix, 15) << endl;
  //将后缀表达式转化为前缀表达式
  //   const char *infix[27] = {"(", "(", "15", "/", "(", "7", "-", "(", "1",
  //                            "+", "1", ")",  ")", ")", "*", "3", ")", "-",
  //                            "(", "2", "+",  "(", "1", "+", "1", ")", ")"};
  //   InitLiStack(opStack);
  //   for(int i =0;i<27;i++){
  //       //妈蛋，用C写太难了，有空再写
  //   }
  return 0;
}