    #include <iostream>
    #include <algorithm>
    #define MAX 10001
    using namespace std;

    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int n; cin >> n;
        int arr[MAX];
        fill(arr, arr + MAX, 0);
        
        for(int i = 0; i < n; i++){
            int num;cin >> num;
            arr[num]++;
        }
        
        for(int i = 1; i < MAX; i++){
            while(arr[i] > 0){
                cout << i << "\n";
                arr[i]--;
            }
        }
        
        return 0;
    }
