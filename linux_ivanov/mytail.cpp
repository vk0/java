#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main (int argc, char ** argv)
{
long int nback;
if (argc < 3) {
    cerr << "Too few arguments" << endl;
    return 1;
}

char ch;

ifstream infile (argv[1], ios::in | ios::binary);

if (!infile) {
    cerr << "Cannot open input file "
    << argv[1] << endl;
    return 1;
}
infile.seekg (0, ios::end);
nback = abs (atoi (argv[2]));
if (nback > infile.tellg ())
    infile.seekg (0, ios::beg);
else
    infile.seekg (-nback, ios::end);
while (infile.get (ch)) cout << ch;
    infile.close ();
    return 0;
}