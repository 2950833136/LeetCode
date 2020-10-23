#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int         base[]   = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char* romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    //分配地址空间 ,20个可以通过
    char* roman = (char*)malloc(sizeof(char) * 20);
    roman[0]    = '\0';
    int i       = 0;
    while (num != 0) {
        if (num >= base[i]) {
            //把对应的罗马数字加入字符串中
            strcat(roman, romans[i]);
            num = num - base[i];
        } else {
            i++;
        }
    }
    return roman;
}

int main() {
    //MCMXCIV
    int   num   = 1994;
    char* roman = intToRoman(num);
    puts(roman);
    return 0;
}
