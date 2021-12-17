vector<string> split(string s, string del = " ")
{
    vector<string> tokens;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        tokens.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    tokens.push_back(s.substr(start, end - start));
    return tokens;
}
