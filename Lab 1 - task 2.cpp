#include<iostream>
using namespace std;

void encode(string s,int j)
{
    for(int i=j; s[i]!= '\0'; i+=j+1)
    {
        {
            s[i] = s[i] + 2;
        }
    }
    cout<<s;
}
int main ()
{
    encode("I am a student",2);
}
