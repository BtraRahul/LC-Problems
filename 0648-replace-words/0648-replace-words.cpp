class Solution {
public:
    string newWord(string curr, vector<string>& dictionary) {
        for (auto d : dictionary) {
            if (curr.substr(0, d.size()) == d) {
                return d;
            }
        }

        return curr;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string word;

        string newSent;

        while (getline(ss, word, ' '))
            newSent += newWord(word, dictionary) + ' ';

        newSent.pop_back();
        return newSent;
    }
};