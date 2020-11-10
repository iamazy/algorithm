#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 15

struct vertex
{
    int degree; //顶点的度
    int index; //顶点的序号
}v[N];

int cmp(const void *a, const void *b)
{
    return ((struct vertex*)b)->degree - ((struct vertex *)a)->degree;
}

int main()
{
    int r,k,p,q;
    int i,j; //顶点序号(用于确定图中边的两个顶点)
    int d1; //为剩下序列排序后第一个顶点(度数最大的顶点)的度数

    int T, n; //测试数据个数，湖泊个数
    int Edge[N][N], flag; //邻接矩阵，是否存在合理相邻关系的标志

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0;i<n;i++) {
            scanf("%d", &v[i].degree);
            v[i].index = i;
        }
        memset(Edge, 0 , sizeof(Edge));
        flag = 1;
        for (k=0;k<n&&flag;k++) {
            // 对v数组后n-k个元素按非递增顺序排序
            qsort(v + k, n - k, sizeof(struct vertex), cmp);
            i = v[k].index; //第k个顶点的序号
            d1 = v[k].degree;
            if (d1 > n - k - 1) {
                flag = 0;
            }
            for (r = 1; r <= d1 && flag; r++) {
                j = v[k + r].index; //后面d1个顶点每个顶点的序号
                if (v[k + r].degree <= 0) {
                    flag = 0;
                }
                v[k + r].degree--;
                Edge[i][j] = Edge[j][i] = 1;
            }
        }
        if (flag) {
            puts("YES");
            for(p=0;p<n;p++) {
                for (q=0;q<n;q++) {
                    if (q) {
                        printf(" ");
                    }
                    printf("%d", Edge[p][q]);
                }
                puts(""); //换行
            }
        } else {
            puts("NO");
        }
        if (T) {
            puts("");
        }
    }
    return 0;
}