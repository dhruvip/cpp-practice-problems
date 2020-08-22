// Your First C++ Program

#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
int main() {
    std::cout << "Hello World!" << std::endl;
    std::unordered_set<std::string> myset = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};
    std::cout << "myset contains:" << std::endl;
    for ( auto it = myset.begin(); it != myset.end(); ++it )
        std::cout << " " << *it;
    std::cout << *(myset.find("Pop"))<< std::endl;
    std::cout << std::endl;
    return 0;
}
