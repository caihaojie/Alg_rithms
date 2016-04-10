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

void prepare();
KEY* insert_keywords();
int insert_id();
int is_keywords_common();
KEY* is_keywords_exist();

void main()
{
	
	char title[6][50] = {
		"computer data structures",
		"introduction to data structure",
		"fundamentals of data structure",
		"the design and analysis of computer algorithms",
		"introduction to numerical analysis",
		"numerical analysis"
	};

	char common[6][4] = { "and","a","an","the","to","of" };

	KEY* head = (KEY*)malloc(sizeof(KEY));
	head->next_ID = NULL;
	head->next_KEY = NULL;
	head->words = NULL;

	char* delim = " ";
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

	head = head->next_KEY;
	while (head)
	{
		printf("\nKeywords: %s\tID:",head->words);
		ID* id_head = head->next_ID;
		while (id_head)
		{
			printf("\t%d", id_head->id);
			id_head = id_head->next_ID;
		}
		head = head->next_KEY;
	}
	
	printf("\n");
}

void prepare(char ** a)
{
	a[0] = "computer data structures";
	a[1] = "introduction to data structure";
	a[2] = "fundamentals of data structure";
	a[3] = "the design and analysis of computer algorithms";
	a[4] = "introduction to numerical analysis";
	a[5] = "numerical analysis";
}

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

int is_keywords_common(char (*common)[4], char* words)
{
	for (int i = 0; i < 6; i++)
	{
		if (!strcmp(common[i], words))
			return 1;
	}
	return 0;
}
	
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

