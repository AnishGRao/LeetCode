string intToRoman(int num)
{
    std::map<int, std::string> M;
    M[1] = "I";
    M[4] = "IV";
    M[5] = "V";
    M[9] = "IX";
    M[10] = "X";
    M[40] = "XL";
    M[50] = "L";
    M[90] = "XC";
    M[100] = "C";
    M[400] = "CD";
    M[500] = "D";
    M[900] = "CM";
    M[1000] = "M";
    std::string ret;
    auto s = M.begin();
    int i = 12;
    while (num > 0)
    {
        int x = num / (std::next(s, i)->first);
        num %= std::next(s, i)->first;
        while (x--)
            ret += std::next(s, i)->second;
        i--;
    }
    return ret;
}