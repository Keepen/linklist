#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//链表：
typedef struct Node
{
	int data;
	struct Node *next;
}Node;

//1.链表的初始化：没有结点。
void NodeInit(Node **head)
{
	*head = NULL;
}

//插入操作：头插与尾插

//(1).头插
void NodeInsertFront(Node **head,int data)
{
	//首先分配内存
	//进行数据赋值
	//链表的连接：1.将该节点的next指向原来的头节点
	//			  2.再将原来的头节点指向该节点
	Node *node = (Node*)malloc(sizeof(Node));	//首先进行内存的分配
	assert(node != NULL);	//判断内存是否分配成功

	node->data = data;
	node->next = *head;
	*head = node;
	//printf("%p\n", *head);
}

//(2).尾插
void NodeInsertTail(Node **head, int data)
{
	//首先分配内存
	//在进行数据的赋值
	//将链表连接起来：1.将原来的头节点指向该节点
	//				  2.再将该节点的next指向NULL
	Node *node = (Node*)malloc(sizeof(Node));
	assert(node != NULL);
	//如果链表为空
	if (head == NULL)
	{
		*head = node;
		node->data = data;
		node->next = NULL;
	}
	//链表不为空
	else {
		(*head)->next = node;
		node->data = data;
		node->next = NULL;
	}
	
}

//(3).在值为pos的结点后插入
void NodeInsertPos(Node** head, int pos, int data)
{
	//先判空
	Node *node = *head;
	//if (node == NULL)
	//{
	//	//进行尾插
	//	NodeInsertTail(*head, data);
	//	return;
	//}
	//链表非空，先遍历，在进行插入
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

//2.删除操作：头删、尾删
//(1).头删：
void NodeDeleteFront(Node **head)
{
	//先将head指向下一个
	//再将第一个结点的内存进行释放
	//判空
	if (*head == NULL)
	{
		return;
	}
	Node* node = *head;
	*head = (*head)->next;
	free(node);
	return;
}

//(2).尾删
void NodeDeleteTail(Node **head)
{
	//先进行遍历找到倒数第二个结点
	//再将倒数第二个结点的next指向空即可
	
	//先进行判空
	Node *node = *head;
	if (*head == NULL)
	{
		printf("链表为空，无法删除！！！\n");
		return;
	}
	//遍历找到倒数第二个节点
	while (node->next->next != NULL)
	{
		node = node->next;
	}
	Node *temp = node->next;
	free(temp);
	node->next = NULL;
}

//(3).删除值为data的结点
void NodeDeleteData(Node** head, int data)
{
	//先进行判空
	if (*head == NULL)
	{
		printf("链表为空，无法删除！！！\n");
		return;
	}
	//再遍历查找值为data的结点的前驱结点
	Node *node = *head;
	while (node != NULL)
	{
		//找到了，进行删除：
		//创建临时变量记录该节点
		//连接链表
		//再将该节点的内存释放
		//目标结点是第一个结点
		if (node->data == data)
		{
			//进行头删操作
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

//3.查找操作：
//查找值为data的结点
Node * NodeFind(Node **head, int data)
{
	//先进行判空
	if (*head == NULL)
	{
		return NULL;
	}
	//链表非空
	Node *node = *head;
	while (node != NULL)
	{
		if (node->data == data)
		{
			printf("找到该数！！！\n");
			return node;
		}
		else node = node->next;
	}
	if (node == NULL)
	{
		printf("查无此数！！！\n");
		return NULL;
	}
}

//4.链表的销毁
void NodeDestroy(Node** head)
{
	//先进行判空

	Node *node = *head;
	*head = NULL;
	head = NULL;
	if (node == NULL)
	{
		printf("链表为空！！！\n");
		return;
	}
	while (node != NULL)
	{
		//先将结点指到下一个位置，再释放当前位置的内存
		Node *temp = node;
		if (node->next != NULL) {
			node = node->next;
		}
		else {
			node = NULL;
		}
		free(temp);	
	}
	printf("链表已销毁！！！\n");
	return;
}



//5.打印链表
void NodePrint(Node *head)
{
	Node *node = head;
	if (node == NULL)
	{
		printf("链表为空！！！\n");
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