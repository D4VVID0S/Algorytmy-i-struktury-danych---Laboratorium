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
    g->adj[b][a] = true;
  } else
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
        printf("%c%c", (char)('A' + row), '-');
        printf("%c%s", (char)('A' + col), ' ');
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

// ================= DFS =================

void dfs(Graph* g, int a)
{
  bool* visited = calloc(g->n, sizeof(bool));
  int k;
  for (k = 0; k < g->n; ++k)
      visited[k] = false;
  visited[a] = true; // rozpocznij od wierzcholka a
  displayVertex(a); // wyswietl wierzcholek
  push(a); // zapisz na stos
  while (StanStosu()==OK)
  {
    // pobierz nie odwiedzony wierzcholek,
    // przylegly do szczytowego elementu stosu
    int b = getUnVisitedVertex(g, NaSzczycie(), visited);
    if (b == -1){ // jezeli nie ma takiego wierzcholka,
      pop();
    }
    else
    {
      visited[b] = true;
      displayVertex(b);
      push(b);
    }
  } // while
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

    // teraz uruchom DFS - mozesz wybrac z ktorego wierzcholka
    printf("\nWierzcholek 1:\n");
    dfs(g,0);
    printf("\nWierzcholek 2:\n");
    dfs(g,1);
    printf("\nWierzcholek 3:\n");
    dfs(g,2);
    printf("\nWierzcholek 4:\n");
    dfs(g,3);
    printf("\nWierzcholek 5:\n");
    dfs(g,4);
    printf("\nWierzcholek 6:\n");
    dfs(g,5);

	return 0;
}