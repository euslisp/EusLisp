/* GCC macros for XC-cube primitives for XC-cube shared memory model.
   version 0.10
   Copyright (C) 2001 Masahiro Yasugi.

   Supported platform:
   __i386__
   __alpha__
   __sparc_v9__
   _POWER _ARCH_PPC
   __mips__

   GCC compilation options:
   for UltraSparc:  -mcpu=ultrasparc
   for PowerPC:     -mcpu=powerpc
   */

#ifndef XCCMEM_H
#define XCCMEM_H

/*
 * assertion
 */

#define XCC_ASSERT(cond,msg) ({char msg[(cond)?1:(-1)]; 0;})

/*
 * Tools for instructions 
 */

typedef int xcc_DItype __attribute__ ((mode (DI)));
typedef int xcc_SItype __attribute__ ((mode (SI)));
typedef int xcc_HItype __attribute__ ((mode (HI)));
typedef int xcc_QItype __attribute__ ((mode (QI)));

typedef float xcc_SFtype __attribute__ ((mode (SF)));
typedef float xcc_DFtype __attribute__ ((mode (DF)));

#define FORCE_TYPE(TP,x) \
({ union { TP x1; typeof(x) x2; } _u ; _u.x2 = (x); _u.x1; })

/*
 * Instructions
 */

#ifdef __i386__

/* lock add $0,(%esp) とどっちが速い? */
#define xcc_slbar_VOID() do{\
  xcc_SItype _tmp1, _tmp2;\
  __asm__("xchgl %1,%0": "=m"(_tmp1), "=r"(_tmp2) :: "memory");\
}while(0)


#define xcc_rawcas_DI(loc,ov,nv) __xcc_rawcas_DI((loc),(ov),(nv))
extern __inline__ int
__xcc_rawcas_DI(xcc_DItype *loc, xcc_DItype ov, xcc_DItype nv){
  int s = 0; 
  union { xcc_DItype v; xcc_SItype w2[2]; } u;
  u.v = nv;
  __asm__ __volatile__("lock; cmpxchg8b %0\n"
		       "	jz 1f\n"
		       "	inc %1\n"
		       "1:"
		       : "=m"(*loc), "=r"(s), "=A"(ov)
		       : "m" (*loc), "1"(s), "2"(ov),
		       "b"(u.w2[0]), "c"(u.w2[1]) : "cc");
  return s;
}

#define xcc_rawcas_SI(loc,ov,nv) __xcc_rawcas_SI((loc),(ov),(nv))
extern __inline__ int
__xcc_rawcas_SI(xcc_SItype *loc, xcc_SItype ov, xcc_SItype nv){
  int s = 0; 
  __asm__ __volatile__("lock; cmpxchgl %6,%0\n"
		       "	jz 1f\n"
		       "	inc %1\n"
		       "1:"
		       : "=m"(*loc), "=r"(s), "=a"(ov)
		       : "m"(*loc), "1"(s), "2"(ov), "q"(nv) : "cc");
  return s;
}

#define xcc_rawcas_HI(loc,ov,nv) __xcc_rawcas_HI((loc),(ov),(nv))
extern __inline__ int
__xcc_rawcas_HI(xcc_HItype *loc, xcc_HItype ov, xcc_HItype nv){
  int s = 0; 
  __asm__ __volatile__("lock; cmpxchgw %6,%0\n"
		       "	jz 1f\n"
		       "	inc %1\n"
		       "1:"
		       : "=m"(*loc), "=r"(s), "=a"(ov)
		       : "m"(*loc), "1"(s), "2"(ov), "q"(nv) : "cc");
  return s;
}

#define xcc_cas_HI(loc,ov,nv) __xcc_cas_HI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_HI(xcc_HItype *loc, xcc_HItype ov, xcc_HItype nv){
  return (*loc != ov) || xcc_rawcas_HI(loc,ov,nv);
}


#define xcc_rawcas_QI(loc,ov,nv) __xcc_rawcas_QI((loc),(ov),(nv))
extern __inline__ int
__xcc_rawcas_QI(xcc_QItype *loc, xcc_QItype ov, xcc_QItype nv){
  int s = 0; 
  __asm__ __volatile__("lock; cmpxchgb %6,%0\n"
		       "	jz 1f\n"
		       "	inc %1\n"
		       "1:"
		       : "=m"(*loc), "=r"(s), "=a"(ov)
		       : "m"(*loc), "1"(s), "2"(ov), "q"(nv) : "cc");
  return s;
}

#define xcc_cas_QI(loc,ov,nv) __xcc_cas_QI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_QI(xcc_QItype *loc, xcc_QItype ov, xcc_QItype nv){
  return (*loc != ov) || xcc_rawcas_QI(loc,ov,nv);
}

#define xcc_atomic_swap_DI(loc,v) __xcc_atomic_swap_DI((loc),(v))
extern __inline__ xcc_DItype
__xcc_atomic_swap_DI(xcc_DItype *loc, xcc_DItype val){ 
  __asm__ __volatile__("movl %%eax,%%ebx\n"
		       "	movl %%edx,%%ecx\n"
		       "	lock\n"
		       "	cmpxchg8b %0\n"
		       "1:	lock\n"
		       "	cmpxchg8b %0\n"
		       "	jnz 1b"
		       : "=m"(*loc), "=A"(val) : "m"(*loc), "1"(val)
		       : "ecx", "ebx", "cc");
  return val;
}

/* lock 必要?? */
#define xcc_atomic_swap_SI(loc,v) __xcc_atomic_swap_SI((loc),(v))
extern __inline__ xcc_SItype
__xcc_atomic_swap_SI(xcc_SItype *loc, xcc_SItype val){ 
  __asm__ __volatile__("xchgl %1,%0"
		       : "=m"(*loc), "=r"(val) : "m"(*loc), "1"(val));
  return val;
}


#define xcc_atomic_swap_HI(loc,v) __xcc_atomic_swap_HI((loc),(v))
extern __inline__ xcc_HItype
__xcc_atomic_swap_HI(xcc_HItype *loc, xcc_HItype val){ 
  __asm__ __volatile__("xchgw %1,%0"
		       : "=m"(*loc), "=r"(val) : "m"(*loc), "1"(val));
  return val;
}

#define xcc_atomic_swap_QI(loc,v) __xcc_atomic_swap_QI((loc),(v))
extern __inline__ xcc_QItype
__xcc_atomic_swap_QI(xcc_QItype *loc, xcc_QItype val){
  __asm__ __volatile__("xchgb %1,%0"
		       : "=m"(*loc), "=r"(val) : "m"(*loc), "1"(val));
  return val;
}

