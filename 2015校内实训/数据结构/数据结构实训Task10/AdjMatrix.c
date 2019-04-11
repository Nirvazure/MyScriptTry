#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 20	//最多顶点个数
#define INFINITY 999	//表示极大值即正无穷
#define ERROR -1
#define OK 1

typedef enum{DG,DN,UDC,UDN} GraphKind;	//
typedef char VertexData;

typedef struct ArcNode{
	int adj;	//对于无权图，用0/1表示是否相邻，带权图为权值类型
}ArcNode;

typedef struct{
	VertexData vertex[MAX_VERTEX_NUM];	//顶点向量
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;	//图的定点数和弧度数
	GraphKind kind;
}AdjMatrix;	//(Adjacency Matrix Graph)

/*
求顶点位置函数
*/
int LocateVertex(AdjMatrix *G, VertexData v){
	int j = ERROR, k;
	for (k = 0; k < G->vexnum;k++)
	{
		if (G->vertex[k] == v){
			j = k;
			break;
		}
	}
	return j;
}
/*
创建一个有向网
*/
int CreateDN(AdjMatrix *G){
	printf("建立有向网");
	int i, j, k,weight;
	VertexData v1, v2;
	printf("输入顶点数和弧数");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//初始化邻接矩阵
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = INFINITY;
		}
	}
	//输入图的顶点
	for (i = 0; i < G->vexnum; i++)
	{
		printf("按顺序输入图的顶点");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//输入一条弧的两个顶点和权值
	for (k = 0; k < G->arcnum; k++)
	{
		printf("输入每一条弧的信息，起始和终止");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		scanf_s("%d", &weight);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = weight;	//建立弧
	}
	return OK;
}


/*
创建一个有向图
*/
int CreateDG(AdjMatrix *G){
	printf("建立有向图");
	int i, j, k;
	VertexData v1, v2;
	printf("输入顶点数和弧数");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//初始化邻接矩阵
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = 0;
		}
	}
	//输入图的顶点
	for (i = 0; i < G->vexnum; i++)
	{
		printf("按顺序输入图的顶点");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//输入一条弧的两个顶点和权值
	for (k = 0; k < G->arcnum; k++)
	{
		printf("输入每一条弧的信息，起始和终止");
		getchar();
		scanf_s("%c",&v1);
		scanf_s("%c", &v2);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = 1;	//建立弧
	}
	return OK;
}

/*
创建一个无向网
*/
int CreateUDN(AdjMatrix *G){
	printf("建立无向网");
	int i, j, k,weight;
	VertexData v1, v2;
	printf("输入顶点数和延对角线的弧数");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//初始化邻接矩阵
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = 0;
		}
	}
	//输入图的顶点
	for (i = 0; i < G->vexnum; i++)
	{
		printf("按顺序输入图的顶点");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//输入一条弧的两个顶点和权值
	for (k = 0; k <G->arcnum; k++)
	{
		printf("输入对角线一边弧的信息，起始和终止");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		scanf_s("%d", &weight);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = weight;	//建立弧
		G->arcs[j][i].adj = weight;
	}
	return OK;
}


/*
创建一个无向图
*/
int CreateUDG(AdjMatrix *G){
	printf("建立无向图");
	int i, j, k;
	VertexData v1, v2;
	printf("输入顶点数和沿对角线弧数");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//初始化邻接矩阵
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = 0;
		}
	}
	//输入图的顶点
	for (i = 0; i < G->vexnum; i++)
	{
		printf("按顺序输入图的顶点");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//输入一条弧的两个顶点和权值
	for (k = 0; k <G->arcnum; k++)
	{
		printf("输入对角线一边弧的信息，起始和终止");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = 1;	//建立弧
		G->arcs[j][i].adj = 1;
	}
	return OK;
}
/*
void main(){
	AdjMatrix *G;
	G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
	CreateDG(G);
	//CreateDN(G);
	//CreateUDG(G);
	//CreateUDN(G);
	int i,j;
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			printf("%d\t", G->arcs[i][j].adj);
		}
		printf("\n");
	}
	system("pause");
}
*/