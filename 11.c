// Панов Е.К. М8О-104Б-22 В20
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#define KOEF 1.609;

int main() {

    int c; // Переменная, которая будет хранить код символа
    long long mi = 0; // Флаг того, что число не в процессе записи
    double km;
    char ps = '0'; // Переменная для запоминания предыдущего символа ('m')

    while (1) {

        c = getchar(); // Берём символ, поступивший на вход

        if (isdigit(c)) { // Если символ является цифрой           
            mi = mi * 10 + (c - '0'); // Составляем число из цифровых символов    
        }
        else if (isspace(c) || (c == EOF)) { // Если символ является пробелом или концом входной строки
            if (mi != 0) { // Если число есть 
               	printf("%lld", mi);
            }
            putchar(c);
            mi = 0;
        } else if (isalpha(c)) {        
            if ((mi != 0)) { // Если число есть и после него идёт сочетание символов "mi"
                if ((c == 'm') && ( ps == '0')) {
                    ps = c;
                } else if ((c == 'i') && (ps == 'm')) {
                    km = mi * KOEF;
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