#define xcc_atomic_write_DI(loc,v) __xcc_atomic_write_DI((loc),(v))
extern __inline__ void
__xcc_atomic_write_DI(xcc_DItype *loc, xcc_DItype val){
  xcc_DItype tmp;
  __asm__ __volatile__("movl %%eax,%%ebx\n"
		       "	movl %%edx,%%ecx\n"
		       "	lock\n"
		       "	cmpxchg8b %0\n"
		       "1:	lock\n"
		       "	cmpxchg8b %0\n"
		       "	jnz 1b"
		       : "=m"(*loc), "=A"(tmp) : "A"(val)
		       : "ecx", "ebx", "cc");
}

#define xcc_atomic_read_DI(loc) __xcc_atomic_read_DI(loc)
extern __inline__ xcc_DItype
__xcc_atomic_read_DI(xcc_DItype *loc){
  xcc_DItype val;
  __asm__ __volatile__("movl %%eax,%%ebx\n"
		       "	movl %%edx,%%ecx\n"
		       "	lock\n"
		       "	cmpxchg8b %1"
		       : "=A"(val) : "m"(*loc)
		       : "ecx", "ebx", "cc", "memory");
  return val;
}

#endif /* __i386__ */

#ifdef __alpha__
/* __alpha_ev4__ __alpha_ev5__ __alpha_ev6__ */

#define xcc_aabar_VOID() __asm__ __volatile__("mb":::"memory")

#define xcc_rawcas_DI(loc,ov,nv) xcc_cas_DI((loc),(ov),(nv))
#define xcc_cas_DI(loc,ov,nv) __xcc_cas_DI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_DI(xcc_DItype *loc, xcc_DItype ov, xcc_DItype nv){
  int cmp;
  xcc_DItype tmp;
  __asm__ __volatile__("ldq_l %0,%5\n"
		       "	cmpeq %0,%3,%1\n"
		       "	beq %1,1f\n"
		       "	mov %4,%1\n"
		       "	stq_c %1,%2\n"
		       "1:"
		       : "=&r"(tmp),"=&r"(cmp),"=m"(*loc)
		       : "r"(ov),"r"(nv),"m"(*loc));
  return !cmp; 
}

#define xcc_rawcas_SI(loc,ov,nv) xcc_cas_SI((loc),(ov),(nv))
#define xcc_cas_SI(loc,ov,nv) __xcc_cas_SI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_SI(xcc_SItype *loc, xcc_SItype ov, xcc_SItype nv){
  int cmp;
  xcc_SItype tmp;
  __asm__ __volatile__("ldl_l %0,%5\n"
		       "	cmpeq %0,%3,%1\n"
		       "	beq %1,1f\n"
		       "	mov %4,%1\n"
		       "	stl_c %1,%2\n"
		       "1:"
		       : "=&r"(tmp),"=&r"(cmp),"=m"(*loc)
		       : "rI"(ov),"rI"(nv),"m"(*loc));
  return !cmp; 
}

#define xcc_atomic_write_HI(loc,v) __xcc_atomic_write_HI((loc),(v))
extern __inline__ void
__xcc_atomic_write_HI(xcc_HItype *loc, xcc_HItype val){
  xcc_DItype _tmp1, _tmp2, *_tmpa, *_tmpb;
  __asm__ __volatile__("lda	%3,%0\n"
		       "	bic	%3,7,%4\n"
		       "	inswl	%6,%3,%2\n"
		       "1:	ldq_l	%1,0(%4)\n"
		       "	mskwl	%1,%3,%1\n"
		       "	bis	%1,%2,%1\n"
		       "	stq_c	%1,0(%4)\n"
		       "	bne	%1,1b"
		       : "=m"(*loc),"=r"(_tmp1),"=r"(_tmp2),
		       "=&r"(_tmpa),"=&r"(_tmpb)
		       : "m"(*loc), "r"(val)); 
}


#define xcc_atomic_write_QI(loc,v) __xcc_atomic_write_QI((loc),(v))
extern __inline__ void
__xcc_atomic_write_QI(xcc_QItype *loc, xcc_QItype val){
  xcc_DItype _tmp1, _tmp2, *_tmpa, *_tmpb;
  __asm__ __volatile__("lda	%3,%0\n"
		       "	bic	%3,7,%4\n"
		       "	insbl	%6,%3,%2\n"
		       "1:	ldq_l	%1,0(%4)\n"
		       "	mskbl	%1,%3,%1\n"
		       "	bis	%1,%2,%1\n"
		       "	stq_c	%1,0(%4)\n"
		       "	bne	%1,1b"
		       : "=m"(*loc),"=r"(_tmp1),"=r"(_tmp2),
		       "=&r"(_tmpa),"=&r"(_tmpb)
		       : "m"(*loc), "r"(val)); 
}

#endif /* __alpha__ */

#ifdef __sparc_v9__
#ifndef __arch64__

#define xcc_slbar_VOID() __asm__("membar #StoreLoad"::: "memory")

#define xcc_rawcas_DI(loc,ov,nv) __xcc_rawcas_DI((loc),(ov),(nv))
extern __inline__ int
__xcc_rawcas_DI(xcc_DItype *loc, xcc_DItype ov, xcc_DItype nv){
  xcc_DItype tmpa, tmpb, ovm=ov, nvm=nv;
  __asm__ __volatile__("ldx %6,%2\n"
		       "	ldx %7,%3\n"
		       "	casx [%5],%3,%2\n"
		       "	stx %2,%1"
		       : "=m"(*loc),"=m"(nvm),"=&r"(tmpa),"=&r"(tmpb)
		       : "m"(*loc),"r"(loc),"m"(nvm),"m"(ovm) : "cc");
  nv = nvm;
  return (nv != ov);
}

#define xcc_rawcas_SI(loc,ov,nv) __xcc_rawcas_SI((loc),(ov),(nv))
extern __inline__ int
__xcc_rawcas_SI(xcc_SItype *loc, xcc_SItype ov, xcc_SItype nv){
  __asm__ __volatile__("cas [%3],%5,%1"
		       : "=m"(*loc),"=&r"(nv)
		       : "m"(*loc),"r"(loc),"1"(nv),"r"(ov) : "cc");
  return (nv != ov);
}

#endif /* not __arch64__ */
#endif /* __sparc_v9__ */

#ifdef _POWER
#ifdef _ARCH_PPC

