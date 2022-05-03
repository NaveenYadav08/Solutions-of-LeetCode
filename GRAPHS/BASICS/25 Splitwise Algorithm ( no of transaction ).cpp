#include <bits/stdc++.h>
using namespace std;

// Money Splitwise Algorithm

int main() {
    int no_of_transactions,friends;
    cin>>no_of_transactions>>friends;

    int  x,y,amount;

    // Make a one d array to store the net amount that each person will have to take at the end
    int net[10000] = {0};

    while (no_of_transactions--)
    {
        cin>>x>>y>>amount;
        net[x] -= amount;
        net[y] += amount;
    }  
    
    multiset<int> m;   
    // init a list and sort it  multiset
  
   for( int i=0; i<friends; i++)
   {
       if(net[i]!=0)
       {
           m.insert(net[i]); 
       }
   }
   // pop out two person left and right and try to settle them
   int cnt =0;
   while( !m.empty())
   {
       auto low =m.begin();
       auto high =prev(m.end());

       int debit = *low;
       int credit = *high;

       //Erase
       m.erase(low);
       m.erase(high);

       // settlement 
       int settlement_amount = min(-debit,credit);
       cnt++;
       // settlement from donor to acceptor
       debit += settlement_amount; 
       credit -= settlement_amount; // one will be 0

       if(debit!=0)
       m.insert(debit);

       if(credit!=0)
       m.insert(credit);

   }
   cout<<cnt<<endl;



}
