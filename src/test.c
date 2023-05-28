#include "s21_string.h"
#include <stdio.h>
#include <setjmp.h>

#define TRY do { jmp_buf buf_state; if ( !setjmp(buf_state)) {
#define CATCH } else {
#define ENDTRY }} while(0)
#define THROW longjmp(buf_state, 1)

int main() {
    char bas[80]; 
    TRY {
        printf("Testing Try statement\n");
        s21_sprintf(bas, "%s %c %s\n", "one", 'N', 304);
        printf("%s\n", bas);
        THROW;
        printf("Statement should not appear, as the THROW block has already thrown the exception \n");
    }
    CATCH {
        printf("Got Exception \n");
    }
    ENDTRY;
    return 0;
}