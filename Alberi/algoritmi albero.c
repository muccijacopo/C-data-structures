int massimo_albero(nodo_albero *a)
{
	if (a == NULL)
		return -1;

	int l = massimo_albero(a->left);
	int r = massimo_albero(a->right);
	return massimo(a->info, massimo(l, r));
}

int massimo(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int massimo_albero2(nodo_albero *a)
{
	if (a == NULL)
		return -1;

	int max = a->info;

	if (a->left != NULL)
	{
		int l = massimo_albero2(a->left);
		max = massimo(max, l);
	}

	if (a->right != NULL)
	{
		int r = massimo_albero2(a->right),
			max = massimo(max, r);
	}

	return max;
}

int profondità_nodo(nodo_albero *a, int k)
{
	if (a == NULL)
		return -1;
	if (a->info == k)
		return 0;

	int l = profondità_nodo(a->left, k);
	int r = profondità_nodo(a->right, k);

	int max = massimo(l, r);

	if (max == -1) // non trovato
	{
		return -1;
	}
	else
		return max + 1;
}

int TWO_CHILDREN(nodo_albero *n)
{
	if (n == NULL)
		return false;

	if (n->left != NULL && n->right != NULL)
		return true;

	return false;
}

ADD_ROOT(nodo_albero *t, int z)
{
	nodo_albero *a;
	a->info = z;
	a->left = NULL;
	a->right = NULL;
}

int ONLY_LEFT(nodo_albero *t)
{
	if (t == NULL)
		return true;
	if (t->right != NULL)
		return false;

	int l = ONLY_LEFT(t->left);
	return l;
}

int CERCA(nodo_albero *t, int n)
{
	if (t == NULL)
		return false;
	if (t->info == n)
		return true;
	int l = CERCA(t->left, n);
	int r = CERCA(t->right, n);

	return l || r;
}

int CONTA_NODI(nodo_albero *t)
{
	if (a == NULL)
		return 0;

	int l = CONTA_NODI(t->left);
	int r = CONTA_NODI(t->right);

	return l + r + 1;
}

int CAMMINO(nodo_albero *t)
{
	if (a == NULL)
		return true;

	if (a->left != NULL && a->right != NULL)
		return false;

	int l = CAMMINO(t->left);
	int r = CAMMINO(t->right);

	return l && r;
}

massimo(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int HEIGHT(nodo_albero *t)
{
	if (a == NULL)
		return -1;

	int l = HEIGHT(t->left);
	int r = HEIGHT(t->right);

	return 1 + massimo(l, r);
}

int AVERAGE(nodo_albero *t)
{
	if (t != NULL)
		return somma_nodi(t) / conta_nodi(t);
}

int conta_nodi(nodo_albero *t)
{
	if (t == NULL)
		return 0;

	int l = conta_nodi(t->left);
	int r = conta_nodi(t->right);

	return l + r + 1;
}

int somma_nodi(nodo_albero *t)
{
	if (t == NULL)
		return 0;

	int l = somma_nodi(t->left);
	int r = somma_nodi(t->right);

	return t->info + l + r;
}
/* Scrivi lo pseudocodice della procedura
COMPLETO(t) che verifichi se un albero
binario t è completo */
int COMPLETO(nodo_albero *t)
{
	if (t == NULL)
		return true;

	if (t->left == NULL && t->right == NULL)
		return true; // sono una foglia
	if (t->left == NULL || t->right == NULL)
		return false;
	if (t->left != NULL && t->right != NULL)
		return true;

	int l = COMPLETO(t->left);
	int r = COMPLET(t->right);

	return l && r;
}

/* 8. Scrivi lo pseudocodice della procedura
DEALLOCA(t) che rimuova (deallocandoli) tutti i
nodi di un albero t */
DEALOCA(albero *t)
{
	if (t->root == NULL)
		return;

	else
		DEALLOCA_RIC(t->root);
}

DEALLOCA_RIC(nodo_albero *n)
{
	if (n == NULL)
		return;
	DEALLOCA_RIC(n->left);
	DEALLOCA_RIC(n->right);

	free(n);
}

/* 9. Scrivi lo pseudocodice della procedura POTA(t,x)
che elimini da un albero binario il sottoalbero
radicato ad un nodo x specificato tramite riferimento */

void POTA_x(albero *t, nodo_albero *x)
{
	if (x = t.root)
		t.root = NULL;
	DEALLOCA(x);

	p = x.parent;
	if (x == p->left)
		p > -left == NULL
						 DEALLOCA_RIC(x);

	else
		p->right == NULL;
	DEALLOCA_RIC(x);
}

/* 10. Scrivi lo pseudocodice della procedura POTA(t,h)
che poti un albero binario lasciando solamente i nodi
a profondità minore di h */
void POTA(albero *t, int h)
{
	if (h == 0)
		t.root = NULL;
	return;
	else POTA_RIC(t->root, 0, h);
}

POTA_RIC(nodo_albero *n, int profondità, int h)
{
	if (n == NULL)
		return;

	if (profondità == h)
		POTA_x(t, n);
	return;

	POTA_RIC(t->left, profondità + 1, h);
	POTA_RIC(t->right, profondità + 1, h);
}

/* 13. Scrivi lo pseudocodice della procedura
VALORE-NONNO(t) che calcoli il numero di nodi
dell’albero binario t che hanno lo stesso valore del
genitore del genitore (cioè del nonno) */
int VALORE_NONNO(nodo_albero *n)
{
	if (n == NULL)
		return 0;

	int l = VALORE_NONNO(n->left);
	int r = VALORE_NONNO(n->right);

	if (n->parent != NULL)
		if (n->parent->parent != NULL)
			if (n->parent->parent->info == n->info)
				return 1;

	return l + r;
}

/* 14. Scrivi lo pseudocodice della procedura DUEFIGLI(
t) che calcoli il numero di nodi nell’albero
binario t che hanno esattamente due figli */
int DUE_FIGLI(nodo_albero n)
{
	if (n == NULL)
		return 0;

	int l = DUE_FIGLI(n->left);
	int r = DUE_FIGLI(n->right);

	int verifica = n->left != NULL & n->right != NULL

													 if (verifica) return l +
													 r + 1;
	return l + r;
}

/* 15. Scrivi lo pseudocodice della procedura QUATTRONIPOTI(
t) che calcoli il numero di nodi dell’albero
binario t che hanno quattro nipotini */
int QUATTRO_NIPOTI(nodo_albero *n)
{
	if (n == NULL)
		return 0;

	int l = QUATTRO_NIPOTI(n->left);
	int r = QUATTRO_NIPOTI(n->right);

	if (VERIFICA_QUATTROO_NIPOTI(n))
		return l + r + 1;
	else
		return l + r;
}

VERIFICA_QUATTRO_NIPOTI(nodo_albero *n)
{
	if (n->left == NULL)
		|| (n->right == NULL) return false;
	if (n->left->left != NULL && n->left->right != NULL)
		if (n->right->left != NULL && n->right->right != NULL)
			return true;

	return false;
}

/* 16. Scrivi la procedura CAMMINO(t,n) che ritorni una
lista con gli identificatori dei nodi del cammino dalla
radice fino al nodo n
– puoi supporre che n appartenga all’albero */
/* NON SICURO SE È GIUSTO */
lista *CAMMINO(albero *t, nodo_albero *n)
{
	lista *l = NULL;
	if (t->root != NULL)
		CAMMINO_RIC(t->root, n, l);
	return l;
}

lista *CAMMINO_RIC(nodo_albero *t, nodo_albero *n, lista *l)
{
	if (n == t)
		return;

	AGGIUNGI(n->info, l);
	CAMMINO_RIC(t, n->parent, l);
}

void AGGIUNGI(int id, lista *l)
{
	if (l == NULL)
		l->info = id,
		l->next = NULL;
	return;
	else lista *nodo;
	nodo->info = id;
	nodo->next = l;
	l = nodo;
}
