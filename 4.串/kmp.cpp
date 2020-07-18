#include <iostream>
using namespace std;

//求next数组
void getNext(char t[], int next[], int len) {
  int i = 1, j = 0;
  next[1] = 0;
  while (i < len) {
    if (j = 0 || t[i] == t[j]) {
      ++i;
      ++j;
      next[i] = j;  //当t[i] = t[j]时next[i +1]= next[j+1]
    } else {
      j = next[j];
    }
  }
}
// kmp匹配过程
int kmp(char s[], char t[], int s_len, int t_len) {
  int next[t_len + 10];
  getNext(t, next, t_len);
  int i = 1, j = 1;
  while (i <= s_len && j <= t_len) {
    if (j == 0 || s[i] == t[j]) {  // j=0时为t串重置，s[i] = t[j]为当前字母匹配
      ++i;
      ++j;
    } else {
      //出现失配
      j = next[j];
    }
  }
  if (i > t_len)
    return i - t_len;
  else
    return -1;
}
int main() {
  int m, n;
  cin >> n;
  char t[n + 10];
  cin >> t + 1;
  cin >> m;
  char s[m + 10];
  cin >> s + 1;
  int e = kmp(s, t, m, n);
  cout << e;
  return 0;
}