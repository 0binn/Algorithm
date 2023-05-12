#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    int length=s.length();
    if(length%2==0){
        //짝수
        answer=s[length/2-1];
        answer+=s[length/2];

    }
    else{
        //홀수
        answer=s[length/2];
    }
    return answer;
}