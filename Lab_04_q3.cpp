char* get_permutation(string s, left, right){
    if(left == right){
        cout<<str;
    }else{
        for(int i = left; i <= right; i++){
            swap(str[left],str[i]);
            get_permutation(str,left,right);
            swap(str[left],str[i]);
        }
    }
}