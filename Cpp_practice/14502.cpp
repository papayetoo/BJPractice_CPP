    //
    //  14502.cpp
    //  Cpp_practice
    //
    //  Created by 최광현 on 2020/01/12.
    //  Copyright © 2020 최광현. All rights reserved.
    //

    #include <iostream>
    #include <vector>
    #include <memory>
    #define MAX 8

    using namespace std;

    void processingVirus(int arr[][MAX], int n, int m, int col, int row);
    int countZero(int arr[][MAX], const int n, const int m);
    void printArray(int arr[][MAX], const int n, const int m);
    void copyArray(int origin[][MAX], int dest[][MAX], int col, int row);

    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
        int n, m; cin >> n >> m;
        int arr[MAX][MAX];
        vector< pair<int, int> > zeroCoordinate;
        
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                // arr 배역의 입력을 받음.
                cin >> arr[i][j];
                // arr에서 값이 0인 부분의 좌표를 저장
                if(!arr[i][j])
                    zeroCoordinate.push_back(make_pair(i, j));
            }
        }
        
        int zeros = zeroCoordinate.size();
        int cp[MAX][MAX];
        int result = 0;
        
        // 3개의 벽을 설치하는 부분은 완전 탐색으로 이루어진다.
        // 벽이 3개이기 때문에 3중 for문을 돌리는 것이 가능하지만
        // 벽의 수가 증가하면 combination 함수를 구현하여 zerroCoordinate에서
        // n 개를 뽑는 함수를 작성하는 것이 효율이 높다고 생각한다.
        for(int i = 0; i < zeros - 2; i++){
            for(int j = i + 1; j < zeros - 1 ; j++){
                for(int k = j + 1; k < zeros ; k++){
                    // 벽이 3개가 설치된 후 바이러스가 퍼진 후 안전지역의 수를 세야하기 때문에 arr을 cp에 복사
                    //copyArray(arr, cp, n, m);
                    copy(&arr[0][0], &arr[0][0] + MAX * MAX, &cp[0][0]);
                    // 아래 3줄에서 cp에 벽을 설치하는 함수.
                    cp[zeroCoordinate[i].first][zeroCoordinate[i].second] = 1;
                    cp[zeroCoordinate[j].first][zeroCoordinate[j].second] = 1;
                    cp[zeroCoordinate[k].first][zeroCoordinate[k].second] = 1;
                    for(int col = 0; col < n; col++){
                        for(int row = 0; row < m; row++){
                            processingVirus(cp, n, m, col, row);
                        }
                    }
                    //result 변수에 안전지역의 수가 최대인 때 저장하기 위함.
                    result = max(result, countZero(cp, n, m));
              }
            }
        }
        cout << result ;
        return 0;
    }

    void copyArray(int origin[][MAX], int dest[][MAX], int col, int row){
        for(int i = 0; i < col; i++){
            copy(origin[i], origin[i] + row, dest[i]);
        }
    }



    void processingVirus(int arr[][MAX], int n, int m, int col, int row){
        //바이러스가 번지는 함수.
        if(arr[col][row] == 1 || arr[col][row] == 0)
            return;
        else if(arr[col][row] == 2){
            if(col + 1 < n && arr[col + 1][row] == 0){
                arr[col + 1][row] = 2;
                processingVirus(arr, n, m,col + 1, row);
            }
            if(col - 1 >= 0 && arr[col -1 ][row] == 0){
                arr[col -1][row] = 2;
                processingVirus(arr, n, m,col - 1, row);
            }
            if(row + 1 < m && arr[col][row + 1] == 0){
                arr[col][row + 1] = 2;
                processingVirus(arr, n, m,col, row + 1);
            }
            if(row - 1 >= 0 && arr[col][row - 1] == 0)
            {
                arr[col][row - 1] = 2;
                processingVirus(arr, n, m, col, row - 1);
            }
        }
    }

    int countZero(int arr[][MAX], const int n, const int m){
        //안전지역을 세는 함수.
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++ ){
                if(arr[i][j] == 0)
                    count++;
            }
        }
        
        return count;
    }

    void printArray(int arr[][MAX], const int n, const int m){
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <m ; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
