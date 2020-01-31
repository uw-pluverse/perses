



struct {
    int tz_minuteswest;
    int tz_dsttime;
} a, b;
void fn1() {
    b.tz_minuteswest = a.tz_minuteswest;
    b.tz_dsttime = a.tz_dsttime;
}
