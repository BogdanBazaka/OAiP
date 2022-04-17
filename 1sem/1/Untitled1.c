#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    std::string s;
    int count = 0;
    char m_ch[1000];
    char reverse_m_ch[1000];
    std::cout << "Input string: " << std::endl;
    std::getline(std::cin, s);

    for (int j = 0; j < s.length(); j++) {
        m_ch[j] = s[j];
    }
    int i = 0;
    while (i < s.length())
    {
        if (isdigit(m_ch[i]) || (m_ch[i] == '-' && isdigit(m_ch[i + 1])))
        {
            count = 0;
            bool point = false;
            bool Minus = false;
            if ((m_ch[i] == '-') && (isdigit(m_ch[i + 1])) && (!Minus)) {
                reverse_m_ch[count] = m_ch[i];
                Minus = true;
                count++;
                i++;
            }
            while (true)
            {
                if (isdigit(m_ch[i]))
                {
                    reverse_m_ch[count] = m_ch[i];
                    count++;
                    i++;
                }
                else if ((m_ch[i] == '.') && (!point) && (isdigit(m_ch[i + 1])))
                {
                    reverse_m_ch[count] = m_ch[i];
                    count++;
                    i++;
                    point = true;
                }
                else
                {
                    for (int p = 0; p < count; p++) {
                        cout << reverse_m_ch[p];
                    }
                    cout << endl;
                    count = 0;
                    break;
                }
            }
        }
        else  i++;
    }
}

