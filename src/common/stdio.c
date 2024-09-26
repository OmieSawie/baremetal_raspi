#include <common/stdio.h>
#include <common/stdlib.h>
#include <kernel/uart.h>

char getc(void) { return uart_getc(); }

void putc(char c) { uart_putc(c); }

void puts(const char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        putc(str[i]);
}

void gets(char *buf, int buflen) {
    int i;
    char c;
    // check entire buffer or till CR
    for (i = 0; (c = getc()) != '\r' && buflen > 1; i++, buflen--) {
        putc(c);
        buf[i] = c;
    }
    // put a line end
    putc('\n');
    if (c == '\n') {
        buf[i] = '\0';
    } else
        buf[buflen - 1] = '\0';
}
