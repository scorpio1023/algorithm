#include <stdio.h>

int a[6] = {-2, 11, -4, 13, -5, -2};

//简单算法
static
int MaxSum1(int a[], int n)
{
    int i, j, k;
    int max_sum = 0;
    int thisv;
    for(i = 0; i < n; i++){
        thisv = 0;
        for(j = i; j < n; j++){
             thisv += a[j];
             if ( thisv > max_sum ) {
                max_sum = thisv;
             }
        }
    }

    return max_sum;
}

//分治算法
static
int MaxSum2(int a[], int s, int e)
{
    int m;
    int leftmax;
    int rightmax;
    int max_sum;
    int left, leftv, s1;
    int right, rightv, s2;

    if ( s == e ) {
        max_sum = ( a[s] > 0 ? a[s] : 0 );
    }
    else {
        m = (e + s) / 2;
        leftmax = MaxSum2(a, 1, m);
        rightmax = MaxSum2(a, m+1, e);
 
        leftv = 0;
        s1 = 0;
        for (left = m - 1; left >= s - 1; left --){
            leftv += a[left];
            if ( leftv > s1 ) {
                s1 = leftv;
            }
        }
 
        rightv = 0;
        s2 = 0;
        for (right = m; right < e; right ++){
            rightv += a[right];
            if ( rightv > s2 ) {
                s2 = rightv;
            }
        }
 
        max_sum = s1 + s2;
 
        if ( leftmax > max_sum ) {
            max_sum = leftmax;
        }
        if ( rightmax > max_sum ) {
            max_sum = rightmax;
        }
    }

    return max_sum;
}

//动态规划算法
static
int MaxSum3(int a[], int n)
{
     int max_sum = 0;
     int b = 0;
     int i;
     for (i = 0; i < n; i++){
        if ( b > 0 ) {
            b += a[i];
        }
        else{
            b = a[i];
        }
        if ( b > max_sum ) {
            max_sum = b;
        }
     }

     return max_sum;
}

int main()
{
    printf("Max: %d\n", MaxSum1(a, 6));
    printf("Max: %d\n", MaxSum2(a, 1, 6));
    printf("Max: %d\n", MaxSum3(a, 6));
    return 0;
}
