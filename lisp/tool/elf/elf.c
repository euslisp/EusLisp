#include <stdio.h>
#include <libelf.h>

extern int errno;


main(argc,argv)
int argc;
char *argv[];
{
  char *fname;
  int elfd;
  Elf *elf;
  Elf32_Ehdr *ehdr;
  Elf_Scn *scn;
  Elf_Data *data;
  int i,j;
  char *cp;

  fname=argv[1];
  elfd=open(fname, 0);
  if (elfd<=0) { fprintf(stderr, "open error %d\n", errno); exit(2);}
  elf_version(EV_CURRENT);
  elf=elf_begin(elfd, ELF_C_READ, 0);
  printf("elf=%d\n", elf);
  if (elf==0) printf("%s\n", elf_errmsg(elf_errno()));
  ehdr=elf32_getehdr(elf);
  printf("elfhdr=%x\n", ehdr);
  printf("e_ident=");
  for (i=0; i<16; i++) {
    printf("%2x ", ehdr->e_ident[i]);}
  printf("\ne_type= %d\n", ehdr->e_type);
  printf("e_machine= %d\n", ehdr->e_machine);
  printf("e_version= %d\n", ehdr->e_version);
  printf("e_entry= 0x%x\n", ehdr->e_entry);
  printf("e_phoff= 0x%x\n", ehdr->e_phoff);
  printf("e_shoff= 0x%x\n", ehdr->e_shoff);
  printf("e_flags= 0x%x\n", ehdr->e_flags);
  printf("e_ehsize= 0x%x\n", ehdr->e_ehsize);
  printf("e_phentsize= %d\n", ehdr->e_phentsize);
  printf("e_phnum= %d\n", ehdr->e_phnum);
  printf("e_shentsize= %d\n", ehdr->e_shentsize);
  printf("e_shnum= %d\n", ehdr->e_shnum);
  printf("e_shstrndx= %d\n", ehdr->e_shstrndx);

  scn= elf_getscn(elf, ehdr->e_shstrndx);
  printf("string section = %x\n", scn);
  data=0; 
  data=elf_getdata(scn, data);
  i=data->d_size;
  cp=data->d_buf;
  while (i-->0) {
    printf("%c", *cp);
    if (*cp == 0) printf("\n");
    cp++;}

  elf_end(elf);
  }


