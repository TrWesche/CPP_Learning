enum class Month {
    Jan = 1,
    January = 1,
    Feb,
    February = Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec     // 12, compiler will increment from 1
};


enum class AutoAssigned {
    AAAA, // 0
    BBBB, // 1
    CCCC, 
    DDDD = 12,
    EEEE // 13
};


enum class OtherType : signed char {
    CHAR1 = -10,
    CHAR2,
    CHAR3
};