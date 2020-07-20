#include <bits/stdc++.h>  //涵盖C++所有库函数

#include <iostream>
using namespace std;

/**
 * 二叉树的顺序存储结构 (适合存放完全二叉树)
 * 二叉树的性质
 * i的左孩子为 2i
 * i的右孩子为 2i+1
 * i的父节点为 [i/2]
 * i所在的层次为 [log2(n+1)] 或者 [log2n]+1
 * */
#define MaxSize 100
typedef char EleType;
struct TreeNode {
  EleType value;
  bool isEmpty;
};
//初始化一个顺序存储的二叉树
TreeNode t[MaxSize];

/**
 * 二叉树的链式存储
 *
 **/
typedef struct BiTNode {
  EleType data;                     //数据域
  struct BiTNode *lchild, *rchild;  //左，右孩子指针
} BiNode, *BiTree;
//初始化一个链式二叉树
BiTree root = NULL;
//新建一个结点
bool biTreeAdd(BiTree &node, EleType e) {
  node = (BiTree)malloc(sizeof(BiNode));
  if (node == NULL) return false;
  node->data = e;
  node->lchild = NULL;
  node->rchild = NULL;
  return true;
}
void vist(BiTree T) { cout << T->data << " "; }
//先序遍历
void preOrder(BiTree T) {
  //先序遍历顺序：根，左，右
  if (T != NULL) {
    vist(T);
    preOrder(T->lchild);
    preOrder(T->rchild);
  }
}
//中序遍历
void inOrder(BiTree T) {
  //先序遍历顺序：左，根，右
  if (T != NULL) {
    inOrder(T->lchild);
    vist(T);
    inOrder(T->rchild);
  }
}
//后序遍历
void posOrder(BiTree T) {
  //先序遍历顺序：左，右，根
  if (T != NULL) {
    posOrder(T->lchild);
    posOrder(T->rchild);
    vist(T);
  }
}
//求二叉树的深度
int treeDepth(BiTree T) {
  if (T == NULL) return 0;
  int l = treeDepth(T->lchild);
  int r = treeDepth(T->rchild);
  return l > r ? l + 1 : r + 1;
}

/**
 * 二叉数的层次遍历
 * 初始化一个辅助队列(这里偷懒使用stl里面的队列了)
 * 根节点入队
 * 若根节点非空，则根节点出队，访问改结点，并将其左孩子、右孩子插入队尾（如果存在）
 * 重复3直至队列为空
 **/
void LeverOrde(BiTree T) {
  queue<BiTree> q;  // stl中实现的队列
  BiTree p;
  q.push(T);  //根节点入队
  while (!q.empty()) {
    p = q.front();  //得到对头的元素
    q.pop();        //将队头元素弹出
    vist(p);        //访问根节点
    if (p->lchild != NULL) q.push(p->lchild);
    if (p->rchild != NULL) q.push(p->rchild);
  }
}

void madeTree() {
  biTreeAdd(root, 'F');
  BiTree C = NULL;
  biTreeAdd(C, 'C');
  root->lchild = C;
  BiTree A = NULL;
  biTreeAdd(A, 'A');
  C->lchild = A;
  BiTree D = NULL;
  biTreeAdd(D, 'D');
  C->rchild = D;
  BiTree B = NULL;
  biTreeAdd(B, 'B');
  D->lchild = B;
  BiTree E = NULL;
  biTreeAdd(E, 'E');
  root->rchild = E;
  BiTree H = NULL;
  biTreeAdd(H, 'H');
  E->lchild = H;
  BiTree G = NULL;
  biTreeAdd(G, 'G');
  E->rchild = G;
  BiTree M = NULL;
  biTreeAdd(M, 'M');
  G->lchild = M;
}
void test() {
  madeTree();
  cout << "前序遍历为: ";
  preOrder(root);
  cout << endl << "中序遍历为 ";
  inOrder(root);
  cout << endl << "后续遍历为 ";
  posOrder(root);
  cout << endl << "层次遍历为 ";
  LeverOrde(root);
  cout << endl << "树的深度为 : " << treeDepth(root) << endl;
}
int main() {
  test();
  return 0;
}