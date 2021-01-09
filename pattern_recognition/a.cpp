#include <bits/stdc++.h>
typedef double _d;
using namespace std;

std::string blob(std::string input){
    int smc_pos = input.find(';');
    //aa;ahhahah
    string find_Str = input.substr(0,smc_pos);
    //aa;ajklnsflaf|kjfnsdf
    //ajklnsflaf|kjfnsdf
    string restr = input.substr(smc_pos+1,input.size()-smc_pos-2);
    std::vector<int> numOcc;

    while(restr.find('|')!=std::string::npos){
        int pipe = restr.find('|');
        string cstr = restr.substr(0,pipe);
        int cOcc = 0;
        for (int i = 0; i<cstr.size() && i+find_Str.size()<=cstr.size(); i++){
            if (cstr.substr(i,find_Str.size())==find_Str)
                cOcc++;
        }
        numOcc.push_back(cOcc);
        restr=restr.substr(restr.find('|')+1,restr.size()-restr.find('|')+1);
    }
    int cOcc = 0;
    string cstr = restr;
    for (int i = 0; i<cstr.size() && i+find_Str.size()<cstr.size(); i++){
        if (cstr.substr(i,find_Str.size())==find_Str)
            cOcc++;

    }
    numOcc.push_back(cOcc);
    std::string ret="";
    int sum = 0;
    for (auto i : numOcc)
        sum+=i, ret+=to_string(i)+"|";
    ret+=to_string(sum);
    return ret;
}

int main()
{
    std::cout<<blob("aa;aaaakjlhaa|aaadsaaa|easaaad|sa");
}
