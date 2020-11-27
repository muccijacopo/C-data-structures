/* ESERCIZI SUGLI ALBERI */

NEW_TREE()
{
	t.root = NULL;
	return t;
}

IS_EMPTY(t)
{
	return t.root == NULL;
}

ROOT(t)
{
	return t.root;
}

LEFT(t, n)
{
	return n.left;
}

RIGHT(t, n)
{
	return n.right;
}

INFO(t, n)
{
	return n.info;
}

TWO_CHILDREN(n) {
		return (n.right != NULL) && (n.left != NULL
}

ADD_ROOT(t, k)
{
	// Creo nuovo nodo
	x.info = k;
	x.parent = NULL;
	x.right = NULL;
	x.left = NULL;
	t.root = x;
}

ADD_LEFT(t, n, z)
{
	// Creazione nuovo nodo
	x.info = z;
	x.parent = n;
	x.right = NULL;
	x.left = NULL;

	n.left = x;
}

/* Controlla se ci sono solo figli sinistri (o non ci sono) */
ONLY_LEFT(t)
{
	x = t.root;
	while (x != NULL)
	{

		if (x.right != NULL)
			return false;
		else
			x = x.left;
	}

	return true;
}

/* ALBERI DI GRADO ARBITRARIO */

/* t e' un albero di grado arbitrario */
ADD_SIBLING(t, n, z)
{
	x.info = z;
	x.parent = n;
	x.left = NULL;
	x.right = n.left;

	n.left = x;
}

/* Cerca in pre-ordine */
CERCA_PRE(t, n)
{
	if (t.root == NULL)
		return false;
	else
		CERCA_RIC(t.root, n);
}
CERCA_PRE_RIC(t, n)
{

	if (t.info == n)
		return true;

	bool l = false;
	bool r = false;

	if (t.left != NULL)
		l = CERCA(t.left, n);
	if (t.right != NULL)
		r = CERCA(t.right, n);

	return l || r;
}
/*------------------- */

/* Ricerca in post-ordine */

CERCA_POST(t, n)
{
	return CERCA_RIC(t.root, n);
}

CERCA_POST_RIC(t, n)
{
	if (t == NULL)
		return false;

	l = CERCA_RIC(t.left, n)
			r = CERCA_RIC(t.right, n);

	return (t.info == u) || l || r;
}

/* Ricerca in ordine simmetrico */
CERCA_SIMM(t, n)
{
	return CERCA_SIMM_RIC(t.root, n);
}

CERCA_SIMM_RIC(n, c)
{
	if (n == NULL)
		return false;
	l = CERCA_SIMM_RIC(n.left, c);
	if (n.info == c)
		return true;

	return CERCA_SIMM_RIC(n.right, c);
}

/* Conta nodi in post-ordine */
CONTA_NODI(t)
{
	return CONTA_NODI_RIC(t.root)

			CONTA_NODI_RIC(n, c)
	{

		if (n == NULL)
			return false;

		l = CONTA_NODI_RIC(n.left, c);
		r = CONTA_NODI_RIC(n.right, c);

		return l + r + 1;
	}

	CAMMINO(t)
	{
		return CAMMINO_RIC(t.root);
	}

	CAMMINO_RIC(n)
	{
		if (n == NULL)
			return true;
		l = CAMMINO_RIC(n.left);
		r = CAMMINO_RIC(n.right);
		if (n.left != NULL)
			&&(n.right != NULL) return false;
		return l && r;
	}