    //
    //  2583.cpp
    //  Cpp_practice
    //
    //  Created by 최광현 on 2020/01/12.
    //  Copyright © 2020 최광현. All rights reserved.
    //

    #include <iostream>
    #include <memory>
    #include <vector>
    #include <algorithm>
    #define MAX 100
    #define WHITE 'W'
    #define BLACK 'B'
    #define CHECKED 'C'
    using namespace std;

    int calWhiteAreas(unique_ptr< unique_ptr<char[]> [] >& areas, int rows, int cols, int curY, int curX);

    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n, m, k; cin >> n >> m >> k;
        
        unique_ptr< unique_ptr<char[]> [] > areas;
        areas = make_unique< unique_ptr <char[]> []>(n);
        for(int i = 0; i < n; i++){
            areas[i] = make_unique<char []>(m);
            fill(areas[i].get(), areas[i].get() + m, WHITE);
        }
        
        for(int i = 0; i < k; i++){
            int lx,ly,rx,ry;
    //      x축 방향으로는 [lx, rx -1]
    //      y축 방향으로는 [ly, ry -1]    까지 BLACK으로 칠하면 됨.
            cin >> lx >> ly >> rx >> ry;
            for(int y = ly; y < ry ; y++){
                for(int x = lx; x < rx; x++){
                    areas[y][x] = BLACK;
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(areas[i][j] == WHITE){
                    areas[i][j] = BLACK;
                    result.push_back(calWhiteAreas(areas, n, m, i, j));
                }
            }
        }
        
        sort(result.begin(), result.end(), less<int>());
        cout << result.size() << "\n";
        for(int e : result)
            cout << e << " ";
        return 0;
    }


    int calWhiteAreas(unique_ptr< unique_ptr<char[]> [] >& areas, int rows, int cols, int curY, int curX){
    //    areas[curY][curX]가 'W'일 때만 계산.
        int result = 1;
        
        int dy[4] = {1,-1,0,0};
        int dx[4] = {0,0,1,-1};
        
        for(int i = 0; i < 4; i++){
        
            if(curY + dy[i] >= 0 && curY + dy[i] < rows && curX + dx[i] >= 0 && curX + dx[i] < cols && areas[curY + dy[i]][curX + dx[i]] == WHITE){
                areas[curY + dy[i]][curX + dx[i]] = BLACK;
//                result += calWhiteAreas(areas, rows, cols, curY + dy[i], curX + dx[i]);
            }
        }
        
        return result;
    }
