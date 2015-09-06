#include <stdio.h>

#include <stdlib.h>

 

int constraint(int t, int n, int c, int *w, int *p, int &cw, int &cp)

{

       int i = t-1;

       //剩余容量

       int cleft = c - cw;

       //当前价值

       int b = cp;

       //以物品单位重量价值递减装入物品

       while (i < n && w[i] <= cleft)

       {

              cleft -= w[i];

              b += p[i];

              i++;

       }

       //装满背包

       if (i < n) b += p[i] * cleft / w[i];

       return b;

 

}

 

void BackTrack(int t, int n, int c, int *w, int *p, int &cw, int &bestp, int &cp, int *x,int *bestx)

{

       if (t == n)

       {

              //重量没有超过，有更优解

              if ( (cw + w[n-1]) < c && (cp + p[n-1]) > bestp)

              {

                     //重新设置最优值

                     bestp = cp + p[n-1];

                     //重新设置最优解

                     x[t-1] = 1;

                     for (int i = 0; i < n; i++)

                            bestx[i] = x[i];

              }

       }

       else{

              int i = t-1;

              //如果可以进入左节点

              if (cw + w[i] < c)

              {

                     cw += w[i];

                     cp += p[i];

                     x[i] = 1;

                     BackTrack(t+1, n, c, w, p, cw, bestp, cp, x, bestx);

                     cw -= w[i];

                     cp -= p[i];

                     x[i] = 0;

              }

              //如果满足约束，可以进入右节点

              if (constraint(t+1, n, c, w, p, cw, cp) > bestp)

              {

                     x[i]=0;

                     BackTrack(t+1, n, c, w, p, cw, bestp, cp, x, bestx);

              }

       }

}

 

int main()

{

       //个数和包的总重量

       int n,c;

       scanf("%d %d",&n, &c);

       //重量

       int *w;

       w = (int *)malloc(sizeof(int) * n);

       for (int i = 0; i < n; i++)

              scanf("%d", &w[i]);

       //价值

       int *p;

       p = (int *)malloc(sizeof(int) * n);

       for (int j = 0; j < n; j++)

              scanf("%d", &p[j]);

       //最优值

       int bestp = 0;

       //当前值

       int cp = 0;

       //当前重量

       int cw = 0;

       //最优解

       int *bestx;

       bestx = (int *)malloc(sizeof(int) * n);

       for (int l = 0; l < n; l++)

              bestx[l] = 0;

       //当前解

       int *x;

       x = (int *)malloc(sizeof(int) * n);

       for (int s = 0; s < n; s++)

              x[s] = 0;

       //进行回溯

       BackTrack(1, n, c, w, p, cw, bestp, cp, x, bestx);

       //输出结果

       printf("最优值：%d\n", bestp);

       printf("最优解：");

       for(int k = 0; k < n; k++)

              printf("%d ", bestx[k]);

       printf("\n");

       return 0;

}

