#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<string> txt;
int count_occurance(vector<string> & txt, string pattern)
{
	int res=0;
	for(int i=0;i<txt.size();i++)
	{
	
		int N=txt[i].length();
		int M=pattern.length();
		
		for (int ii = 0; ii <= N - M; ii++) 
    {  
        
        int j; 
        for (j = 0; j < M; j++) 
            if (txt[i][ii+j] != pattern[j]) 
                break; 
   
        
        if (j == M)   
        { 
           res++; 
           j = 0; 
        } 
    } 
	}
    return res;
}

int main() {
    int n = 2;

    string s;
    getline(cin, s);
    sscanf(s.c_str(), "%d", &n);
    txt.resize(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, txt[i]);
    }
    for(int i=0;i<txt.size();i++)
	{
		replace( txt[i].begin(), txt[i].end(), '0', 'o');
		replace( txt[i].begin(), txt[i].end(), '1', 'l');
		replace( txt[i].begin(), txt[i].end(), '2', 'z');
		replace( txt[i].begin(), txt[i].end(), '5', 's');
	}
    int m;
    getline(cin, s);
    sscanf(s.c_str(), "%d", &m);
    for (int i = 0; i < m; ++i) {
        string pattern;
        getline(cin, pattern);
        cout<<count_occurance(txt, pattern)<<"\n" ;
    }


    return 0;
}
