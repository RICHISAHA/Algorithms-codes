#include <stdio.h>
#include <stdlib.h>
int move(int,char,char,char);
int main()
{
    int n;
    printf("Enter the number of rings.");
    scanf("%d",&n);
    int count=move(n,'A','B','C');
    //printf("\n The number of moves required is %d",count);
}
int move(int n,char source,char dest,char spare)
{
    int c=0;c++;
    if(n==1)
        {
            printf("\n Move %d disk from %c to %c",n,source,dest);
            c++;
        }
    else
    {
        move(n-1,source,spare,dest);//c++;
        printf("\n Move %d disk from %c to %c",n,source,dest);
        move(n-1,spare,dest,source);//c++;
    }
    return c;
}
