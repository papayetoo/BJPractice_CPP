//
//  16000.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/13.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 2000
#define LAND '#'
#define AMBIGUOUS '?'
#define SEA '.'
#define SAFE 'O'
#define DANGER 'X'

using namespace std;

template <class T> void printMaps(T maps[][MAX], int rows, int cols);
void replaceChar(char maps[][MAX], int rows, int cols, int curY, int curX, char before, char after);
bool isSafe(char maps[][MAX], bool visited[][MAX], int rows, int cols, int curY, int curX);
void visitIsland(char maps[][MAX], bool visited[][MAX], int rows, int cols, int curY, int curX);

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int rows, cols; cin >> rows >> cols;
    char maps[MAX][MAX];
    bool visited[MAX][MAX]; fill(&visited[0][0], &visited[0][0] + MAX * MAX, false);
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cin >> maps[r][c];
        }
    }
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++)
        {
            if(maps[r][c] == LAND) {
                fill(&visited[0][0], &visited[0][0] + MAX * MAX, false);
                visitIsland(maps, visited, rows, cols, r, c);
                if(isSafe(maps, visited, rows, cols, r, c)){
                    maps[r][c] = SAFE;
                    replaceChar(maps, rows, cols, r, c, LAND, SAFE);
                }
                else{
                    maps[r][c] = DANGER;
                    replaceChar(maps, rows, cols, r, c, LAND, DANGER);
                }
            }
        }
    }
    
    printMaps(maps, rows, cols);
    
}

template <class T> void printMaps(T maps[][MAX], int rows, int cols){
    
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++)
            cout << maps[r][c];
        cout << "\n";
    }
    
}

void replaceChar(char maps[][MAX], int rows, int cols, int curY, int curX, char before, char after){
//   safe 한지 아닌 지에 대한 판단은 아직 안한 상태.
    
    int dy[4] = {1, -1, 0, 0 };
    int dx[4] = {0, 0, -1, 1 };
    
    for(int i = 0; i < 4; i++){
        if(curY + dy[i] >= 0 && curY + dy[i] < rows && curX + dx[i] >= 0 && curX + dx[i] < cols && maps[curY +dy[i]][curX + dx[i]] == before ){
            maps[curY +dy[i]][curX + dx[i]] = after;
            replaceChar(maps, rows, cols, curY + dy[i], curX + dx[i], before, after);
        }
    }
}

bool isSafe(char maps[][MAX], bool visited[][MAX], int rows, int cols, int curY, int curX){
    bool ret= false;
    
    visited[curY][curX] = true;
    
    
    
    return ret;
}

void visitIsland(char maps[][MAX], bool visited[][MAX], int rows, int cols, int curY, int curX){
    
    
    int dy[4] = {1, -1, 0, 0 };
    int dx[4] = {0, 0, 1, -1};
    
    for(int i = 0; i < 4; i++){
        if(curY + dy[i] >= 0 && curY + dy[i] < rows && curX + dx[i] >= 0 && curX + dx[i] < cols && maps[curY +dy[i]][curX + dx[i]] != SEA && !visited[curY + dy[i]][curX + dx[i]] ){
            visited[curY +dy[i]][curX + dx[i]] = true;
            visitIsland(maps, visited,rows, cols,  curY + dy[i], curX + dx[i]);
        }
    }
}

