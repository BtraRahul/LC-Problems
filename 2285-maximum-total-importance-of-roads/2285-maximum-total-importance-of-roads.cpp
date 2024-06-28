class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> indegree(n, 0);

        for (auto p : roads) {
            indegree[p[0]]++, indegree[p[1]]++;
        }

        sort(indegree.rbegin(), indegree.rend());

        long long sum = 0;

        for (long long e : indegree)
            sum += (long long)(n--) * e;

        return sum;
    }
};