#define xcc_aabar_VOID() __asm__ __volatile__("sync":::"memory")
#define xcc_isync_VOID() __asm__ __volatile__("isync":::"memory")
#define xcc_ssbar_VOID() __asm__ __volatile__("eieio":::"memory")

#define xcc_rawcas_DI(loc,ov,nv) xcc_cas_SI((loc),(ov),(nv))
#define xcc_cas_DI(loc,ov,nv) XCC_ASSERT(0,_64bit_cas_not_support)
#define xcc_atomic_swap_DI(loc,v) XCC_ASSERT(0,_64bit_cas_not_support)
#define xcc_cas_DF(loc,ov,nv) XCC_ASSERT(0,_64bit_cas_not_support)
#define xcc_atomic_swap_DF(loc,v) XCC_ASSERT(0,_64bit_cas_not_support)

#define xcc_rawcas_SI(loc,ov,nv) xcc_cas_SI((loc),(ov),(nv))
#define xcc_cas_SI(loc,ov,nv) __xcc_cas_SI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_SI(xcc_SItype *loc, xcc_SItype ov, xcc_SItype nv){
  int cmp = 1;
  xcc_SItype tmp;
  __asm__ __volatile__("lwarx %2,0,%4\n"
		       "	cmpw %6,%2\n"
		       "	bne- 1f\n"
		       "	stwcx. %5,0,%4\n"
		       "	bne- 1f\n"
		       "	li %1,0\n"
		       "1:"
		       : "=m"(*loc),"=r"(cmp),"=&r"(tmp)
		       : "m"(*loc),"r"(loc),"r"(nv),"r"(ov),"1"(cmp) : "cc");
  return cmp; 
}

#endif /* _ARCH_PPC */
#endif /* _POWER */

#ifdef __mips__

#define xcc_rawcas_DI(loc,ov,nv) xcc_cas_DI((loc),(ov),(nv))
#define xcc_cas_DI(loc,ov,nv) __xcc_cas_DI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_DI(xcc_DItype *loc, xcc_DItype ov, xcc_DItype nv){
  int cmp;
  xcc_DItype tmp;
  __asm__ __volatile__(".set	noreorder\n"
		       "	lld %0,%5\n"
		       "	bne %0,%3,1f\n"
		       "	or %1,$0,$0\n"
		       "	or %1,%4,$0\n"
		       "	scd %1,%2\n"
		       "1:\n"
		       "	.set	reorder"
		       : "=&r"(tmp),"=&r"(cmp),"=m"(*loc)
		       : "r"(ov),"r"(nv),"m"(*loc));
  return !cmp; 
}

#define xcc_rawcas_SI(loc,ov,nv) xcc_cas_SI((loc),(ov),(nv))
#define xcc_cas_SI(loc,ov,nv) __xcc_cas_SI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_SI(xcc_SItype *loc, xcc_SItype ov, xcc_SItype nv){
  int cmp;
  xcc_SItype tmp;
  __asm__ __volatile__(".set	noreorder\n"
		       "	ll %0,%5\n"
		       "	bne %0,%3,1f\n"
		       "	or %1,$0,$0\n"
		       "	or %1,%4,$0\n"
		       "	sc %1,%2\n"
		       "1:\n"
		       "	.set	reorder"
		       : "=&r"(tmp),"=&r"(cmp),"=m"(*loc)
		       : "r"(ov),"r"(nv),"m"(*loc));
  return !cmp; 
}

#endif /* __mips__ */

/*
 * Common inst. and common emulations
 */

#ifndef xcc_nnbar_VOID
#define xcc_nnbar_VOID() __asm__ __volatile__("":::"memory")
#endif

#ifndef xcc_cas_DI
#define xcc_cas_DI(loc,ov,nv) __xcc_cas_DI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_DI(xcc_DItype *loc, xcc_DItype ov, xcc_DItype nv){
  return (*loc != ov) || xcc_rawcas_DI(loc,ov,nv);
}
#endif

#ifndef xcc_cas_SI
#define xcc_cas_SI(loc,ov,nv) __xcc_cas_SI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_SI(xcc_SItype *loc, xcc_SItype ov, xcc_SItype nv){
  return (*loc != ov) || xcc_rawcas_SI(loc,ov,nv);
}
#endif

#ifndef xcc_cas_HI
#define xcc_cas_HI(loc,ov,nv) __xcc_cas_HI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_HI(xcc_HItype *loc, xcc_HItype ov, xcc_HItype nv){
  int ofs = (loc - (xcc_HItype *)(xcc_SItype *)0) & 1;
  xcc_SItype *p = (xcc_SItype *)(loc - ofs), uov = *p;  
  union { xcc_SItype v; xcc_HItype s[2]; } unv;
  unv.v = uov;
  if(unv.s[ofs] != ov) return 1;
  unv.s[ofs] = nv;
  return xcc_rawcas_SI(p,uov,unv.v);
}
#endif

#ifndef xcc_cas_QI
#define xcc_cas_QI(loc,ov,nv) __xcc_cas_QI((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_QI(xcc_QItype *loc, xcc_QItype ov, xcc_QItype nv){
  int ofs = (loc - (xcc_QItype *)(xcc_SItype *)0) & 3;
  xcc_SItype *p = (xcc_SItype *)(loc - ofs), uov = *p;  
  union { xcc_SItype v; xcc_QItype c[4]; } unv;
  unv.v = uov;
  if(unv.c[ofs] != ov) return 1;
  unv.c[ofs] = nv;
  return xcc_rawcas_SI(p,uov,unv.v);
}
#endif

#ifndef xcc_cas_DF
#define xcc_cas_DF(loc,ov,nv) __xcc_cas_DF((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_DF(xcc_DFtype *loc, xcc_DFtype ov, xcc_DFtype nv){
  return xcc_cas_DI((xcc_DItype *)loc,
		    FORCE_TYPE(xcc_DItype,ov),
		    FORCE_TYPE(xcc_DItype,nv));
}
#endif

#ifndef xcc_cas_SF
#define xcc_cas_SF(loc,ov,nv) __xcc_cas_SF((loc),(ov),(nv))
extern __inline__ int
__xcc_cas_SF(xcc_SFtype *loc, xcc_SFtype ov, xcc_SFtype nv){
  return xcc_cas_SI((xcc_SItype *)loc,
		    FORCE_TYPE(xcc_SItype,ov),
		    FORCE_TYPE(xcc_SItype,nv));
}
#endif

