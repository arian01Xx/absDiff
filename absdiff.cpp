#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<int>& vsum, int n, int sum){
        if(ind==n){
            vsum.push_back(sum);
            return;
        }
        solve(nums,ind+1,vsum,n,sum+nums[ind]);
        solve(nums,ind+1,vsum,n,sum);
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> A, B;
        for(int i=0; i<n/2; i++){ //primera mitad
            A.push_back(nums[i]);
        }
        for(int i=n/2; i<n; i++){ //segunda mitad
            B.push_back(nums[i]);
        }
        vector<int> sumA, sumB;

        solve(A, 0, sumA, A.size(), 0); //llena los vectores sumA y sumB
        solve(B, 0, sumB, B.size(), 0);
        sort(sumB.begin(),sumB.end());
        int ans=INT_MAX;

        for(int i=0; i<sumA.size(); i++){
            int s=sumA[i];
            int l=0, r=sumB.size()-1;
            while(l<=r){  //binary search
                int mid=l+(r-l)/2;
                int sum=s+sumB[mid];
                ans=min(ans, abs(goal-sum));
                if(ans==0) return 0;
                if(sum<goal) l=mid+1;
                else r=mid-1;
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}