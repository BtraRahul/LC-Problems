class Solution {
    // [1,2,3,6,2,3,4,7,8]
    //  
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize)  return false;
        map<int, int> mp;
        for(int i: hand) mp[i]++;
        
        while(mp.size()){
            int start=mp.begin()->first;
            int temp=groupSize;
            
            if(mp.find(start) == mp.end()) continue;


            for(int s=start;s<start+temp;s++){
                if(mp.find(s) == mp.end()) return false;

                mp[s]--;
                if(mp[s]==0) mp.erase(s);
            }
        }

        return true;
   }
};