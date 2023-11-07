#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N = 5, W = 7;
    int row = N + 1;
    int col = W + 1;
    int K[row][col];
    int P[5] = {15, 14, 10, 45, 30};
    int Wt[5] = {2, 5, 1, 3, 4};
    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= W; j++){
            if (i == 0 || j == 0){
                K[i][j] = 0;
            }
            else if (Wt[i - 1] <= j){
                K[i][j] = max(P[i - 1] + K[i - 1][j - Wt[i - 1]], K[i - 1][j]);
            }
            else{
                K[i][j] = K[i - 1][j];
            }
        }
    }
    vector<int> ans;
    int i = N, j = W;
    while (i > 0 && j > 0){
        if (K[i][j] == K[i - 1][j]){
            i--;
        }
        else{
            ans.push_back(i);
            i--;
            j -= Wt[i];
        }
    }
    cout << "Selected Objects are: { ";
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if (i == ans.size() - 1)
            break;
        cout << ", ";
    }
    cout << " }\n";
    cout << "Maximum Profit is: " << K[N][W];
    return 0;
}
