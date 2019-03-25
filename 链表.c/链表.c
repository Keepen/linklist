#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//����
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

//1.����ĳ�ʼ����û�н�㡣
void NodeInit(Node **head)
{
	*head = NULL;
}

//���������ͷ����β��

//(1).ͷ��
void NodeInsertFront(Node **head,int data)
{
	//���ȷ����ڴ�
	//�������ݸ�ֵ
	//��������ӣ�1.���ýڵ��nextָ��ԭ����ͷ�ڵ�
	//			  2.�ٽ�ԭ����ͷ�ڵ�ָ��ýڵ�
	Node *node = (Node*)malloc(sizeof(Node));	//���Ƚ����ڴ�ķ���
	assert(node != NULL);	//�ж��ڴ��Ƿ����ɹ�

	node->data = data;
	node->next = *head;
	*head = node;
	//printf("%p\n", *head);
}

//(2).β��
void NodeInsertTail(Node **head, int data)
{
	//���ȷ����ڴ�
	//�ڽ������ݵĸ�ֵ
	//����������������1.��ԭ����ͷ�ڵ�ָ��ýڵ�
	//				  2.�ٽ��ýڵ��nextָ��NULL
	Node *node = (Node*)malloc(sizeof(Node));
	assert(node != NULL);
	//�������Ϊ��
	if (head == NULL)
	{
		*head = node;
		node->data = data;
		node->next = NULL;
	}
	//����Ϊ��
	else {
		(*head)->next = node;
		node->data = data;
		node->next = NULL;
	}
	
}

//(3).��ֵΪpos�Ľ������
void NodeInsertPos(Node** head, int pos, int data)
{
	//���п�
	Node *node = *head;
	//if (node == NULL)
	//{
	//	//����β��
	//	NodeInsertTail(*head, data);
	//	return;
	//}
	//����ǿգ��ȱ������ڽ��в���
	while (node != NULL)
	{
		if (node->data == pos)
		{
			Node *tem = (Node *)malloc(sizeof(Node));
			assert(tem != NULL);
			tem->data = data;
			tem->next = node->next;
			node->next = tem;
			return;
		}
		else node = node->next;
	}
}

//2.ɾ��������ͷɾ��βɾ
//(1).ͷɾ��
void NodeDeleteFront(Node **head)
{
	//�Ƚ�headָ����һ��
	//�ٽ���һ�������ڴ�����ͷ�
	//�п�
	if (*head == NULL)
	{
		return;
	}
	Node* node = *head;
	*head = (*head)->next;
	free(node);
	return;
}

//(2).βɾ
void NodeDeleteTail(Node **head)
{
	//�Ƚ��б����ҵ������ڶ������
	//�ٽ������ڶ�������nextָ��ռ���
	
	//�Ƚ����п�
	Node *node = *head;
	if (*head == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��������\n");
		return;
	}
	//�����ҵ������ڶ����ڵ�
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	Node *temp = node->next;
	free(temp);
	node->next = NULL;
}

//(3).ɾ��ֵΪdata�Ľ��
void NodeDeleteData(Node** head, int data)
{
	//�Ƚ����п�
	if (*head == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��������\n");
		return;
	}
	//�ٱ�������ֵΪdata�Ľ���ǰ�����
	Node *node = *head;
	while (node != NULL)
	{
		//�ҵ��ˣ�����ɾ����
		//������ʱ������¼�ýڵ�
		//��������
		//�ٽ��ýڵ���ڴ��ͷ�
		//Ŀ�����ǵ�һ�����
		if (node->data == data)
		{
			//����ͷɾ����
			Node* tem = *head;
			*head = (*head)->next;
			free(tem);
			return;
			//NodeDeleteFront(*head);
		}
		 if (node->next->data == data)
		{
			Node *temp = node->next;
			node->next = node->next->next;
			free(temp);
			return;
		}
		else node = node->next;
	}
}

//3.���Ҳ�����
//����ֵΪdata�Ľ��
Node * NodeFind(Node **head, int data)
{
	//�Ƚ����п�
	if (*head == NULL)
	{
		return NULL;
	}
	//����ǿ�
	Node *node = *head;
	while (node != NULL)
	{
		if (node->data == data)
		{
			printf("�ҵ�����������\n");
			return node;
		}
		else node = node->next;
	}
	if (node == NULL)
	{
		printf("���޴���������\n");
		return NULL;
	}
}

//4.���������
void NodeDestroy(Node** head)
{
	//�Ƚ����п�

	Node *node = *head;
	*head = NULL;
	head = NULL;
	if (node == NULL)
	{
		printf("����Ϊ�գ�����\n");
		return;
	}
	while (node != NULL)
	{
		//�Ƚ����ָ����һ��λ�ã����ͷŵ�ǰλ�õ��ڴ�
		Node *temp = node;
		if (node->next != NULL) {
			node = node->next;
		}
		else {
			node = NULL;
		}
		free(temp);	
	}
	printf("���������٣�����\n");
	return;
}



//5.��ӡ����
void NodePrint(Node *head)
{
	Node *node = head;
	if (node == NULL)
	{
		printf("����Ϊ�գ�����\n");
	}
	while (node != NULL)
	{
		printf("%-3d ", node->data);
		node = node->next;
	}
}



int main()
{
	Node *head ;
	NodeInit(&head);
	NodeInsertFront(&head, 10);
	NodeInsertFront(&head, 20);
	NodeInsertFront(&head, 30);
	NodeInsertFront(&head, 40);
	//NodeDeleteFront(&head);
	//NodeDeleteTail(&head);
	//NodeDeleteData(&head, 40);
	//NodeInsertPos(&head, 20, 25);
	Node *pos = NodeFind(&head,20);
	NodeDestroy(&head);
	NodePrint(head);
	system("pause");
	return 0;
}