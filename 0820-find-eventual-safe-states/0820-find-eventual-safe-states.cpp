class Solution {
public:
    //do a topological sort, but keep track of outdegree, if outdegree is 0, mark it as safe
    //after that reduce outdegree of all the nodes that lead to that safe node
    vector<vector<int>> makeGraph(vector<int>& indegree, vector<int>& outdegree, vector<vector<int>>& graph){

        int n=graph.size();

        vector<vector<int>> fromGraph(n);

        for(int i=0;i<n;i++){
            for(int node: graph[i]){
                indegree[node]++;
                outdegree[i]++;

                fromGraph[node].push_back(i);
            }
        }


        return fromGraph;
    }

    vector<int> topoSort(vector<int>& indegre, vector<int>& outdegree, vector<vector<int>> & fromGraph){
        int n=fromGraph.size();

        //maintain all nodes with outdegree==0, i.e they are the terminal/safe nodes;
        vector<int> safeNodes;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdegree[i] == 0) {
                q.push(i);
                safeNodes.push_back(i);
            }
        }


        while(q.size()){
            int curr=q.front(); q.pop();

            for(int node: fromGraph[curr]){
                outdegree[node]--;

                if(outdegree[node] == 0){
                    safeNodes.push_back(node);
                    q.push(node);
                }
            }
        }

        return safeNodes;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> indegree(n,0), outdegree(n, 0);

        //fromGraph a[5]=2  means there is an edge from 2->5
        vector<vector<int>> fromGraph=makeGraph(indegree, outdegree, graph);

        vector<int> ans=topoSort(indegree, outdegree, fromGraph);

        sort(ans.begin(), ans.end());

        return ans;
        
    }
};