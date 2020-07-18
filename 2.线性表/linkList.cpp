#include <stdio.h>

#include <iomanip>
#include <iostream>

using namespace std;

typedef int EleType;

// 带头结点的单链表一个结点，其中data是数据域，next指向下一个结点
typedef struct LNode {
  EleType data;
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
bool ListInsert(linkList &list, int i, EleType e) {
  if (i < 1) return false;

  // 首先找到要插入的位置i-1
  int j = 0;
  LNode *p;
  p = list;
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }
  //找到i-1的位置后将元素e插入
  //先为元素e创建一个结点
  LNode *node = (LNode *)malloc(sizeof(LNode));
  if (node == NULL) return false;  //申请内存空间失败

  node->data = e;
  //将node插入到i-1和i之间
  node->next = p->next;
  p->next = node;
  return true;
}

// 后插值操作，在p结点之后插入元素e
bool InsertNextNode(LNode *p, EleType e) {
  if (p == NULL) return false;
  //   首先创建结点e
  LNode *node = (LNode *)malloc(sizeof(LNode));
  if (node == NULL) return false;  //申请内存空间失败

  node->data = e;
  // 将node插入到p结点之后
  node->next = p->next;
  p->next = node;
  return true;
}

//前插值操作，在p结点之前插入元素e
bool InsertPriorNode(LNode *p, EleType e) {
  //不能直接找到p的前驱，但是可以将新增的结点放在p的后面，
  //然后将p中存的值放到新增结点中，将e存入p中,也可以达到O(1)的时间复杂度,偷天换日

  //首先创建一个结点
  LNode *node = (LNode *)malloc(sizeof(LNode));
  if (node == NULL) return false;
  //将新增的node放在p的后面，把p中的data复制到node中
  node->data = p->data;
  node->next = p->next;
  p->next = node;
  //再将e存入p中
  p->data = e;
  return true;
}
// 删除指定位置i(i>=1)处的结点，并返回被删除的值，返回值为e
bool ListDelete(linkList &list, int i, EleType &e) {
  if (i < 1) return false;
  LNode *p = list;
  int j = 0;
  // 找到i-1的前驱结点
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }
  if (p == NULL || p->next == NULL) return false;
  LNode *node = p->next;  //此时，node为待删除的结点，p为他的前驱
  e = node->data;         // e作为返回值
  //将i的前驱指向i的后继
  p->next = node->next;
  // 释放待删除的node
  free(node);
  return true;
}

//找到指定位置i(i>=1)处的结点
LNode *GetEle(linkList list, int i) {
  if (i < 1) return NULL;
  LNode *p = list;
  int j = 0;
  while (p != NULL && j < i) {
    p = p->next;
    j++;
  }
  return p;
}

/**
 * 头插法建立链表
 * 重要应用，比如逆序，即可在扫描一个链表的同时使用头插法构建他的逆序
 * */
linkList List_HeadInsert(linkList &list) {
  LNode *s;
  int x;
  //创建头结点
  list = (linkList)malloc(sizeof(LNode));
  list->next = NULL;

  while (scanf("%d", &x) != EOF) {
    // 创建新的结点
    s = (linkList)malloc(sizeof(LNode));
    s->data = x;
    //让新的结点指向头结点的下一个结点,即指向第二个元素
    s->next = list->next;
    // 让头结点指向新结点
    list->next = s;
  }
  return list;
}

//尾插法
linkList List_TailInsert(linkList &list) {
  int x;
  list = (linkList)malloc(sizeof(LNode));
  // s用于创建新节点，r一直指向尾巴
  LNode *s, *r = list;
  while (scanf("%d", &x) != EOF) {
    //新建头结点
    s = (linkList)malloc(sizeof(LNode));
    s->data = x;
    r->next = s;
    r = s;
  }
  r->next = NULL;
  return list;
}

int main() {
  linkList list, p;
  // list = List_HeadInsert(list);
  // p = list->next;
  // while (p->next) {
  //   cout << p->data << " ";
  //   p = p->next;
  // }
  InitList(list);
  for (int i = 1; i < 10; i++) {
    ListInsert(list, i, i + 10);
  }
  p = list;
  p = p->next;
  InsertNextNode(p, 1314);
  p = p->next;
  InsertPriorNode(p, 520);
  EleType e = 0;
  ListDelete(p, 1, e);
  cout << "删除了:" << e << endl;
  p = list->next;
  while (p->next) {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
  LNode *node = GetEle(list, 5);
  cout << "找到的元素为：" << node->data << endl;
  return 0;
}