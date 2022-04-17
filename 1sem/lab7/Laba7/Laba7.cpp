#include <string>
#include <stdio.h>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char s[256]; int n;
    cout << "Input string: " << endl;
    gets_s(s);
    n = strlen(s);
    int i = 0;

    while (i < n)
    {
        if (std::isdigit(s[i]) || s[i] == '-')
        {
            char ss[102];
            bool point = false;
            if (s[i] == '-') {
                ss[i] += s[i++];
            }
            while (true)
            {
                if (std::isdigit(s[i]))
                {
                    ss[i] += s[i++];
                }
                else if (s[i] == '.' && !point)
                {
                    ss[i] += s[i++];
                    point = true;
                }
                else
                {
                    puts(ss); cout << endl;
                    break;
                }
            }
        }
        else  i++;
    }
}
