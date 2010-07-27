/* rmphdr.c
/*	remove program execution header and substantial segments
/*	from an elf format object file.
/* May/1994	(c) Toshihiro Matsui, Electrotechnical Laboratory
/*
*/


#include <stdio.h>
#include <sys/types.h>
#include <libelf.h>	/* sys/elf.h is read */
#include <fcntl.h>

#define min(x,y) ((x)<(y)?(x):(y))

extern int errno;


void copy_bytes(infd, outfd, offset, nbytes)
int infd, outfd, offset, nbytes;
{ char buf[8192];
  int  i, s;
  lseek(infd, offset, SEEK_SET);
  while (nbytes>0) {
    s=min(8192, nbytes);
    s=read(infd, buf, s);
    if (s<=0) { 
	fprintf(stderr, "cannot read object %d", errno);
	return;}
    write(outfd, buf, s);
    nbytes -= s;}
  }

void copy_new_symtab(infd,outfd,symtab)
int infd, outfd;
Elf32_Shdr *symtab;
{ register int i;
  int s, ss, k;
  Elf32_Sym symbuf[16384];	/* 256KB */
  unsigned char info;

  s=symtab->sh_size;
  if (s>sizeof(symbuf)) { fprintf(stderr, "symtab too big %d\n",s); exit(5);}
  lseek(infd, symtab->sh_offset, SEEK_SET);
  ss=read(infd, symbuf, s);
  if (ss!=s) { fprintf(stderr, "cannt read symtab %d\n", ss); exit(6);}
  k=ss/sizeof(Elf32_Sym);	/*number of symtab entries*/
  for (i=symtab->sh_info; i<k; i++) {
    info=symbuf[i].st_info;
    if (ELF32_ST_TYPE(info)==STT_OBJECT) {
      fprintf(stderr, "symbol[%d] is OBJECT\n", i);
      symbuf[i].st_info += 1;}}
  write(outfd, symbuf, ss);}

main(argc,argv)
int argc;
char *argv[];
{
  char *fname;
  int elfd, outfd;
  char outfname[128];
  Elf *elf;
  Elf32_Ehdr *ehdr, newehdr;
  Elf_Scn *scn;
  Elf32_Shdr *scnhdr, scntab[40], *symtab;
  Elf_Data *data;
  int scn_symt[40];
  int i, j, scn_num, scn_count, scn_total_size, scn_offset;
  char *cp;
  
  fname=argv[1];
  sprintf(outfname,"%s.r",fname);
  elfd=open(fname, 0);
  outfd=open(outfname, O_RDWR | O_CREAT, 0777);
  if (elfd<=0) {
    fprintf(stderr, "%s cannot open %d\n", fname, errno);
    exit(2);}
  if (outfd<=0) {
    fprintf(stderr, "%s cannot open %d\n", outfname, errno);
    exit(2);}
  fprintf(stderr, "%s opened\n", outfname);

  elf_version(EV_CURRENT);
  elf=elf_begin(elfd, ELF_C_READ, 0);
  if (elf==0) printf("%s\n", elf_errmsg(elf_errno()));
  ehdr=elf32_getehdr(elf);
  memcpy(&newehdr, ehdr, sizeof(newehdr));
/*  printf("elfhdr=%x\n", ehdr); */
/*  printf("e_ident="); */
/*  for (i=0; i<16; i++) {  printf("%2x ", ehdr->e_ident[i]);} */

  printf("\ne_type= %d\n", newehdr.e_type);
  printf("e_machine= %d\n", newehdr.e_machine);
  printf("e_version= %d\n", newehdr.e_version);
  printf("e_entry= 0x%x\n", newehdr.e_entry);
  printf("e_phoff= 0x%x\n", newehdr.e_phoff);
  printf("e_shoff= 0x%x\n", newehdr.e_shoff);
  printf("e_flags= 0x%x\n", newehdr.e_flags);
  printf("e_ehsize= 0x%x\n", newehdr.e_ehsize);
  printf("e_phentsize= %d\n", newehdr.e_phentsize);
  printf("e_phnum= %d\n", newehdr.e_phnum);
  printf("e_shentsize= %d\n", newehdr.e_shentsize);
  printf("e_shnum= %d\n", newehdr.e_shnum);
  printf("e_shstrndx= %d\n", newehdr.e_shstrndx);

  /* get all section headers and reindex section headers */
  scn_num=newehdr.e_shnum;
  scn_count=0;
  scn_total_size=0;
  for (i=0; i<scn_num; i++) {
    scn=elf_getscn(elf, i);
    scnhdr=elf32_getshdr(scn);
    memcpy(&scntab[i], scnhdr, sizeof(Elf32_Shdr));
/*    printf("sh_flags[%d]=%d\n", i, scntab[i].sh_flags); */
    if (scntab[i].sh_flags==0) {
      scn_symt[i]=scn_count++;
      if (scntab[i].sh_type == SHT_SYMTAB) symtab=&scntab[i];
      scn_total_size +=scntab[i].sh_size; } }

  printf("ehdrsize=%d;  %d sections are needed.\n", 
	sizeof(Elf32_Ehdr), scn_count);

  /* prepare a new elf header */
  newehdr.e_type=ET_REL;	/*relocatable*/
  newehdr.e_entry=0;
  newehdr.e_phoff=0;	/* no program execution header*/
  newehdr.e_shoff= sizeof(Elf32_Ehdr) + scn_total_size;
  newehdr.e_phentsize=0;
  newehdr.e_phnum=0;
  newehdr.e_shstrndx=scn_symt[newehdr.e_shstrndx];
  newehdr.e_shnum=scn_count;	/* number of symbol table sections */

  fprintf(stderr, "ehdr updated\n");

  /* write new elf header */
  write(outfd, &newehdr, sizeof(Elf32_Ehdr));

  /* no phdr written */
  /* copy section contents */
  for (i=1; i<scn_num; i++) {
    if (scn_symt[i]!=0 && scntab[i].sh_type != SHT_NOBITS) {
      fprintf(stderr, "%d size=%d\n", i, scntab[i].sh_size);
      if (scntab[i].sh_type==SHT_SYMTAB) {
	copy_new_symtab(elfd, outfd, symtab);}
      else 
	copy_bytes(elfd, outfd, scntab[i].sh_offset, scntab[i].sh_size);
      }}

  /* write updated section headers */
  /* write zeroth header */
  scn_offset=sizeof(Elf32_Ehdr);
  write(outfd, scntab[0], sizeof(Elf32_Shdr));
  for (i=1; i<scn_num; i++) {
    if (scn_symt[i]!=0) {
      j=scntab[i].sh_link;
      if (j!=0) scntab[i].sh_link=scn_symt[j]; /*rewrite link*/
      scntab[i].sh_offset=scn_offset;
      scn_offset += scntab[i].sh_size;
      write(outfd, scntab[i], sizeof(Elf32_Shdr));
      } }

  elf_end(elf);
  close(elfd);
  close(outfd);
  }


