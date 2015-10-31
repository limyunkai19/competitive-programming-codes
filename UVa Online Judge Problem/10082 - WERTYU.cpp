#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char temp;
    while( (temp = getchar()) != EOF){
        switch(temp){
            case '=': putchar('-'); break;
            case '-': putchar('0'); break;
            case '0': putchar('9'); break;
            case '9': putchar('8'); break;
            case '8': putchar('7'); break;
            case '7': putchar('6'); break;
            case '6': putchar('5'); break;
            case '5': putchar('4'); break;
            case '4': putchar('3'); break;
            case '3': putchar('2'); break;
            case '2': putchar('1'); break;
            case '1': putchar('`'); break;
            case '\\': putchar(']'); break;
            case ']': putchar('['); break;
            case '[': putchar('P'); break;
            case 'P': putchar('O'); break;
            case 'O': putchar('I'); break;
            case 'I': putchar('U'); break;
            case 'U': putchar('Y'); break;
            case 'Y': putchar('T'); break;
            case 'T': putchar('R'); break;
            case 'R': putchar('E'); break;
            case 'E': putchar('W'); break;
            case 'W': putchar('Q'); break;
            case '\'': putchar(';'); break;
            case ';': putchar('L'); break;
            case 'L': putchar('K'); break;
            case 'K': putchar('J'); break;
            case 'J': putchar('H'); break;
            case 'H': putchar('G'); break;
            case 'G': putchar('F'); break;
            case 'F': putchar('D'); break;
            case 'D': putchar('S'); break;
            case 'S': putchar('A'); break;
            case '/': putchar('.'); break;
            case '.': putchar(','); break;
            case ',': putchar('M'); break;
            case 'M': putchar('N'); break;
            case 'N': putchar('B'); break;
            case 'B': putchar('V'); break;
            case 'V': putchar('C'); break;
            case 'C': putchar('X'); break;
            case 'X': putchar('Z'); break;
            case '\n': putchar('\n'); break;
            case ' ': putchar(' '); break;
        }
    }
    return 0;
}
