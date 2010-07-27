#define strchr(p) ((char *)((p)->c.str.chars))
/*#define ckstrchr(p) (isstring(p)?strchr(p):(int)error(E_NOSTRING))*/
#define ckstrlength(p) (isstring(p)?strlength(p):(int)error(E_NOSTRING))
#define ckstrval(p) ckstrchr(p)
#define fvecfv(p) ((float *)((p)->c.fvec.fv))
#define ckfvecfv(p) (isfltvector(p)?fvecfv(p):(int)error(E_FLOATVECTOR))

extern long larg2long();

