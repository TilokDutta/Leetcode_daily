class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freqMap;

        // Count frequencies of each word
        for (const auto& word : words) {
            freqMap[word]++;
        }

        vector<string> uniqueWords;
        for (const auto& entry : freqMap) {
            uniqueWords.push_back(entry.first);
        }

        sort(uniqueWords.begin(), uniqueWords.end(), [&](const string& a, const string& b) {
            if (freqMap[a] == freqMap[b]) {
                return a < b;
            }
            return freqMap[a] > freqMap[b]; 
        });
        return vector<string>(uniqueWords.begin(), uniqueWords.begin() + k);
    }
};
