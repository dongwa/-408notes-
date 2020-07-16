/**
 *队列的顺序实现
 *队列的本质是受限制的线性表
 *限制从一端入队，另外一端出队
 *队尾入队，对头出队
 * */
#include <iostream>
using namespace std;

#define MaxSize 100
typedef int EleType;

typedef struct {
  EleType data[MaxSize];  //静态方式实现队列
  int front, rear;  // front指示队头元素的位置，rear指向队尾元素的后一个位置
  //注意这里也可以让rear指向队尾元素，在后续的代码中会有一些不同
} SqQueue;
//初始化队列
bool InitQueue(SqQueue &q) {
  q.front = 0;
  q.rear = 0;
  return true;
}
//判空
bool IsEmpty(SqQueue &q) { return q.front == q.rear; }
//判满，注意这种方式实现的队列，在满时会浪费一个空间
//想处理这个情况，可在列队的结构体中增加一个size变量存放队列的长度，入队时size++，出队时size--，判空即为size==0，判满即为size==MaxSize
bool IsFull(SqQueue q) { return (q.rear + 1) % MaxSize == q.front; }
//获取当前队列的长度
int getSize(SqQueue q) { return (q.rear + MaxSize - q.front) % MaxSize; }
//入队
bool add(SqQueue &q, EleType e) {
  if (IsFull(q)) return false;  //队列已满
  q.data[q.rear] = e;  //将e存入队列中队尾的位置，将队列的队尾指针后移一位
  q.rear = (q.rear + 1) % MaxSize;
  //当有元素出队时，队首的位置会空出来，当队尾的空间用完后，将队尾指针对最大空间取余。可以将队尾指针定位到队首的位置去
  return true;
}
//出队，并将出队的元素数据返回，e为返回值
bool pop(SqQueue &q, EleType &e) {
  if (q.rear == q.front) return false;  //队列为空
  e = q.data[q.front];
  q.front = (q.front + 1) % MaxSize;
  return true;
}
//获取队头元素
bool getRear(SqQueue q, EleType &e) {
  if (q.rear == q.front) return false;  //队列为空
  e = q.data[q.front];
  return true;
}
void test() {
  SqQueue q;
  InitQueue(q);
  EleType e = 0;
  add(q, 120);
  add(q, 520);
  pop(q, e);
  cout << "当前出队元素为：" << e << endl;
  add(q, 1314);
  cout << "当前队列中有" << getSize(q) << "个元素：  ";
  while (q.front != q.rear) {
    pop(q, e);
    cout << e << " ";
  }
};

int main() {
  test();
  return 0;
}
