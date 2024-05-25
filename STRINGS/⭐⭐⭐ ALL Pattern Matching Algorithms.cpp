// strcmp (key,buffer) != 0 // return 1 if same else 0
  
// getline(cin, str); // input str with space


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




█▀█ ▄▀█ █▄▄ █ █▄░█ ▄▄ █▄▀ ▄▀█ █▀█ █▀█   ▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█▀▄ █▀█ █▄█ █ █░▀█ ░░ █░█ █▀█ █▀▄ █▀▀   █▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

Avg Case :
txt[n]
pat[m]
     TC = O ( m + n )
          
Worst Case :
txt[] = "AAAAAAAAAAAAAAAAAA";
pat[] = "AAAAA";

    TC = O(m*(n-m+1)) = O ( m*n )
         
It uses Rolling Hash to match Pattern.
Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match then only it starts matching individual characters.
     

     Rehashing is done using the following formula. 
s is start index
hash( txt[s+1 to s+m] ) = < d * { hash( txt[s to s+m-1] ) – txt[s]*h } + txt[s + m] > mod q 

d: Number of characters in the alphabet = 256
q: A prime number = 1e9 + 7
h: d^(m-1)
     
     

█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄
     
     

#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q; // h = d ^ ( m - 1 ) with modulo

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q; // recursion sae hash nikala p = 0 * d + txt 
                                    // p = txt * d + txt 1
                                    // p = d*(d*txt + txt1) + txt2
                
		t = (d * t + txt[i]) % q;
      
	}

	// Slide the pattern over text one by one
for (i = 0; i <= N - M; i++)
{

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
          
		if ( p == t )
		{
			bool flag = true;
			/* Check for characters one by one */
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j])
				{
				flag = false;
				break;
				}
				
					
			}

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
		
			if (j == M)
				cout<<"Pattern found at index "<< i<<endl;
		}

		// Calculate hash value for next window of text: Remove
		// leading digit, add trailing digit
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;

			// We might get negative value of t, converting it
			// to positive
			if (t < 0)
			t = (t + q);
		}
}
}

/* Driver code */
int main()
{
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";
	
	// A prime number 
	int q = 101;
	
	// Function Call
	search(pat, txt, q);
	return 0;
}




█▄▀ █▀▄▀█ █▀█   ▄▀█ █░░ █▀▀ █▀█ █▀█ █ ▀█▀ █░█ █▀▄▀█
█░█ █░▀░█ █▀▀   █▀█ █▄▄ █▄█ █▄█ █▀▄ █ ░█░ █▀█ █░▀░█

Need of Preprocessing?
An important question arises from the above explanation, 
how to know how many characters to be skipped. To know this, 
we pre-process pattern and prepare an integer array 
lps[] that tells us the count of characters to be skipped. 
	
 lps[i] = the longest proper prefix of pat[0..i] 
              which is also a suffix of pat[0..i]. 
	a b d x a b d , here lps = a b d
	
The time complexity of KMP algorithm is O(n) in the worst case.


█▀▀ █▀█ █▀▄ █▀▀
█▄▄ █▄█ █▄▀ ██▄


#include <bits/stdc++.h>
  
void computeLPSArray(char* pat, int M, int* lps);
  
// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
  
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
  
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
  
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
  
// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0; // length of the previous longest prefix suffix
  
    lps[0] = 0; // lps[0] is always 0
  
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
		// The LPS array up to the current len already provides information about the longest prefixes. 
		// When there is a mismatch, we look at lps[len - 1], 
		// which tells us the length of the next best candidate prefix that is also a suffix.
            if (len != 0) {
                len = lps[len - 1];
  
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
  
// Driver program to test above function
int main()
{
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}


