#include<stdio.h> 
    void main() 
    { 
        int year; 
        year=2000; 
      go: if(((year%4 == 0)&&(year%100 != 0)) || (year%400 == 0)) 
           printf("%d is run nian",year); 
        if(year<=2500) 
           year=year++; 
          if(year>2500)
           goto end;        
      goto go; 
        end:   getch(); 
       } 
