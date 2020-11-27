/* PILE */

NEW_STACK()
{
	p.head = NULL;
	return p;
}

IS_EMPTY(p)
{
	return p.head == NULL;
}

PUSH(p, u)
{
	x.info = u;
	x.next = p.head;
	p.head = x;
}

POP(p)
{
	if (p.head == NULL)
		printf("Pila vuota.");
	else
		int x = p.head.info;
	p.head = p.head.next;
	return x;
}
