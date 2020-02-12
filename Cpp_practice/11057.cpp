//
//  11057.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/02/03.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#define MAX 1001
#define DIV 10007
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int n; cin >> n;
    
    int dp[MAX][10];
    // dp[자릿수][제일 앞에 오는 숫자]
    
    fill(&dp[0][0], &dp[0][0] + MAX * 10, 0);
    
    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    for(int k = 2; k <= n; k++){
        for(int j = 0; j < 10; j++)
            dp[k][j] = accumulate( &dp[k-1][0 + j], &dp[k-1][0] + 10, 0) % DIV;
    }
    
    int answer = accumulate(&dp[n][0], &dp[n][0] + 10, 0) % DIV;
    cout << answer;
    
    return 0;
}
