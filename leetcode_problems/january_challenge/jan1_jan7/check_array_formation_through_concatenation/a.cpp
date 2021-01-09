#include <bits/stdc++.h>
typedef double _d;
using namespace std;
/*
 *
 *      82/82 test cases passed
 *      8ms runtime
 *      10.6 MB memory usage.
 *
 *
 *
 *
*/
bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
    std::sort(pieces.begin(), pieces.end(), 
            [](const std::vector<int>&a, const std::vector<int>&b){
                return a.size()>b.size();
            });
    //take every slice in pieces
    for (auto piece : pieces){
        //if founds solo dolo
        if (piece.size()==1){
            auto found = std::find(arr.begin(),arr.end(),piece[0]);
            if (found != arr.end()){
                arr.erase(found);
            }
            else
                return false;
            //TODO check if this is a valid exfound case for quick finish
        }

        //if founds all paired up wfoundh one or more other int
        else{
            auto found = std::find(std::begin(arr), std::end(arr), piece[0]);
            if (found == arr.end()){
                //same TODO as before
                return false;
            }
            else{
                for (int i = 1; i<piece.size(); i++)
                    if (*(found+i)!=piece[i])
                        return false;
                    
                for (int i = 0; i<piece.size(); i++)
                    arr.erase(found);
            }
        }
    }
    return arr.size()==0;

}
int main() {
    vector<int> tA = {1,2,3};
    vector<vector<int>> tP = {{2}, {1,3}};
    std::cout << canFormArray(tA,tP)<<"\n";
}
