#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ID
{
	int id;
	struct ID* next_ID;
};

typedef struct ID ID;

struct KEY
{
	char* words;
	struct KEY* next_KEY;
	ID* next_ID;
};

typedef struct KEY KEY;

KEY* insert_keywords();
int insert_id();
int is_keywords_common();
KEY* is_keywords_exist();

void main()
{
	//要建立索引表的二维数组
	char title[6][50] = {
		"computer data structures",
		"introduction to data structure",
		"fundamentals of data structure",
		"the design and analysis of computer algorithms",
		"introduction to numerical analysis",
		"numerical analysis"
	};

	//要排除的关键词表
	char common[6][4] = { "and","a","an","the","to","of" };

	//关键词链表表头，不存放关键词
	KEY* head = (KEY*)malloc(sizeof(KEY));
	head->next_ID = NULL;
	head->next_KEY = NULL;
	head->words = NULL;

	//以空格作为title分割符
	char* delim = " ";

	//构建关键词链表，及每个关键词对应的title编号表
	for (int i = 0; i < 6; i++)
	{
		int temp = 0;
		char* words;
		KEY* keys;
		while (*(title[i] + temp))
		{
			words = strtok((title[i] + temp), delim);
			temp += strlen(words) + 1;
			if (!is_keywords_common(common, words))
			{
				if (!(keys = is_keywords_exist(head, words)))
					insert_keywords(head, words, i);
				else
					insert_id(keys, i);
			}
		}

	}

	//格式化输出建立的索引表，并执行free()
	KEY* k = head->next_KEY;
	free(head);
	head = k;
	while (head)
	{
		printf("\nKeywords: %s\tID:", head->words);
		ID* id_head = head->next_ID;
		while (id_head)
		{
			printf("\t%d", id_head->id);
			ID* id_temp = id_head->next_ID;
			free(id_head);
			id_head = id_temp;
		}
		KEY* key_temp = head->next_KEY;
		free(head);
		head = key_temp;
	}

	printf("\n");
}

/*************************************************
Function: insert_id(KEY*, int)
Description: 按照从小到大的顺序将title的id插到对应的关键词结点之后
Calls: malloc(), free()
Called By: main(), insert_keywords()
Input: KEY* head->关键词链表结点地址
int id->该关键词对应title的编号
Output: NULL
Return: 返回1代表操作成功
Others: NULL
*************************************************/
int insert_id(KEY* keywords, int id)
{
	ID* node = (ID*)malloc(sizeof(ID));
	node->id = id;
	node->next_ID = NULL;

	ID* head = (ID*)malloc(sizeof(ID));
	ID* temp = head;
	head->next_ID = keywords->next_ID;
	head->id = 0;

	while (head->next_ID)
	{
		if (head->next_ID->id > node->id)
		{
			node->next_ID = head->next_ID;
			head->next_ID = node;
			keywords->next_ID = temp->next_ID;
			free(temp);
			return 1;
		}
		else {
			head = head->next_ID;
		}
	}
	head->next_ID = node;
	keywords->next_ID = temp->next_ID;
	free(temp);
	return 1;
}

/*************************************************
Function: insert_keywords(KEY*, char*, int)
Description: 用头插法，插入关键词到关键词链表
Calls: malloc()
Called By: main()
Input: KEY* head->关键词链表头结点
char* keywords->要插入的关键词的地址
int id->该关键词对应title的编号
Output: NULL
Return: 新插入的关键词的在关键词链表中的地址
Others: NULL
*************************************************/
KEY* insert_keywords(KEY* head, char* keywords, int id)
{
	KEY* Node = (KEY*)malloc(sizeof(KEY));
	Node->next_KEY = head->next_KEY;
	head->next_KEY = Node;
	Node->next_ID = NULL;
	Node->words = keywords;
	insert_id(Node, id);
	return Node;
}

/*************************************************
Function: is_keywords_common(char**, char*)
Description: 判断关键字是否属于要排除的
Calls: strcmp()
Called By: main()
Input:  char (*common)[4]->要排除的关键词数组
char* words->要判断的关键词地址
Output: NULL
Return: 是要排除的则返回1,不是则返回0
Others: NULL
*************************************************/
int is_keywords_common(char(*common)[4], char* words)
{
	for (int i = 0; i < 6; i++)
	{
		if (!strcmp(common[i], words))
			return 1;
	}
	return 0;
}

/*************************************************
Function: is_keywords_exist(KEY*, char*)
Description: 判断关键字是否存在
Calls: strcmp()
Called By: main()
Input:  KEY* head->关键词链表头结点
char* words->要判断的关键词地址
Output: NULL
Return: 已存在则返回对应关键词链表结点地址,不存在则返回NULL
Others: NULL
*************************************************/
KEY* is_keywords_exist(KEY* head, char* words)
{
	head = head->next_KEY;
	while (head)
	{
		if (!strcmp(head->words, words))
			return head;
		head = head->next_KEY;
	}
	return NULL;
}

