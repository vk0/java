#include <iostream>
#include <vector>

using namespace std;

const int INF = 100000;

struct Edge {
    int s, t, w;
};

bool bf(int source, int n, Edge e[], int m) {
    vector <int> d(n, INF);
    d[source] = 0;
    
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[e[j].s] > d[e[j].t] + e[j].w) {
				d[e[j].s] = d[e[j].t] + e[j].w;
			}
        }
    }
    
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (d[e[j].s] > d[e[j].t] + e[j].w) {
	    		return true;
		    }
        }
    }

    return false;
}

int main() {
    int n,m,w,s,t;
    cin >> n >> m;

    Edge e[m];

    for (int i = 0; i < m; ++i) {
        cin >> s >> t >> w;
        e[i].s = s - 1;
        e[i].t = t - 1;
        e[i].w = w;
    }

    bool result;
    result = bf(1, n, e, m);
    if (result) cout << "True";
    else cout << "False";
    return 0;
}
