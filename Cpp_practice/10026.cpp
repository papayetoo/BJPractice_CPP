//
//  10026.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/13.
//  Copyright © 2020 최광현. All rights reserved.
//

#include <iostream>
#include <memory>
#define MAX 100
#define RED 'R'
#define GREEN 'G'
#define BLUE 'B'
#define CHECKED 'C'
using namespace std;

void dfs(char grid[][MAX], int size, int row, int col, char c);
void colorblindPerson(char grid[][MAX], int size, int row, int col, char c);
void printGrid(char grid[][MAX], int size);
int solution(char grid[][MAX], int size);

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int size; cin >> size;
    char grid[MAX][MAX];
    
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++)
            cin >> grid[r][c];
    }
    
    
    char ncopy[MAX][MAX];
    copy(&grid[0][0], &grid[0][0] + MAX * MAX, &ncopy[0][0]);
    
    char blindcopy[MAX][MAX];
    for(int r = 0; r < size; r++){
        for(int c = 0;  c < size ; c++){
            if(grid[r][c] == GREEN){
                blindcopy[r][c] = RED;
            }else
                blindcopy[r][c] = grid[r][c];
        }
    }
    
    int normal = solution(ncopy, size);
    int colorblind = solution(blindcopy, size);
    
    cout << normal << " " << colorblind;
    
    return 0;
}

void dfs(char grid[][MAX], int size, int row, int col, char c){
    
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
    
    for(int i = 0; i < 4; i++){
        if(row + dy[i] >= 0 && row + dy[i] < size && col + dx[i] >= 0 && col + dx[i] < size && grid[row + dy[i]][col + dx[i]] == c){
        grid[row + dy[i]][col + dx[i]] = CHECKED;
        dfs(grid, size, row + dy[i], col + dx[i], c);
        }
    }
    
}

void printGrid(char grid[][MAX], int size){
    
    for(int r = 0; r < size ; r++){
        for(int c = 0; c < size ; c++)
            cout << grid[r][c];
        cout <<"\n";
    }
    
}

int solution(char grid[][MAX], int size){
   
    int result = 0;
    
    for(int r = 0; r < size ; r ++){
        for(int c = 0; c < size; c++){
            char temp = grid[r][c];
            if(temp != CHECKED)
            {
                grid[r][c] = CHECKED;
                dfs(grid, size, r, c, temp);
                result++;
            }
        }
    }
    
    return result;
}
