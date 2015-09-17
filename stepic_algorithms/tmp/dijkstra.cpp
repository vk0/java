#include <queue>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int INF = 10000;

struct Edge {
    int t, w;
};

struct compare {
    bool operator()(const Edge& l, const Edge& r) {
        return l.w > r.w;
    }
};

void dijkstra(int n, int source) {
    vector <int> d(n, INF);
    d[source] = 0;

    /*
    while (!pq.empty()) {
        // Extract min
        u = pq.front();
        pq.pop();
    }
    */

}

int main() {
    /*
    4 4
    1 2 1
    4 1 2
    2 3 2
    1 3 5
    1 3
    */
    int n, m;
    int s, t, w;
    cin >> n >> m;
    vector< vector<int> > e[n];

    for (int i=0; i<m; ++i) {
        
        e[s-1].push_back(t);
    }
    
    vector<int>::iterator it;

    for (int i=0; i<m; ++i) {
        cout << "Vertex" << i+1 << endl;
        for (it = e[i].begin(); it != e[i].end(); it++) {
            cout << *it << " ";
        }
    }


    
    

    return 0;
}

