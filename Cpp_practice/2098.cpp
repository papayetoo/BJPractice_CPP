    //
    //  2098.cpp
    //  Cpp_practice
    //
    //  Created by 최광현 on 2020/02/03.
    //  Copyright © 2020 최광현. All rights reserved.
    //  외판원 순회 (TSP) 문제

    #include <iostream>
    #define MAX 17
    #define IMP 1000000001
    using namespace std;
    int buffer[MAX][1 << 16];
    int tsp(int matrix[][MAX], int numOfCities, int start, int bitmask);

    int main(){
        
        int numOfCities;
        cin >> numOfCities;
        
        
        int matrix[MAX][MAX];
       
        fill(&buffer[0][0], &buffer[0][0] + MAX * (1 << 16), 0);
        
        for(int row = 0; row < numOfCities; row++)
            for(int col = 0; col < numOfCities; col++)
                cin >> matrix[row][col];
        
        int bitmask = 1 << 0;
        cout << tsp(matrix,  numOfCities,0, bitmask);
        return 0;
    }

    int tsp(int matrix[][MAX], int numOfCities, int start, int bitmask){
        // 시작점은 0번 정점으로 하는 tsp
        // 다시 순환하면 복귀할 때도 0번 정점으로 복귀
        // tsp에서 시작정점은 문제 되지 않음.
        
        if( bitmask == (1 << numOfCities) - 1){
            if(matrix[start][0])
                return matrix[start][0];
            else
                return IMP;
        }

        // DP 안쓰면 시간초과 발생.
        int& result = buffer[start][bitmask];
        // buffer[start][bitmask] 는 start점을 지나며 bitmask에 표시된 정점을 지나는 최소거리
        if(result)
            return result;
        result = IMP;

        for(int j = 0; j < numOfCities; j++){
            if( matrix[start][j] != 0 && !( bitmask & (1 << j) ) )
                result = min(result, matrix[start][j] + tsp(matrix, numOfCities, j, bitmask | 1 << j));
        }
        return result;
    }
