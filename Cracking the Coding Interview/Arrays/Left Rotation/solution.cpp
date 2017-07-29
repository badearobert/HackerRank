vector<int> array_left_rotation(vector<int> a, int n, int k) {
    if (a.empty() ) return a;
    
    for (int i = 0; i < k; ++i) {
        auto item = a.front();
        a.erase(a.begin(), a.begin() +1);
        a.push_back(item);
    }
    return a;
}