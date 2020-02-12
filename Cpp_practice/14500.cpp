//
//  14500.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/20.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#define MAX 500

using namespace std;

int dfs(int arr[][MAX], int curY, int curX, int row, int col, int count, bool visited[][MAX]){

    if(count == 3)
        return arr[curY][curX];
    
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    
    int result = arr[curY][curX];
    int maxCost = 0;
    for(int i = 0; i < 4; i++){
        if(curY + dy[i] >= 0 && curY + dy[i] < row && curX + dx[i] >= 0 && curY +dx[i] < col && !visited[curY + dy[i]][curX + dx[i]]){
            visited[curY + dy[i]][curX + dx[i]] = true;
            maxCost = max(maxCost, dfs(arr, curY + dy[i], curX + dx[i], row, col, count + 1, visited));
            visited[curY + dy[i]][curX + dx[i]] = false;
        }
    }
    
    return result + maxCost;
}


int moutainBlock(int arr[][MAX], int curY, int curX, int row, int col){
    
    int result = 0;
    
//    ㅜ
    if(curY + 1 < row && curX + 2 < col){
        result = max(result, arr[curY][curX] + arr[curY][curX + 1] + arr[curY][curX + 2] + arr[curY + 1][curX + 1]);
    }
    
//    ㅗ
    if(curY - 1 >= 0 && curX + 2 < col){
        result = max(result, arr[curY][curX] + arr[curY][curX + 1] + arr[curY][curX + 2] + arr[curY - 1][curX + 1]);
    }
    
//    ㅏ
    if (curY + 2 < row && curX + 1 < col){
        result = max(result, arr[curY][curX] + arr[curY + 1][curX] + arr[curY + 2][curX] + arr[curY + 1][curX + 1]);
    }
    
//    ㅓ
    if( curY + 2 < row && curX - 1 >= 0 ){
        result = max(result, arr[curY][curX] + arr[curY + 1][curX] + arr[curY + 2][curX] + arr[curY + 1][curX - 1]);
    }
    
    return result;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int arr[MAX][MAX];
    bool visited[MAX][MAX];
    fill(&arr[0][0], &arr[0][0] + MAX * MAX, 0);
    fill(&visited[0][0], &visited[0][0] + MAX * MAX, false);
    
    int row, col;
    cin >> row >> col;
    
    for(int r = 0; r < row ; r++){
        for(int c = 0; c < col; c++){
            cin >> arr[r][c];
        }
    }
    
    int answer = 0;
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            visited[r][c] = true;
            answer = max(answer, dfs(arr, r,c,row,col, 0, visited));
            answer = max(answer, moutainBlock(arr, r, c, row, col));
            visited[r][c] = false;
        }
    }
    cout << answer ;
    return 0;
}
