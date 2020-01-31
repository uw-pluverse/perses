




int func (int val);
void *func2 (void *ptr);

static const char *ifs;
static char map[256];

typedef struct {


  char *data;
  int length;
  int maxlen;
  int quote;
} o_string;



static int parse_stream (void *dest, void *ctx)
{
  int ch = func (0), m;

  while (ch != -1) {
    m = map[ch];
    if (ch != '\n')
    func2(dest);

    ctx = func2 (ctx);
    if (!func (0))
      return 0;
    if (m != ch) {
      func2 ("htns");
      break;
    }
  }
  return -1;
}

static void mapset (const char *set, int code)
{
  const char *s;
  for (s=set; *s; s++) map[(int)*s] = code;
}

static void update_ifs_map(void)
{

  ifs = func2 ("abc");
  if (ifs == 0) ifs="def";

  func2 (map);
  {
    char subst[2] = {4, 0};
    mapset (subst, 3);
  }
  mapset (";&|#", 1);
}

int parse_stream_outer (int flag)
{
  int blah;
  o_string temp={0,0,0,0};
  int rcode;

  do {
    update_ifs_map ();
    func2 (&blah);
    rcode = parse_stream (&temp, 0);
    func2 ("aoeu");
    if (func (0) != 0) {
      func2 (0);
    }
  } while (rcode != -1);
  return 0;
}
