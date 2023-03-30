#include <bits/stdc++.h>
using namespace std;
const int N =1e3+2;
int dp[N][N];
int coin(vector<int> &a,int n,int x){
    if(x==0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(dp[n][x]!=-1){
        return dp[n][x];
    }
    //return coin(a,n,x-a[n-1]) + coin(a,n-1,x);
    dp[n][x] = coin(a,n,x-a[n-1]) + coin(a,n-1,x);
    return dp[n][x];
}
int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        dp[i][j]=-1;
    }
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    cout<<coin(a,n,x);

    return 0;
}

// iterative -
// int main(){
//     int n;cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int x;
//     cin>>x;

//     vector<vector<int>> dp(n+1,vector<int> (x+1,0));
//     dp[0][0]=1;
//     for(int i=1;i<n+1;i++){
//         for(int j=0;j<x+1;j++){
//             if(j-a[i-1]>=0){
//                 dp[i][j] +=dp[i][j-a[i-1]];
//             }
//             dp[i][j]+=dp[i-1][j];
//         }
//     }
//     cout<<dp[n][x];
// }


//space optimization
// int main(){
//     int n;cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int x;
//     cin>>x;
//     sort(a.begin(),a.end());
//     vector<int> dp(x+1,0);
//     dp[0]=1;
//     for(int i=n-1;i>=0;i--){
//         for(int j=0;j<x+1;j++){
//             if(j-a[i]>=0){
//                 dp[j] +=dp[j-a[i]];
//             }
//         }
//     }
//     cout<<dp[x];
// }


