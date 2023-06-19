#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int main() {

    int c; // Переменная, которая будет хранить код символа
    long long mi = 0; // Флаг того, что число не в процессе записи
    double km;
    char ps = '0';

    while (1) {

        c = getchar(); // Берём символ, поступивший на вход

        if (isdigit(c)) { // Если символ является цифрой           
            if (mi == 0) { // Если число не начало записываться до этого
                mi = 0;
            }
            mi = mi * 10 + (c - '0'); // Составляем число из цифровых символов    
        }
        else if (isspace(c) || (c == EOF)) { // Если символ является пробелом или концом входной строки
            if (mi != 0) { // Если число есть
            	if (ps != '0') { 
                	printf("%lld%c", mi, ps);
            } else {
            	printf("%lld", mi);
            }
            }
            putchar(c);
            mi = 0;
            ps = '0';
        } else if (isalpha(c)) {		
        	if ((mi != 0)) { // Если число есть и после него идёт сочетание символов "mi"
        		if ((c == 'm') && ( ps == '0')) {
           			ps = c;
          		} else if ((c == 'i') && (ps == 'm')) {
        			km = mi * 1.609;
                 	printf("%fkm", km); 
                	mi = 0;
                	ps = '0';
          		} else { // Если число есть и после него не идёт сочетание символов "mi" 
           			if (ps != '0') { 
                 		printf("%lld%c", mi, ps);
            		} else { 
               			printf("%lld", mi);
            		}
           			ps = '0';
           			mi = 0;
           			putchar(c);
          		}
         	} else {   				
          		mi = 0;
          		putchar(c);
         	}
     	}	
        if (c == EOF) { // Условие выхода из цикла
        	break;
        } 
    }
}