#ifndef xcc_atomic_swap_DI
#define xcc_atomic_swap_DI(loc,v) __xcc_atomic_swap_DI((loc),(v))
extern __inline__ xcc_DItype
__xcc_atomic_swap_DI(xcc_DItype *loc, xcc_DItype val){
  xcc_DItype ov;
  do{ ov = *loc; }while(xcc_rawcas_DI(loc,ov,val));
  return ov;
}
#endif

#ifndef xcc_atomic_swap_SI
#define xcc_atomic_swap_SI(loc,v) __xcc_atomic_swap_SI((loc),(v))
extern __inline__ xcc_SItype
__xcc_atomic_swap_SI(xcc_SItype *loc, xcc_SItype val){
  xcc_SItype ov;
  do{ ov = *loc; }while(xcc_rawcas_SI(loc,ov,val));
  return ov;
}
#endif

#ifndef xcc_atomic_swap_HI
#define xcc_atomic_swap_HI(loc,v) __xcc_atomic_swap_HI((loc),(v))
extern __inline__ xcc_HItype
__xcc_atomic_swap_HI(xcc_HItype *loc, xcc_HItype val){
  int ofs = (loc- (xcc_HItype *)(xcc_SItype *)0) & 1;
  xcc_SItype *p = (xcc_SItype *)(loc - ofs), uov;
  union { xcc_SItype v; xcc_HItype s[2]; } unv;
  do{ unv.v = uov = *p; unv.s[ofs] = val; 
  }while(xcc_rawcas_SI(p,uov,unv.v));
  unv.v = uov; return unv.s[ofs];
}
#endif

#ifndef xcc_atomic_swap_QI
#define xcc_atomic_swap_QI(loc,v) __xcc_atomic_swap_QI((loc),(v))
extern __inline__ xcc_QItype
__xcc_atomic_swap_QI(xcc_QItype *loc, xcc_QItype val){
  int ofs = (loc- (xcc_QItype *)(xcc_SItype *)0) & 3;
  xcc_SItype *p = (xcc_SItype *)(loc - ofs), uov;
  union { xcc_SItype v; xcc_QItype c[4]; } unv;
  do{ unv.v = uov = *p ; unv.c[ofs] = val;
  }while(xcc_rawcas_SI(p,uov,unv.v));
  unv.v = uov; return unv.c[ofs];
}
#endif

#ifndef xcc_atomic_swap_DF
#define xcc_atomic_swap_DF(loc,v) __xcc_atomic_swap_DF((loc),(v))
extern __inline__ xcc_DFtype
__xcc_atomic_swap_DF(xcc_DFtype *loc, xcc_DFtype val){
  return FORCE_TYPE(xcc_DFtype,
		    xcc_atomic_swap_DI((xcc_DItype *)(loc),
				       FORCE_TYPE(xcc_DItype,val)));
}
#endif

#ifndef xcc_atomic_swap_SF
#define xcc_atomic_swap_SF(loc,v) __xcc_atomic_swap_SF((loc),(v))
extern __inline__ xcc_SFtype
__xcc_atomic_swap_SF(xcc_SFtype *loc, xcc_SFtype val){
  return FORCE_TYPE(xcc_SFtype,
		    xcc_atomic_swap_SI((xcc_SItype *)(loc),
				       FORCE_TYPE(xcc_SItype,val)));
}
#endif

/* end of Instructions */

/* *//* *//* *//* *//* */

/*
 * data mapping
 */

#ifdef __i386__

#define xcc_atomic_read_long_long(loc)\
(sizeof(*(loc))==8 ? xcc_atomic_read_DI((xcc_DItype *)(loc)) :\
 XCC_ASSERT((sizeof(*(loc))==8), atomic_read_long_long))

#define xcc_atomic_write_long_long(loc,v)\
do{ if(sizeof(*(loc))==8) xcc_atomic_write_DI((xcc_DItype *)(loc),(v)); \
else XCC_ASSERT((sizeof(*(loc))==8), atomic_write_long_long); }while(0)

#define xcc_slbar() xcc_slbar_VOID()
#define xcc_sabar() xcc_slbar_VOID()
#define xcc_albar() xcc_slbar_VOID()
#define xcc_aabar() xcc_slbar_VOID()

#define xcc_start_access_after_lock() xcc_nnbar_VOID()
#define xcc_start_read_after_lock()  xcc_nnbar_VOID()
#define xcc_start_write_after_lock()  xcc_nnbar_VOID()

#endif /* __i386__ */

#ifdef __alpha__
/* __alpha_ev4__ __alpha_ev5__ __alpha_ev6__ */

#define xcc_atomic_write_char(loc,v)\
do{ if(sizeof(*(loc))==1) xcc_atomic_write_QI((xcc_QItype *)(loc),(v)); \
else XCC_ASSERT((sizeof(*(loc))==1), atomic_write_char); }while(0)

#define xcc_atomic_write_short(loc,v)\
do{ if(sizeof(*(loc))==2) xcc_atomic_write_HI((xcc_HItype *)(loc),(v)); \
else XCC_ASSERT((sizeof(*(loc))==2), atomic_write_short); }while(0)

#define xcc_defaultbar_VOID() xcc_aabar_VOID()

#define XCC_LONG_TYPE_SIZE 8
#define XCC_PTR_TYPE_SIZE 8

#endif /* __alpha__ */

#ifdef __sparc_v9__
#ifndef __arch64__
/*  -mcpu=ultrasparc */

/* assuming TSO */
#define xcc_slbar() xcc_slbar_VOID()
#define xcc_sabar() xcc_slbar_VOID()
#define xcc_albar() xcc_slbar_VOID()
#define xcc_aabar() xcc_slbar_VOID()

#define xcc_start_access_after_lock() xcc_nnbar_VOID()
#define xcc_start_read_after_lock()  xcc_nnbar_VOID()
#define xcc_start_write_after_lock()  xcc_nnbar_VOID()

#endif /* ! __arch64__ */
#endif /* __sparc_v9__ */

#ifdef _POWER
#ifdef _ARCH_PPC
/*  -mcpu=powerpc */

#define xcc_atomic_read_long_long(loc) XCC_ASSERT(0, atomic_read_long_long)
#define xcc_atomic_write_long_long(loc,v)\
do{ XCC_ASSERT((sizeof(*(loc))==8), atomic_write_long_long); }while(0)
#define xcc_atomic_swap_long_long(loc,v) XCC_ASSERT(0, atomic_swap_long_long)
#define xcc_cas_long_long(loc,ov,nv) XCC_ASSERT(0, cas_long_long)
#define xcc_atomic_swap_double(loc,v) XCC_ASSERT(0, atomic_swap_double)
#define xcc_cas_double(loc,ov,nv) XCC_ASSERT(0, cas_double)

#define xcc_defaultbar_VOID() xcc_aabar_VOID()
#define xcc_ssbar() xcc_ssbar_VOID()
#define xcc_start_access_after_lock() xcc_isync_VOID()
#define xcc_start_read_after_lock()  xcc_isync_VOID()
#define xcc_start_write_after_lock()  xcc_isync_VOID()

#endif /* _ARCH_PPC */
#endif /* _POWER */

#ifdef __mips__

#define XCC_INT_TYPE_SIZE (_MIPS_SZINT/8)
#define XCC_LONG_TYPE_SIZE (_MIPS_SZLONG/8)
#define XCC_PTR_TYPE_SIZE (_MIPS_SZPTR/8)

#endif /* __mips__ */

/*
 * Common data mapping and/or common (usual) GNUC case
 */

#ifndef XCC_CHAR_TYPE_SIZE
#define XCC_CHAR_TYPE_SIZE 1
#endif
#ifndef XCC_SHORT_TYPE_SIZE
#define XCC_SHORT_TYPE_SIZE 2
#endif
#ifndef XCC_INT_TYPE_SIZE
#define XCC_INT_TYPE_SIZE 4
#endif
#ifndef XCC_LONG_TYPE_SIZE
#define XCC_LONG_TYPE_SIZE 4
#endif
#ifndef XCC_LONG_LONG_TYPE_SIZE
#define XCC_LONG_LONG_TYPE_SIZE 8
#endif
#ifndef XCC_FLOAT_TYPE_SIZE
#define XCC_FLOAT_TYPE_SIZE 4
#endif
#ifndef XCC_DOUBLE_TYPE_SIZE
#define XCC_DOUBLE_TYPE_SIZE 8
#endif
#ifndef XCC_PTR_TYPE_SIZE
#define XCC_PTR_TYPE_SIZE 4
#endif

#ifndef xcc_atomic_read_char
#define xcc_atomic_read_char(loc) (*(volatile char *)(loc))
#endif
#ifndef xcc_atomic_read_short
#define xcc_atomic_read_short(loc) (*(volatile short *)(loc))
#endif
#ifndef xcc_atomic_read_int
#define xcc_atomic_read_int(loc) (*(volatile int *)(loc))
#endif
#ifndef xcc_atomic_read_long
#define xcc_atomic_read_long(loc) (*(volatile long *)(loc))
#endif
/* long long: except for i386, PPC32, MIPS1/2  */
#ifndef xcc_atomic_read_long_long
#define xcc_atomic_read_long_long(loc) (*(volatile long long *)(loc))
#endif
#ifndef xcc_atomic_read_float
#define xcc_atomic_read_float(loc) (*(volatile float *)(loc))
#endif
#ifndef xcc_atomic_read_double
#define xcc_atomic_read_double(loc) (*(volatile double *)(loc))
#endif
#ifndef xcc_atomic_read_ptr
#define xcc_atomic_read_ptr(loc) (*(void * volatile *)(loc))
#endif

/* char: except for Alhpa  */
#ifndef xcc_atomic_write_char
#define xcc_atomic_write_char(loc,v) do{*(volatile char *)(loc)=(v);}while(0)
#endif
#ifndef xcc_atomic_write_short
#define xcc_atomic_write_short(loc,v) do{*(volatile short *)(loc)=(v);}while(0)
#endif
#ifndef xcc_atomic_write_int
#define xcc_atomic_write_int(loc,v) do{*(volatile int *)(loc)=(v);}while(0)
#endif
#ifndef xcc_atomic_write_long
#define xcc_atomic_write_long(loc,v) do{*(volatile long *)(loc)=(v);}while(0)
#endif
/* long long: except for i386, PPC32, MIPS1/2  */
#ifndef xcc_atomic_write_long_long
#define xcc_atomic_write_long_long(loc,v)\
do{*(volatile long long *)(loc)=(v);}while(0)
#endif
#ifndef xcc_atomic_write_float
#define xcc_atomic_write_float(loc,v)\
do{*(volatile float *)(loc)=(v);}while(0)
#endif
#ifndef xcc_atomic_write_double
#define xcc_atomic_write_double(loc,v)\
do{*(volatile double *)(loc)=(v);}while(0)
#endif
#ifndef xcc_atomic_write_ptr
#define xcc_atomic_write_ptr(loc,v) do{*(void * volatile *)(loc)=(v);}while(0)
#endif

#ifndef xcc_atomic_swap_char
#define xcc_atomic_swap_char(loc,v)\
(sizeof(*(loc))==1 ? xcc_atomic_swap_QI((xcc_QItype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==1), atomic_swap_char))
#endif

#ifndef xcc_atomic_swap_short
#define xcc_atomic_swap_short(loc,v)\
(sizeof(*(loc))==2 ? xcc_atomic_swap_HI((xcc_HItype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==2), atomic_swap_short))
#endif

#if XCC_INT_TYPE_SIZE == 4
#ifndef xcc_atomic_swap_int
#define xcc_atomic_swap_int(loc,v)\
(sizeof(*(loc))==4 ? xcc_atomic_swap_SI((xcc_SItype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==4), atomic_swap_int))
#endif
#elif XCC_INT_TYPE_SIZE == 8
#ifndef xcc_atomic_swap_int
#define xcc_atomic_swap_int(loc,v)\
(sizeof(*(loc))==8 ? xcc_atomic_swap_DI((xcc_DItype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==8), atomic_swap_int))
#endif
#endif /* XCC_INT_TYPE_SIZE == 8 */

#if XCC_LONG_TYPE_SIZE == 4
#ifndef xcc_atomic_swap_long
#define xcc_atomic_swap_long(loc,v)\
(sizeof(*(loc))==4 ? xcc_atomic_swap_SI((xcc_SItype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==4), atomic_swap_long))
#endif
#elif XCC_LONG_TYPE_SIZE == 8
#ifndef xcc_atomic_swap_long
#define xcc_atomic_swap_long(loc,v)\
(sizeof(*(loc))==8 ? xcc_atomic_swap_DI((xcc_DItype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==8), atomic_swap_long))
#endif
#endif /* XCC_LONG_TYPE_SIZE == 8 */

#ifndef xcc_atomic_swap_long_long
#define xcc_atomic_swap_long_long(loc,v)\
(sizeof(*(loc))==8 ? xcc_atomic_swap_DI((xcc_DItype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==8), atomic_swap_long_long))
#endif

#ifndef xcc_atomic_swap
#define xcc_atomic_swap(loc,v)\
(sizeof(*(loc))==1 ? xcc_atomic_swap_QI((xcc_QItype *)(loc),(v)) :\
 sizeof(*(loc))==2 ? xcc_atomic_swap_HI((xcc_HItype *)(loc),(v)) :\
 sizeof(*(loc))==4 ? xcc_atomic_swap_SI((xcc_SItype *)(loc),(v)) :\
 sizeof(*(loc))==8 ? xcc_atomic_swap_DI((xcc_DItype *)(loc),(v)) :\
 XCC_ASSERT(((sizeof(*(loc))==1) && (__alignof__(*(loc))==1) ||\
             (sizeof(*(loc))==2) && (__alignof__(*(loc))==2) ||\
             (sizeof(*(loc))==4) && (__alignof__(*(loc))==4) ||\
             (sizeof(*(loc))==8) && (__alignof__(*(loc))==8)),\
           atomic_swap))
#endif

#ifndef xcc_atomic_swap_float
#define xcc_atomic_swap_float(loc,v)\
(sizeof(*(loc))==4 ? xcc_atomic_swap_SF((xcc_SFtype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==4), atomic_swap_float))
#endif

#ifndef xcc_atomic_swap_double
#define xcc_atomic_swap_double(loc,v)\
(sizeof(*(loc))==8 ? xcc_atomic_swap_DF((xcc_DFtype *)(loc),(v)) :\
 XCC_ASSERT((sizeof(*(loc))==8), atomic_swap_double))
#endif

#if XCC_PTR_TYPE_SIZE == 4
#ifndef xcc_atomic_swap_ptr
#define xcc_atomic_swap_ptr(loc,v)\
(sizeof(*(loc))==4 ? \
 xcc_atomic_swap_SI((xcc_SItype *)(loc),(xcc_SItype)(v)) :\
 XCC_ASSERT((sizeof(*(loc))==4), atomic_swap_ptr))
#endif
#elif XCC_PTR_TYPE_SIZE == 8
#ifndef xcc_atomic_swap_ptr
#define xcc_atomic_swap_ptr(loc,v)\
(sizeof(*(loc))==8 ? \
 xcc_atomic_swap_DI((xcc_DItype *)(loc),(xcc_DItype)(v)) :\
 XCC_ASSERT((sizeof(*(loc))==8), atomic_swap_ptr))
#endif
#endif /* XCC_PTR_TYPE_SIZE == 8 */

#ifndef xcc_cas_char
#define xcc_cas_char(loc,ov,nv)\
(sizeof(*(loc))==1 ? xcc_cas_QI((xcc_QItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==1), cas_char))
#endif

#ifndef xcc_cas_short
#define xcc_cas_short(loc,ov,nv)\
(sizeof(*(loc))==2 ? xcc_cas_HI((xcc_HItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==2), cas_short))
#endif

#if XCC_INT_TYPE_SIZE == 4
#ifndef xcc_cas_int
#define xcc_cas_int(loc,ov,nv)\
(sizeof(*(loc))==4 ? xcc_cas_SI((xcc_SItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==4), cas_int))
#endif
#elif XCC_INT_TYPE_SIZE == 8
#ifndef xcc_cas_int
#define xcc_cas_int(loc,ov,nv)\
(sizeof(*(loc))==8 ? xcc_cas_DI((xcc_DItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==8), cas_int))
#endif
#endif /* XCC_INT_TYPE_SIZE == 8 */

/* raw cas */
#if XCC_INT_TYPE_SIZE == 4
#ifndef xcc_rawcas_int
#define xcc_rawcas_int(loc,ov,nv)\
(sizeof(*(loc))==4 ? xcc_rawcas_SI((xcc_SItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==4), rawcas_int))
#endif
#elif XCC_INT_TYPE_SIZE == 8
#ifndef xcc_rawcas_int
#define xcc_rawcas_int(loc,ov,nv)\
(sizeof(*(loc))==8 ? xcc_rawcas_DI((xcc_DItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==8), rawcas_int))
#endif
#endif /* XCC_INT_TYPE_SIZE == 8 */

#if XCC_LONG_TYPE_SIZE == 4
#ifndef xcc_cas_long
#define xcc_cas_long(loc,ov,nv)\
(sizeof(*(loc))==4 ? xcc_cas_SI((xcc_SItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==4), cas_long))
#endif
#elif XCC_LONG_TYPE_SIZE == 8
#ifndef xcc_cas_long
#define xcc_cas_long(loc,ov,nv)\
(sizeof(*(loc))==8 ? xcc_cas_DI((xcc_DItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==8), cas_long))
#endif
#endif /* XCC_LONG_TYPE_SIZE == 8 */

#ifndef xcc_cas_long_long
#define xcc_cas_long_long(loc,ov,nv)\
(sizeof(*(loc))==8 ? xcc_cas_DI((xcc_DItype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==8), cas_long_long))
#endif

#ifndef xcc_cas_float
#define xcc_cas_float(loc,ov,nv)\
(sizeof(*(loc))==4 ? xcc_cas_SF((xcc_SFtype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==4), cas_float))
#endif

#ifndef xcc_cas_double
#define xcc_cas_double(loc,ov,nv)\
(sizeof(*(loc))==8 ? xcc_cas_DF((xcc_DFtype *)(loc),(ov),(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==8), cas_double))
#endif

#if XCC_PTR_TYPE_SIZE == 4
#ifndef xcc_cas_ptr
#define xcc_cas_ptr(loc,ov,nv)\
(sizeof(*(loc))==4 ? \
 xcc_cas_SI((xcc_SItype *)(loc),(xcc_SItype)(ov),(xcc_SItype)(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==4), cas_ptr))
#endif
#elif XCC_PTR_TYPE_SIZE == 8
#ifndef xcc_cas_ptr
#define xcc_cas_ptr(loc,ov,nv)\
(sizeof(*(loc))==8 ? \
 xcc_cas_DI((xcc_DItype *)(loc),(xcc_DItype)(ov),(xcc_DItype)(nv)) :\
 XCC_ASSERT((sizeof(*(loc))==8), cas_ptr))
#endif
#endif /* XCC_PTR_TYPE_SIZE == 8 */

#ifndef xcc_defaultbar_VOID
#define xcc_defaultbar_VOID() xcc_nnbar_VOID()
#endif

#ifndef xcc_ssbar
#define xcc_ssbar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_slbar
#define xcc_slbar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_sabar
#define xcc_sabar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_lsbar
#define xcc_lsbar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_llbar
#define xcc_llbar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_labar
#define xcc_labar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_asbar
#define xcc_asbar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_albar
#define xcc_albar() xcc_defaultbar_VOID()
#endif
#ifndef xcc_aabar
#define xcc_aabar() xcc_defaultbar_VOID()
#endif

/* Pentium's spinlock means aabar() Alpha's spinlock does not */
#ifndef xcc_start_access_after_lock
#define xcc_start_access_after_lock() xcc_aabar()
#endif
#ifndef xcc_start_access_after_read
#define xcc_start_access_after_read() xcc_labar()
#endif
#ifndef xcc_start_access_after_write
#define xcc_start_access_after_write() xcc_sabar()
#endif
#ifndef xcc_start_read_after_lock
#define xcc_start_read_after_lock() xcc_albar()
#endif
#ifndef xcc_start_read_after_read
#define xcc_start_read_after_read() xcc_llbar()
#endif
#ifndef xcc_start_read_after_write
#define xcc_start_read_after_write() xcc_slbar()
#endif
#ifndef xcc_start_write_after_lock
#define xcc_start_write_after_lock() xcc_asbar()
#endif
#ifndef xcc_start_write_after_read
#define xcc_start_write_after_read() xcc_lsbar()
#endif
#ifndef xcc_start_write_after_write
#define xcc_start_write_after_write() xcc_ssbar()
#endif

#ifndef xcc_finish_access_before_unlock
#define xcc_finish_access_before_unlock() xcc_asbar()
#endif
#ifndef xcc_finish_access_before_read
#define xcc_finish_access_before_read() xcc_albar()
#endif
#ifndef xcc_finish_access_before_write
#define xcc_finish_access_before_write() xcc_asbar()
#endif
#ifndef xcc_finish_read_before_unlock
#define xcc_finish_read_before_unlock() xcc_lsbar()
#endif
#ifndef xcc_finish_read_before_read
#define xcc_finish_read_before_read() xcc_llbar()
#endif
#ifndef xcc_finish_read_before_write
#define xcc_finish_read_before_write()  xcc_lsbar()
#endif
#ifndef xcc_finish_write_before_unlock
#define xcc_finish_write_before_unlock() xcc_ssbar()
#endif
#ifndef xcc_finish_write_before_read
#define xcc_finish_write_before_read() xcc_slbar()
#endif
#ifndef xcc_finish_write_before_write
#define xcc_finish_write_before_write() xcc_ssbar()
#endif

#ifndef xcc_LOCK_INITIALIZER
#define xcc_LOCK_INITIALIZER 0
#endif
#ifndef xcc_lock_t
#define xcc_lock_t int
#endif
#ifndef xcc_try_lock
#define xcc_try_lock(loc) xcc_cas_int((loc),0,1)
#endif
#ifndef xcc_spin_lock
#define xcc_spin_lock(loc) __xcc_spin_lock(loc)
extern __inline__ void
__xcc_spin_lock(int *loc){ while(xcc_try_lock(loc)) xcc_llbar(); }
#endif
#ifndef xcc_release_lock
#define xcc_release_lock(loc) xcc_atomic_write_int((loc),0)
#endif

#ifndef xcc_RWLOCK_INITIALIZER
#define xcc_RWLOCK_INITIALIZER 0
#endif
#ifndef xcc_rwlock_t
#define xcc_rwlock_t int
#endif
#ifndef xcc_try_rlock
#define xcc_try_rlock(loc) __xcc_try_rlock(loc)
extern __inline__ int
__xcc_try_rlock(int *loc){
  int c=xcc_atomic_read_int(loc);
  return ((c<0) || xcc_rawcas_int(loc,c,c+1));
}
#endif
#ifndef xcc_spin_rlock
#define xcc_spin_rlock(loc) __xcc_spin_rlock(loc)
extern __inline__ void
__xcc_spin_rlock(int *loc){ while(xcc_try_rlock(loc)) xcc_llbar(); }
#endif
#ifndef xcc_release_rlock
#define xcc_release_rlock(loc) __xcc_release_rlock(loc)
extern __inline__ void
__xcc_release_rlock(int *loc){
  int c; do{c = *loc;}while(xcc_rawcas_int(loc,c,c-1));
}
#endif
#ifndef xcc_try_wlock
#define xcc_try_wlock(loc) xcc_cas_int((loc),0,-1)
#endif
#ifndef xcc_spin_wlock
#define xcc_spin_wlock(loc) __xcc_spin_wlock(loc)
extern __inline__ void
__xcc_spin_wlock(int *loc){ while(xcc_try_wlock(loc)) xcc_llbar(); }
#endif
#ifndef xcc_release_wlock
#define xcc_release_wlock(loc) xcc_atomic_write_int((loc),0)
#endif

/* *//* *//* *//* *//* */

/*
 * xccmem API primitives
 */

#define atomic_read_char(loc) xcc_atomic_read_char(&(loc))
#define atomic_read_short(loc) xcc_atomic_read_short(&(loc))
#define atomic_read_int(loc) xcc_atomic_read_int(&(loc))
#define atomic_read_long(loc) xcc_atomic_read_long(&(loc))
#define atomic_read_long_long(loc) xcc_atomic_read_long_long(&(loc))
#define atomic_read_float(loc) xcc_atomic_read_float(&(loc))
#define atomic_read_double(loc) xcc_atomic_read_double(&(loc))
#define atomic_read_ptr(loc) xcc_atomic_read_ptr(&(loc))

#define atomic_read_volatile_char(loc) atomic_read_char(loc)
#define atomic_read_volatile_short(loc) atomic_read_short(loc)
#define atomic_read_volatile_int(loc) atomic_read_int(loc)
#define atomic_read_volatile_long(loc) atomic_read_long(loc)
#define atomic_read_volatile_long_long(loc) atomic_read_long_long(loc)
#define atomic_read_volatile_float(loc) atomic_read_float(loc)
#define atomic_read_volatile_double(loc) atomic_read_double(loc)
#define atomic_read_volatile_ptr(loc) atomic_read_ptr(loc)

#define read_volatile_char(loc) atomic_read_char(loc)
#define read_volatile_short(loc) atomic_read_short(loc)
#define read_volatile_int(loc) atomic_read_int(loc)
#define read_volatile_long(loc) atomic_read_long(loc)
#define read_volatile_long_long(loc) atomic_read_long_long(loc)
#define read_volatile_float(loc) atomic_read_float(loc)
#define read_volatile_double(loc) atomic_read_double(loc)
#define read_volatile_ptr(loc) atomic_read_ptr(loc)

#define atomic_write_char(loc,v) xcc_atomic_write_char(&(loc),(v))
#define atomic_write_short(loc,v) xcc_atomic_write_short(&(loc),(v))
#define atomic_write_int(loc,v) xcc_atomic_write_int(&(loc),(v))
#define atomic_write_long(loc,v) xcc_atomic_write_long(&(loc),(v))
#define atomic_write_long_long(loc,v) xcc_atomic_write_long_long(&(loc),(v))
#define atomic_write_float(loc,v) xcc_atomic_write_float(&(loc),(v))
#define atomic_write_double(loc,v) xcc_atomic_write_double(&(loc),(v))
#define atomic_write_ptr(loc,v) xcc_atomic_write_ptr(&(loc),(v))

#define atomic_write_volatile_char(loc, v) atomic_write_char((loc), (v))
#define atomic_write_volatile_short(loc, v) atomic_write_short((loc), (v))
#define atomic_write_volatile_int(loc, v) atomic_write_int((loc), (v))
#define atomic_write_volatile_long(loc, v) atomic_write_long((loc), (v))
#define atomic_write_volatile_long_long(loc, v) \
atomic_write_long_long((loc), (v))
#define atomic_write_volatile_float(loc, v) atomic_write_float((loc), (v))
#define atomic_write_volatile_double(loc, v) atomic_write_double((loc), (v))
#define atomic_write_volatile_ptr(loc, v) atomic_write_ptr((loc), (v))

#define write_volatile_char(loc, v) atomic_write_char((loc), (v))
#define write_volatile_short(loc, v) atomic_write_short((loc), (v))
#define write_volatile_int(loc, v) atomic_write_int((loc), (v))
#define write_volatile_long(loc, v) atomic_write_long((loc), (v))
#define write_volatile_long_long(loc, v) atomic_write_long_long((loc), (v))
#define write_volatile_float(loc, v) atomic_write_float((loc), (v))
#define write_volatile_double(loc, v) atomic_write_double((loc), (v))
#define write_volatile_ptr(loc, v) atomic_write_ptr((loc), (v))

#define atomic_swap_char(loc,v) xcc_atomic_swap_char(&(loc),(v))
#define atomic_swap_short(loc,v) xcc_atomic_swap_short(&(loc),(v))
#define atomic_swap_int(loc,v) xcc_atomic_swap_int(&(loc),(v))
#define atomic_swap_long(loc,v) xcc_atomic_swap_long(&(loc),(v))
#define atomic_swap_long_long(loc,v) xcc_atomic_swap_long_long(&(loc),(v))
#define atomic_swap_float(loc,v) xcc_atomic_swap_float(&(loc),(v))
#define atomic_swap_double(loc,v) xcc_atomic_swap_double(&(loc),(v))
#define atomic_swap_ptr(loc,v) xcc_atomic_swap_ptr(&(loc),(v))

#define atomic_swap(loc,v) xcc_atomic_swap(&(loc),(v))

#define cas_char(loc,ov,nv) xcc_cas_char(&(loc),(ov),(nv))
#define cas_short(loc,ov,nv) xcc_cas_short(&(loc),(ov),(nv))
#define cas_int(loc,ov,nv) xcc_cas_int(&(loc),(ov),(nv))
#define cas_long(loc,ov,nv) xcc_cas_long(&(loc),(ov),(nv))
#define cas_long_long(loc,ov,nv) xcc_cas_long_long(&(loc),(ov),(nv))
#define cas_float(loc,ov,nv) xcc_cas_float(&(loc),(ov),(nv))
#define cas_double(loc,ov,nv) xcc_cas_double(&(loc),(ov),(nv))
#define cas_ptr(loc,ov,nv) xcc_cas_ptr(&(loc),(ov),(nv))

#define ssbar() xcc_ssbar()
#define slbar() xcc_slbar()
#define sabar() xcc_sabar()
#define lsbar() xcc_lsbar()
#define llbar() xcc_llbar()
#define labar() xcc_labar()
#define asbar() xcc_asbar()
#define albar() xcc_albar()
#define aabar() xcc_aabar()

#define start_access_after_lock() xcc_start_access_after_lock()
#define start_access_after_read() xcc_start_access_after_read()
#define start_access_after_write() xcc_start_access_after_write()
#define start_read_after_lock() xcc_start_read_after_lock()
#define start_read_after_read() xcc_start_read_after_read()
#define start_read_after_write() xcc_start_read_after_write()
#define start_write_after_lock() xcc_start_write_after_lock()
#define start_write_after_read() xcc_start_write_after_read()
#define start_write_after_write() xcc_start_write_after_write()

#define finish_access_before_unlock() xcc_finish_access_before_unlock()
#define finish_access_before_read() xcc_finish_access_before_read()
#define finish_access_before_write() xcc_finish_access_before_write()
#define finish_read_before_unlock() xcc_finish_read_before_unlock()
#define finish_read_before_read() xcc_finish_read_before_read()
#define finish_read_before_write() xcc_finish_read_before_write()
#define finish_write_before_unlock() xcc_finish_write_before_unlock()
#define finish_write_before_read() xcc_finish_write_before_read()
#define finish_write_before_write() xcc_finish_write_before_write()

#define LOCK_INITIALIZER xcc_LOCK_INITIALIZER
#define lock_t xcc_lock_t
#define try_lock(loc) xcc_try_lock(&(loc))
#define spin_lock(loc) xcc_spin_lock(&(loc))
#define release_lock(loc) xcc_release_lock(&(loc))

#define RWLOCK_INITIALIZER xcc_RWLOCK_INITIALIZER
// #define rwlock_t xcc_rwlock_t /* R.Hanai */
#define try_rlock(loc) xcc_try_rlock(&(loc))
#define spin_rlock(loc) xcc_spin_rlock(&(loc))
#define release_rlock(loc) xcc_release_rlock(&(loc))
#define try_wlock(loc) xcc_try_wlock(&(loc))
#define spin_wlock(loc) xcc_spin_wlock(&(loc))
#define release_wlock(loc) xcc_release_wlock(&(loc))

/* end of xccmem API primitives */

/* *//* *//* *//* *//* */

#endif /* not XCCMEM_H */
