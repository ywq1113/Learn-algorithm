#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    char* number = new char[12];
    memset(number,'0',11);
    number[11] = '\0';

    for(int i=0;i<=11;++i)
        number[i] = i+'0';

    for(int j=0;j<=11;++j)
        printf("%c",number[j]);
}
