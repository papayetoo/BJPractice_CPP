//
//  1987.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/13.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <memory>
#define ALPHANUM 26
using namespace std;

int dfs(unique_ptr< unique_ptr<char[]> [] >& arr, int r, int c, int i, int j, int alpha[ALPHANUM]);

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    //r : row, c: column
    unique_ptr< unique_ptr<char [] > [] > arr;
    arr = make_unique< unique_ptr<char []> []>(r);
    for(int i = 0; i < r; i++){
        arr[i] = make_unique<char []>(c);
        for(int j = 0; j < c; j++)
            cin >> arr[i][j];
    }
    
    int alpha[ALPHANUM]; fill(alpha, alpha + ALPHANUM, 0);
    //0 아직 지나지 않았다는 것을 의미함.
    alpha[arr[0][0] - 'A'] = 1;
    cout << dfs(arr, r, c, 0, 0, alpha) << "\n";

    return 0;
}

int dfs(unique_ptr< unique_ptr<char[]> [] >& arr, int r, int c, int i, int j, int alpha[ALPHANUM]){
    
    int result = 1;

    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    
    for(int k = 0; k < 4; k++){
        if(i + dy[k] >= 0 && i + dy[k] < r && j + dx[k] >= 0 && j + dx[k] < c && !alpha[arr[i + dy[k]][j + dx[k]] - 'A']){
            alpha[arr[i + dy[k]][j + dx[k]] - 'A'] = 1;
            result = max(result, dfs(arr, r, c, i + dy[k], j + dx[k], alpha) + 1);
            alpha[arr[i + dy[k]][j + dx[k]] - 'A'] = 0;
        }
    }
    
    return result;
}

