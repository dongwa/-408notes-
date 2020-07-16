#include <iomanip>
#include <iostream>

using namespace std;

#define EleType int   //数据类型宏
#define maxSize 20    //最大数据量宏
#define growthLen 10  //每次扩容增长长度宏

//动态顺序表的数据结构
typedef struct {
  EleType *data;  //指向数据的首地址
  int length;     //当前表长度
} sqList;

// 动态方式初始化顺序表
void InitList(sqList &list) {
  list.data = (EleType *)malloc(maxSize * sizeof(EleType));
  list.length = 0;
}

// 在指定位置i(i>=1)插入元素e
bool ListInsert(sqList &list, int i, EleType e) {
  // i~[1,list.length+1]否则为不合法数据
  if (i <= 0 && i > list.length + 1) return false;
  // list已经满了，需要扩容
  if (list.length == maxSize) {
    return false;
  }
  //在插入之前要将i后面的所有元素后移一位，平均时间复杂度为O(n)
  for (int j = list.length; j >= i; j++) list.data[j] = list.data[j - 1];
  list.data[i - 1] = e;
  list.length++;
  return true;
}

//删除指定位置i(i>=1)除的元素，并返回删除的值，e为返回值
bool ListDelete(sqList &list, int i, EleType &e) {
  // i~[1,list.length]否则为不合法数据
  if (i <= 0 && i > list.length) return false;
  //   返回删除的元素
  e = list.data[i - 1];
  //   将第i个元素删除需要将i后面的所有元素前移一位，平均时间复杂度为O(n)
  for (int j = i; j < list.length; j++) list.data[j - 1] = list.data[j];
  list.length--;
  return true;
}

// 返回表中i(i>=1)处位置的元素,平均时间复杂度O(1)
EleType GetElem(sqList list, int i) {
  // i~[1,list.length]否则为不合法数据
  if (i <= 0 && i > list.length) return -1;
  return list.data[i - 1];
}

//返回表中指定元素的下标索引,表中不存在则返回-1，平均时间复杂度为O(n)
int GetLastOf(sqList list, EleType e) {
  for (int i = 0; i < list.length; i++) {
    if (list.data[i] == e) return i + 1;
  }
  return -1;
}

int main() {
  sqList list;
  InitList(list);
  for (int i = 0; i < 10; i++) ListInsert(list, i + 1, i * i);
  for (int i = 0; i < list.length; i++) cout << list.data[i] << " ";
  int e = -1;
  ListDelete(list, 2, e);
  cout << e << endl;
  printf("\n%d\n", e);
  for (int i = 0; i < list.length; i++) cout << list.data[i] << " ";
  return 0;
}