#include<iostream>
using namespace std;
class infix
{
    public:
    int infi[12]={0};
    int top=(-1);

   bool isEmpty()
    {
        if(top==(-1))
        {
            return true;

        }
        else
            return false;
    }

    void Push(char B)
    {
        top++;
        infi[top]=B;
    }
    char Pop()
    {
        char temp = infi[top];
        infi[top] = 0;
        top--;
    }
    void Print()
    {
        for(int i=0;i<12;i++)
        {
            cout << infi[i] << endl;
        }
    }

};
int prec(char A)
{
    if(A=='^')
    {
        return 3;

    }
    else if(A=='*'||A=='/')
    {
        return 2;
    }
    else if(A=='+' || A=='-')
    {
        return 1;
    }
}
int main()
{
    infix s1;
    int a=1,b=2,c=3;
    char arr[12]={a+b *c^a+b/a};
    for(int i=0;i<12;i++)
    {
        if((arr[i]>='a' && arr[i] <= 'z') || arr[i] >= 'A' && arr[i] <= 'Z');
        {
            s1.Push(arr[i]);
        }
        else if(arr[i]=='('  || arr[i]=='['  ||  arr[i]=='{')
                {
                  s1.Push(arr[i]);
                }
                else if
                    {
                        if(arr[i]==')'  || arr[i]==']'  ||  arr[i]=='}')
                        {
                            if(arr[i]=='(')
                            {
                                while(s1.infi[s1.top]!='(')
                                {
                                    s1.Pop();
                                }
                                s1.Pop();
                            }
                            else if(arr[i]==']')
                            {
                                while(s1.infi[s1.top]!='[')
                                {
                                    s1.Pop();
                                }
                                s1.Pop();
                            }
                            else if(arr[i]=='}')
                            {
                                while(s1.infi[s1.top]!='{')
                                {
                                    s1.Pop();
                                }
                                s1.Pop();
                            }


                        }
                        else if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/' || arr[i]=='^')
                        {
                            if(prec(arr[i]) >= prec(s1.infi[s1.top]))
                            {
                                s1.Push(arr[i]);
                            }
                            else
                            {
                                while(prec(arr[i]) >= prec(s1.infi[s1.top]) )
                                {
                                    s1.Pop();
                                }
                                s1.Push(arr[i]);
                            }
                        }

                    }

     }

    }
    if(s1.top==(-1))
    {
        s1.Print();
    }
}
