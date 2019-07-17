#include <stdio.h>
int pow(int x,int n);
int main()
{
    int x,n;
    printf("\n enter x and n");
    scanf("%d %d",&x,&n);
    int res=pow(x,n);
    printf("\n The answer is %d",res);
}
int pow(int x,int n)
{
    int b;
    if(n==0)
        return 1;
    else
    {
        b=pow(x,n/2);
        if(n%2==0)
        {
            //b=pow(x,n/2);
            return(b*b);
        }

        else
        {
             //b=pow(x,n/2);
             return(x*b*b);
        }

    }
}
