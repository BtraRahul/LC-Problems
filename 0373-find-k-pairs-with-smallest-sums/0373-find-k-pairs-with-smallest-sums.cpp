class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        priority_queue < pair<int, vector<int> > > pq;
        for(auto n: nums1){
            for(auto m: nums2){
                long long sum=n+m;
                if(pq.size()<k){
                    vector<int> v;
                    v.push_back(n);
                    v.push_back(m);
                    pq.push({sum,v});    
                } 
                else if(sum<pq.top().first) {
                    pq.pop();
                    vector<int> v;
                    v.push_back(n);
                    v.push_back(m);
                    pq.push({sum,v}); 
                }
                else break;
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;    
    }
};