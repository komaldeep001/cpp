#include<iostream>
#include<string>
using namespace std;
class Stack{
    public:
char arr[6]={0};
int top = (-1);

bool isEmpty()
{
    if(top==(-1))
    {
        return true;
    }
    else
    {
       return false;
    }
}
void push(char symb)
{
    top++;
    arr[top]=symb;
}
char pop()
{
    char temp;
    temp = arr[top];
    arr[top]=0;
    top--;
    return temp;
}
};

int main()
{
    Stack s1;
   char str[]="([{}])";

   int flag=0;
   for(int i=0;i<6;i++)
   {
       if(str[i]=='('||str[i]=='{'||str[i]=='[')
        {
            s1.push(str[i]);
        }
        else
        {
                 if(str[i]==')'||str[i]=='}' || str[i]==']')
        {
            if(s1.isEmpty())
            {
                cout << "unbalanced" <<endl ;
                return 0;
            }
            else
            {
                char symbol= s1.pop();
                if((str[i]==')' && symbol=='(')  ||  (str[i]=='}' && symbol=='{') ||  (str[i]==']' && symbol=='[') )
                    {
                        flag=1;
                        continue;
                    }
                    else
                    {
                        cout <<" Unbalanced" <<endl;
                        return 0;
                    }

            }
        }
        }

   }
   if(s1.isEmpty() && flag==1)
   {
       cout << "It is balanced" << endl;
   }
   else
   {
       cout << "unbalanced" <<endl;
   }

}

