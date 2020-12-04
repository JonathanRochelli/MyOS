#include "kernel/tty.h"
#include "kernel/io.h"
#include "kernel/kbd.h"
#include "libc/include/string.h"
#include "kernel/rtc.h"

void kernel_early(void) {
	terminal_initialize();
}

int main(void) {
	char *buff;
	strcpy(&buff[strlen(buff)], "");
	printprompt();
	memset(&buff[0], 0, sizeof(buff));
	while (1) {
		uint8_t byte;
		while (byte = scan()) {
			printf(buff);
			if (byte == 0x1c) {
				if (strlen(buff) > 0 && strcmp(buff, "exit") == 0)
					read_rtc();
				printprompt();
				memset(&buff[0], 0, sizeof(buff));
				break;
			} else {
				char c = normalmap[byte];
				char *s;
				s = ctos(s, c);
				printf("%s", s);
				strcpy(&buff[strlen(buff)], s);
			}
			
			move_cursor(get_terminal_row(), get_terminal_col());
		}
	}
	return 0;
}
