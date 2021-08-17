#include <bits/stdc++.h>

using namespace std;
#define int     long long
static int mod = 1000000007;

int numEnclaves(vector<vector<int>>& grid) {
    int i, n, k, cnt = 0;
    if(grid.size() < 2 || grid[0].size() < 2){
        return 0;
    }
    int n1 = grid.size(), n2 = grid[0].size();
    for(i = 0; i <= n1-1; i++){
        cnt -= doDFS(grid, i, 0);
        cnt -= doDFS(grid, i, n-1);
    }
    for(i = 0; i <= n2-1; i++){
        cnt -= doDFS(grid, 0, i);
        cnt -= doDFS(grid, n-1, i);
    }
    for(i = 0; i <= n1-1; i++){
        for(k = 0; k <= n2-1; k++){
            cnt += grid[i][k];
        }
    }
    return cnt;
}

int doDFS(vector<vector<int>> &grid, int i, int k){
    if(i < 0 || k < 0 || i >= grid.size() || k >= grid[0].size() || grid[i][k] != 1){
        return 0;
    }
    grid[i][k] = -1;
    return 1 + doDFS(grid, i, k-1)
    + doDFS(grid, i, k+1)
    + doDFS(grid, i-1, k)
    + doDFS(grid, i+1, k);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("G:\\CODES\\Pure DSA\\output.txt", "w", stdout);
    freopen("G:\\CODES\\Pure DSA\\input.txt", "r", stdin);
#endif
    int t = 1;
    cin >> t;
    return 0;
}