#include<stdio.h>
#include"circle-two-way-linklist.h"
void main()
{
	struct sqlist *head,*p,*q;
	struct sqlist list;
	int length,value,local;
	head=&list;
	head=NULL;
	printf("��ʼ��һ��˫��ѭ������,����С��������ֽ�������\n");
    head=input(head);

	//��ȡ�����Ⱥ�����
//	length=LISTlength(head);

	//��ȡ�������һ��Ԫ�ص�ָ��ĺ���;
//	p=FOUNDw(head);

	//����ǰ�幦�ܣ�
//	printf("������Ҫǰ�����ֵ��\n");
//	scanf("%d",&value);
//	head=proinsert(head,value);

	//�����幦�ܣ�
//	printf("������Ҫ���ӵ�����ĩβ�����֣�\n");
//	scanf("%d",&value);
//	head=bottominsert(head,value);

	//����λ�ò��뺯����
//	printf("������Ҫ�����λ�ú���ֵ��\n");
//	scanf("%d%d",&local,&value);
//	head=insertlocal(head,local,value);

	//����ɾ����һ���ڵ㺯����
//	head=DELlistt(head);

	//ɾ����β������
//	head=DELlistw(head);

	//��λ��ɾ��������
//	printf("������Ҫɾ�����ݵ�λ�ã�\n");
//	scanf("%d",&local);
//	head=DELlocal(head,local);

	//����ֵɾ��������
//	printf("������Ҫɾ������ֵ��\n");
//	scanf("%d",&value);
//	head=DELvalue(head,value);

	//����λ�ò��Һ�����
//	printf("������Ҫ���ҵ�λ��\n");
//	scanf("%d",&local);
//	p=FOUNDlocal(head,local);

	//����ֵ���Һ�����
//	printf("������Ҫ���ҵ�ֵ:\n");
//	scanf("%d",&value);
//	local=FOUNDvalue(head,value);

	//������鹦�ܣ�
//	print(head);
//	printf("%d\n",length);
//	printf("%d\n",p->elem);
	printf("%d\n",local);
}