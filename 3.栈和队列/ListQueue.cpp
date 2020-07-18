/**
 *
 * 队列的链式实现
 *
 * */
#include <iostream>
using namespace std;
typedef int EleType;
//结点的结构个单链表的一样
typedef struct LinkNode {
  EleType data;
  struct LinkNode *next;
} LinkNode;
//这个结构体用于指向队列的头和尾,带头结点
typedef struct {
  LinkNode *front, *rear;
  int size;  //保存队列的长度
} LinkQueue;

bool IntitQueue(LinkQueue &q) {
  LinkNode *node =
      (LinkNode *)malloc(sizeof(LinkNode));  //创建一个新节点，即头结点
  if (node == NULL) return false;            //若创建失败，返回false
  node->next = NULL;  //初始化时将头结点的next指向空
  q.front = node;     //让队列的头和尾都指向创建的头结点
  q.rear = node;
  q.size = 0;  //初始化队列长度为0
  return true;
}
bool IsEmpty(LinkQueue q) { return q.front->next == NULL; }
//队尾入队
bool add(LinkQueue &q, EleType e) {
  LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));  //创建一个新节点
  if (newNode == NULL) return false;  //若创建失败，返回false
  newNode->data = e;  //将e存入新节点中并将新结点连在队尾即可
  newNode->next = NULL;
  q.rear->next = newNode;
  q.rear = newNode;  //更新队尾指针为新结点
  q.size++;          //有元素入队时，队列的size++
  return true;
}
//队头出队
bool pop(LinkQueue &q, EleType &e) {
  if (IsEmpty(q)) return false;
  LinkNode *t = q.front->next;  // t即为即将出队的结点
  e = t->data;                  //先返回出队结点的值
  q.front->next = t->next;      //将队头结点删除
  if (q.rear == t)
    q.rear = q.front;  //若当前出队的结点为队尾结点，则需要更新队尾指针
  free(t);
  q.size--;  //有元素出队，size--
  return true;
}
//获取队头元素
bool getPoll(LinkQueue q, EleType &e) {
  if (IsEmpty(q)) return false;
  e = q.front->next->data;
  return true;
}
void test() {
  LinkQueue q;
  IntitQueue(q);
  EleType e = 0;
  add(q, 1);
  add(q, 2);
  add(q, 3);
  add(q, 10);
  add(q, 50);
  pop(q, e);
  cout << "当前出队的值为： " << e << endl;
  cout << "当前队列中有" << q.size << "个元素:";
  while (!IsEmpty(q)) {
    pop(q, e);
    cout << e << " ";
  }
}
int main() {
  test();
  return 0;
}