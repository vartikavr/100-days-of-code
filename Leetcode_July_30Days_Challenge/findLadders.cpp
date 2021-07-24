/*BFS + DFS

Time : O(26*l*n + VE)  => (26*l*n) for BFS, VE for DFS
where, 
n : number of words
l : length of word 
V : vertices
E : edges
Solution explanation : https://www.youtube.com/watch?v=mIZJIuMpI2M
*/

class Solution {
public:
    vector<vector<string>> res;
   void DFS(string beginWord, string endWord, unordered_map<string, unordered_set<string>> &adjList, vector<string> &path)
    {
        path.push_back(beginWord);
        if( beginWord == endWord)
        {
            res.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x: adjList[beginWord])
        {
            DFS(x, endWord, adjList, path);
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> adjList;
        unordered_map<string, int> visited;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        visited[beginWord] = 0;
        while(!todo.empty())
        {
            string original = todo.front();
            todo.pop();
            string explore = original;
            for(int j=0;j<original.length();j++)
            {
                for(int k=0;k<26;k++)
                {
                    char temp = 'a'+ k;
                    if(temp == original[j]) //same word
                        continue;
                    explore[j] = temp;
                    if(dict.find(explore)!=dict.end()){
                        if(visited.count(explore) == 0) //not visited
                        {
                            visited[explore] = visited[original] + 1;
                            todo.push(explore);
                            adjList[original].insert(explore);
                        }
                        else if(visited[explore] == visited[original]+1) //already visited and is child
                        {
                            adjList[original].insert(explore);
                        }
                    }
                }
                explore[j] = original[j];
            }
        }
        vector<string> path;
        DFS(beginWord, endWord, adjList, path);
        return res;
    }
};