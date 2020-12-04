#ifndef _RTC_H
#define _RTC_H 1

enum {
      cmos_address = 0x70,
      cmos_data    = 0x71
};

int get_update_in_progress_flag();
unsigned char get_RTC_register(int reg);
void read_rtc();

#endif

