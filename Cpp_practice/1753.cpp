    //
    //  1753.cpp
    //  Cpp_practice
    //
    //  Created by 최광현 on 2020/01/07.
    //  Copyright © 2020 최광현. All rights reserved.
    //

    #include <iostream>
    #include <memory>
    #include <algorithm>
    #define MAXNODE 20001
    #define MAX 2999990

    using namespace std;

    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int v, e; cin >> v >> e;
        int startNode; cin >> startNode;
        int** adjArr = new int* [v];
        unique_ptr<int[]> dist(new int[v]);
        for(int i = 0; i < v; i++){
            adjArr[i] = new int[v];
            for(int j = 0; j < v; j++){
                if(j != i)
                    adjArr[i][j] = MAX;
                else
                    adjArr[i][j] = 0;
            }
        }
        
        for(int i = 0; i < e; i++){
            int from, to, weight;
            cin >> from >> to >> weight;
            adjArr[from - 1][to - 1] = weight;
        }
        for(int i = 0; i < v; i++){
            dist[i] = adjArr[startNode - 1][i];
        }
        
        unique_ptr<int []> visited(new int [v]);
        int bitmasking = startNode << 1;
        cout << bitmasking << endl;
        fill(visited.get(), visited.get() + v, 0);
        visited[startNode - 1] = 1;
        int count = 1;
        while(count < v){
            int selectedIndex = -1;
            int temp = INT_MAX;
            for(int i = 0; i < v; i++){
                if(!visited[i] && temp > adjArr[startNode - 1][i] && adjArr[startNode-1][i] > 0){
                    temp = adjArr[startNode - 1][i];
                    selectedIndex = i;
                }
            }
            visited[selectedIndex] = 1;
            for(int i = 0; i < v; i++){
                dist[i] = min(dist[i], dist[selectedIndex] + adjArr[selectedIndex][i]);
            }
            count++;
        }
        
        for(int i = 0; i <v; i++){
            if(dist[i]  < MAX)
                cout << dist[i] << "\n";
            else
                cout << "INF" << "\n";
        }
        
        for(int i = 0; i < v; i++){
            delete[] adjArr[i];
        }
        delete[] adjArr;
        return 0;
    }
