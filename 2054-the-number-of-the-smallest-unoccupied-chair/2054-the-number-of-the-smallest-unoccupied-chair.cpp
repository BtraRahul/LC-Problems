class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> instant;
        map<int,int> arrive;
        map<int,vector<int>> leave;
        int n=times.size();
        int index=0;
        for(auto v: times){
            instant.insert(v[0]);
            instant.insert(v[1]);
            arrive[v[0]]=index;
            leave[v[1]].push_back(index);
            index++;
        }
        unordered_map<int,int> pos;
        set<int> vacant;
        for(int i=0;i<n;i++){
            vacant.insert(i);
        }
        for(auto ins: instant){
            if(leave.find(ins)!=leave.end()){
                for(auto p: leave[ins]){
                    vacant.insert(pos[p]);
                }
            }
            if(arrive.find(ins)!=arrive.end()){
                int p=arrive[ins];
                pos[p]=*vacant.begin();
                vacant.erase(vacant.begin());
            }
            if(ins==times[targetFriend][0]) return pos[targetFriend];
        }
        return n;
    }
};