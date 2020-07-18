/**
 * 双链表
 *
 * */
#include <iostream>

using namespace std;

typedef int EleType;

//带头结点的双链表结构
typedef struct DNode {
  EleType data;                //数据域
  struct DNode *prior, *next;  //指针域，prior指向前驱，next指向后继
} DNode, *DLinkList;

//初始化一个双链表
bool InitDLinkList(DLinkList &list) {
  list = (DNode *)malloc(sizeof(DNode));
  if (list == NULL) return false;
  list->prior = NULL;
  list->next = NULL;
  return true;
}

bool IsEmpty(DLinkList list) { return list->next == NULL; }

//在p结点后插入s结点
bool InsertNextDNode(DNode *p, DNode *s) {
  s->next = p->next;
  if (p->next != NULL)
    p->next->prior = s;  //这里如果p为最后一个结点，则出错,所以特判了一下
  p->next = s;
  s->prior = p;
  return true;
}

// 删除p结点的后继结点
bool DeteleNextDNode(DNode *p) {
  if (p == NULL || p->next == NULL) return false;
  if (p->next->next != NULL) {
    //普通情况
    DNode *t = p->next;
    t->next->prior = p;
    p->next = t->next;
    free(t);
    return true;
  } else {
    // p为倒数第二个节点,即要删除最后一个结点，
    free(p->next);   //将最后一个结点释放
    p->next = NULL;  //将p->next指向空
    return true;
  }
}

//销毁一个双链表
void DestoryDList(DLinkList &list) {
  while (list->next != NULL) {
    DeteleNextDNode(list);
  }
  free(list);
  list = NULL;
}
void test() {
  DLinkList list, p;
  InitDLinkList(list);
  for (int i = 0; i < 10; i++) {
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = i * i;
    InsertNextDNode(list, s);
  }
  p = list->next;
  while (p != NULL) {
    cout << p->data << " ";
    p = p->next;
  }
}

int main() {
  test();
  return 0;
}