// Что будет напечатано в результате работы программы?

#include <iostream>
#include <vector>
using namespace std;

int main () {

  vector<int> v;
  vector<int>::iterator vp;

  for (int i = 0; i < 5; i++)
    v.push_back(i);
  vp = v.begin();
  vp = v.insert(vp, 6)++;
  v.erase(vp);
  for (int i = 0; i < v.size(); i++)
    cout<<v[i];
  return 0;
}

//01234