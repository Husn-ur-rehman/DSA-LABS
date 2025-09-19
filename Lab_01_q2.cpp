#include<iostream>
using namespace std;
#include<vector>
int main(){
    vector<vector<float>> gpa ={
        {3.66,3.33,4.0,3.0,2.66},
        {3.33,3.0,3.66,3.0,-1},
        {4.0,3.66,2.66,-1,-1},
        {2.66,2.33,4.0,-1,-1},
        {3.33,3.66,4.0,3.0,3.33}
    };
    vector<string> names = {"Ali","Hiba","Asma","Zain","Faisal"};
    int cr_hr = 3;

    for(int i = 0; i < names.size();i++){
        float q_point = 0.00;
        float each_gpa = 0.00;
        int tot_cr_hr = 0;
        for(int j = 0; j < gpa.size(); j++){
            if(gpa[i][j] != -1){
                q_point += cr_hr * gpa[i][j];
                tot_cr_hr += 3;
            }
        }
        each_gpa = q_point/tot_cr_hr;
        tot_cr_hr = 0;
        cout<<names[i]<<"'s Gpa is : "<<each_gpa<<endl;

    }
    return 0;

}