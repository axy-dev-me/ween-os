#ifndef TIME_H
#define TIME_H

#include "types.h"

typedef struct {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint16_t year;
} rtc_time_t;

#define CMOS_PORT_REG  0x70
#define CMOS_PORT_DATA 0x71

#define RTC_REG_SECOND 0x00
#define RTC_REG_MINUTE 0x02
#define RTC_REG_HOUR   0x04
#define RTC_REG_DAY    0x07
#define RTC_REG_MONTH  0x08
#define RTC_REG_YEAR   0x09
#define RTC_REG_STAT_A 0x0A
#define RTC_REG_STAT_B 0x0B

#define BCD_TO_BIN(bcd) ((((bcd) & 0xF0) >> 4) * 10 + ((bcd) & 0x0F))

__sil_int rtc_is_updating(void) {
    outb(CMOS_PORT_REG, RTC_REG_STAT_A);
    return (inb(CMOS_PORT_DATA) & 0x80);
}

__sil_uint8_t get_rtc_register(int reg) {
    outb(CMOS_PORT_REG, reg | 0x80);
    return inb(CMOS_PORT_DATA);
}

__sil_void read_rtc(rtc_time_t *time) {
    while (rtc_is_updating());

    uint8_t second = get_rtc_register(RTC_REG_SECOND);
    uint8_t minute = get_rtc_register(RTC_REG_MINUTE);
    uint8_t hour   = get_rtc_register(RTC_REG_HOUR);
    uint8_t day    = get_rtc_register(RTC_REG_DAY);
    uint8_t month  = get_rtc_register(RTC_REG_MONTH);
    uint8_t year   = get_rtc_register(RTC_REG_YEAR);
    
    uint8_t reg_b = get_rtc_register(RTC_REG_STAT_B);

    if (!(reg_b & 0x04)) {
        time->second = BCD_TO_BIN(second);
        time->minute = BCD_TO_BIN(minute);
        time->hour   = BCD_TO_BIN(hour);
        time->day    = BCD_TO_BIN(day);
        time->month  = BCD_TO_BIN(month);
        time->year   = BCD_TO_BIN(year);
    } else {
        time->second = second;
        time->minute = minute;
        time->hour   = hour;
        time->day    = day;
        time->month  = month;
        time->year   = year;
    }

    if (!(reg_b & 0x02) && (time->hour & 0x80)) {
        time->hour = ((time->hour & 0x7F) + 12) % 24;
    }

    time->year += 2000; 
}

#endif
