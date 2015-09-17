#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int visited[100000];
int vertices, edges, cc;
list<int> orderedList;

void explore(vector<int> adjList[], int vertex);
void exploreT(vector<int> adjList[], int vertex);

int scc(vector<int> adjList[], vector<int> adjListT[]) {
    for (int i=0; i<=vertices; ++i) {
        visited[i] = false;
    }
    
    for (int u=1; u<=vertices; ++u) {
        if (!visited[u]) {
            exploreT(adjListT, u);
        }
    }
    
    for (int i=0; i<=vertices; ++i) {
        visited[i] = false;
    }

    cc = 0;    
    list<int>::iterator it;
    
    for (it = orderedList.begin(); it != orderedList.end(); it++) {
        if (!visited[*it]) {
            explore(adjList, *it);
            cc++;
        }
    }
        
    return cc;
}

void exploreT(vector<int> adjList[], int vertex) {
    visited[vertex] = true;

    for (int v=0; v<adjList[vertex].size(); ++v) {
        if (!visited[adjList[vertex][v]]) {
            exploreT(adjList, adjList[vertex][v]);
        }
    }

    orderedList.push_front(vertex);
}

void explore(vector<int> adjList[], int vertex) {
    visited[vertex] = true;
    
    for (int v=0; v<adjList[vertex].size(); ++v) {
        if (!visited[adjList[vertex][v]]) {
            explore(adjList, adjList[vertex][v]);
        }
    }
}

int main()
{
    int n, m, u, v;
    cin >> vertices >> edges;
    
    vector<int> adjList[vertices+1];
    vector<int> adjListT[vertices+1];
    
    for (int i=0; i<edges; ++i) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjListT[v].push_back(u);
    }
    
    for (int i=0; i<vertices; ++i) {
        sort (adjList[i].begin(), adjList[i].end());
        sort (adjListT[i].begin(), adjListT[i].end());
    }
    
    int result;
    result = scc(adjList, adjListT);
    cout << result;
    return 0;
}
