#include <stdio.h>
int main(int argc, char const* argv[]){
    int a = 0x55, b = 0xaa;
    if ((b & (0x01 << 3)) != 0){
        printf("Pass");
    }
    else {
        printf("Fail");
    }
}