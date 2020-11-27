/* 7. Scrivi lo pseudocodice della procedura
ADD_SIBLING(t,n,z) che aggiunge al nodo
n un figlio che contiene il valore z */
ADD_SIBLING(nodo_albero *t, nodo_albero *n, int z)
{
	nodo_albero *nodo = (nodo_albero *)malloc(sizeof(nodo_albero));
	nodo->info = z;
	nodo->parent = n;
	nodo->left = NULL;
	nodo->right = n->left;
	n->left = nodo;
}

/* 18. Scrivi lo pseudocodice della procedura
CONTA-NODI(t) che ritorni il numero dei
nodi di un albero t realizzato tramite una
struttura di dati “figlio-sinistro-fratellodestro” */
int CONTA_NODI(t)
{
	if (t == NULL)
		return 0;

	int l = CONTA_NODI(t->left);

	if (t->left != NULL)
		return CONTA_NODI_FIGLI(t) + l;
	else
		return l;
}

int CONTA_NODI_FIGLI(nodo_albero *t)
{
	nodo_albero *nodo = t->left;
	int cont = 0;
	while (nodo != NULL)
	{
		cont++;
		nodo = nodo->right;
	}

	return cont;
}