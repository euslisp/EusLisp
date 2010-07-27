/* eus_help.c
	EusLisp interface to Eushelp
	1994/Jul/24
	(c) 1994 Nakagaki, H., KEPCO
*/

#include "eus.h"
#include <sys/types.h>
#include <unistd.h>

#define	CHAR_SIZE 2048

static int  bp=0;
static char buf[CHAR_SIZE];
static char us[4]={0x1b, 0x5b, 0x34, 0x6d},  /* underline start */
            ue[3]={0x1b, 0x5b, 0x6d},        /* underline end */
            so[4]={0x1b, 0x5b, 0x37, 0x6d},  /* highlight mode start */
            se[3]={0x1b, 0x5b, 0x6d},        /* highlight mode end */
            md[4]={0x1b, 0x5b, 0x31, 0x6d},  /* bold mode start */
            me[3]={0x1b, 0x5b, 0x6d};        /* bold mode end */

/*****************************************************************/
/* READ_TEX( fp ) : read latex file and convert to eushelp       */
/*****************************************************************/

static char READ_CHAR(fd)
int fd;
{
  char c;

  if ((bp == -1) || (bp == CHAR_SIZE)){
    bp=0;
    read(fd, &buf[0], CHAR_SIZE);
  }
  c=buf[bp];
  bp++;
  return(c);
}

static int COMPARE_STRING(str)
char *str;
{
  int mode=0;

  if ((str[0] == 't') && (str[1] == 't'))
    mode=1;
  if ((str[0] == 'e') && (str[1] == 'm'))
    mode=2;
  if ((str[0] == 'i') && (str[1] == 't'))
    mode=2;
  if ((str[0] == 'b') && (str[1] == 'f'))
    mode=3;
  return(mode);
}

/* (read-tex fp) */
static pointer READ_TEX(ctx, n,argv)
context *ctx;
int n;
pointer argv[];
{ register int i,j, fd;
  int brace=1, bslash=0, brace2=0, emphasis=0, kanji=0, mode;
  off_t  offset;
  pointer fp, s;
  char *sp, c, *ch;
  static char str[CHAR_SIZE], cmd[10];

  ckarg(2);
  fp=argv[0];
  offset=(off_t)ckintval(argv[1]);
  fd=intval(fp->c.fstream.fd);
  if (offset >= 0){
    bp=-1;
    lseek( fd, offset, 0);
  }

  for(;(c=READ_CHAR(fd)) != '{';);
  for(sp=&str[0],j=0;brace != 0;){
    c=READ_CHAR(fd);
    if (kanji != 0){
      *sp++=c;
      if ( c == 27 ){
	for(i=0;i<2;i++){ c=READ_CHAR(fd); *sp++=c;}
	kanji=0;
      }
    }
    else if (bslash != 0){
      switch(c){
          case '>' : for(i=0; i<3; i++) *sp++=' ';
          case '=' : bslash=0; break;
          case '&' : ;
          case '#' : *sp++=c; bslash=0; break;
          case '\\': *sp++=0x0a; bslash=0; break;
          case ' ' : if ((mode=COMPARE_STRING(cmd)) != 0){
	                switch(mode){
			  case 1 : ch=us; break;
			  case 2 : ch=so; break;
			  case 3 : ch=md; break;
			  }
			for(i=0;i<4;i++)
			  *sp++=ch[i];
			emphasis=1;
		      }
	             bslash=0; break;
          case '$' : bslash=0; break;
          case '}' : if (j == 0) *sp++='}';
                     bslash=0; break;
          case '[' : j=0; break;
          case '{' : if (j == 0) {*sp++='{'; bslash=0; break;}
                     j=0; break;
          case ']' : for(i=0;i<4;i++) *sp++=' ';
                     for(i=0;i<j;i++) *sp++=cmd[i];
                     bslash=0;
	             brace2=1;
                     break;
          default  : cmd[j++]=c; break;
          }
        }
    else {
      switch(c){
          case '$' : break;
          case '\\': bslash=1; j=0; break;
          case '{' : brace++; break;
          case '}' : if (emphasis != 0){
	               for(i=0;i<3;i++) *sp++=ue[i];
		       emphasis=0;
		     }
	             brace--; break;
          case 10  : if (brace2 == 1) *sp++=10; else *sp++=' ';
	             brace2=0; break;
	  case 27  : kanji=1; *sp++=27; break;
          default  : *sp++=c; break;
          }
        }
  }
  *sp=NULL;
  j=strlen(str);
  s=makestring(&str[0],j);
  return(s);
}

/*****************************************************************/
/* eusmain routine                                               */
/*****************************************************************/

helpsub(ctx,n,argv)
context *ctx;
int n;
pointer argv[];
{ pointer mod=argv[0];
  defun(ctx, "READ-TEX", mod, READ_TEX);
 }
