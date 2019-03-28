#include<stdio.h>
#include<stdlib.h>

	typedef struct Node			/*������Ͷ���*/
	{
		char data;
		struct Node *next;
	}Node,*LinkList;			/*LinkList��������ͷ��㣬��ǿ����ɶ���*/


//��ͷ�巨������
    void CreateFromHead(LinkList L){
		Node *s;
		char c;
		int flag = 1;		//����һ�����Ʋ����������롰$��ʱ��flagΪ0���������
		while( flag ){
			c = getchar();
			if(c !='$'){
				s = (Node*)malloc(sizeof(Node));
//malloc�����ǿ���һ���ռ䣬�ռ�ľ����С����()��ģ���������ֵ��sizeof����˼�Ǽ���Node��ռ�ռ�Ĵ�С��***����malloc�����ٳ����Ŀռ���һ����ַ�ռ䣬������ǰ��Ҫ��һ����Node*����ǿ��ת����Node*���ͣ����ǽ�����ͣ�
				s ->data = c;
				s ->next = L ->next;
				L ->next = s;
			}
			else flag = 0;
		}
}//����������÷���ֵ����������Ϊ��C�з����ܷ��ز��������ܸı��ַ���߷��ص�ַ���������ͷ���β�嶼���Ե�ַ����ʽ���еģ����Բ��÷���������Ч

//β�巨������
	void CreateFromTail(LinkList L){
		Node *r=L,*s;
		int flag=1;					//����һ�����Ʋ����������롰$��ʱ��flagΪ0���������
		char c;
		while(r->next!=NULL){			//rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���
			r=r->next;
		}
		while(flag){
			c=getchar();
			if(c!='$'){
				s=(Node*)malloc(sizeof(Node));
				s->data=c;
				r->next=s;
				r=s;
			}
			else{
				flag=0;
				r->next=NULL;	//�����һ������next������Ϊ�գ���ʾ����Ľ���
			}
		}
	}

//������λ�ò���ĳֵ
	int Create(LinkList L){
		int j=0,num1=0,flag=0;
		char letter1=0;			//letter1,num1���ǲ��������������û��������Ϣ��j�ǲ���
		Node *p=L,*s;

		printf("��������Ҫ�����λ�ã�0�����ͷ����\n");		//���û���������Ҫ����Ϣ
		scanf("%d",&num1);
		printf("��������Ҫ������ַ�\n");
		scanf("%c",&letter1);
		
		if(num1=0){			//�жϲ���λ���Ƿ��Ǳ�ͷ��
				s=(Node*)malloc(sizeof(Node));
				s->data=letter1;
				s->next=L->next;
				L->next=s;
				flag=1;
			}
		if(num1>0){	 //����λ�÷Ǳ�ͷ�������ݲ���
			while((p->next!=NULL)&&(j<num1)){
				p=p->next;
				j++;
			}
			if(num1==j){
				s=(Node*)malloc(sizeof(Node));
				s->data=letter1;
				s->next=p->next;
				p->next=s;
				flag=1;
			}
		}
		return flag;
	}

//����ĳֵ
	void Locate(LinkList L){
		int num2=0;
		char key=0;
		Node* p=L->next;
		printf("��������Ҫ���ҵ��ַ�����");
		scanf("%c",&key);

		//�ӱ��е�һ����㿪ʼ��
		while(p!=NULL){			//��ǰ��δ����
			if(p->data!=key){
				p=p->next;
				num2++;
			}
			else {
				num2++;
				break;
			}			//�ҵ����ֵ=key���˳�ѭ����num2++��Ϊ��ʹδ�ҵ��͵�һ�ξ��ҵ��˵Ľ�����ֿ���
		}
		if(num2!=0)printf("�����ҵ����ݵ�λ����%d",num2);
		else printf("δ�ҵ�����Ҫ�ҵ�����");
	}

//��ȡĳ����ֵ
	void Get(LinkList L){
		int num3=0,j=0;
		Node *p=L;

		do{
		printf("��������Ҫ��ȡ�����ݵ�λ�ã�λ�õ�ֵ����0��");
		scanf("%d",&num3);
		}while(num3<=0);			//ȷ���õ���λ�ô���0
		
		while((p->next!=NULL)&&(j<num3)){		//��ͷ��㿪ʼɨ��
			p=p->next;
			j++;								//��ɨ����ļ�����
		}
		if(num3==j)printf("��Ҫ�ҵ�����Ϊ%c",p->data);		//�ҵ���num3�����
		else printf("δ�ҵ���Ҫ�ҵ�����");					//�Ҳ�����㣬λ�õ�ֵ����������
	}

