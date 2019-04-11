#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR -1

typedef enum{DG,DN,UDC,UDN} GraphKind;

typedef struct ArcNode{
	int adjvex;
	int weight;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VertexNode{
	char Data;
	ArcNode *firstArc;
}VertexNode;

typedef struct{
	VertexNode vertex[MAX_VERTEX_NUM];
	int vexnum, arcnum;
	GraphKind kind;
}AdjList;

int LocateVertex(AdjList *G, char v){
	int j = ERROR, k;
	for (k = 0; k < G->vexnum; k++)
	{
		if (G->vertex[k].Data == v){
			j = k;
			break;
		}
	}
	return j;
}

int CreateUDN(AdjList *G){
	printf("����������");
	int i, j, k,weight;
	char v1, v2;
	ArcNode *tempNode;
	printf("���붥�����ͶԽ��߻���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i].Data);
		G->vertex[i].firstArc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)
	{
		printf("����ÿһ��������Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		scanf_s("%d", &weight);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		tempNode = (ArcNode *)malloc(sizeof(ArcNode));
		tempNode->adjvex = j;
		tempNode->weight = weight;
		tempNode->nextarc = G->vertex[i].firstArc;
		G->vertex[i].firstArc = tempNode;
		tempNode = (ArcNode *)malloc(sizeof(ArcNode));
		tempNode->adjvex = i;
		tempNode->weight = weight;
		tempNode->nextarc = G->vertex[j].firstArc;
		G->vertex[j].firstArc = tempNode;
	}
	return OK;
}

int CreateDG(AdjList *G){
	printf("��������ͼ");
	int i, j, k;
	char v1, v2;
	ArcNode *tempNode;
	printf("���붥�����ͻ���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i].Data);
		G->vertex[i].firstArc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)
	{
		printf("����ÿһ��������Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		tempNode = (ArcNode *)malloc(sizeof(ArcNode));
		tempNode->adjvex = j;
		tempNode->weight = 1;
		tempNode->nextarc = G->vertex[i].firstArc;
		G->vertex[i].firstArc = tempNode;
	}
	return OK;
}

int CreateDN(AdjList *G){
	printf("����������");
	int i, j, k,weight;
	char v1, v2;
	ArcNode *tempNode;
	printf("���붥�����ͻ���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i].Data);
		G->vertex[i].firstArc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)
	{
		printf("����ÿһ��������Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		scanf_s("%d", &weight);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		tempNode = (ArcNode *)malloc(sizeof(ArcNode));
		tempNode->adjvex = j;
		tempNode->weight = weight;
		tempNode->nextarc = G->vertex[i].firstArc;
		G->vertex[i].firstArc = tempNode;
	}
	return OK;
}

int CreateUDG(AdjList *G){
	printf("��������ͼ");
	int i, j, k;
	char v1, v2;
	ArcNode *tempNode;
	printf("���붥�����ͶԽ��߻���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i].Data);
		G->vertex[i].firstArc = NULL;
	}
	for (k = 0; k < G->arcnum; k++)
	{
		printf("����ÿһ��������Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		tempNode = (ArcNode *)malloc(sizeof(ArcNode));
		tempNode->adjvex = j;
		tempNode->weight = 1;
		tempNode->nextarc = G->vertex[i].firstArc;
		G->vertex[i].firstArc = tempNode;
		tempNode = (ArcNode *)malloc(sizeof(ArcNode));
		tempNode->adjvex = i;
		tempNode->weight = 1;
		tempNode->nextarc = G->vertex[j].firstArc;
		G->vertex[j].firstArc = tempNode;
	}
	return OK;
}

void main(){
	AdjList *G;
	G = (AdjList *)malloc(sizeof(AdjList));
	//CreateDG(G);
	//CreateDN(G);
	//CreateUDG(G);
	CreateUDN(G);
	int i;
	for (i = 0; i < G->vexnum; i++){
		ArcNode *temp=G->vertex[i].firstArc;
		printf("%c", G->vertex[i].Data);
		while (temp!=NULL)
		{
			printf("-(%d)->%d",temp->weight, (temp->adjvex+1));
			temp = temp->nextarc;
		}
		printf("\n");
	}
	system("pause");
}
