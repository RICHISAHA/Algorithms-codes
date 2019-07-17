#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
int main()
{
    srand(time(NULL));
    FILE *f1,*f2,*f3;
    int i,j=MAX-1;
    f1=fopen("ascending.txt","w+");
    f2=fopen("descending.txt","w+");
    f3=fopen("random.txt","w+");
    for(i=0;i<MAX;i++)
    {
        putw(i,f1);
        putw(j,f2);j--;
        putw(rand()%MAX,f3);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    i=0;int a;
    int arr[MAX],a1[MAX],b1[MAX];
    f1=fopen("ascending.txt","r+");
    while((a=getw(f1))!=EOF)
    {
        arr[i]=a;
        i++;
    }
    fclose(f1);i=0;
    f2=fopen("descending.txt","r+");
    while((a=getw(f2))!=EOF)
    {
        a1[i]=a;
        i++;
    }
    fclose(f2);i=0;
    f3=fopen("random.txt","r+");
    while((a=getw(f3))!=EOF)
    {
        b1[i]=a;
        i++;
    }
    fclose(f3);i=0;
    int value;
    while(1)
    {
    printf("Pivot -1,2,3, 1-first element, 2-middle, 3-end.");
    scanf("\n %d",&value);
    if(value==1)
    {
        printf("\n Ascending :");
        time_t start,stop;
        start=clock();
        quickSort1(arr,0,MAX-1);
        stop=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);

        printf("\n Descending");
        time_t start2,stop2;
        start2=clock();
        quickSort1(a1,0,MAX-1);
        stop2=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);

        printf("\n Random");
        time_t start3,stop3;
        start3=clock();
        quickSort1(b1,0,MAX-1);
        stop3=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);
    }
    else if(value==2)
    {
        printf("\n Ascending :");
        time_t start,stop;
        start=clock();
        quickSort2(arr,0,MAX-1);
        stop=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);

        printf("\n Descending");
        time_t start2,stop2;
        start2=clock();
        quickSort2(a1,0,MAX-1);
        stop2=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);

        printf("\n Random");
        time_t start3,stop3;
        start3=clock();
        quickSort2(b1,0,MAX-1);
        stop3=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);
    }
    else if(value==3)
    {
    printf("\n Ascending :");
        time_t start,stop;
        start=clock();
        quickSort3(arr,0,MAX-1);
        stop=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);

        printf("\n Descending");
        time_t start2,stop2;
        start2=clock();
        quickSort3(a1,0,MAX-1);
        stop2=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);

        printf("\n Random");
        time_t start3,stop3;
        start3=clock();
        quickSort3(b1,0,MAX-1);
        stop3=clock();
        printf("% lf ",(double)(stop-start)/CLOCKS_PER_SEC);
    }
        else
        exit(0);
    }
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition1 (int arr[], int low, int high)
{
    int pivot = arr[low];    // pivot
    int i,j;
    i=j=low+1;  // Index of smaller element

    while(j<=high)
    {
        if (arr[j] <pivot)
        {
           swap(&arr[i], &arr[j]);
            i+=1;
        }
        j+=1;
    }
    swap(&arr[low], &arr[i-1]);
    return (i - 1);
}
int partition3 (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
    int j;
    for(j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int partition2 (int arr[], int low, int high)
{

    int pivot = arr[(low+high)/2];
    int i,j;
    i= low;  // Index of smaller element
    j=high;
    while(i>=j)
    {
        if (arr[i] > pivot && arr[j]<pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    return (i + 1);
}
void quickSort1(int arr[], int low, int high)
{

           if (low < high)
    {
        int pi = partition1(arr, low, high);
        quickSort1(arr, low, pi - 1);
        quickSort1(arr, pi + 1, high);
    }
}
void quickSort2(int arr[], int low, int high)
{

           if (low < high)
    {
        int pi = partition2(arr, low, high);
        quickSort2(arr, low, pi - 1);
        quickSort2(arr, pi + 1, high);
    }
}
void quickSort3(int arr[], int low, int high)
{

           if (low < high)
    {
       int pi = partition3(arr, low, high);
        quickSort3(arr, low, pi - 1);
        quickSort3(arr, pi + 1, high);
    }
}
