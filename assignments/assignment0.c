// localTime.c
// A program to test a function getLocalTime which determines the
// local time in a specified city, given the current UTC time.
//
// This program by Jack Gifford (z5160408) on 2017-08-15
//
// Program stub created by Andrew Bennett on 2017-08-01.
// Version 1.0.3: Add version numbers.
// Version 1.0.2: Fixed include order.
// Version 1.0.1: Fix `CITY_LORD_HOWE_IS` symbol name.
// Version 1.0.0: First release onto an unsuspecting class.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE !TRUE


// ===========      StandardTimeZoneStartDates      ===========
#define AUS_START_DAY 1
#define AUS_START_MONTH 4

#define NZ_START_DAY 1
#define NZ_START_MONTH 4
#define NZ_START_HOUR 1400

// ===========      StandardTimeZoneEndDates      ===========
#define AUS_END_DAY 30
#define AUS_END_MONTH 9

#define NZ_END_DAY 23
#define NZ_END_MONTH 9
#define NZ_END_HOUR 1400

// ===========      Cities      ===========

// Australia
#define CITY_ADELAIDE 0
#define CITY_BRISBANE 1
#define CITY_BROKEN_HILL 2
#define CITY_CANBERRA 3
#define CITY_DARWIN 4
#define CITY_EUCLA 5
#define CITY_HOBART 6
#define CITY_LORD_HOWE_IS 7
#define CITY_MELBOURNE 8
#define CITY_PERTH 9
#define CITY_SYDNEY 10

// New Zealand
#define CITY_AUCKLAND 11
#define CITY_CHRISTCHURCH 12
#define CITY_WELLINGTON 13

// =========== Timezone Offsets ===========

// Australia
#define TIMEZONE_AWST 800 // Australian Western Standard Time

#define TIMEZONE_ACWST 845 // Australian Central Western Standard Time

#define TIMEZONE_ACST 930  // Australian Central Standard Time
#define TIMEZONE_ACDT 1030 // Australian Central Daylight Time

#define TIMEZONE_AEST 1000 // Australian Eastern Standard Time
#define TIMEZONE_AEDT 1100 // Australian Eastern Daylight Time

#define TIMEZONE_LHST 1030 // Lord Howe Standard Time
#define TIMEZONE_LHDR 1100 // Lord Howe Daylight Time

// New Zealand
#define TIMEZONE_NZST 1200 // NZ Standard Time
#define TIMEZONE_NZDT 1300 // NZ Daylight Time

// =========== Function Prototypes ===========
//       [DO NOT CHANGE THIS PROTOTYPE!]
int getLocalTime(int city, int day, int month, int timeUTC);

int main(int argc, char *argv[])
{
    // UTC time: 3:30pm on 1st April, time in Sydney: 2:30am
    assert(getLocalTime(CITY_SYDNEY, 1, 4, 1530) == 230);
    // UTC time: 4:30pm on 1st April, time in Sydney: 2:30am
    assert(getLocalTime(CITY_SYDNEY, 1, 4, 1630) == 230);

    // UTC time 3.59pm on 30th Sep, time in Canberra: 1.59am on the 1st Oct 
    assert(getLocalTime(CITY_CANBERRA, 30, 9, 1559) == 159); 
    
    // UTC time 4.00pm on 30th Sep, time in Canberra: 3.00am on the 1st Oct 
    assert(getLocalTime(CITY_CANBERRA, 30, 9, 1600) == 300); 

    // UTC time: 8:59am on 15th May, time in Christchurch: 8:59pm
    assert(getLocalTime(CITY_CHRISTCHURCH, 15, 5, 859) == 2059);

    // UTC time: midnight on 5th April, time in Sydney: 10am
    assert(getLocalTime(CITY_SYDNEY, 5, 4, 0) == 1000);

    // UTC time: 10:30am on 30th June, time in Adelaide: 8pm
    assert(getLocalTime(CITY_ADELAIDE, 30, 6, 1030) == 2000);

    // UTC time: 8:15pm on 17th August, time in Brisane: 6:15am
    assert(getLocalTime(CITY_BRISBANE, 17, 8, 2015) == 615);

    // UTC time: 8am on 27th April, time in Auckland: 8pm
    assert(getLocalTime(CITY_AUCKLAND, 27, 4, 800) == 2000);

    // UTC time: 11:11pm on 30th January, time in Perth: 7:11am on the 31st
    assert(getLocalTime(CITY_PERTH, 30, 1, 2311) == 711);

    // UTC time: 8pm on 5th May, time in Perth: 4am on the 6th
    assert(getLocalTime(CITY_PERTH, 2, 5, 2000) == 400);

    // UTC time: 10:30pm on 6th Oct, time in Christchurch: 11:30am on the 7th
    assert(getLocalTime(CITY_CHRISTCHURCH, 6, 10, 2230) == 1130);

    // UTC time: 2:28pm on 16th December, time in Canberra: 1:28am on the 17th
    assert(getLocalTime(CITY_CANBERRA, 16, 12, 1428) == 128);

    // UTC time: 3:39am on 1st November, time in Darwin: 1:09pm
    assert(getLocalTime(CITY_DARWIN, 1, 11, 339) == 1309);

    // UTC time: 1pm on 8th July, time in Hobart: 11pm
    assert(getLocalTime(CITY_HOBART, 8, 7, 1300) == 2300);

    // UTC time: 1:54pm on 27th September, time in Melbourne: 11:54pm
    assert(getLocalTime(CITY_MELBOURNE, 27, 9, 1354) == 2354);

    // UTC time: 9:24am on 5th January, time in Wellington: 10:24pm
    assert(getLocalTime(CITY_WELLINGTON, 5, 1, 924) == 2224);

    // UTC time: 2pm on 18th April, time in Brisbane: 12:00am on the 19th
    assert(getLocalTime(CITY_BRISBANE, 18, 4, 1400) == 0);

    // UTC time: 11:06am on 8th October, time in Brisbane: 9:06pm
    assert(getLocalTime(CITY_BRISBANE, 8, 10, 1106) == 2106);

    // UTC time: 12:01pm on 29th October, time in Sydney: 11:01pm
    assert(getLocalTime(CITY_SYDNEY, 29, 10, 1201) == 2301);

    // UTC time: 11:45pm on 17th February, time in Darwin: 9:15am on the 18th
    assert(getLocalTime(CITY_DARWIN, 17, 2, 2345) == 915);

    // UTC time: 11pm on 7th August, time in Auckland: 10am on the 8th
    assert(getLocalTime(CITY_AUCKLAND, 7, 8, 2200) == 1000);

    // UTC time: 10:15 am on 5th September, time in Eucla: 7pm
    assert(getLocalTime(CITY_EUCLA, 5, 9, 1015) == 1900);

    // UTC time: 10am on 1st January, time in Broken Hill: 8:30pm
    assert(getLocalTime(CITY_BROKEN_HILL, 1, 1, 1000) == 2030);

    // UTC time: 10:15pm on 1st October, time in Lord Howe Island: 9:15am on the 2nd
    assert(getLocalTime(CITY_LORD_HOWE_IS, 1, 10, 2215) == 915);

    // UTC time: 11:59pm on 6th February, time in Eucla: 8:44am on the 7th
    assert(getLocalTime(CITY_EUCLA, 6, 2, 2359) == 844);

    // UTC time: 1:17am on 17th July, time in Broken Hill: 10:47 am
    assert(getLocalTime(CITY_BROKEN_HILL, 17, 7, 117) == 1047);

    // Add your own tests here
    printf("All tests passed\n");

    return EXIT_SUCCESS;
}

