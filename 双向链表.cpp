#include<iostream>
#include <stdlib.h>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std;

typedef void llist_op(void *);


struct llist_node_st
{
	void *data;//未来的数据还未确定。想要储存的时候，需要知道有多少空间。
	struct llist_node_st *prev, *next;
};


typedef struct 
{
	int size;//这个与上面的遥相呼应，给数据定义了data需要的空间，
	struct llist_node_st  head;
}LLIST;

struct Person
{
	int age;
	char name[30];
	int id;
};
LLIST * list_creat(int size)//而技术的关键在于用了指针函数。返回的是指针。。。
{
	//创建头节点。
	LLIST *newnode;  //借外面的字创建一个结点，创建完后让别人指向它就行。
	//newnode = (LLIST*)malloc(sizeof(*newnode));
	newnode = (LLIST*)new LLIST*[(sizeof(*newnode))];//new char[srrlen()];//创建的是指针，需要储存东西，必须要创建空间给他。

		if (newnode == NULL)
			return NULL;
		//初始化
		newnode->size = size;
		newnode->head.prev = newnode->head.next = &newnode->head;
		printf("%p  ,%p,%p,%p，%d \n",newnode , &newnode->head, list_creat, newnode,size);

			return newnode;
}
int list_inser(LLIST *ptr, const void *data, int mode)
{
	struct llist_node_st *newnode;//创建新节点
	newnode = (llist_node_st *)malloc(sizeof(*newnode));//给新节点分配空间
	if (newnode == NULL)
		return -1;
	newnode->data = malloc(ptr->size);//给里面的指针分配空间
	if (newnode->data == NULL)
	{
		free(newnode);
		return -1;
	}
	memcpy(newnode->data ,data,ptr->size);//将传进来的数据赋值。


	//int list_inser(LLIST *ptr, const void *data, int mode)
	//struct llist_node_st *newnode;//创建新节点
	if (mode == 1)//创建链接方式。
	{
		
		//newnode->prev = &ptr->head;//新的节点的前指针指向头
		//newnode->next = ptr->head.next;//新节点的下一个指针，指向头节点的下一个节点
		//newnode->prev->next = newnode;//
		//newnode->next->prev = newnode;

		newnode->prev = ptr->head.prev;   //新节点指向旧节点对应的前驱后继。
		newnode->next = ptr->head.next;
		ptr->head.next = newnode;
		ptr->head.prev = newnode;


	}
	else if(mode==2)
	{
		newnode->prev = ptr->head.prev;
		newnode->next = &ptr->head;
		newnode->prev->next = newnode;
		newnode->next->prev = newnode;
	}
	else
	{
		return -2;
	}

	return 0;
}
void print_s(void *data)
{
	struct Person * d = (Person*)data;
	cout << d->id << " " << d->age << " "<< d->name<<endl;
	// printf("%d  %d  %s \n", d->id, d->age ,d->name);
	 //printf("%d     ", d->age);

}

void list_tral(LLIST *ptr,llist_op * op)
{
	struct llist_node_st  *cur;
	for (cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
	{
		op(cur->data);
	}
}

void  list_destroy(LLIST *ptr)
{
	struct llist_node_st  *cur ,*node;
	for (cur = ptr->head.next; cur != &ptr->head; cur = node)
	{ 
		node = cur->next;
		free(cur->data);
		free(cur);
	}

}

void  main()
{
	LLIST *handle;//只是创建了头结点。头结点不放数据。
	int i;
	struct  Person  tmp;//创建数据的地方。
	handle = list_creat(sizeof(struct Person ));//创建了头结点。并且返回了其中的起始地址。
	for (i = 0; i < 1000000; i++)
	{
		tmp.age = 20 + i;
		tmp.id = i;
		snprintf(tmp.name, 30, "hahah%d",2);
		list_inser(handle,&tmp,1);//什么类型能接收一个结构体，没错除了结构体类型，还有VIOD；
	}
	list_tral(handle,print_s);
	list_destroy(handle);

	system("pause");
}




