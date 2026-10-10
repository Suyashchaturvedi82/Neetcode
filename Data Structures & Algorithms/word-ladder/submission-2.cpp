class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If the target word isn't even in the dictionary, no path exists
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        // Queue stores pairs of {current_word, current_path_length}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while (!q.empty()) {
            string word = q.front().first;
            int length = q.front().second;
            q.pop();
            
            // Try changing each character of the word one by one
            for (int i = 0; i < word.length(); i++) {
                char original_char = word[i];
                
                // Replace the character with every letter from 'a' to 'z'
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    
                    // If we found the target word, return the total length
                    if (word == endWord) {
                        return length + 1;
                    }
                    
                    // If the mutated word is in our dictionary, add it to the queue
                    if (dict.find(word) != dict.end()) {
                        q.push({word, length + 1});
                        dict.erase(word); // Remove to prevent cycles
                    }
                }
                
                // Restore the original character before moving to the next position
                word[i] = original_char;
            }
        }
        
        return 0; // No valid transformation sequence found
    }
};