#include<bits/stdc++.h>
using namespace std;

class productOfNumbers{
    stack<int> s;
    public:
    productOfNumbers(){};
    
    void add(int val){
        s.push(val);

    }
    int getProduct (int k){
        if ( s.size() < k ) return -1;
        int ans = 1;
        vector<int> temp;
        for ( int i = 0 ; i < k ; i++ ){
            ans *= s.top();
            temp.push_back(s.top());
            s.pop();
        }
        for ( int i = temp.size() - 1 ; i >= 0 ; i-- ) s.push(temp[i]);
        return ans;
    }
    void display(){
        stack<int> temp = s;
        while( !temp.empty() ){
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<endl;
    }   
};
int main() {
    productOfNumbers p;
    p.add(3); 
    p.add(0); 
    p.add(2); 
    p.add(5); 
    p.add(4); 
    p.display();         
    cout<<p.getProduct(2)<<endl;        
    cout<<p.getProduct(3)<<endl;        
    cout<<p.getProduct(4)<<endl;
    p.display();        
    p.add(8);          
    cout<<p.getProduct(2)<<endl;        
    cout<<p.getProduct(3)<<endl;        
    cout<<p.getProduct(4)<<endl;
    p.display();        
    return 0;        
}
