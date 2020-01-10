#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstdlib>
#define MAX 9999999

using namespace std;


void vwap(vector<int>& v, int first, int second){
    //vector<int> v에서 index가 first에 해당하는 것과 second에 해당하는 것을
    //swap 해주느 함수
    int temp = v[first];
    v[first] = v[second];
    v[second] = temp;
}

bool decimalCount(int n){
    //소수인지 아닌지 판단하는 함수입니다.
    bool ret = true;
    
    if(n < 2)
        return false;
    
    for(int i = 2 ; i <= n/2; i++){
        //중요한 점으 i의 상한선으 조절해서 시간을 단축시켜야함.
        if( n % i == 0)
            return false;
    }
    
    return ret;
}

void permutation(vector<int> v, int r, int depth, set<int>& s){
    // 순열을 만들어 내서 set<int> s에 저장하는 함수.
    // set을 사용하는 이유는 set은 중복으 배제하기 때문에
    if(r == depth){
        int sum = 0;
        for(int i = 0; i < depth; i++){
            sum += v[i] * pow(10, depth - i - 1);
        }
        
        if(decimalCount(sum))//모든 sum을 넣을 필요는 없으므로 소수인지 아닌 지 판별.
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
        //011과 전체 vector에서 1,2,3,..length 까지 뽑는 것을 구현.
        permutation(iVec, i, 0, s);
    }
    //소수의 개수를 묻는 문제이므로 set<int> s(소수만을 포함하는)의 크기를 반환하면 됨.
    answer = s.size();
    
    return answer;
}
