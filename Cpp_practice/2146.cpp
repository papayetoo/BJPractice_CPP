//
//  2146.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/02/11.
//  Copyright © 2020 최광현. All rights reserved.
//  백준 2146문제 가장 짧은 다리 놓기 문제(그리디 알고리즘)

#include <iostream>
#include <string>
#include <array>
#include <queue>
#define MAX 100
#define INF 100000


using namespace std;

struct island{
    int x, y, islandNum;
    island(int y, int x, int islandNum): y(y), x(x), islandNum(islandNum){};
};

int islandCount = 2;
int visited[MAX][MAX];
queue< island > islandInfo;
void printArray(int arr[][MAX], int size);
// 배열 출력하기 위한 함수.
int min_Bridge(int arr[][MAX], int size, int curRow, int curCol, int islandNum);
int calculateMin();
void bfs_Coloring(int arr[][MAX], int size, int curRow, int curCol);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    //  std::array<int [], 100> maps;
    int maps[MAX][MAX];
    fill(&maps[0][0], &maps[0][0] + MAX * MAX, 0);
    //  초기화
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> maps[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (maps[i][j] == 1){
                maps[i][j] = islandCount;
                bfs_Coloring(maps, n, i, j);
                islandCount++;
            }
        }
    }

    cout << calculateMin();

    return 0;
}

void printArray(int arr[][MAX], int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size ; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

}

int min_Bridge(int arr[][MAX], int size, int curRow, int curCol, int islandNum){

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int answer = 10000;

//    dfs 진행.
    for(int i = 0; i < 4 ; i++){
        if(curRow + dy[i] >= 0 && curRow + dy[i] < size && curCol + dx[i] >= 0 && curCol + dx[i] < size){
            if(arr[curRow + dy[i]][curCol + dx[i]] > 0 && arr[curRow + dy[i]][curCol + dx[i]] != islandNum){
                            // 바다가 아니고 다른 섬인 경우 종료
            //                visited[curRow + dy[i]][curCol + dx[i]] = 1;
                            return 1;
            }
            else if(!arr[curRow + dy[i]][curCol + dx[i]] && !visited[curRow + dy[i]][curCol + dx[i]])
            {
                // 0 이면서 아직 방문하지 않은 곳으로 이동.
                visited[curRow + dy[i]][curCol + dx[i]] = 1;
                answer = min(answer, 1 + min_Bridge(arr, size, curRow + dy[i], curCol + dx[i], islandNum));
//                visited[curRow + dy[i]][curCol + dx[i]] = 0;
            }
        }
    }
    return answer;
}

int calculateMin(){

    int answer = INF;
    while(!islandInfo.empty()){
        int y0 = islandInfo.front().y;
        int x0 = islandInfo.front().x;
        int islandNum0 = islandInfo.front().islandNum;

        islandInfo.pop();
        queue<island> islandInfoCopy = islandInfo;
        while(!islandInfoCopy.empty()){
            int y1 = islandInfoCopy.front().y;
            int x1 = islandInfoCopy.front().x;
            int islandNum1 = islandInfoCopy.front().islandNum;

            islandInfoCopy.pop();

            if(islandNum0 == islandNum1)
                continue;

            answer = min(answer, abs(y1-y0) + abs(x1 - x0) -1);
        }
    }
    return answer;
}

void bfs_Coloring(int arr[][MAX], int size, int curRow, int curCol){

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    queue< pair<int, int> > q;
    q.push(make_pair(curRow, curCol));
    islandInfo.push(island(curRow, curCol, islandCount));

    while (!q.empty()){
        pair<int, int> frontPos = q.front();
        q.pop();
        arr[frontPos.first][frontPos.second] = islandCount;
        for( int i = 0; i < 4 ; i++){
            if(frontPos.first + dy[i] >= 0 && frontPos.first + dy[i] < size && frontPos.second + dx[i] >= 0 && frontPos.second + dx[i] < size && arr[frontPos.first + dy[i]][frontPos.second + dx[i]] == 1){
                arr[frontPos.first + dy[i]][frontPos.second+dx[i]] = islandCount;
                q.push(make_pair(frontPos.first + dy[i], frontPos.second + dx[i]));
                islandInfo.push(island(frontPos.first + dy[i], frontPos.second + dx[i], islandCount));
            }
        }
    }

}

