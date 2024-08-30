//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isSafe(int row,int col,vector<vector<int>>&board,int n){

int duprow=row;
       int dupcol=col;
       while(row>=0 && col>=0){
           if(board[row][col]==1) return false;
           row--;
           col--;
       } 
       row=duprow;
       col=dupcol;
       while(col>=0){
           if(board[row][col]==1) return false;
           col--;
       }
       row=duprow;
       col=dupcol;
       while(row<n && col>=0){
           if(board[row][col]==1) return false;
           row++;
           col--;
       } 
       return true;
   }
void solve(int col , vector<vector<int>>&board ,vector<vector<int>>&ans,  vector<int>&left ,
  vector<int>&upperD,vector<int>&lowerD,int n){
      if(col == n) {
         
          vector<int>temp;
          for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++)  {
                if(board[i][j] == 1){
                  temp.push_back(j+1) ; 
                }
            }
          }
          ans.push_back(temp);
          return;}
          for(int row = 0 ; row<n ; row++){
              if(left[row] == 0 && lowerD[row + col] == 0 && upperD[n-1+col-row] == 0){
                  board[row][col] = 1;
                  left[row] = 1;
                 lowerD[row + col] = 1; 
                  upperD[n-1+col-row] = 1;
                  solve(col + 1,board,ans,left,upperD,lowerD,n); 
                  board[row][col] = 0;
                  left[row] = 0;
                 lowerD[row + col] = 0; 
                  upperD[n-1+col-row] =0;
              }
          }
          
  }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
       
       
        vector<int>left(n,0),upperD(2*n-1,0), lowerD(2*n-1,0);
        solve(0,board,ans,left,upperD,lowerD,n);
         sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends