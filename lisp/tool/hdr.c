#include <fcntl.h>
#include <filehdr.h>
#include <aouthdr.h>
#include <scnhdr.h>
#include <sym.h>

main(argc,argv)
int argc;
char *argv[];
{ int fd,i;
  struct filehdr hdr;
  struct aouthdr ahdr;
  struct scnhdr  shdr;
  HDRR symhdr;
  FDR fdr;

  fd=open(argv[1],O_RDONLY);
  if (fd<0) {printf("cannot open %s\n",argv[1]); exit(1);}

  read(fd, &hdr, sizeof(hdr));
  printf("filehdr\nmagic=0x%x nscns=%d timdat=0x%x symptr=0x%x\n",
	hdr.f_magic,hdr.f_nscns, hdr.f_timdat, hdr.f_symptr);
  printf("nsyms=%d opthdr=0x%x flags=0x%x\n\n",hdr.f_nsyms, hdr.f_opthdr,
	hdr.f_flags);

  read(fd, &ahdr, sizeof(ahdr));
  printf("aouthdr:\nmagic=0x%x vstamp=0x%x tsize=0x%x dsize=0x%x bsize=0x%x\n",
	ahdr.magic, ahdr.vstamp, ahdr.tsize, ahdr.dsize, ahdr.bsize);
  printf("entry=0x%x text_start=0x%x data_start=0x%x bss_start=0x%x\n",
	ahdr.entry, ahdr.text_start, ahdr.data_start, ahdr.bss_start);

  for (i=0; i<hdr.f_nscns; i++) {
    read(fd, &shdr, sizeof(shdr));
    printf("\nsection %d\nsname=%s paddr=0x%x vaddr=0x%x size=0x%x scnptr=0x%x\n",
	i,shdr.s_name, shdr.s_paddr, shdr.s_vaddr, shdr.s_size, shdr.s_scnptr);
    printf("relptr=0x%x lnnoptr=0x%x nreloc=0x%x nlnno=0x%x flags=0x%x\n",
	shdr.s_relptr, shdr.s_lnnoptr, shdr.s_nreloc, shdr.s_nlnno, shdr.s_flags);
    }

  lseek(fd, hdr.f_symptr,0);
  read(fd,&symhdr,sizeof(symhdr));
  printf("\nsymbolic header:\n");
  printf("magic=0x%x vstamp=0x%x ilinemax=%d cbLine=%d cbLineOffset=%d\n",
	 symhdr.magic, symhdr.vstamp, symhdr.ilineMax, symhdr.cbLine,
	 symhdr.cbLineOffset);
  printf("idnMax=0x%x cbDnOffset=0x%x ipdMax=%d cbPdOffset=%d\n",
	 symhdr.idnMax, symhdr.cbDnOffset, symhdr.ipdMax, symhdr.cbPdOffset);
  printf("isymMax=0x%x cbSymOffset=0x%x ioptMax=%d cbOptOffset=%d\n",
	 symhdr.isymMax, symhdr.cbSymOffset, symhdr.ioptMax, symhdr.cbOptOffset);
  printf("issExtMax=%d cbSsExtOffset=0x%x ifdMax=%d cbFdOffset=0x%x\n",
	 symhdr.issExtMax, symhdr.cbSsExtOffset, symhdr.ifdMax, symhdr.cbFdOffset);
  printf("crfd=%d cbRfdOffset=0x%x iextMax=%d cbExtOffset=0x%x\n",
	 symhdr.crfd, symhdr.cbRfdOffset, symhdr.iextMax, symhdr.cbExtOffset);


  printf("\nfile descriptor header\n");
  lseek(fd,symhdr.cbFdOffset,0);
  for (i=0; i<symhdr.ifdMax; i++) {
    read(fd, &fdr, sizeof(fdr));
    printf("%d adr=0x%x rss=0x%x ",i, fdr.adr, fdr.rss);
  printf("issBase=0x%x cbSs=0x%x isymBase=0x%x csym=0x%x\n",
		fdr.issBase, fdr.cbSs, fdr.isymBase, fdr.csym); }
  }


