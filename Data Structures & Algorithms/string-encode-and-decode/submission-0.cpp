class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string& str: strs){
            encoded_string += (std::format("{:03}",str.size()));
            encoded_string += str;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0;
        int len = 0;
        while(i < s.size()){
            len = std::stoi(s.substr(i, 3));
            i += 3;
            decoded_strs.push_back(s.substr(i, len));
            i+=len;
        }
        return decoded_strs;
    }
};
