    //
    //  2468.cpp
    //  Cpp_practice
    //
    //  Created by 최광현 on 2020/01/12.
    //  Copyright © 2020 최광현. All rights reserved.
    //

    #include <iostream>
    #define MAX 100

    using namespace std;

    int sink(int arr[][MAX], int size, int limit);
    void countSafeArea(int arr[][MAX], int row, int col, int size);
    void printArray(int arr[][MAX], int size);

    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n; cin >> n;
        
        int arr[MAX][MAX];
        
        //높이 변수 초기화.
        int height[MAX + 1];
        fill(height, height + MAX, 0);
        
        int m = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
                if(!height[arr[i][j]]) height[arr[i][j]] = 1;
                m = max(arr[i][j], m);
            }
        }
        
        int answer = 0;
        for(int i = 0; i < MAX; i++){
            answer = max(answer, sink(arr, n, i));
        }
        
        cout << answer;
        
        return 0;
    }


    int sink(int arr[][MAX], int size, int limit){
        
        int copies[MAX][MAX];
        copy(&arr[0][0], &arr[0][0] + MAX * MAX,  &copies[0][0]);
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
            {
//              limit 이하는 -1로 바꿈.
                if(copies[i][j] <= limit)
                    copies[i][j] = -1;
                else
                    copies[i][j] = 1;
//                limit 초과는 1로 바꿈.
            }
        }
        
        
        int count = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(copies[i][j] == 1)
                {
                    countSafeArea(copies, i, j, size);
                    count++;
                }
            }
        }
        
        return count;
    }

    void countSafeArea(int arr[][MAX], int row, int col, int size){
        // sink 함수의 결과인 copies 배열에서 -1이 아닌 것에 대하여 dfs를 실행하면 됨.
        if(arr[row][col] == -1)
            return;
        
        arr[row][col] = 0;
        if(row + 1 < size && arr[row + 1][col] == 1){
            arr[row + 1][col] = 0;
            countSafeArea(arr, row + 1, col, size);
        }
        if(row  - 1 >= 0 && arr[row - 1][col] == 1){
            arr[row - 1][col] = 0;
            countSafeArea(arr, row - 1, col, size);
        }
        if(col + 1 <  size && arr[row][col + 1]  == 1){
            arr[row][col + 1] = 0;
            countSafeArea(arr, row, col + 1, size);
        }
        if(col -1 >= 0 && arr[row][col - 1]  == 1){
            arr[row][col - 1] = 0;
            countSafeArea(arr, row, col - 1, size);
        }
        
    }

    void printArray(int arr[][MAX], int size){
        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                cout << arr[i][j] << ' ';
            cout << "\n";
        }
        
    }
