#define pdpii pair<double, pair<int, int>>
class Solution {
    double dist(int i, int j) { return sqrt(i * i + j * j); }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pdpii> pq;

        for (vector<int>& coor : points) {
            int x = coor[0], y = coor[1];
            double dis = dist(x, y);
            pq.push({dis, {x, y}});
            // cout << dis << " ";
            if (pq.size() > k)
                pq.pop();
        }

        // while (pq.size() > k)
        //     pq.pop();

        vector<vector<int>> ans;
        while (pq.size()) {
            auto t = pq.top();
            cout << t.first << " ";
            pq.pop();
            int x = t.second.first;
            int y = t.second.second;
            ans.push_back({x, y});
        }

        return ans;
    }
};

// 41, 61, 52