 #include <stdio.h>
 #include <math.h>

 int isPrime(int n) {
     int i;
     if (n < 2) {
         return 0;
     }
     for (i = 2 ; i < sqrt(n) ; i++) {
         if (n % i == 0) {
             return 0;
         }
     }
     return 1;
 }

 int main(int agrc, char *argv[]) {
     int primes[1000] = {0};
     int a, b;
     int max = 0;
     int result;

     for (a = -1000 ; a < 1000 ; a++) {
         for (b = -1000 ; b < 1000 ; b++) {
             int n = 0;
             while (isPrime(n * n + a * n + b )) {
                 printf("n=%i\n", n * n + a * n + b);
                 n++;
             }
             if (n > max) {
                 max = n;
                 result = a * b;
                 printf("result: %i, %i , %i, %i\n", result, a, b, n);
             }
         }
     }

     printf("%i\n", result);
     return 0;
 }