//Checks if the second supplied date occurs after the first date.
int dateChecker(int firstDay, int firstMonth, int firstHour, int secondDay, int secondMonth, int secondHour) {
    int isSecondAfterFirst;
    if (secondMonth > firstMonth) {
        isSecondAfterFirst = TRUE;
    } else if  (secondMonth == firstMonth && secondDay == firstDay && secondHour > firstHour) {
        isSecondAfterFirst = TRUE;
    } else if (secondMonth == firstMonth && secondDay > firstDay) {
        isSecondAfterFirst = TRUE;
    } else {
        isSecondAfterFirst = FALSE;
    }

    return isSecondAfterFirst;
}

//Returns the correct aus timezone based on provided city, and date
int getAusTime(int city, int day, int month, int hour)
{
    int timezone;
    if (city == CITY_SYDNEY || city == CITY_CANBERRA || 
            city == CITY_MELBOURNE || city == CITY_HOBART) {
        if (dateChecker(1, 4, 1600, day, month, hour) && 
            dateChecker(day, month, hour, 30, 9, 1600)) {
                    timezone = TIMEZONE_AEST;
        } else {
            timezone = TIMEZONE_AEDT;
        }
    } else if (city == CITY_ADELAIDE || city == CITY_BROKEN_HILL) {
        if (dateChecker(1,4,1630, day, month, hour) && 
            dateChecker(day, month, hour, 30,9,1630)) {
                timezone = TIMEZONE_ACST;
        } else {
                timezone = TIMEZONE_ACDT;
        }
    } else if (city == CITY_DARWIN) {
        timezone = TIMEZONE_ACST;
    } else if (city == CITY_PERTH) {
        timezone = TIMEZONE_AWST;
    } else if (city == CITY_EUCLA) {
        timezone = TIMEZONE_ACWST;
    } else if (city == CITY_BRISBANE) {
        timezone = TIMEZONE_AEST;
    } else if (city == CITY_LORD_HOWE_IS) {
         if (dateChecker(1,4,1530, day, month, hour) && 
            dateChecker(day, month, hour, 30,9,1530)) {
            timezone =  TIMEZONE_LHST;
        } else {
            timezone = TIMEZONE_LHDR;   
        }
    }

    //Not an australian city
    return timezone;
}

int getNewZealandTime(int day, int month, int hour)
{
    int timeZone;
    if (dateChecker(1,4,1400, day, month, hour) && 
        dateChecker(day, month, hour, 23,9,1400)) {
            timeZone = TIMEZONE_NZST;         
    } else {
        timeZone = TIMEZONE_NZDT;
    }

    return timeZone;
}


//Combines timeUTC, and timeZone, and reformats them into the correct time
int formatTime(int timeUTC, int timeZone) {
    //Combine utc, and timezone and then separate into hours
    // and minutes i.e 2359 becomes 23 and 59. 
    int timeInHours = ((timeUTC / 100) + (timeZone / 100)) * 100; 
    int timeInMinutes = (timeUTC % 100) + (timeZone % 100);    

    //Handles overflow when timezone is a day ahead.
    if (timeInHours >= 2400) {
        timeInHours = timeInHours - 2400;
    }

    int localTime = timeInHours + timeInMinutes;
    
    if (timeInMinutes >= 60) {
        localTime = localTime + 100 + -60;
    } 

    return localTime;
}

// Converts the time to local time
// [DO NOT CHANGE THIS PROTOTYPE!]
int getLocalTime(int city, int day, int month, int timeUTC)
{
    int timeZone;
    if (city >= 0 && city <= 10) {
        timeZone = getAusTime(city, day, month, timeUTC);
    } else {
        timeZone = getNewZealandTime(day, month, timeUTC);
    }
    
    int localTime = formatTime(timeUTC, timeZone);

    return localTime;
}