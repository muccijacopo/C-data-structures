#include <stdio.h>
#include <stdlib.h>
#include "lista-array.h"

lista *NEW_LIST()
{

	int i;
	lista *l = (lista *)malloc(sizeof(lista));
	l->size = 8;
	l->next = (int *)calloc(l->size, sizeof(int));
	l->info = (int *)calloc(l->size, sizeof(int));
	l->prev = (int *)calloc(l->size, sizeof(int));

	for (i = 0; i < l->size; i++)
	{
		l->next[i] = i + 1;
		l->prev[i] = i - 1;
	}
	l->next[l->size - 1] = -1;
	l->head = -1;
	l->free = 0;
}

void INSERT(lista *l, int u)
{

	int col = ALLOCATE_COLUMN(l);
	l->info[col] = u;
	l->next[col] = l->head;
	l->prev[col] = -1;
	if (l->head != -1)
	{
		l->prev[l->head] = col;
	}
	l->head = col;
	printf("ho inserito l'elemento %d\n", u);
}

void DELETE(lista *l, int u)
{

	int i = l->head;
	while (i != -1)
	{
		if (l->info[i] == u)
		{ // devo rimuoverlo

			if (l->prev[i] != -1)
				l->next[l->prev[i]] = l->next[i];
			else
				l->head = l->next[i];
			if (l->next[i] != -1)
				l->prev[l->next[i]] = l->prev[i];
			FREE_COLUMN(l, i);
			return;
		}

		i = l->next[i];
	}
}

int ALLOCATE_COLUMN(lista *l)
{

	if (l->free == -1)
	{
		int i;
		// printf("errore: lista libera terminata\n");
		// exit(1);
		l->info = (int *)realloc(l->info, l->size * 2 * sizeof(int));
		l->next = (int *)realloc(l->next, l->size * 2 * sizeof(int));
		l->prev = (int *)realloc(l->prev, l->size * 2 * sizeof(int));
		for (i = l->size; i < l->size * 2; i++)
		{
			l->next[i] = i + 1;
			l->prev[i] = i - 1;
		}
		l->next[l->size * 2 - 1] = -1;
		l->prev[l->size] = -1;
		l->free = l->size;
		l->size = l->size * 2;
		printf("ho allocato %d caselle\n", l->size);
	}
	int output = l->free;
	if (l->next[l->free] != -1)
		l->prev[l->next[l->free]] = -1;
	l->free = l->next[l->free];
	return output;
}

void FREE_COLUMN(lista *l, int i)
{

	if (l->free != -1)
		l->prev[l->free] = i;
	l->next[i] = l->free;
	l->prev[i] = -1;
	l->free = i;
}
