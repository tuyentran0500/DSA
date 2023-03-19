#include <stdio.h>
int main(void){
    printf("%X", 0xF0 | (0x01 << 3  | 0x01 << 1));
}