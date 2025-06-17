class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int, int> depthLen;
        depthLen[0] = 0;
        int maxLen = 0;

        stringstream ss(input);
        string line;
        while (getline(ss, line, '\n')) {
            int depth = 0;
            while (line[depth] == '\t') depth++;  // count depth

            string name = line.substr(depth);     // get actual name

            if (name.find('.') != string::npos) { // it's a file
                maxLen = max(maxLen, depthLen[depth] + (int)name.length());
            } else {                              // it's a directory
                depthLen[depth + 1] = depthLen[depth] + name.length() + 1;
            }
        }

        return maxLen;
    }
};