//�޸�ĳ����ֵ
	void Changedata(LinkList L){
		int num4=0,j=0;
		char letter2;
		Node *p=L;

		do{
		printf("��������Ҫ�޸ĵ����ݵ�λ�ã�λ�õ�ֵ����0��");
		scanf("%d",&num4);
		}while(num4<=0);			//ȷ���õ���λ�ô���0

		while((p->next!=NULL)&&(j<num4)){		//��ͷ��㿪ʼɨ��
			p=p->next;
			j++;								//��ɨ����ļ�����
		}
		if(num4==j){
			printf("��������Ҫ�޸ĵ�ֵ");
			scanf("%c",&letter2);
			p->data=letter2;
			printf("�޸ĳɹ�");
		}
		else printf("δ�ҵ���Ҫ�޸ĵ�����");					//�Ҳ�����㣬λ�õ�ֵ����������
	}

//ɾ��ĳ����ֵ
	void Deletedata(LinkList L){
		Node *p=L,*r;
		int k=0,num5;
		
		do{
		printf("��������Ҫ�޸ĵ����ݵ�λ�ã�λ�õ�ֵ����0��");
		scanf("%d",&num5);
		}while(num5<=0);			//ȷ���õ���λ�ô���0

		while(p->next!=NULL&&k<num5-1){		//Ѱ�ұ�ɾ�����num4��ǰ�����num5 - 1ʹpָ����
			p=p->next;
			k++;
		}									//���ҵ�num5 - 1�����
		if(!(p->next)){				//whileѭ������Ϊp->next=NULL��i<1������ȥ�ģ���Ϊp->nextΪ�գ�û���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ��λ��num5���Ϸ�
			printf("ɾ���ڵ��λ�ò�����");
		}
		else{
			r=p->next;
			p->next=r->next;			//�޸�ָ�룬ɾ�����
			free(r);
			printf("ɾ���ɹ�");
		}					//�ͷű�ɾ���Ľ����ռ�õ��ڴ�ռ�
	}

//������ĳ���
	int ListLength(LinkList L){
		Node *p=L->next;
		int j=0;
		while(p!=NULL){
			p=p->next;
			j++;
		}
		return j;		//jΪ����ĳ���
	}

//��˳���������
	void output(LinkList L){
		Node *p=L;
		while (p ->next != NULL){
            p = p ->next;
			printf("%c",p ->data);
		}
		printf("\n");
	}

	
	
	
	void main(){
		char letter=0,letter1=0;
		int num1=0;
		LinkList L;
		L=(LinkList)malloc(sizeof(Node));
		L->next=NULL;

//��ѭ���ṹ�����ظ���ѡ����Ҫ�Ĺ���
		do{
			printf("�������:\n\tA.��ͷ�巨������\n\tB.��β�巨������\n\tC.������λ�ò���ĳֵ(0�����ͷ��)\n\tD.����ĳֵ\n\tE.��ȡĳ����ֵ\n\tF.�޸�ĳֵ\n\tG.ɾ��ĳ����ֵ\n\tH.������ĳ���\n\tI.�������\n\tJ.�˳�����\n");
			printf("����������Ҫ���еĺ����ı��\n");
			scanf("%c",&letter);
			while( (letter<'A') || (letter>'J'&&letter<'a') || (letter>'j') ){
			printf("����������\n");
			scanf("%c",&letter);
			}

			if(letter=='a'||letter=='A'){
				printf("�����������ַ����ݣ�����'$'���Ž�β\n");
				CreateFromHead(L);
				printf("����ɹ�");
			}

			if(letter=='b'||letter=='B'){
				printf("�����������ַ����ݣ�����'$'���Ž�β\n");
				CreateFromTail(L);
				printf("����ɹ�");
			}

			if(letter=='c'||letter=='C'){
				while(Create(L)==0){
					printf("���������Ϣ��������������\n\n");
				}
				printf("����ɹ�");
			}

			if(letter=='d'||letter=='D'){
				Locate(L);
			}

			if(letter=='e'||letter=='E'){
				Get(L);
			}

			if(letter=='f'||letter=='F'){
				Changedata(L);
			}

			if(letter=='g'||letter=='G'){
				Deletedata(L);
			}

			if(letter=='h'||letter=='H'){
				printf("������Ϊ%d",ListLength(L));
			}
			
			if(letter=='i'||letter=='I'){
				output(L);
			}
			printf("\n\n\n");
		}while((letter!='j')&&(letter!='J'));
		
	}
