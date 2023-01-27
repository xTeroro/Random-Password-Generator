#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
 
using namespace std;
 
int r;
int N;
int Vars[4] = {1,2,3,4},Lgt=4,poz=0;
 
char lCase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char uCase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char Numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
char Symbols[14] = {'!','<','>','@','#','$','%','^','&','*',';','(',')','.'};
char Special[500];
 
void lCGenerator()
{
    r = rand()%26;
    cout<<lCase[r];
}
 
void uCGenerator()
{
    r = rand()%26;
    cout<<uCase[r];
}

 
void nGenerator()
{
    r = rand()%10;
    cout<<Numbers[r];
}
 
void sGenerator()
{
    r = rand()%14;
    cout<<Symbols[r];
}
 
bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
        if(isdigit(str[i]) == false) 
            return false;
            return true; 
}

void Answer(string A,int p)
{
    string a;
    cout<<A;
    while(true)
    {
        cin>>a;
        if(a == "Y" || a == "y" || a == "N" || a == "n")
        {
            break;
        }else 
        {
            cout<<'\n'<<"Seems like the input was not quite correct. Try again."<<'\n'<<'\n';
            cout<<A;
        }
    }
    cout<<'\n'<<'\n';
    if(a == "Y" || a == "y")
    {
    }else if(a == "N" || a == "n")
    {
        for(int i = p; i < Lgt-1; i++)
        {
            Vars[i] = Vars[i+1];
        }
        Lgt--;
        poz++;
    }
}
 
void PGen(){
    cout<<'\n'<<"Here is your password : ";
    for(int i = 0; i < N; i++)
    {
        int choice = Vars[rand() % Lgt];
 
        if(choice == 1)
        lCGenerator();
 
        if(choice == 2)
        uCGenerator();
 
        if(choice == 3)
        nGenerator();
 
        if(choice == 4)
        sGenerator();
    }
    cout<<'\n'<<'\n'<<"If you want to generate a password again with the same settings press X : ";
    char a;
    while(true)
    {
        cin>>a;
        if(a == 'X' || a == 'x')
        {
            PGen();
        }else
        {
            abort();
        }
    }
}

int NumCheck(string ErrMsg, string Msg, int Min, int Max)
{
    string chk;
    while(true)
    {
        cin>>chk;
        if(!check_number(chk))
        {
            cout<<'\n'<<ErrMsg<<'\n';
            cout<<'\n'<<Msg;
        }else
        {
            N = stoi(chk);
            if(N > Min && N < Max)
            {
                break;
            }else{
                cout<<'\n'<<ErrMsg<<'\n';
                cout<<'\n'<<Msg;
            }
        }
        
    }
    return N;
}

int main()
{
    srand(time(NULL));
    cout<<"Welcome to the Random Password Generator!"<<'\n'<<'\n'<<"Lets start creating your password!"<<'\n'<<'\n';
 
    Answer("First, Should the Password contain lower case letters? Y/N for answer : ",0-poz);
    Answer("Second, Should the Password contain upper case letters? Y/N for answer : ",1-poz);
    Answer("Third, Should the Password contain numbers? Y/N for answer : ",2-poz);
    Answer("Fourth, Should the Password contain symbols? Y/N for answer : ",3-poz);
 
 
 
    cout<<"Finally! Last Question, How many characters should the password be made of? : ";

    NumCheck("Seems like the input was not quite correct. Try again with a number between 0 and 500","Finally! Last Question, How many characters should the password be made of? : ", 0, 500);

    PGen();

    return 0;
}
 