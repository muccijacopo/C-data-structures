typedef struct nodo_struct
{
	int id;
	elem_archi *archi;
	elem_nodi *pos; // riferimento lista nodi
} nodo;

typedef nodo *pnodo;

typedef struct element_list_nodi
{
	element_list_nodi *prev;
	element_list_nodi *next;
	pnodo info;
} elem_nodi;

typedef struct arco_struct
{
	int id;
	elem_archi *pos;
	pnodo from;
	pnodo to;
	elem_archi *frompos;
	elem_archi *topos;
} arco;

typedef arco *parco;

typedef struct elem_list_archi
{
	elem_list_archi *prev;
	elem_list_archi *next;
	arco *info;
} elem_archi;

typedef struct grafo_struct
{
	int numero_nodi;
	int numero_archi;
	elem_nodi *nodi;
	elem_archi *archi;
} grafo_oggetto;

typedef grafo_oggetto *grafo;

/* AGGIUNGI NODO */

pnodo AGGIUNGI_NODO(grafo g, int u) // u è l'id del nodo
{
	pnodo n = (pnodo)malloc(sizeof(pnodo));

	n->id = u;
	n->archi = NULL;

	elem_nodi *e = (elem_nodi *)malloc(sizeof(elem_nodi));
	e->info = n;
	e->prev = NULL;
	e->next = g->nodi;

	if (g->nodi != NULL)
		g->nodi->prev = e;

	g->nodi = e;
	g->numeronodi++;
	n->pos = e;

	return n;
}

/* Aggiungi arco */
parco AGGIUNGI_ARCO(grafo g, pnodo from, pnodo to, int u) // dove u è l'id dell'arco
{
	parco a = (parco)malloc(sizeof(parco));
	a->id = u;
	a->from = from;
	a->to = to;

	elem_archi *e = (elem_archi *)malloc(sizeof(elem_archi));
	e->info = a;
	e->prev = NULL;
	e->next = g->archi;

	if (g->archi != NULL)
		g->archi->prev = e;

	g->archi = e;
	g->numero_archi++;

	a->pos = e;

	// aggiungi a alla lista degli archi del nodo from

	e = (elem_archi *)malloc(sizeof(elem_archi));

	e->info = a;
	e->prev = NULL;
	e->next = from->archi;

	if (from->archi != NULL)
		from->archi->prev = e;

	from->archi = e;
	a->frompos = e;

	// aggiungi a alla lista degli archi del nodo to

	e = (elem_archi *)malloc(sizeof(elem_archi));
	e->info = a;
	e->prev = NULL;
	e->next = to->archi;

	if (to->archi != NULL)
		to->archi->prev = e;

	to->archi = e;
	a->topos = e;

	return a;
}

struct nodo_struct
{
	int colore;
	elem_nodi *pos;
	elem_archi *archi;
}

void
DFS(grafo g, pnodo n)

{
	elem_nodi *en = g->nodi;
	while (en != NULL)
	{
		en->info->color = 0;
		en = en->next;
	}

	DFS_RIC(n);
}

DFS_RIC(pnodo n)
{
	n->color = 1;

	elem_archi ea = n->archi;

	while (ea != NULL)
	{
		pnodo nodo = ea->info->from;
		if (nodo == n)
			nodo = ea->info->to;

		if (nodo->color == 0)
			DFS_RIC(nodo);

		ea = ea->next;
	}
}

/* --------------------- */

typedef struct elem_struct
{
	struct elem_struct *prev;
	struct elem_struct *next;
	int info;
} elem;

typedef struct grafo_array_struct
{
	int numero_nodi;
	elem **A;
} grafo_array;

void DFS(grafo_array *g, int v)
{
	int i;

	int *color = (int *)calloc(g->numero_nodi, sizeof(int));

	for (i = 0; i < g->numero_nodi; i++)
	{
		color[i] = 0;
	}

	DFS_RIC(g, v, color);
}

void DFS_RIC(grafo_array *g, int v, int *color)
{
	color[v] = 1;

	elem *x = g->A[v];
	while (x != NULL)
	{
		int i = x->info;
		if (color[i] == 0)
			DFS_RIC(g, i, color);

		x = x->next;
	}
}