

using LInt = __int128;
ostream& operator<<(ostream&cout , LInt number){
    auto toString = [](LInt num){
        auto tenPow18 = 1000000000000000000;
        std::string str;
        do {
            long long digits = num % tenPow18;
            auto digitsStr = std::to_string(digits);
            auto leading0s = (digits != num) ? std::string(18 - digitsStr.length(), '0') : "";
            str = leading0s + digitsStr + str;
            num = (num - digits) / tenPow18;
        } while (num != 0);
        return str;
    };
    cout << toString(number);
    return cout;
}

istream& operator>>(istream&cin , LInt &number){
    string s; cin >> s; 
    number = 0;
    bool neg_flag =false;
    for(auto&itr:s){
        if(itr=='-'){
            neg_flag = true;
            continue;
        }
        number *= 10;
        number += (itr-'0');
    }
    if(neg_flag){
        number*=(-1);
    }
    return cin;
}


