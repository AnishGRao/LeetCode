#include <bits/stdc++.h>
using namespace std;

std::string sA,sB;
bool split(int beg1, int end1, int beg2, int end2){
    // DP base case--substring of size 1 vs substring of size n
    //if it is a substring of size one, just check if the positions match in the two strings 
    // if they do, then this means that you have found a valid split
    if (end1-beg1==1)
        return sA[beg1] == sB[beg2];
    //DP base case 2--if the substrings are not at least the same characters, theres no point in continuing
    //just return false
    //e.g. great rgeat |-> if we split after e, we have gre+at and rge+at, and gre and rge are possible permutes, so we can continue
    if(!std::is_permutation(sA.begin()+beg1, sA.begin()+end1, sB.begin()+beg2, sB.begin()+end2))
        return 0;
    //this is basically for every number from 1 to the current substring size, make substrings of all sizes
    //This is done by first making substring splits where the substrings are of size i starting at initial pos, then, substring of size end-begin-i
    //Then substring of size i and end-begin-i, etc. with all possible values beign taken and called recursively
    //if you think this sucks--you're right, it does.
    //Think of DP as fancy brute force--its literally brute force with a hint of recursion and a touch of basecases, and a great heaping spoonful of knowing the prior values.
    for (int i = 1; i<end1-beg1; i++)
        if((split(beg1, beg1 + i, beg2, beg2 + i) && split(beg1 + i, end1, beg2 + i, end2))||(split(beg1, beg1 + i, end2 - i, end2) && split(beg1 + i, end1, beg2, end2 - i)))
            return 1;
    return 0;
}

bool isScramble(string s1, string s2) {
    sA=s1,sB=s2;
    return split(0,sA.size(), 0, sB.size());
}

int main(){

}
