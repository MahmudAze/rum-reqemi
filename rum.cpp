#include <bits/stdc++.h>
using namespace std;

// Rum ededden 10-luqa ceviren funksiya
int romanToInt(string& setir)   // setiri input kimi goturur
{
    int num = 0;    // rum ededden 10 luqa cevirmek toplanmaq ucun sifirdan baslayir

    // yeni map lugeti yaradiriq
    map <char, int> m;
    m['M'] = 1000;
    m['D'] = 500;
    m['C'] = 100;
    m['L'] = 50;
    m['X'] = 10;
    m['V'] = 5;
    m['I'] = 1;

    // rum setirde bir-bir num deyisenine toplamaq ucun yeni dovr yaradiriq
    for (int i = 0; i < setir.length(); i++)
    {
        // eger ikinci herf birinci herfden boyukdurse, cixilir. Mes. IV -> num += 4-3
        if (m[setir[i]] < m[setir[i+1]])
        {
            num += m[setir[i+1]] - m[setir[i]];
            i++; //bu continue kimi yeni ikinci novbetiye kecir

        }
        else
        {
            num += m[setir[i]];
        }
    }

    // axirda num deyiseni tapdiqdan sonra return edirik
    return num;
};

string intToRoman(int number)
{
    string m[] = { "", "M", "MM", "MMM", "MMMM" };
    string c[] = { "", "C", "CC", "CCC", "CD", "D",
                    "DC", "DCC", "DCCC", "CM" };

    string x[] = { "", "X", "XX", "XXX", "XL", "L",
                    "LX", "LXX", "LXXX", "XC" };

    string i[] = { "", "I", "II", "III", "IV", "V",
                    "VI", "VII", "VIII", "IX" };

    // converting to Roman
    string thousands = m[number / 1000];
    string hundreds = c[(number % 1000) / 100];
    string tens = x[(number % 100) / 10];
    string ones = i[number % 10];

    string ans = thousands + hundreds + tens + ones;

    return ans;
};

int main()
{
    cout << "Rum reqemi edede cevirir:" << endl;
    cout << "Meselen:" << endl;
    cout << "CIX  --->>>  109" << endl;
    cout << "I - 1" << endl;
    cout << "V - 5" << endl;
    cout << "X - 10" << endl;
    cout << "L - 50" << endl;
    cout << "C - 100" << endl;
    cout << "M - 1000" << endl;
    cout << "Rum reqemi daxil edin:" << endl;
    string s;

    cin >> s;

    int n = s.length();

    int x = s.find("+");

    string r1 = s.substr(0, x);
    string r2 = s.substr(x+1, n);

    int a = romanToInt(r1);
    int b = romanToInt(r2);

    int cem = a + b;

    string setir = to_string(a) + " + " + to_string(b) + " = ?";

    cout << setir << endl;
    cout << cem << endl;
    cout << s << " = ";
    cout << intToRoman(cem) << endl;
}
