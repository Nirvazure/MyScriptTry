#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 20	//��ඥ�����
#define INFINITY 999	//��ʾ����ֵ��������
#define ERROR -1
#define OK 1

typedef enum{DG,DN,UDC,UDN} GraphKind;	//
typedef char VertexData;

typedef struct ArcNode{
	int adj;	//������Ȩͼ����0/1��ʾ�Ƿ����ڣ���ȨͼΪȨֵ����
}ArcNode;

typedef struct{
	VertexData vertex[MAX_VERTEX_NUM];	//��������
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;	//ͼ�Ķ������ͻ�����
	GraphKind kind;
}AdjMatrix;	//(Adjacency Matrix Graph)

/*
�󶥵�λ�ú���
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
����һ��������
*/
int CreateDN(AdjMatrix *G){
	printf("����������");
	int i, j, k,weight;
	VertexData v1, v2;
	printf("���붥�����ͻ���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//��ʼ���ڽӾ���
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = INFINITY;
		}
	}
	//����ͼ�Ķ���
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//����һ���������������Ȩֵ
	for (k = 0; k < G->arcnum; k++)
	{
		printf("����ÿһ��������Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		scanf_s("%d", &weight);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = weight;	//������
	}
	return OK;
}


/*
����һ������ͼ
*/
int CreateDG(AdjMatrix *G){
	printf("��������ͼ");
	int i, j, k;
	VertexData v1, v2;
	printf("���붥�����ͻ���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//��ʼ���ڽӾ���
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = 0;
		}
	}
	//����ͼ�Ķ���
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//����һ���������������Ȩֵ
	for (k = 0; k < G->arcnum; k++)
	{
		printf("����ÿһ��������Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c",&v1);
		scanf_s("%c", &v2);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = 1;	//������
	}
	return OK;
}

/*
����һ��������
*/
int CreateUDN(AdjMatrix *G){
	printf("����������");
	int i, j, k,weight;
	VertexData v1, v2;
	printf("���붥�������ӶԽ��ߵĻ���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//��ʼ���ڽӾ���
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = 0;
		}
	}
	//����ͼ�Ķ���
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//����һ���������������Ȩֵ
	for (k = 0; k <G->arcnum; k++)
	{
		printf("����Խ���һ�߻�����Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		scanf_s("%d", &weight);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = weight;	//������
		G->arcs[j][i].adj = weight;
	}
	return OK;
}


/*
����һ������ͼ
*/
int CreateUDG(AdjMatrix *G){
	printf("��������ͼ");
	int i, j, k;
	VertexData v1, v2;
	printf("���붥�������ضԽ��߻���");
	scanf_s("%d,%d", &G->vexnum, &G->arcnum);
	//��ʼ���ڽӾ���
	for (i = 0; i < G->vexnum; i++){
		for (j = 0; j < G->vexnum; j++){
			G->arcs[i][j].adj = 0;
		}
	}
	//����ͼ�Ķ���
	for (i = 0; i < G->vexnum; i++)
	{
		printf("��˳������ͼ�Ķ���");
		getchar();
		scanf_s("%c", &G->vertex[i]);
	}
	//����һ���������������Ȩֵ
	for (k = 0; k <G->arcnum; k++)
	{
		printf("����Խ���һ�߻�����Ϣ����ʼ����ֹ");
		getchar();
		scanf_s("%c", &v1);
		scanf_s("%c", &v2);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);
		G->arcs[i][j].adj = 1;	//������
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