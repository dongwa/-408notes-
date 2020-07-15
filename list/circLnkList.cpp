/**
 *
 * 循环单链表
 * */
#include <iostream>

using namespace std;
typedef int Eletype;

typedef struct LNode {
  Eletype data;
  struct LNode *next;
} LNode, *LinkList;

// 初始化一个循环单链表
bool InitList(LinkList &list) {
  list = (LinkList)malloc(sizeof(LNode));
  if (list == NULL) return false;  //分配内存失败
  list->next = list;               //循环链表的尾指针要指向头
  return true;
}
//判断一个循环链表是否是空链表
bool IsEmpty(LinkList list) { return list->next == list; }
//判断结点p是否是循环单链表的标尾结点
bool IsTail(LinkList list, LNode *p) { return p->next == list; }

void test() {
  LinkList list;
  InitList(list);
  cout << IsEmpty(list) << endl;
}

int main() {
  test();
  return 0;
}