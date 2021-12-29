#include <bits/stdc++.h>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printArr(int dist[], int n)
{
    cout << "\nDISTENCES FORM SOURCE EDGE ";
    cout << "\n=============================";
    printf("\nVERTEX  D(FROM SOURCE)\n");
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << dist[i] << endl;
    cout << "\n=============================";
}

void InputData(Graph *graph, int e)
{
    int s, d, w;
    for (int i = 0; i < e; i++)
    {
        cout << "\nENTER | SOURCE | DESTINATION | WEIGHT | OF " << i + 1 << " EDGE : ";
        cin >> s >> d >> w;
        graph->edge[i].src = s;
        graph->edge[i].dest = d;
        graph->edge[i].weight = w;
    }
}

void BellmanFord(Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "GRAPH CONTAIN NEGATIVE EDGE CYCLE " << endl;
            return;
        }
    }
    printArr(dist, V);
    return;
}

int main()
{
    int V, E, S;
    cout << "ENTER NO OF VERTICES : ";
    cin >> V;
    cout << "ENTER NO OF EDGES : ";
    cin >> E;
    Graph *graph = createGraph(V, E);
    InputData(graph, E);

    cout << "\nENTER SOURCE EDGE : ";
    cin >> S;

    auto start = high_resolution_clock::now();
    BellmanFord(graph, S - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nEXECUTION OF DP ALGORITHM : " << duration.count() << " MILISECONDS" << endl;

return 0;
}

// 5 8
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 3 1 1
// 4 3 -3
// 1
