#include <stdio.h>
#include <stdlib.h>

typedef int EleType;

typedef struct {
  EleType *data;
  struct LNode *next;
} LNode, *linkList;

// 初始化一个带头结点的单链表
bool InitList(linkList &list) {
  list = (linkList)malloc(sizeof(LNode));
  if (list == NULL) return false;
  list->next = NULL;
  return true;
}

// 判断一个带头结点的单链表是否为空
bool IsEmpty(linkList list) { return list->next == NULL; }

// 在指定位置i(i>=1)处插入元素e
bool ListInsert(linkList &L, int i, EleType e) {}
int main() { return 0; }