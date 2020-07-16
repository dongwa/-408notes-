/**
 * 循环双链表
 * */
#include <iostream>

using namespace std;
typedef int Eletype;

typedef struct DNode {
  Eletype data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

// 初始化一个循环双链表
bool InitList(DLinkList &list) {
  list = (DLinkList)malloc(sizeof(DNode));
  if (list == NULL) return false;  //分配内存失败
  list->next = list;               //循环链表的尾指针要指向头
  list->prior = list;              //循环链表的头指针要指向头
  return true;
}
//判断一个循环链表是否是空链表
bool IsEmpty(DLinkList list) { return list->next == list; }
//判断结点p是否是循环单链表的标尾结点
bool IsTail(DLinkList list, DNode *p) { return p->next == list; }

void test() {
  DLinkList list;
  InitList(list);
  cout << IsEmpty(list) << endl;
}

int main() {
  test();
  return 0;
}