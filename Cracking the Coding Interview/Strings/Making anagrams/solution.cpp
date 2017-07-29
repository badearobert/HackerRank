#include <cmath>
#include <iostream>

using namespace std;

const int NR_OF_CHARS = 26;

int getInt(char c) { return c - 'a'; }

int number_needed(string a, string b) {
    int a_arr[NR_OF_CHARS] = { }; 
    int b_arr[NR_OF_CHARS] = { };
    for (const auto& i : a) { int index = getInt(i); a_arr[index]++; }
    for (const auto& i : b) { int index = getInt(i); b_arr[index]++; }
    
    int counter = 0;
    
    for (int i = 0; i < NR_OF_CHARS; ++i) {
        counter+= abs( a_arr[i] - b_arr[i] );
    }
   
    return counter;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
