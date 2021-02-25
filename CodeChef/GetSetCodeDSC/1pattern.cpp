#include<bits/stdc++.h>
using namespace std;

void print(vector<int> row){
    for(int i = 0; i < row.size(); i++){
        cout<<row[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin >>t;
    while(t--) {
        int n; cin >> n;
        vector<int> row1(n);
        row1[0] = 1;

        for(int i = 1; i < n; i++){
            row1[i] = row1[i-1] * 2  + 2;
        }

        vector<int> row2(n);
        row2[0] = 2;

        for(int i = 1; i < n; i++){
            row2[i] = row2[i-1] *2 + 1;
        }

        vector<int> row3(n);
        row3[0] = 4;
        for(int i = 1; i < n; i++){
            row3[i] = row3[i-1] *2 +2;
        }

        vector<int> row4(n);
        row4[0] = 3;
        for(int i = 1; i < n; i++)
            row4[i] = row4[i-1] *2;

        print(row1);
        print(row2);
        print(row3);
        print(row4);
    }
    return 0;
}