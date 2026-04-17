class Solution {
public:
int rev(int n){
    int r=0;
    while(n>0){
        r=r*10+n%10;
        n=n/10;

    }
    return r;
}
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mindist=INT_MAX;
        for(int i=0 ;i<nums.size();i++){
            if(mp.count(nums[i])){
                mindist=min(mindist,i-mp[nums[i]]);
            }
            mp[rev(nums[i])]=i;
        }
       
        return ( mindist==INT_MAX)?-1:mindist;
    }
};