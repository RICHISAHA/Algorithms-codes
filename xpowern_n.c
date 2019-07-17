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
    if(n==0)
        return 1;
    else
    {
        if(n%2==0)
            return(pow(x,n/2)*pow(x,n/2));
        else
            return(x*pow(x,n/2)*pow(x,n/2));
    }
}
