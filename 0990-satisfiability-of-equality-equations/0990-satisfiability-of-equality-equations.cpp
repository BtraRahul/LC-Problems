class Solution {
public:
    // graph problem
    //1. a==b: Deal with == signs first, create edges bet a,b where a=b
    //2. a!=b: if there is an edge(direct/indirect), return false;

    // ["c==c","f!=a","f==b","b==c"]
    // c--c--b--f a => we can reach c from f(f->b->c) but we can never reach a
    //for every pair a!=b we have determine if a path exist or not

    bool pathExist(char src, char dest, map<char, vector<char>> edges){
        queue<char> q;
        q.push(src);

        map<char, int> vis;
        vis[src]=1;
        while(q.size()){
            char curr=q.front();
            q.pop();
            if(curr==dest) return true;

            for(char next: edges[curr]){
                if(vis[next]) continue;

                if(next==dest) return true;

                vis[next]=1;
                q.push(next);
            }
        }

        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        
        map<char, vector<char>> edges;

        for(string s: equations){
            if(s[1]=='!') continue;

            char a=s[0], b=s[3];

            if(a==b) continue;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        for(string s: equations){
            if(s[1]=='=') continue;

            char a=s[0], b=s[3];

            if(pathExist(a, b, edges)) return false;
        }

        return true;
        
    }
};