// PATTERN SEARCHING ALGORITHMS ARE USED TO Find all occurrences of pat[] in txt[].

█▄░█ ▄▀█ █ █░█ █▀▀   ▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█░▀█ █▀█ █ ▀▄▀ ██▄   █▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

Best Case :
txt[n] = "AABCCAADDEE";
pat[m] = "FAA";
     first char of pattern is missing from txt
     TC = O ( n )
Worst Case :
txt[] = "AAAAAAAAAAAAAAAAAA";
pat[] = "AAAAA";

    TC = O(m*(n-m+1))
      
      

█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄

// C++ program for Naive Pattern
// Searching algorithm
#include <bits/stdc++.h>
using namespace std;
 
void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
 
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            cout << "Pattern found at index "
                 << i << endl;
    }
}
 
// Driver Code
int main()
{
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    search(pat, txt);
    return 0;
}
