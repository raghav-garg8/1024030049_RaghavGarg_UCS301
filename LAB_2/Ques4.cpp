#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string concateStr(string str1 , string str2){
    return str1 + str2;
}
string reverseStr(string str1 ){
  
   return string(str1.rbegin(), str1.rend());
}



int main() {
    string str1 = "Raghav ";
    string str2 = "Garg";
    
    cout << "Concatenated string: " <<concateStr(str1,str2) << endl;
    cout << "Reverse string: " <<reverseStr(str1) << endl;
    
    return 0;
}
