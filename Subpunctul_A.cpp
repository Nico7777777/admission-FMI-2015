#include <fstream>
#include <vector>
#include <algorithm>
#include<stdlib.h>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out_A.txt");
int a, b, c, n, x;
long double timp;
vector <int> s;
int main()
{

    timp = clock();
    fin >> a >> b >> c >> n;
    for(int i=0;i<n;i++) {fin>>x; s.push_back(x);}
    sort(s.begin(), s.end());

    for(int i=0, j=n-1; i<j;){
        long long formula = a*s[i]*s[i] + b*s[j]*s[j];
        if( formula == c ){
            fout<<"("<< s[i] <<','<< s[j]<<")\n";
            fout<<"("<< s[j] <<','<< s[i]<<")\n";
            i++; j--;
        }
        else if( formula < c ) i++;
        else j--;
    }
    timp = ( clock() - timp )/CLOCKS_PER_SEC;
    fout<<"Rezolvarea are complexitate O(n) si a durat "<<timp<<" sec.";
    fin.close(); fout.close();
}