#include <iostream>
#include <fstream>
#include<string>
using namespace std;

string lowercase (string s)
{
    char upercase[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char lowercase[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (int i=0;i<s.length();i++)
    {
        for (int j=0;j<26;j++)
        {
            if (s[i]==upercase[j])
                s[i]=lowercase[j];
        }
    }
    return s;
}

string last(string s)
{
    char st1[s.length()-1];
    string st = st1;
    char sy[29]={'!','"','#','%','@','`','~','^','*','(',')','_','-','=','+','{','}','[',']',';',':','/','?','>','.','<',',','’','|'};
    for (int i=0;i<29;i++)
    {
        if (s[s.length()-1]==sy[i])
        {
            for (int j=0;j<s.length()-1;j++)
            {
                st[j]=s[j];
            }
            return st;
            break;
        }
    }
    return s;
}

string Relative_test (double n)
{
    if (n<15)
         return"not spam";
    else if (n>=15&&n<50)
         return"maybe spam";
    else if (n>=50)
         return"definitely spam";
}

string Spam_test (int n)
{
    if (n<10)
        return "not spam";
    else if (n>=10&&n<50)
         return"maybe spam";
    else if (n>=50)
         return"definitely spam";
}

int Total_score(string arr[],int n)
{
    int score = 0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]=="$")
            score+=10;
        else if ((arr[i]=="earn")&&(arr[i+1]=="per")&&(arr[i+2]=="week"))
            score+=20;
        else if ((arr[i]=="double")&&(arr[i+1]=="your"))
        {
            score+=20;
            i++;
        }
        else if ((arr[i]=="income")&&(arr[i+1]=="in")&&(arr[i]=="one")&&(arr[i+1]=="week"))
            score+=15;
        else if ((arr[i]=="trial")&&(arr[i+1]=="that")&&(arr[i]=="lasts")&&(arr[i+1]=="forever"))
            score+=30;
        else if (arr[i]=="opportunity")
            score+=10;
        else if (arr[i]=="income")
            score+=10;
        else if (arr[i]=="cash")
            score+=20;
        else if ((arr[i]=="month")&&(arr[i+1]=="free")&&(arr[i+2]=="trial"))
        {
            score+=15;
            i+=2;
        }
        else if ((arr[i]=="your")&&(arr[i+1]=="love")&&(arr[i+2]=="life"))
            score+=25;
    }
    return score;
}
int Tot_num(string arr[],int n)
{
    int num = 0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]=="$")
            num++;
        else if ((arr[i]=="earn")&&(arr[i+1]=="per")&&(arr[i+2]=="week"))
            num+=3;
        else if ((arr[i]=="double")&&(arr[i+1]=="your"))
            num+=2;
        else if ((arr[i]=="income")&&(arr[i+1]=="in")&&(arr[i]=="one")&&(arr[i+1]=="week"))
            num+=4;
        else if ((arr[i]=="trial")&&(arr[i+1]=="that")&&(arr[i]=="lasts")&&(arr[i+1]=="forever"))
            num+=4;
        else if (arr[i]=="opportunity")
            num++;
        else if (arr[i]=="income")
            num++;
        else if (arr[i]=="cash")
            num++;
        else if ((arr[i]=="month")&&(arr[i+1]=="free")&&(arr[i+2]=="trial"))
            num+=3;
        else if ((arr[i]=="your")&&(arr[i+1]=="love")&&(arr[i+2]=="life"))
            num+=3;
    }
    return num;
}
string Spelling_mistakes(string a)
{
    if (a=="$$")
        {
            a="$";
            return a;
        }
    string b[17]={"earn","per","week","double","your","income","one","trial","that","lasts","forever","opportunity","cash","month","free","love","life"};
    for (int k=0;k<17;k++)
    {
        int l1=0;
        int l2=0;
        int l3=0;
        int l=0;
        int maxi = max(a.length(),b[k].length());
        for (int i=0;i<maxi;i++)
        {
            if (a[i]==b[k][i])
                continue;
            l1++;
            l2++;
            l3++;
            for (int j=i;j<(b[k].length())-1;j++)
            {
                if (a[j]==b[k][j+1])
                    continue;
                l1++;
            }
            for (int j=i;j<b[k].length();j++)
            {
                if (a[j+1]==b[k][j])
                    continue;
                l2++;
            }
            for (int j=i;j<(b[k].length())-1;j++)
            {
                if (a[j+1]==b[k][j+1])
                    continue;
                l3++;
            }
            l=min(min(l1,l2),l3);
            break;
        }
        if (l==1)
        {
            a=b[k];
            break;
        }
    }
        return a;
}
int main()
{
    int words;
    ifstream file ("mail.txt");
    int n=500;
    string mail[n];
    for (int i=0 ; i<n ; i++)
    {
        file>> mail[i];
        if (mail[i]=="")
        {
           words=i;
           break;
        }
        mail[i]=last(mail[i]);
        mail[i]=lowercase(mail[i]);
        mail[i]=Spelling_mistakes(mail[i]);
    }
    file.close();
    ofstream result("result.txt");
    result<<"total score is "<<Total_score(mail,words)<<endl;
    result<<"result using score is "<<Spam_test(Total_score(mail,words))<<endl;
    float num=Tot_num(mail,words)*1.0;
    float relative=(num/(words*1.0))*100;
    result<<"relative spam is "<<relative<<"%"<<endl;
    result<<"relative spam is "<<Relative_test(relative)<<endl;
    result.close();
    return 0;
}
