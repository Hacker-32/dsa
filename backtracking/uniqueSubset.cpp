#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> nums,int n, int i, vector<int> sub, set<vector<int>> &res){
    if(i==n){
        sort(sub.begin(), sub.end());
        res.insert(sub);
        return;
    }
    // not include the nums[i]
    helper(nums,n,i+1,sub, res);
    //inlcude the nums[i]
    sub.push_back(nums[i]);
    helper(nums, n, i+1,sub, res);
}


vector<vector<int>> uniqueSubsets(vector<int> nums){
    set<vector<int>> out;
    vector<vector<int>> r;
    helper(nums,nums.size(),0,{},out);
    for(auto x: out){
        r.push_back(x);
    }
    return r;
}
int main(){
    vector<int> in = {1,3,4,3};
    vector<vector<int>>  out = uniqueSubsets(in);
    for(auto x: out){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

}