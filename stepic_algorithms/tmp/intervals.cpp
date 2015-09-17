#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int s, t;
};

void sort(Interval arr[], int l, int r) {

}
void quickSort(Interval arr[], int l, int r) {

    int i = l, j = r - 1;
    int m = l, n = r - 1;
    int k;
    Interval pivot = arr[l];
    Interval tmp;

    for ( ; ; ) {
        while (arr[++i].s < pivot.s) ;
        while (arr[--j].s > pivot.s) {
            if (j == l) break;
        }

        if ( i >= j ) break;

        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;

        if (arr[i].s == pivot.s) {
            tmp = arr[m];
            arr[m] = arr[i];
            arr[i] = tmp;
            m++;
        }
            
        if (arr[j].s == pivot.s) {
            tmp = arr[n];
            arr[n] = arr[j];
            arr[j] = tmp;
            n--;
        }
    }

    tmp = arr[i];
    arr[i] = arr[r-1];
    arr[r-1] = tmp;

    j = i - 1;
    i = i + 1;
    
    for ( k = l; k < m; k++, j-- ) {
        tmp = arr[k];
        arr[k] = arr[j];
        arr[j] = tmp;
    }
    
    for (k = r - 1; k > n; k--, i++ ) {
        tmp = arr[k];
        arr[k] = arr[i];
        arr[i] = tmp;
    }

    quickSort(arr, l, j);
    quickSort(arr, i, r);
}

int main() {
    int n, m;
    cin >> n >> m;

    Interval ins[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> ins[i].s >> ins[i].t;
    }

    vector<int> p(m, 0);
    vector<int> c(m, 0);

    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }

    /*
    for (int i = 0; i < n; ++i) {
        cout << "Interval #" << i << "(" << ins[i].s << ", " << ins[i].t << ")" << endl;
    }
    */

    quickSort(ins, 0, n-1);

    /*
    for (int i = 0; i < n; ++i) {
        cout << "Interval #" << i << "(" << ins[i].s << ", " << ins[i].t << ")" << endl;
    }
    */

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (p[i] >= ins[j].s) {
                if (p[i] <= ins[j].t) c[i]++;
            }
            else break;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << c[i] << endl;
    }

    return 0;
}
