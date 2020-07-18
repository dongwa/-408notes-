#include <iostream>
using namespace std;

typedef int EleType;
//带头结点的链式栈
typedef struct LinkNode {
  EleType data;
  struct LinkNode *next;
} * LiStack;

bool InitLiStack(LiStack &s) {
  s = (LiStack)malloc(sizeof(LinkNode));
  if (s == NULL) return false;  //分配内存空间失败
  s->next = NULL;
  return true;
}
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
bool getTop(LiStack s, EleType &e) {
  if (s->next == NULL) return false;  //栈空
  e = s->next->data;
  return true;
}

void test() {
  LiStack s;
  InitLiStack(s);
  EleType e = 0;
  push(s, 520);
  push(s, 2333);
  pop(s, e);
  cout << "出栈元素为：" << e << endl;
  push(s, 1314);
  getTop(s, e);
  cout << e << endl;
}
int main() {
  test();
  return 0;
}