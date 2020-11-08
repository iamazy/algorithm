#include<stdio.h>
#include<string.h>

#define MAXN 100 // 顶点个数最大值

int Edge[MAXN][MAXN]; //邻接矩阵

int main() {
    int i,j;
    int n,m; //顶点个数，边数
    int u,v; //边的起点和终点
    int od,id; //顶点的出度和入度

    while (1) {
        scanf("%d%d", &n, &m); // 读取顶点个数n和边数m
        if(n==0&&m==0) {
            break;
        }
        memset(Edge, 0, sizeof(Edge));
        for(i=1; i<=m; i++) {
            scanf("%d%d", &u, &v); // 读取边的起点和终点
            Edge[u-1][v-1] = 1; //构造邻接矩阵
        }
        for(i=0;i<n;i++) { //求各顶点的出度
            od = 0;
            for(j=0;j<n;j++) {
                od += Edge[i][j];
            }
            if (i==0) {
                printf("%d", od);
            } else {
                printf(" %d", od);
            }
        }
        printf("\n");
        for (i=0;i<n;i++) { //求各顶点的入度
            id = 0;
            for (j=0;j<n;j++) {
                id += Edge[j][i];
            }
            if (i==0) {
                printf("%d", id);
            } else {
                printf(" %d", id);
            }
        }
        printf("\n");
    }
    return 0;
}