
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
string s;
int countn = 0;
int state = 0;
int point = 0;
int minus = 0;
cout << "Input string: " << endl;
getline(cin, s);
char m_ch[1000];
for (int i = 0; i < s.length()+1; i++) {
    m_ch[i] = s[i];
}
for (int i = 0; i < s.length(); i++) {
    state = 0;
    if ((m_ch[i] == '-' && isdigit(m_ch[i + 1])) || isdigit(m_ch[i])) {
        state = 1;
        if (isdigit(m_ch[i])) {
            cout << m_ch[i];
            if (m_ch[i + 1] == '.') {
                if (point == 0) {
                    point = 1;
                    cout << m_ch[i + 1];
                    i ++;
                    continue;
                }
            }
        }
        if (m_ch[i] == '-' && isdigit(m_ch[i + 1])) {
            if (minus == 0) {
                minus = 1;
                cout << m_ch[i];
                continue;
            }
        }
        if (i != s.length() - 1) {
            if (isdigit(m_ch[i]) && !isdigit(m_ch[i + 1])) {
                cout << endl;
            }
        }
    }
    else {
        point = 0;
        minus = 0;
    }
}
}