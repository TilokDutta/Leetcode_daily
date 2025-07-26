class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(),bank.end());
        set<string> vis;
        queue<pair<string,int>> q;
        q.push({startGene,0});
        vis.insert(startGene);
        int res = -1;
        char alpha[] = {'A','C','G','T'};
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            if(word == endGene){
                res = level;
                break;
            }
            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 4; j++){
                    string newWord = word;
                    newWord[i] = alpha[j];
                    if(!vis.count(newWord) && st.count(newWord)){
                        q.push({newWord,level+1});
                        vis.insert(newWord);
                    }
                }
            }
        }
        return res;
    }
};