#include<iostream>
using namespace std;
class passlab
{
    string pass, re_pass;
    int len,st;
public:
    void login()
    {
        cout<<" Please Type Password :";
        getline(cin, pass);
        cout<<"  Please Retype Password :";
        getline(cin, re_pass);
        check();
    }
    void check ()
    {
        int up = 0, low = 0, sc_1 = 0, sc_2 = 0, sc_3 = 0;
        len = pass.size();

        if (pass != re_pass)
        {
            cout << "\tPassword mismatch!.Try again please.\n ";
            login();
        }
        else
        {

            for (int i = 0; i < len; i++)
            {
                if (pass[i] >= 65 && pass[i] <= 90)
                {
                    up++;
                }
                else if (pass[i] >= 97 && pass[i] <= 122)
                {
                    low++;
                }
                else if (pass[i] == '#')
                {
                    sc_1++;
                }
                else if (pass[i] == '$')
                {
                    sc_2++;
                }
                else if (pass[i] == '&')
                {
                    sc_3++;
                }
            }
            st = sc_1 + sc_2 + sc_3;

            if (pass.size()<8)
            {
                cout << "\tMinimum 8 character needed!.Try again please.\n ";
                login();
            }
            else if ( up == 0 || low == 0 || (st == 0))
            {
                cout << "\tWeak Password. ";
            }
            else if (up > 0 && low > 0 && (st == 1))
            {
                cout << "\tMedium Password.";
            }
            else if ((sc_1 > 0 && sc_2 > 0) || (sc_2 > 0 && sc_3 > 0) || (sc_1 > 0 && sc_3 > 0))
            {
                cout << "\tStrong Password.";
            }
        }
    }
};
int main()
{
    passlab p;
    p.login();
}

