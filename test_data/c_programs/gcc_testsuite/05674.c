


struct rtx_def;
typedef struct rtx_def *rtx;



union rtunion_def
{
  int rtint;
};
typedef union rtunion_def rtunion;



struct rtx_def
{
  rtunion fld[1];

};

static int *uid_cuid;
static int max_uid_cuid;
int insn_cuid (rtx);

rtx
bar (rtx r)
{
  rtx place = r;

  if (place->fld[0].rtint <= max_uid_cuid
      && (place->fld[0].rtint > max_uid_cuid ? insn_cuid (place) :
   uid_cuid[place->fld[0].rtint]))
    return r;

  return 0;
}
