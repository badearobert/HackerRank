#include <iostream>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) 
{
    unordered_map<string, unsigned int> hash = {};
    for (const auto & i : magazine) 
    {
        hash[i]++;
    }
    
    for (const auto & i : ransom) 
    {
        if (hash.find(i) == hash.end() || hash[i] == 0) 
        {
            return false;
        }
        hash[i]--; 
    }
    return true;
    
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++)
    {
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++)
    {
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
