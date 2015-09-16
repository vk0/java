// 2014. Test exercise for three sum
// .cpp file 

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int twoPointers(std::vector<int> &vec, int sum, int *i, int *j)
{
    unsigned l = 0;
    unsigned r = (unsigned)vec.size() - 1;
    
    while (l < r)
    {
        if (vec.at(l) + vec.at(r) == sum)
        {
            *i = l;
            *j = r;
            return 0;
        }
        else if (vec.at(l) + vec.at(r) > sum)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    
    return -1;
}

int threeSum(std::vector<int> &vec, int *i, int *j, int *k)
{
    for (int c = 0; c < vec.size(); c++)
    {
        int element = vec.at(c);
        if (twoPointers(vec, (-element), j, k) != -1)
        {
            *i = c;
            return 0;
        }
    }
    
    return -1;
}

int main()
{
    std::vector<int> firstArray;
    std::string str;
    std::getline(std::cin, str);
    std::istringstream sstr(str);
    int n;
    while(sstr >> n)
    {
        firstArray.push_back(n);
    }
    
    int i = 0, j = 0, k = 0;
    if (threeSum(firstArray, &i, &j, &k) != -1)
    {
        // each value needs to be incremented due to task definition
        cout << "i: " << ++i << endl << "j: " << ++j << endl << "k: " << ++k << endl;
    }
    else
    {
        cout << "there are no numbers which give 0 in sum " << endl;
    }
}
