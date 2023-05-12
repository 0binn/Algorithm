#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int remain;
    for(int x=2;x<n;x++){
        remain=n%x;
        if(remain==1){
            answer=x;
            break;
        }
    }
    return answer;
}