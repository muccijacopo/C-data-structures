/* CODE */
NEW_QUEUE()
{
	c.head = NULL;
	return c;
}

IS_EMPTY()
{
	return c.head == NULL;
}

/* ENQUEUE: Aggiungi nuovo elemento in coda */
ENQUEUE(c,u)
{
	x.info = u;
	x.next = NULL;

	if IS_EMPTY(c)
		c.head = x;
		return

	else
		nodo = c.head;
		while(nodo.next != NULL)
			nodo = nodo.next;

		nodo.next = x;

}
/* DEQUEUE: Rimuove l'elemento più vecchio della coda e lo restituisce */
DEQUEUE(c) 
{
	if IS_EMPTY(c)
		printf("Coda vuota, nulla da eliminare.");

	else
	{
		int x = c.head.info;
		c.head = c.head.next;
		return x;
	}
}