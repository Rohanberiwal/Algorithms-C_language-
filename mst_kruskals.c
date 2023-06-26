#include<stdio.h>
#include<stdlib.h>

struct Edge
{
   int src, dest, weight;
};

struct Graph
{
   int V, E;
   struct Edge* edge;
};

struct Subset
{
   int parent;
   int rank;
};

struct Graph* createGraph(int V, int E)
{
   struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
   graph->V = V;
   graph->E = E;
   graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
   return graph;
}

int find(struct Subset subsets[], int i)
{
   if (subsets[i].parent != i)
   {
      subsets[i].parent = find(subsets, subsets[i].parent);
   }
   return subsets[i].parent;
}

void unionSet(struct Subset subset[], int x, int y)
{
   int xroot = find(subset, x);
   int yroot = find(subset, y);
   if (subset[xroot].rank < subset[yroot].rank)
   {
      subset[xroot].parent = yroot;
   }
   else if (subset[xroot].rank > subset[yroot].rank)
   {
      subset[yroot].parent = xroot;
   }
   else
   {
      subset[yroot].parent = xroot;
      subset[xroot].rank++;
   }
}

int compare(const void* a, const void* b)
{
   struct Edge* edge1 = (struct Edge*)a;
   struct Edge* edge2 = (struct Edge*)b;
   return edge1->weight - edge2->weight;
}

void kruskalMST(struct Graph* graph)
{
   int V = graph->V;
   int E = graph->E;

   struct Edge result[V];
   int e = 0;
   int i = 0;
   int totalCost = 0;

   qsort(graph->edge, E, sizeof(graph->edge[0]), compare);

   struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

   // Create V number of subsets with single element
   for (int v = 0; v < V; v++)
   {
      subsets[v].parent = v;
      subsets[v].rank = 0;
   }

   // Pick the smallest edge and check if it forms a cycle or not
   // If it doesn't form a cycle, add it to the result and update the subsets
   while (e < V - 1 && i < E)
   {
      struct Edge next_edge = graph->edge[i++];
      int x = find(subsets, next_edge.src);
      int y = find(subsets, next_edge.dest);

      if (x != y)
      {
         result[e++] = next_edge;
         unionSet(subsets, x, y);
         totalCost += next_edge.weight;
      }
   }

   printf("Minimum Cost Spanning Tree:\n");
   for (int i = 0; i < e; i++)
   {
      printf("%d -- %d\tWeight: %d\n", result[i].src, result[i].dest, result[i].weight);
   }
   printf("Total Cost: %d\n", totalCost);
}

int main()
{
   int V = 4;
   int E = 5;
   struct Graph* graph = createGraph(V, E);

   // Add edge 0 to 1
   graph->edge[0].src = 0;
   graph->edge[0].dest = 1;
   graph->edge[0].weight = 8;

   // Add edge 0 to 2
   graph->edge[1].src = 0;
   graph->edge[1].dest = 2;
   graph->edge[1].weight = 5;

   // Add edge 0 to 3
   graph->edge[2].src = 0;
   graph->edge[2].dest = 3;
   graph->edge[2].weight = 4;

   // Add edge 1 to 3
   graph->edge[3].src = 1;
   graph->edge[3].dest = 3;
   graph->edge[3].weight = 12;

   // Add edge 2 to 3
   graph->edge[4].src = 2;
   graph->edge[4].dest = 3;
   graph->edge[4].weight = 3;

   kruskalMST(graph);

   return 0;
}