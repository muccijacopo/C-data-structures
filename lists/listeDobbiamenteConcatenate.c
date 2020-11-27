/* LISTE DOPPIAMENTE CONCATENATE */
/* IN C */
typedef struct nodo_struct
{
	int info;
	nodo_struct *next;
	nodo_struct *prev;
} nodo;

typedef nodo *lista;

void INSERT(lista *l, int i)
{
	nodo *n = (nodo *)malloc(sizeof(nodo));
	nodo->info = i;
	nodo->prev = NULL;
	nodo->next = (*l);
	if ((*l) != NULL)
		(*l)->prev = nodo;

	(*l) = nodo;
}

void DELETE(lista *l, int i)
{
	nodo *n = (*l);
	while (n != NULL)
	{
		if (n->info == i)
		{
			if (n->prev != NULL)
				n->prev->next = n->next;
			else
				(*l) = (*l)->next;
			if (n->next != NULL)
				n->next->prev = n->prev;
			free(n);
			return;
		}

		n = n->next;
	}
}

/* IN PSEUDOCODIFICA */

INSERT_BEFORE(l, n, i)
{
	x.info = n;

	// Se i è il primo
	if (i.prev == NULL)
	{
		x.next = l.head;
		x.prev = NULL;
		l.head = x;
	}
	else
	{
		x.next = i;
		x.prev = i.prev;
		i.prev = x;
	}
}

DELETE(l, u)
{
	if IS_EMPTY (l)
		printf("Lista vuota");
	return;

	x = l.head;

	while (x != NULL)
	{
		if (x.info == u)
		{
			if (x.prev != NULL)
				x.prev.next = x.next;
			else
				l.head = x.next;
			if (x.next != NULL)
				x.next.prev = x.prev;

			return;
		}

		x = x.next;
	}
}
