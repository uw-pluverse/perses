struct rtx_def ;
typedef struct rtx_def * rtx ;
struct rtvec_def ;
typedef struct rtvec_def * rtvec ;
union tree_node ;
typedef union tree_node * tree ;
typedef struct mem_attrs
{
long alias ;
}
mem_attrs ;
union rtunion_def
{
mem_attrs * f6 ( int ) __attribute__ ( ( alloc_align ( 0 ) ) ) ;
} ;
typedef union rtunion_def rtunion ;
struct rtx_def
{
int code ;
rtunion fld [ 1 ] ;
} ;
struct tree_decl
{
rtx rtl ;
} ;
union tree_node
{
struct tree_decl decl ;
} ;
void make_decl_rtl ( tree , int ) ;
long
get_alias_set ( t , z )
tree t ;
rtx z ;
{
if ( t -> decl . rtl && ( ( ( t -> decl . rtl ? z
: ( make_decl_rtl ( t , 0 ) , t -> decl . rtl ) ) ) -> code ) )
return ( ( ( ( ( t -> decl . rtl ? z : ( make_decl_rtl ( t , 0 ) , t -> decl . rtl ) ) ) ->
fld [ 1 ] ) . rtmem ) == 0 ? 0 : ( ( ( ( (
{
t ; }
) -> decl .
rtl ? z : ( make_decl_rtl ( t , 0 ) ,
t -> decl . rtl ) ) ) ->
fld [ 1 ] ) . rtmem ) -> alias ) ;
}
