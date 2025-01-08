#include <stdio.h>
/*
void tower_hanoi (int n , char src , char inter , char dest) {
    if ( n == 0 ) {
        return;
    }
    tower_hanoi(n-1, src, dest, inter);
    printf("%d is transfered from %c to %c\n", n , src , dest);

    tower_hanoi (n-1, inter , src , dest);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    tower_hanoi(n , 'A' , 'B' , 'C');
    return 0;
}
 */
int fibo (int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibo(n - 1) + fibo(n - 2);
}
int main() {
    int num;
    printf("Enter until what term do you want fibonacci series: ");
    scanf("%d",&num);
    int res;
    for (int i = 0 ; i < num ; i++){
        res = fibo (i);
        printf("%d\n", res);
    }
    return 0;
}
