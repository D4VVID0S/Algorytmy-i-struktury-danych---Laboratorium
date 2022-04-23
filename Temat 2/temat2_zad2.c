// Both stdio.h & stdlib.h required to get NULL to work
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ================= stos =================

#define DLUGOSC_MAX 200
int const STOS_PELNY = 3;
int const STOS_PUSTY = 2;
int const OK = 1;
int szczyt = 0;
int Stos[DLUGOSC_MAX + 1];
int push (int x);
int pop();
int StanStosu();
int NaSzczycie();

void clear()
{
  szczyt = 0;
}

int StanStosu() 
{
	switch(szczyt) 
  {
	  case 0: return (STOS_PUSTY);
		case DLUGOSC_MAX+1: return (STOS_PELNY);
		default: return (OK);
	}
}

int NaSzczycie()
{
	return Stos[szczyt-1];
}

int push(int x)
{
	if(szczyt<=DLUGOSC_MAX)
  {
		Stos[szczyt++]=x;
		return (OK);
	}
  else
		return (STOS_PELNY);
}

int pop()
{
	if(szczyt>0)
  {
		--szczyt;
		return (OK);
	}
  else
		return (STOS_PUSTY);
}

// ================= graf =================
typedef struct
{
   int n; // liczba wierzcholkow grafu
   bool** adj; // macierz sasiedztwa
} Graph;

// inicjalizacja struktury Graph
void init(Graph*, int);
// dodanie krawedzi
void addEdge(Graph*, int, int);
void display(Graph const*); // wyswietlenie grafu
void dfs(Graph*, int); // wyszukiwanie "wglab"
void bfs(Graph*, int); // wyszukiwanie "wszerz"
int getUnVisitedVertex(Graph*,int, bool const visited []);
void displayVertex(int);

void init(Graph* g, int n)
{
  int k,a,b;
  g->n = n;
  g->adj = calloc(n, sizeof(bool*));
  for (k = 0; k < n; ++k)
  {
    g->adj[k] = calloc(n, sizeof(bool));
  }
  for(b = 0; b < n; ++b)
  {
    for(a = 0; a < n; ++a)
    {
      g->adj[a][b] = false;
    }
  }// zerowanie macierzy
}

void addEdge(Graph* g, int a, int b)
{
  if (a >= 0 && a < g->n && b >= 0 && b < g->n)
  {
    g->adj[a][b] = true;
  }
  else
  {
    printf("Niepoprawne dane\n\n");
    exit(EXIT_FAILURE);
  }
}

void displayVertex(int a)
{
  printf("%c ", 'A' + a);
}
void display(Graph const* g)
{
  int row,col;
  printf("\nKrawedzie grafu:\n");
  for (row = 0; row < g->n; ++row)
    for (col = 0; col < g->n; ++col)
      if (g->adj[row][col])
      {
        printf("%c%c%c", (char)('A' + row), '-', '>');
        printf("%c%c", (char)('A' + col), ' ');
      }
  printf("\n");
}

// zwraca nie odwiedzony wierzcholek przylegly do a
// zwraca -1, jezeli takiego wierzcholka nie ma
int getUnVisitedVertex(Graph* g, int a, bool const visited [])
{
  int b;
  for (b = 0; b < g->n; ++b)
  {
    if (g->adj[a][b] && !visited[b])
    {
      return b;
    }
  }
  return -1;
}

// ================= implementacja dynamiczna / kolejka =================

// ifndef - if not defined
#ifndef ITEM_H
#define ITEM_H
typedef struct ITEM
{
    int data;
    struct ITEM *next;
} Item;
#endif

#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
typedef struct
{
    Item* first;
    Item* last;
} Queue;
#endif

void initQueue(Queue *q)
{ // inicjalizacja kolejki
    q -> first = q -> last = NULL;
}

bool queueEmpty(Queue q)
{ // Zwraca True jeżeli kolejka jest pusta
    return (q.first == NULL);
}

int front(Queue const *q)
{ // Pobiera wartosc pierwszego elementu
    return q -> first -> data;
}

void inject(Queue *q, int w)
{ // Dodaje elementy do kolejki
    Item* p = malloc(sizeof(Item));
    p -> data = w;
    p -> next = NULL;
    if (q -> first == NULL)
    {
        q -> first = q -> last = p;
    }
    else
    {
        q -> last -> next = p;
        q -> last = p;
    }
}

void eject(Queue *q)
{ // Ususwa element z kolejki
    // Jeden element lub kolejka jest pusta
    if (q -> first == q -> last)
    {
        free(q -> first);
        q -> first = q -> last = NULL;
    }
    else
    {
        Item *p = q -> first;
        q -> first = p -> next;
        free(p);
    }
}

void clearQueue(Queue *q)
{ // Usuwa z kolejki wszystkie elementy
    while (q -> first != NULL)
        eject(q);
}

// ================= BFS =================
void bfs(Graph* g, int a)
{
    bool *visited = calloc(g -> n, sizeof(bool));
    for (unsigned k = 0; k < g -> n; ++k)
        visited[k] = false;
    Queue q; initQueue(&q);
    visited[a] = true;
    displayVertex(a);
    inject(&q, a); // wstaw na koncu
    while (!queueEmpty(q))
    {
        int b = front(&q); // pobierz pierwszy wierzcholek
        eject(&q); // usun go z kolejki
        int c; // dopoki nie ma odpowiednich sasiadow
        while ((c =getUnVisitedVertex(g, b, visited)) != -1)
        {
            visited[c] = true;
            displayVertex(c);
            inject(&q, c);
        }
    } // while (kolejka nie jest pusta)
    free(visited);    
}

// ================= program =================

int main()
{   
    int a, i;
    Graph *g;
    g = malloc(sizeof(Graph));
    // pamietaj zeby zmienic 5 na wlasciwa liczbe wierzcholkow
	init(g, 6); 
    // ponizej dodaj krawedzie
    addEdge(g, 0, 1); //(1, 2)
    addEdge(g, 0, 2); //(1, 3)
    addEdge(g, 1, 3); //(2, 4)
    addEdge(g, 1, 4); //(2, 5)
    addEdge(g, 2, 3); //(3, 4)
    addEdge(g, 2, 5); //(3, 6)
    addEdge(g, 3, 0); //(4, 1)
    addEdge(g, 4, 3); //(5, 4)
    addEdge(g, 2, 5); //(3, 6)

    display(g);
    bfs(g, 0);

	return 0;
}