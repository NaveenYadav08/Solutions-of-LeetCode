https://www.geeksforgeeks.org/birthday-paradox/

How many people must be there in a room to make the probability 50% that at-least two people in the room have same birthday? 
  
  
  
  
  
Let the probability that two people in a room with n have same birthday be P(same). 
P(Same) can be easily evaluated in terms of P(different) where P(different) is the probability that all of them have different birthday.
P(same) = 1 – P(different)
P(different) can be written as 1 x (364/365) x (363/365) x (362/365) x …. x (1 – (n-1)/365)
 

  
  
#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
  
    // Assuming non-leap year
    
    float num = 365;
  
    float denom = 365;
    float pr;
    int n = 0;
    cout << "Probability to find P(same) : " << endl;
    cin >> pr;
  
    if(pr==1)
    {cout<<366<<endl; return 0;}
    if(pr==0)
    {
        cout<<1<<endl; return 0;
    }
  
    float p = 1;
    while (p > 1-pr){
        p *= (num/denom);
        num--;
        n++;
    }
  
//     cout <<  " Total no. of people out of which there is " << p
//     << "probability that two of them have same birthdays is  "  << n << endl;
  
cout<<"There are atleast "<<n<<" "<<"people so that "<<pr<<" chance that atleast two have same bday"<<endl;
  
    return 0;
}
