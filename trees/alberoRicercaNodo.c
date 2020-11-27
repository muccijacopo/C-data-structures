#include <stdio.h>
#include <stdlib.h>

/* scrivi qui la definizione del tipo nodo_albero che rappresenta una struttura con tre campi: un campo info di tipo intero, un campo sx (il puntatore al sottoalbero sinistro), un campo dx (un puntatore al sottoalbero destro).
ATTENZIONE: NON CAMBIARE L'ORDINE DEI CAMPI DI QUESTA STRUTTURA, ALTRIMENTI
NON SARA' POSSIBILE TESTARE CORRETTAMENTE IL TUO CODICE. */

typedef struct nodo_albero
{
    int info;
    struct nodo_albero *sx;
    struct nodo_albero *dx;
} nodo;

/* scrivi qui la definizione del tipo albero che rappresenta un puntatore alla struttura nodo_albero */

typedef struct albero
{
    nodo *n;
} albero;

/* scrivi qui eventuali funzioni di appoggio */
nodo *nuovoNodo(int v)
{
    nodo *nuovo = (nodo *)malloc(sizeof(nodo));
    nuovo->sx = NULL;
    nuovo->dx = NULL;
    nuovo->info = v;
    return nuovo;
}

int bst_inserisci(nodo *n, int v)
{
    int inserito = 0;
    if (v < n->info)
    {
        if (n->sx == NULL)
        {
            n->sx = nuovoNodo(v);
            inserito = 1;
        }
        else
        {
            inserito = bst_inserisci(n->sx, v);
        }
    }
    else
    {
        if (n->dx == NULL)
        {
            n->dx = nuovoNodo(v);
            inserito = 1;
        }
        else
        {
            inserito = bst_inserisci(n->dx, v);
        }
    }
    return inserito;
}

int inserisci(albero *T, int v)
{
    if (T->n == NULL)
    {
        T->n = nuovoNodo(v);
        return 1;
    }
    else
    {
        return bst_inserisci(T->n, v);
    }
}

int cerca_ric(nodo *T, int v)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        if (T->info == v)
        {
            return 1;
        }
        else
        {
            if (T->info > v)
            {
                cerca_ric(T->sx, v);
            }
            else
            {
                cerca_ric(T->dx, v);
            }
        }
    }
}

int cerca(nodo *T, int v)
{
    return cerca_ric(T, v);
}

/* INIZIO FUNZIONE */
int albero_ricerca_nodo(albero *T, int v)
{
    /* Si consideri un riferimento ad un albero binario di ricerca T e un intero v (si ricorda che rispetto ad ogni nodo, il figlio sinistro avrà un valore minore rispetto al padre, il figlio destro avrà un valore maggiore rispetto al padre): la funzione albero_ricerca_nodo deve restituire un booleano: 1 (true) se esiste in T un nodo contenente il valore v, 0 (false) altrimenti. Se l'albero T è vuoto allora la funzione deve restituire 0. Nel caso in cui non esista in T un nodo contenete il valore v (quindi anche quando T è vuoto) oltre a ritornare 0 bisogna modificare T inserendo un nuovo nodo contenente il valore v. Tale inserimento deve mantenere T un albero binario di ricerca. */
    nodo *n = T->n;
    int trovato = cerca(n, v);
    if (trovato == 0)
    {
        inserisci(T, v);
    }
    return trovato;
}
