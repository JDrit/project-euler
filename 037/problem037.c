#include <stdio.h>                                                                                                                                   
 #include <stdlib.h>                                                                                                                                  
 #include <math.h>                                                                                                                                    
                                                                                                                                                      
 int isPrime(long n) {                                                                                                                                
     long i;                                                                                                                                          
     if (n == 1) return 0;                                                                                                                            
     for (i = 2 ; i <= sqrt(n) ; i++) {                                                                                                               
         if (n % i == 0) {                                                                                                                            
             return 0;                                                                                                                                
         }                                                                                                                                            
     }                                                                                                                                                
     return 1;                                                                                                                                        
 }                                                                                                                                                    
                                                                                                                                                      
 int main(int argc, char *argv[]) {                                                                                                                   
     short count = 0;                                                                                                                                 
     long index = 8;                                                                                                                                  
     long sum = 0;                                                                                                                                    
     short bad;                                                                                                                                       
                                                                                                                                                      
     while (count < 11) {                                                                                                                             
         index++;                                                                                                                                     
         char *number = malloc(10 * sizeof(char));                                                                                                    
         sprintf(number, "%ld", index);                                                                                                               
         bad = 0;                                                                                                                                     
         do {                                                                                                                                         
             if (!isPrime(atol(number++))) {                                                                                                          
                 bad = 1;                                                                                                                             
                 break;                                                                                                                               
             }                                                                                                                                        
         } while (atol(number) != 0); 
         if (bad) {                                                                                                                                   
             continue;                                                                                                                                
         }                                                                                                                                            
         long i = index;                                                                                                                              
         do {                                                                                                                                         
             if (isPrime(i)) {                                                                                                                        
                  i /= 10;                                                                                                                            
             } else {                                                                                                                                 
                 bad = 1;                                                                                                                             
                 break;                                                                                                                               
             }                                                                                                                                        
         } while (i != 0);                                                                                                                            
         if (bad) {                                                                                                                                   
             continue;                                                                                                                                
         }                                                                                                                                            
         sum += index;                                                                                                                                
         count++;                                                                                                                                     
                                                                                                                                                      
     }                                                                                                                                                
     printf("sum: %ld\n", sum);                                                                                                                       
     return 0;                                                                                                                                        
 }              
