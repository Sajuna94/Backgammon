#include <stdbool.h>

bool S(char* x) {

}

bool J(char* x) {

}

bool sol(char* sentence) {
    if (S(sentence) && J(sentence))
        return true;
    return false;
}