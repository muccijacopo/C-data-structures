/* Scrivi la funzione ricerca che dato un
albero binario t e un intero k, restituisca 1 se
k è contenuto in almeno un nodo di t e
restituisca 0 altrimenti */

typedef struct nodo_albero
{
	int info;
	struct nodo_albero *sx;
	struct nodo_albero *dx;
}, nodo;

typedef nodo *albero;

int ricerca(albero t, int k)
{
	if (t == NULL)
		return 0;

	if (t->info == k)
		return 1;

	int l = ricerca(t->left, k);
	int r = ricerca(t->right, k);

	return l || r;
}

/* Scrivi la funzione get_max che dato un
albero binario t restituisca il valore massimo
tra i valori contenuti nei nodi di t
– definisci anche le strutture di dati
– se l’albero è vuoto restituisci -1 */
int masismo(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int get_max(albero t)
{
	int max;

	if (t == NULL)
		return -1;

	max = t->info;

	if (t->left != NULL)
	{
		int l = get_max(t->left);
		max = massimo(max, l);
	}
	if (t->right != NULL)
	{
		int r = get_max(t->right);
		max = massimo(max, r);
	}
	return max;
}

/* 3. Scrivi la funzione uguali che dati due alberi
binari t1 e t2 restituisca 1 se i due alberi
sono uguali (stessi nodi con gli stessi valori
contenuti), 0 altrimenti */

int uguali(albero t1, albero t2)
{
	if (t1 == NULL && t2 == NULL)
		return 1;
	if (t1 == NULL || t2 == NULL)
		return 0;

	if (t1->info != t2->info)
		return 0;

	int l = uguali(t1->sx, t2->sx);
	int r = uguali(t1->dx, t2->dx);

	return l && r;
}

/* 4. Scrivi la funzione esiste_foglia che
dato un albero binario t e un intero k
restituisca 1 se esiste una foglia di t con
valore k, 0 altrimenti */
int esiste_foglia(albero t, int k)
{
	if (t == NULL)
		return 0;

	if (t->left != NULL)
		int l = esiste_foglia(t->left);
	if (t->right != NULL)
		;
	int r = esiste_foglia(t->right);

	if (t->info == k)
		return 1;

	return l || r;
}

/* 5. Scrivi la funzione altezza che dato un
albero binario t restituisca l’altezza
dell’albero
– se l’albero è vuoto restituisce -1 */
int massimo(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int altezza(albero t)
{
	if (t == NULL)
		return -1;

	return 1 + massimo(altezza(t->left), altezza(t->right));
}

/* 6. Scrivi la funzione
numero_nodi_livello che dato un
albero binario t e un intero h restituisca il
numero dei nodi dell’albero t alla
profondità h */
int conta_nodi(albero t, int k, int profondità)
{
	if (t == NULL)
		return -1;
	if (k == prondità)
		return 1;
	return conta_nodi(t->left, k, profondità + 1) + conta_nodi(t->right, k, profondità + 1);
}

int numero_nodi_livello(albero t, int k)
{
	return conta_nodi(t, k, 0);
}

/* 7. Scrivi la funzione lista_foglie che dato un
albero binario t restituisca una lista semplicemente
concatenata contenente i valori di tutte le foglie di t
• definisci anche le strutture dati e le funzioni di
manipolazione della lista
• se t è vuoto restituisci una lista vuota */

typedef struct nodo_albero
{
	int info;
	struct nodo_albero *left;
	struct nodo_albero *right;
} nodo;

typedef nodo *albero;

typedef struct elem
{
	int info;
	struct elem *next;
} elemento;

typedef elemento *lista;

void AGGIUNGI(lista *pl, int k)
{

	elem *np = (elem *)malloc(sizeof(elem));
	np->info = k;
	np->next = (*pl);
	(*pl) = np;
}

void ricorri(albero t, lista *pl)
{

	if (t == NULL)
		return;
	if ((t->sx == NULL) && (t->dx == NULL))
	{
		AGGIUNGI(pl, t->info);
		return;
	}
	ricorri(t->sx, pl);
	ricorri(t->dx, pl);
}

lista lista_foglie(albero t)
{

	lista l = NULL;
	ricorri(t, &l);
	return l;
}

/*8) Scrivi la funzione lista_nodi_livello che
dato un albero binario t e un intero h restituisca una
lista semplicemente concatenata contenente i valori
dei nodi dell’albero t alla profondità h
• se t non ha nodi alla profondità h restituisci una lista
vuota */

void AGGIUNGI(int k, lista *pl)
{
	elemento *np = (elemento *)malloc(sizeof(elemento));
	np->info = k;
	np->next = (*pl);
	(*pl) = np;
}

void lista_nodi_livello_ric(albero t, lista *pl, h, i)
{
	if (t == NULL)
		return;
	if (h == i)
	{
		AGGIUNGI(t->info, pl)
		return;
	}

	lista_nodi_livello_ric(t->left, pl, h, i + 1);
	lista_nodi_livello_ric(t->right, pl, h, i + 1);
}

lista lista_nodi_livello(albero t, h)
{
	lista l = NULL;
	lista_nodi_livello_ric(t, &l, h, 0);
	return l;
}

/* 9. Scrivi la funzione array_nodi_livello
che dato un albero binario t e un intero h
restituisca un array contenente i valori dei
nodi dell’albero t alla profondità h
• restituisce NULL se l’albero non ha nodi alla
profondità h */

carico_array(int *a, albero t, int h, int *pindice)
{
	if (t == NULL)
		return;
	if (h == 0)
	{
		a[indice] = t->info;
		(*pindice) = (*pindice) + 1;
		return;
	}

	carico_array(a, t->left, h, indice);
	carico_array(a, t->left, h, indice);
}

void conta_nodi_livello(albero t, int h, int p) //p = profondità
{
	if (t == NULL)
		return 0;

	if (h == p)
	{
		return 1;
	}

	return conta_nodi_livello(t->left, h, p + 1) + conta_nodi_livello(t->right, h, p + 1);
}

int *array_nodi_livello(albero t, int h)
{

	int dim;
	dim = conta_nodi_livello(t, h, 0);
	int *a;
	a = (int *)calloc(dim, sizeof(int));
	int indice = 0;
	carico_array(a, t, h, indice);
	return a;
}

/* 10. Scrivi la funzione livello_numeroso che dato
un albero binario t restituisca la profondità
dell’albero alla quale sono presenti più nodi
• restituisce -1 se l’albero è vuoto */
massimo(a, b)
{
	if (a > b)
		return a;
	return b;
}

calcolo_altezza(albero t)
{
	if (t == NULL)
		return -1;

	return 1 + massimo(calcolo_altezza(t->left), calcolo_altezza(t->right));
}

conta_nodi_livello(albero t, livello)
{
	if (t == NULL)
		return 0;
	if (livello == 0)
		return 1;

	return conta_nodi_livello(t->left, livello - 1) + conta_nodi_livello(t->right, livello - 1);
}

int livello_numeroso(albero t)
{
	if (t == NULL)
		return -1;
	int altezza = calcolo_altezza(t);

	int i = 0;
	int livellomax = 0;
	int max = 0;
	while (i < altezza)
	{
		nodi = calcolo_nodi_livello(t, i);
		if (nodi > max)
		{
			livellomax = i;
			max = nodi;
		}

		i++;
	}

	return livellomax;
}