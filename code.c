

#include <stdio.h>
 
int min(int a,int b)
{
    if(a<b)
        return a;
    else
        return b;
}
 
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
 
 
void swap(int A[],int i,int j)
{
    int temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}
 
void quick_sort(int A[],int left,int right)
{
    int mid=(left+right)/2;
    int i=left,j=right,val=A[mid];
    do
    {
        while (A[i] < val)
            i++;
        while (A[j] > val)
            j--;
        if (i <= j)
        {
            swap(A, i, j);
            i++;
            j--;
        }
    } while (i <= j);
 
    if (i < right)
        quick_sort(A, i, right);
    if (left < j)
        quick_sort(A, left, j);
}
 
void main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int cost[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &cost[i]);
        quick_sort(cost, 0, n - 1);
 
        long total = 0, i = n - 1;
        while (i > 2)
        {
            
            int cost1 = cost[i] + cost[0] + cost[i - 1] + cost[0];
            int cost2 = cost[1] + cost[0] + cost[i] + cost[1];
            total += min(cost1, cost2);
            i -= 2;
        }
        if (i == 2)
            total += (cost[0] + cost[1] + cost[2]);
        else if (i == 1)
            total += max(cost[0], cost[1]);
        else
            total += cost[0];
        printf("%ld\n", total);
    }
}


