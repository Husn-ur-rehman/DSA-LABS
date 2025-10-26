#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void Towerofhanoi(int n,char f_rod, char t_rod,char h_rod){
        if( n == 1){
            cout<<"Move disk "<<n<<" from "<<f_rod<<" to "<<t_rod<<endl;
            return;
        }
        Towerofhanoi(n-1,f_rod,h_rod,t_rod);
        cout<<"Move disk "<<n<<" from "<<f_rod<<" to "<<t_rod<<endl;

        Towerofhanoi(n-1,h_rod,t_rod,f_rod);
    }
};

int main(){
    int nd;
    cin>>nd;
    Solution obj;
    obj.Towerofhanoi(nd,'A','C','B');
}