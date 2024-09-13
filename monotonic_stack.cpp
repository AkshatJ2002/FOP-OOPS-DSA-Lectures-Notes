#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void insert(stack<int>&st,int val){
    if(st.empty())
    st.push(val);
    else{
        while(!st.empty() && st.top()>val)
        st.pop();
        st.push(val);
    }
}
void print(stack<int>st){
    if(st.empty())
    cout<<"stack is empty";
    else{
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
}
vector<int> nge(vector<int>v){
    vector<int>res(v.size());
    stack<int>st;
    for(int i=0;i<v.size();i++){
        if(st.empty())
        st.push(i);
        else{
            while(!st.empty() &&v[st.top()]<v[i]){
                res[st.top()]=v[i];
                st.pop();
            }
            st.push(i);
        }
    }
    res[v.size()-1]=-1;
    return res;
}
int main(){
    stack<int>st;
    vector<int>arr={9,1,7,5,8,9,10};
    insert(st,1);
    insert(st,7);
    insert(st,9);
    insert(st,5);
    insert(st,8);
    print(st);
//     vector<int>res=nge(arr);
// for(int i=0;i<res.size();i++){
//     cout<<res[i]<<" ";;
// }
    return 0;
}
