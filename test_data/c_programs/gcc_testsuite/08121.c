
typedef unsigned char uch;
typedef unsigned short ush;
extern uch window[];
extern ush prev[];
typedef unsigned IPos;
unsigned max_chain_length;
extern unsigned strstart;
unsigned int prev_length;

unsigned good_match;
int nice_match;

int longest_match(IPos cur_match)
{
    unsigned chain_length = max_chain_length;
    register uch *scan = window + strstart;
    register uch *match;
    register int len;
    int best_len = prev_length;
    IPos limit = strstart > (IPos)(0x8000 -(258 +3 +1)) ? strstart - (IPos)(0x8000 -(258 +3 +1)) : 0;
    register uch *strend = window + strstart + 258;
    register uch scan_end = scan[best_len];
    if (prev_length >= good_match) {
    }
    do {
        if (match[best_len] != scan_end ||
            *++match != scan[1]) continue;
        do {
        } while (*++scan == *++match && *++scan == *++match &&
                 scan < strend);
        len = 258 - (int)(strend - scan);
        if (len > best_len) {
            best_len = len;
            if (len >= nice_match) break;
        }
    } while ((cur_match = prev[cur_match & (0x8000 -1)]) > limit
      && --chain_length != 0);
    return best_len;
}
