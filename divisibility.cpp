// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

//STACK OVERFLOW LINK: https://stackoverflow.com/a/65515273

char randomChar(){
    int iSecret;

  /* generate secret number between 97 and 122, inclusive: */
  iSecret = rand() % 26 + 97;

    return (char) iSecret;
}

string randomPattern(int len) {
    string s = "";
    vector<bool> seen(26, false);

    while (len) {
        s+= randomChar();
        --len;
    }

    for (const char& c : s) {
        seen[c - 'a'] = true;
    }

    for (int i = 0; i != 26; ++i) {
        if (!seen[i]) {
            return s + (char) (i + 97);
        }
    }

    return s + randomChar();
}

string word(const string& pat, int len) {
    string s = pat;
    while (len) {
        s+= pat;
        --len;
    }

    return s;
}

int randomNumber(int max) {
    return rand() % max + 1;
}


bool isConcat(const string& s, const string& t)
{
    int start = 0, size = s.size(), tSize = t.size();

    if (size % tSize != 0)
        return false;

    int curr, end = 0;
    while (end < size)
    {
        curr = 0;
        end = start + tSize;

        while (start + curr < end)
        {
            if (s[start + curr] != t[curr])
            {
                return false;
            }
            curr++;
        }
        start = end;
    }

    return true;
}

string getValidPrefix(const string& str)
{
    vector<int> lps(str.length(),0);
      int i=1;
      int len=0;

      while(i<str.length()){
          if(str[i] == str[len]){
              len++;
              lps[i] = len;
              i++;
          }
          else{
              if(len == 0) i++;
              else{
                  len = lps[len-1];
              }
          }
      }
      int n=str.length();
      int x = lps[n-1];
      if(n%(n-x) == 0){
          return str.substr(0,n-x);    
      }
      return str;
}

string getValidPrefixBrute(const string& s) {

    for (int i = 0; i != s.size(); ++i) {
        string pattern = s.substr(0, i + 1);
        if (isConcat(s, pattern)) {
            return pattern;
        }
    }
}

int getDivisibility(const string& s, const string& t)
{
    bool isValid = isConcat(s, t);
    if (!isValid)
        return -1;

    string validPrefix = getValidPrefix(t);
    cout << "prefix " << validPrefix << endl;

    int ans = validPrefix.size();
    return ans;
}

// int getDivisibilityBrute(const string& s, const string& t)
// {
//     bool isValid = isConcat(s, t);
//     if (!isValid)
//         return -1;

//     string validPrefix = getValidPrefixBrute(t);
//     cout << "prefix " << validPrefix << endl;

//     int ans = validPrefix.size();
//     return ans;
// }

int main()
{
    // Write C++ code here

    int RUNNING = 100000;
    srand (time(0));

    while (RUNNING) {
        string pattern = randomPattern(randomNumber(8));
        int s_len = randomNumber(10);
        // int t_len = randomNumber(s_len);
        string s = word(pattern, s_len);
        // string t = word(pattern, t_len);
        cout << "S = " << s << endl;
        // cout << "T = " << t < <endl;
        string optimized = getValidPrefix(s);
        if (optimized != pattern) {
            cout << "\n\nERROR FOUND!!!!!!!!!!!!!!\n\n";
            cout << "optimized = " << optimized << endl;
            cout << "pattern = " << pattern << endl;
            break;
        }
        --RUNNING;
    }

    // cout << getValidPrefix("aaxxxaaaaxxxaa") << endl;

    return 0;
}
