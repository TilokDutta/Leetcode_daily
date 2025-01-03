class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0, cows = 0;
        unordered_map<char, int> mp;

        // First pass: Count frequencies in secret and identify bulls
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                mp[secret[i]]++;
            }
        }

        // Second pass: Identify cows
        for (int i = 0; i < n; i++) {
            if (secret[i] != guess[i] && mp[guess[i]] > 0) {
                cows++;
                mp[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
