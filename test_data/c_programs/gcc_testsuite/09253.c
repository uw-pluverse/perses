







typedef int YYSTYPE;
typedef struct tDefEntry
{
  unsigned t;

} tDefEntry;
struct incomplete;


YYSTYPE
 addSibMacro(
         YYSTYPE list )
 {
     tDefEntry** ppT = (tDefEntry**)&list;

     struct incomplete *p = (struct incomplete *)&list;

     return list;
 }
