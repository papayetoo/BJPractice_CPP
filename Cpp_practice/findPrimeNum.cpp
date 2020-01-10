#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstdlib>
#define MAX 9999999

using namespace std;


void vwap(vector<int>& v, int first, int second){
    int temp = v[first];
    v[first] = v[second];
    v[second] = temp;
}

bool decimalCount(int n){
    
    bool ret = true;
    
    if(n < 2)
        return false;
    
    for(int i = 2 ; i <= n/2; i++){
        if( n % i == 0)
            return false;
    }
    
    return ret;
}

void permutation(vector<int> v, int r, int depth, set<int>& s){
    if(r == depth){
        int sum = 0;
        for(int i = 0; i < depth; i++){
            sum += v[i] * pow(10, depth - i - 1);
        }
        
        if(decimalCount(sum))
            s.insert(sum);
    
        return;
    }
    for(int i = depth ;  i < v.size(); i++){
        vwap(v, i, depth);
        permutation(v, r, depth+1, s);
        vwap(v, i, depth);
    }
}


int solution(string numbers) {
    int answer = 0;
    vector<int> iVec;
    set<int> s;
    for(int i = 0; i < numbers.length() ; i++){
        iVec.push_back(numbers[i] - '0');
    }
    
    for(int i = 1 ; i <= numbers.length(); i++){
        permutation(iVec, i, 0, s);
    }
    
    answer = s.size();
    
    return answer;
}
