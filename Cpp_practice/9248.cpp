//
//  9248.cpp
//  Cpp_practice
//
//  Created by 최광현 on 2020/01/19.
//  Copyright © 2020 최광현. All rights reserved.
//  접미사 배열에 관한 문제 멘버 - 마이어스 알고리즘

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ALPHANUM 26
using namespace std;

struct suffixInfo{
    int startPos;
    int rank;
};

class Comparator{
private:
    const vector<int>& rank;
    int t;
public:
    Comparator(vector<int>& _rank, int _t) : rank(_rank), t(_t){}
    bool operator() (int a, int b){
        if(rank[a] != rank[b]) return rank[a] < rank[b];
        else//rank[a] == rank[b]이면
            return rank[a + t] < rank[b + t];
    }
    
    int GetT(){
        return this->t;
    }
};


vector<int> getSA(const string& str){
    int length = str.length();
    vector<int> rank(length + 1);
    vector<int> startPos(length);
    
    for(int i = 0; i < length; i++){
        // startPos 의 값은 접미사 배열의 시작 인덱스를 알려줌.
        startPos[i] = i;
//        첫 번째 랭크
        rank[i] = str[i];
    }
    rank[length] = -1;
    
   
//    두 번째 랭크 구하기
    int t = 1;
       
    while (t < length) {
        Comparator compareUsing2T(rank, t);
        sort(startPos.begin(), startPos.end(), compareUsing2T);
        //rank가 낮은 순서대로 정렬
        t *= 2;
        if (t >= length)
            break;
        vector<int> newRank(length + 1);
        newRank[length] = -1;
        //문장 끝을 -1로 정의
        newRank[startPos[0]] = 0;
        //정렬된 결과에 따라 가장 앞에 오는
        for (int i = 1; i < length; i++)
            if (compareUsing2T(startPos[i - 1], startPos[i]))
                newRank[startPos[i]] = newRank[startPos[i - 1]] + 1;
            else
                newRank[startPos[i]] = newRank[startPos[i - 1]];
        rank = newRank;
    }
    // 새로운 rank 값 계산
    return startPos;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string str; cin >> str;
    int length = str.size();
    vector<int> sa = getSA(str);
    for(int e : sa){
        cout << e + 1 << " ";
    }
    cout << "\n";
    
    int* rank = new int[length];
    int* lcp = new int[length];
    for(int i = 0; i < length; i++)
        rank[sa[i]] = i;
    
    int len = 0;
    
    
    for(int i = 0; i < length; i++){
        int k = rank[i];
        // str[i]로 시작하는 접미사가 사전순서에서 몇 번째 순서인지 나타내는 값
        // k = 0일 때를 제외하기 위함임.
        //lcp[i]는 sa[i-1]과 sa[i] 사이의 최장 공통 접두사의 길이임.
        //첫 번째로 등장하는 배열 계산 불가.
        if(k){
            int j = sa[k - 1];
            //k번째 이전에 나타나는 k - 1번째 접미사 배열에 첫 문자가 나타나는 인덱스를 반환.
            while(str[j + len] == str[i + len])
                len++;
            //길이가 같으므로 증가.
            
            lcp[k] = len;
            
            //접미사 배열의 인접한 값이므로 -1
            //최소 0까지 떨어짐.
            if(len)
                len--;
        }
    }
    
    for(int i = 0; i < length; i++){
        if(i)
            cout << lcp[i] << " ";
        else
            cout << "x" << " ";
    }
    
    delete[] lcp;
    delete[] rank;
    return 0;
}
