//Панов Е. К. М8О-104Б-22 В 23
#include <stdio.h>
#include <math.h>// Необходимые библиотеки
#include <stdlib.h>

#define min(i , j) ((i) < (j) ? (i) : (j))// Функция минимума
#define max(i , j) ((i) > (j) ? (i) : (j))// Функция максимума

#define I 29 // входные данны переменных показателей
#define J  -6
#define L  1
#define NOM_STEP 50
#define KOORDX1 -10// входные данные координат точек треугольника
#define KOORDX2  0
#define KOORDX3 -10
#define KOORDY1 0
#define KOORDY2 10
#define KOORDY3 20

int main(){
    int i = I, j = J, l = L;
    int bang = 0, out = 0;// Счётчики попаданий и промахов
    for (int k = 1; k <= NOM_STEP; k += 1){// цикл
        
        i = min(max(min(i - j, i - l), j - l), i - k) % 30;//изменение координаты i
        j = max(min(max(i - j, i - l), j - l), i - k) % 30;// изменение координаты j
        l = (i % 30) - (j % 30) + (l % 30) - (k % 30);// изменение параметра движения l
        
        if (((j - i) >= KOORDY2) && ((j + i) <= KOORDY2) && (j <= KOORDY3) && (j >= KOORDY1) && (i >= KOORDX1) && (i <= KOORDX2)) {// условия попадания
            bang += 1;
            printf("popal(%d;%d) L=%d   K=%d\n", i, j, l, k);
            
        } else {//условия промаха
            out += 1;
        }
    } 
    printf("bang=%d, out=%d, L=%d, K=%d\n", bang, out, l, NOM_STEP);
}