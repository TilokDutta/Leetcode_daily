class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> s(wordList.begin(),wordList.end());
        set<string> vis;
        vis.insert(beginWord);
        q.push({beginWord,1});
        int ans=0;
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endWord){
                ans = level;
                break;
            }
            for(int i = 0; i < word.size(); i++){
                for(char c = 'a'; c <= 'z'; c++){
                    string nWord = word;
                    nWord[i] = c;
                    if(!vis.count(nWord) && s.count(nWord)){
                        q.push({nWord,level+1});
                        vis.insert(nWord);
                    }
                }
            }
        }
        return ans;
    }
};