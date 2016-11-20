/************************************************
 **图的数据结构定义和算法定义
 **	1. 有向图、无向图数据结构定义
 **	2. 图的初始化定义
 **	3. 图的遍历算法
 **	4. 图的路径算法
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#define TRUE 1
#define FALSE 0

/**图的最大顶点数定义**/
#define MAXVER 100

/*数据类型定义*/
typedef char VertexType;
typedef int EdgeType;

/**图的邻接矩阵表示发**/
typedef struct GraphArray {
	int numEdge, numVer;
	VertexType gVer[MAXVER];		//定点表
	EdgeType gEdge[MAXVER][MAXVER]; //边表
}GraphArray;

/*查找对应的坐标点对应的下标*/
int localIndex(GraphArray *g, char ch)
{
	int i;
	for (i = 0; i < g->numVer; i++) {
		if (g->gVer[i] == ch)
			break;
	}
	if (i >= g->numVer)
		return -1;
	return i;
}

/************************************************
 **图的初始化
 **	功能：
 **		 实现用于实现图的构建
 **	参数：
 **		 GraphArray：定义的图结构 
 **	返回值：
 **		成功：TRUE
 **		失败：FALSE
 **	
 *************************************************/
int initGraphArray(GraphArray *g) 
{
	int i,j;
	char v1, v2; //对应图的顶点坐标
	int m, n; //用于查找两个顶点对应的下标
	printf("请输入边数和顶点数[eg:3,2]：");
	scanf("%d,%d",&(g->numEdge), &(g->numVer));

	printf("请输入图的顶点：\n");
	//输入相应的顶点
	for (i = 0; i < g->numVer; i++) {
		scanf("\n%c", &g->gVer[i]);
	}
#ifdef DEBUG
	for ( i = 0; i< g->numVer; i++ ){
		printf("%c ",g->gVer[i]);
	}
	printf("\n");
#endif
	//初始化图的边值
	for (i = 0; i < MAXVER; i++) {
		for (j = 0; j < MAXVER; j++) {
			g->gEdge[i][j] = 0;
		}
	}
	printf("请输入相应的顶点(v1,v2):\n");
	for (i = 0; i < g->numEdge; i++) {
		scanf("\n%c,%c", &v1, &v2);
		m = localIndex(g, v1);
		n = localIndex(g, v2);

		if (m == -1 || n == -1) {
			printf("输入的定点不存在.\n");
			return FALSE;
		}

		g->gEdge[m][n] = 1;
		//无向图的时候加上，有向图的时候去掉
		g->gEdge[n][m] = 1;
	}
	return TRUE;
}

/************************************************
 **图的深度优先遍历(邻接矩阵)
 **	功能：
 **		 按照深度优先规则遍历图结构 
 **	参数：
 **		 void
 **	返回值：
 **		成功：TRUE
 **		失败：FALSE
 **	
 *************************************************/

int main()
{
	GraphArray g;
	int i, j;
	int flag = 0;
	flag = initGraphArray(&g);
	if( flag == 0 ){
		printf("图构建失败.\n");
		return 0;
	}
#ifdef DEBUG
	for (i = 0; i < g.numVer;i++){
		for (j = 0; j < g.numVer; j++) {
			printf("%d ", g.gEdge[i][j]);
		}
		printf("\n");
	}
#endif
	getchar();
	getchar();
	return 0;
}
