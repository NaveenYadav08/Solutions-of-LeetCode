#include <bits/stdc++.h>
using namespace std;

int R;
int C;

void printMat(char input[][50])
{
    for(int i=0; i<R;i++)
    {
        for(int j=0; j<C; j++)
        {
            cout<<input[i][j];
        }
        cout<<endl;
    }
}

// W N E S
int dx[]= {-1,0,1,0};
int dy[]= {0,-1,0,1};

// color is the character to be added
// ch is char to be replaced
// color is char to be added
void floodFill( char mat[][50], int i, int j, char ch, char color)
{
 // base case
 if(i<0 or j<0 or i>=R or j>=C)
 return;

 //fig boundry cndn
 if(mat[i][j]!=ch)
 {
     return ;

 }

 // recursive call
 mat[i][j]=color;
 for( int k=0; k<4; k++) 
 {
  floodFill(mat,i+dx[k],j+dy[k],ch,color);   
 }



}

int main() {
    cin>>R>>C;
    char input[15][50];

    for( int i=0;i<R; i++)
    {
        for( int j=0; j<C; j++)
        {
            cin>>input[i][j];
        }
    }
    printMat(input);
    floodFill(input,8,13,'.','r');
    printMat(input);


    
}
