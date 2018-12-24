#define _CRT_SECURE_NO_WARNINGS
#include"Contact.h"

enum Option
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY
};

void ChooseOption(pContact pCon)
{
	int input = 0;
	do{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Add(pCon);
			break;
		case DELETE:
			Delete(pCon);
			break;
		case SEARCH:
			Search(pCon);
			break;
		case MODIFY:
			Modify(pCon);
			break;
		case SHOW:
			Show(pCon);
			break;
		case SORT:
			Sort(pCon);
			break;
		case EMPTY:
			Empty(pCon);
			break;
		case EXIT:
			Destroy(pCon);
			printf("Exit success!\n");
			break;
		default:
			printf("Input Error!\n");
			break;
		}
	} while (input);
}

void menu()
{
	printf("******************************\n");
	printf("***   Welcome Contact!!!   ***\n");
	printf("******************************\n");
	printf("******************************\n");
	printf("*** 1.add        2.delete  ***\n");
	printf("*** 3.search     4.modify  ***\n");
	printf("*** 5.show       6.sort    ***\n");
	printf("*** 7.empty      0.exit    ***\n");
	printf("******************************\n");
	printf("Please input:");
}
//初始化
void InitContact(pContact pCon)
{
	pCon->data = (pPeoInfo)malloc(DEFAULT_CAPACITY*sizeof(PeoInfo));
	pCon->capacity = DEFAULT_CAPACITY;
	pCon->size = 0;
}

static int CheckCapacity(pContact pCon)
{
	assert(pCon);
	if (pCon->size == pCon->capacity)
	{
		pPeoInfo Expand = (pPeoInfo)realloc(pCon->data,
			sizeof(PeoInfo)*(pCon->capacity + ADD_CAPACITY));
		if (Expand != NULL)
		{
			pCon->data = Expand;
			pCon->capacity += ADD_CAPACITY;
			printf("Expand success!\n");
			return 1;
		}
		else
		{
			printf("Expand faliure!\n");
			return 0;
		}
	}
	return 1;
}

void Add(pContact pCon)
{
	assert(pCon);
	if (CheckCapacity(pCon) == 0)
		return;
	printf("Please input name:\n");
	scanf("%s", pCon->data[pCon->size].name);
	printf("Please input age:\n");
	scanf("%d", &pCon->data[pCon->size].age);
	printf("Please input sex:\n");
	scanf("%s", pCon->data[pCon->size].sex);
	printf("Please input tele:\n");
	scanf("%s", pCon->data[pCon->size].tele);
	printf("Please input addre:\n");
	scanf("%s", pCon->data[pCon->size].addre);
	pCon->size++;
}

static int Find(const pContact pCon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	assert(pCon);
	printf("Please input name:\n");
	scanf("%s", name);
	for (i = 0; i < pCon->size; i++)
	{
		if (strcmp(name, pCon->data[i].name) == 0)
			return i;
	}
	return -1;
}

void Delete(pContact pCon)
{
	int i = 0;
	int ret = 0;
	assert(pCon);
	ret = Find(pCon);
	if (ret == -1)
	{
		printf("Delete is not exist!\n");
		return;
	}
	else
	{
		for (i = ret; i < pCon->size; i++)
		{
			pCon->data[i] = pCon->data[i + 1];
		}
		pCon->size--;
		printf("Successfully deleted!\n");
	}
}

void Search(const pContact pCon)
{
	int ret = 0;
	assert(pCon);
	ret = Find(pCon);
	if (ret == -1)
	{
		printf("Search failure!\n");
		return;
	}
	else
	{
		printf("Search Success!\n");
		printf("%10s %5s %10s %15s %10s\n", "Name", "Age", "Sex", "Tele", "Addre");
		printf("%10s %5d %10s %15s %10s\n", pCon->data[ret].name, 
			pCon->data[ret].age, pCon->data[ret].sex, pCon->data[ret].tele, pCon->data[ret].addre);
	}
}

void Modify(pContact pCon)
{
	int i = 0;
	int ret = 0;
	assert(pCon);
	ret = Find(pCon);
	if (ret == -1)
	{
		printf("Find failure!\n");
		return;
	}
	else
	{
		printf("Please input name:\n");
		scanf("%s", pCon->data[ret].name);
		printf("Please input age:\n");
		scanf("%d", &pCon->data[ret].age);
		printf("Please input sex:\n");
		scanf("%s", pCon->data[ret].sex);
		printf("Please input tele:\n");
		scanf("%s", pCon->data[ret].tele);
		printf("Please input addre:\n");
		scanf("%s", pCon->data[ret].addre);
		printf("Modify Success!\n");
	}
}

void Show(const pContact pCon)
{
	int i = 0;
	assert(pCon);
	if (pCon->size == 0)
	{
		printf("Contact is empty!\n");
	}
	printf("%10s %5s %10s %15s %10s\n", "Name", "Age", "Sex", "Tele", "Addre");
	for (i = 0; i < pCon->size; i++)
	{
		printf("%10s %5d %10s %15s %10s\n", pCon->data[i].name,
			pCon->data[i].age, pCon->data[i].sex, pCon->data[i].tele, pCon->data[i].addre);
	}
}

void Sort(pContact pCon)
{
	int i = 0;
	int j = 0;
	int flag = 0;
	assert(pCon);
	for (i = 0; i < pCon->size - 1; i++)
	{
		for (j = 0; pCon->size - 1 - i; j++)
		{
			if (strcmp(pCon->data[j].name, pCon->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pCon->data[j];
				pCon->data[j] = pCon->data[j + 1];
				pCon->data[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	printf("Sort success!\n");
}

void Empty(pContact pCon)
{
	assert(pCon);
	pCon->capacity = 0;
	pCon->size = 0;
	printf("Empty success!\n");
}

void Destroy(pContact pCon)
{
	free(pCon->data);
	pCon->data = NULL;
	pCon->capacity = 0;
	pCon->size = 0;
}
