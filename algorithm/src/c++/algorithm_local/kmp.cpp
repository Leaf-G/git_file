#include <iostream>

using namespace std;

const int N = 10010, M = 100010;



int main()
{
    int n,m;
    char p[N], s[M];
    int ne[N];  // next 这个名字可能会报错

    // 字符串从1 开始
    cin >> n >> p + 1 >> m>> s + 1;

     cout << n << m << endl;
     cout << p + 1;

    // 求next 过程, 这里不能将i = 1， 否则error
    for(int i = 2, j = 0; i <= n; i ++)
    {
        while( j && p[i] != p[ j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }

    // kmp 匹配过程
    for (int i =1, j = 0; i <= m; i ++)
    {
        while( j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n)
        {
            // 匹配成功
            printf("%d ", i - n);
            // 这里比较结束了， 需要把j 赋值为 ne[j], 待下一次进行匹配
            j = ne[j];
        }
    }
    return 0;
}
