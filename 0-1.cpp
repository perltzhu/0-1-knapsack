#include <stdio.h>

#include <stdlib.h>

 

int constraint(int t, int n, int c, int *w, int *p, int &cw, int &cp)

{

       int i = t-1;

       //ʣ������

       int cleft = c - cw;

       //��ǰ��ֵ

       int b = cp;

       //����Ʒ��λ������ֵ�ݼ�װ����Ʒ

       while (i < n && w[i] <= cleft)

       {

              cleft -= w[i];

              b += p[i];

              i++;

       }

       //װ������

       if (i < n) b += p[i] * cleft / w[i];

       return b;

 

}

 

void BackTrack(int t, int n, int c, int *w, int *p, int &cw, int &bestp, int &cp, int *x,int *bestx)

{

       if (t == n)

       {

              //����û�г������и��Ž�

              if ( (cw + w[n-1]) < c && (cp + p[n-1]) > bestp)

              {

                     //������������ֵ

                     bestp = cp + p[n-1];

                     //�����������Ž�

                     x[t-1] = 1;

                     for (int i = 0; i < n; i++)

                            bestx[i] = x[i];

              }

       }

       else{

              int i = t-1;

              //������Խ�����ڵ�

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

              //�������Լ�������Խ����ҽڵ�

              if (constraint(t+1, n, c, w, p, cw, cp) > bestp)

              {

                     x[i]=0;

                     BackTrack(t+1, n, c, w, p, cw, bestp, cp, x, bestx);

              }

       }

}

 

int main()

{

       //�����Ͱ���������

       int n,c;

       scanf("%d %d",&n, &c);

       //����

       int *w;

       w = (int *)malloc(sizeof(int) * n);

       for (int i = 0; i < n; i++)

              scanf("%d", &w[i]);

       //��ֵ

       int *p;

       p = (int *)malloc(sizeof(int) * n);

       for (int j = 0; j < n; j++)

              scanf("%d", &p[j]);

       //����ֵ

       int bestp = 0;

       //��ǰֵ

       int cp = 0;

       //��ǰ����

       int cw = 0;

       //���Ž�

       int *bestx;

       bestx = (int *)malloc(sizeof(int) * n);

       for (int l = 0; l < n; l++)

              bestx[l] = 0;

       //��ǰ��

       int *x;

       x = (int *)malloc(sizeof(int) * n);

       for (int s = 0; s < n; s++)

              x[s] = 0;

       //���л���

       BackTrack(1, n, c, w, p, cw, bestp, cp, x, bestx);

       //������

       printf("����ֵ��%d\n", bestp);

       printf("���Ž⣺");

       for(int k = 0; k < n; k++)

              printf("%d ", bestx[k]);

       printf("\n");

       return 0;

}

