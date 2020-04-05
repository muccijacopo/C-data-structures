/* Resituisce il valore massimo di una lista */
int massimo(l) 
{
	x = l.head;

	if (x == NULL)
		printf("Lista vuota");
	else
		int max = x.info;
		x = x.next;

		while(x != NULL) {
			if(x.info > max) {
				max = x.info;
			}

			x = x.next;
		}

		return max;
}

/* Resituisce la somma degli elementi contenuti
in una lista singolarmente concatenata di interi */
int somma(l)
{
	x = l.head;

	if(x == NULL)
		printf("La lista è vuota");
	else
		int somma = 0;
		while(x != NULL)
		{
			somma = somma + x.info;
			x = x.next;
		}


	return somma;
}

/* Ritorna il riferimento all'elemento i che contiene
il valoro intero u in una lista singolarmente concatenata di interi */
int search(l,u) 
{
	x = l.head;

	while(x != NULL)
	{
		if(x.info == u)
			return x;

		x = x.next;
	}

	return NULL;
}

/* Ritorna il riferimento all'elemento che precedere l'elemento i */
int prev(l,i) 
{
	x = l.head;
	
	while(x != NULL)
	{
		if(x.next == i)
			return x;
		x = x.next;
	}

	return NULL;
}

/* Cancella nodo u */
void delete(l,u)
{
	x = l.head;

	if(x == NULL)
		printf("Lista vuota");
	else 
	{
		if(x.info == u)
		{
			l.head = l.head.next;
			x = l.head;
		}
		else
		{
			prev = x;
			x = x.next;
			while(x != NULL)
			{
				if(x.info == u)
					prev.next = x.next;
					return 0;

				x = x.next;
				prev = prev.next;
			}
		}

	}

}

int COMUNI(l1,l2)
{
	int comuni = 0;
	x = l1.head;

	if (IS_EMPTY(l1) || IS_EMPTY(l2))
		printf("Non ci sono elementi in comune.");

	else
		while(x != NULL)
			y = l2.head;
			while(y != NULL)
				if (x.info == y.info)
					comuni++;
			y = y.next;

		x = x.next;
}

INVERSA(l1)
{
	l2 = NEW_LIST();

	x = l1.head;

	if IS_EMPTY(l1)
		printf("Lista vuota, non invertibile.");
	else
		while(x != NULL)
		{
			newnodo.info = x.info;
			newnodo.next = l2.head;
			l2.head = newnodo;
			x = x.next;
		}
	return l2;
}


ACCODA(l1,l2)
{
	x = l1.head;

	if IS_EMPTY(l1)
		x = l2.head;
		return 0;

	while(x.next != NULL)
	{
		x = x.next;
	}

	x.next = l2.head;


}


void INSERT(list* pl, int u){

	elem* e = (elem*)malloc(sizeof(elem));
	e->info = u;
	e->prev = NULL;
	e->next = (*pl);
	if( (*pl) != NULL ) {  // c'era gia' un elemento in lista
		(*pl)->prev = e;
	}
	(*pl) = e;
}


void DELETE(list* pl, int u) {

	elem* e = (*pl);
	while ( e != NULL) {
		if( e->info == u) {  // l'ho trovato e lo rimuovo
			if( e->prev != NULL) 
				e->prev->next = e->next;
			else
				(*pl) = e->next;
			if( e->next != NULL)
				e->next->prev = e->prev;
			free(e);
			return;
		}
		e = e->next;
	}

}