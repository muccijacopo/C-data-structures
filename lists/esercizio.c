typedef struct capoabb
{
	int modello;
	int taglia;
	int disponibilità;
} capo;

typedef struct elem_lista
{
	capo *vestito;
	struct elem_lista *next;
} elist;

typedef elist *lista;

void INSERISCI(lista *pl, int modello, int taglia, int disponibilità)
{
	capo *c = (capo *)malloc(sizeof(capo));
	c->modello = modello;
	c->taglia = taglia;
	c->disponibilità = disponibilità

		elist *e = malloc(sizeof(elist));
	e->vestito = c;
	e->next = *(pl);
	*(pl) = e;
}

int VERIFICA_DISP(lista l, int modello, int taglia)
{

	while (l != NULL)
	{
		if (l->vestito->modello == modello)
			&&(l->> vestito->taglia == taglia) return l->vestito->disponibilità;

		l = l->next;
	}

	return 0;
}

int VENDITA(lista l, int modello, int taglia)
{
	while (l != NULL)
	{
		if ((l->vestito->modello = modello) && (l->vestito->taglia) && (l->vestito->disponibilità != 0))
		{
			l->vestito->disponibilità = (l->vestito->disponibilità) - 1;
		}

		l = l->next;
	}

	return 0;
}

lista ESAURITI(lista l)
{
	lista esauriti = NULL;

	while (l != NULL)
	{
		if (l->vestito->disponibilità == 0)
		{
			elist *e = (elist *)malloc(sizeof(elist));
			e->vestito = lista->vestito;
			e->next = esauriti;
			esauriti = e;
		}

		esauriti = esauriti->next;
	}

	return esauriti;
}
