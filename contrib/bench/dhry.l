#|
Path: etlcom!gama!nttlab!icot32!kddlab!uunet!husc6!bbn!rochester!pt.cs.cmu.edu!g.gp.cs.cmu.edu!lehmann
From: lehmann@g.gp.cs.cmu.edu (Eric Lehmann)
Newsgroups: comp.lang.lisp
Subject: lisp version of dhrystone benchmark
Message-ID: <2715@pt.cs.cmu.edu>
Date: 16 Aug 88 05:31:31 GMT
Sender: netnews@pt.cs.cmu.edu
Reply-To: lehmann@g.gp.cs.cmu.edu (Eric Lehmann)
Organization: Carnegie-Mellon University, CS/RI
Lines: 935
Keywords:
|#

;;;
; This file is a Common LISP translation of the C version of Dhrystone 2.0.
;
; Care was taken to declare the types of all variables.  Where necessary
; to get around compiler stupidity the results of operations were redeclared,
; using 'the', to the obvious type.  We invite compiler authors to strive to
; produce good code for programs which contain fewer declarations.
;
; The declarations had a major effect on the performance of the program
; for some machines, and absolutely no effect on the speed of execution
; for others.  Special-purpose LISP hardware probably does not benefit
; from most of the declarations.
;  
; This benchmark exercises only a small part of the Common LISP language.
; It manipulates only simple data objects like characters, integers, and
; arrays.  It uses simple control structures.  It does not use lexical
; closures or throws.  It does no memory allocation.  Certainly this program
; is not typical LISP code.  The Dhrystone benchmark estimates the speed
; of ordinary operations used in a large number of programs.  It may be
; useful to benchmark the same operations in LISP.  The LISP Dhrystone
; performance does roughly follow the C Dhrystone figures.
;
; We do not know if the LISP Dhrystone performance of a machine can be used
; to predict (or guess) the speed of the machine running other programs.
; From the numbers below it is obvious that the LISP version of Dhrystone 2.0
; runs slower than the C version on most machines.  From the experience with
; this one program it is also obvious that credible performance can be
; obtained from programs written in LISP.
;
; We tried to run the benchmark on machines which were not memory starved.
; We obtain compile times by typing (time (compile-file "dhry.lisp"))
; several times and taking the best time.  We then type (load "dhry").
; The program is run by typing (main).  The program prompts for an iteration
; count.  We always type 1 the first time and examine the output for errors.
; We then run the program several times with iteration counts of roughly
; 10000, and record the best result.
;
; Please send constructive comments and new timings to Lehmann@g.gp.cs.cmu.edu
;
; preliminary results as of August 15 1988
;
; machine type      clock    compiler   C(regs) lisp  ratio  lisp compile time
;
; DEC 750 (4 Mbyte)        VAX LISP 2.2    863   320   2.7       32:00 total
; DEC uVAX II              LUCID 2.1.0    1476   345   4.3   89u, 1:32 total
; DEC 780                  LUCID 2.1.0    1517   370   4.1   97u
; DEC 785 (vms)            LUCID 2.1.1    2004   463   4.3   68u
; DEC 785 (unix)           LUCID 2.1.0    2004   621   3.2   58u
; TI EXPLORER I            SYSTEM 3.1            495   ---          54 total
; MAC II            16MHz  ALLEGRO 1.0           500   ---          36 total
; DEC 780 (20 Mbyte)       VAX LISP 2.2   1517   502   3.0        3:16 total
; HP9000/320 68020  16MHz  HP/UX CL1.01   2870   572   5.0   42u,   54 total
; DEC 785                  VAX LISP 2.2   2004   735   2.7   66u
; IBM RT-6150              CMU CL V1.6    2191   861   2.5   32u,   43 total
; DEC VAX 6240             LUCID 2.1.0    3859   940   4.1   31u,   32 total
; DEC uVAX III             LUCID 2.1.0    3853   979   3.9   33u,   36 total
; SUN 3/60   68080  20MHz  LUCID 2.1.0    4487  1055   4.3   21u,   37 total
; DEC uVAX III             VAX LISP 2.2   3853  1212   3.2          43 total
; SYMBOLICS 3600           GENERA 7.1           1269   ---          36 total
; SUN 3/260  68080  25MHz  LUCID 2.1.0    7146  1590   4.5   17u,   19 total
; IBM RT-6151 APC          CMU CL V1.6    4474  1803   2.5   17u,   19 total
; DEC 8600                 VAX LISP 2.2         1945   ---   24u
; DEC 8650                 LUCID 2.1.0    8593  2012   4.3   16.0u, 18 total
; DEC 8800                 LUCID 2.1.1    9696  2232   4.2   15.3u, 16 total
; TI EXPLORER II           SYSTEM 4.1           2429   ---          11 total
; DEC 8800                 VAX LISP 2.2   9696  3327   2.9   14.2u, 35 total
; SUN 4/260  SPARC  17MHZ  LUCID 2.1.0   18048  4376   4.1   11.7u, 16 total
;
; ****************************************************************************
; *
; *                   "DHRYSTONE" Benchmark Program
; *                   -----------------------------
; *                                                                           
; *  Version:    C, Version 2.0
; *                                                                           
; *  File:       dhry_global.h (part 1 of 3)
; *
; *  Date:       March 3, 1988
; *
; *  Author:     Reinhold P. Weicker
; *                      Siemens AG, E STE 35
; *                      Postfach 3240
; *                      8520 Erlangen
; *                      Germany (West)
; *                              Phone:  [xxx-49]-9131-7-20330
; *                                      (8-17 Central European Time)
; *                              Usenet: ..!mcvax!unido!estevax!weicker
; *
; *              Original Version (in Ada) published in
; *              "Communications of the ACM" vol. 27., no. 10 (Oct. 1984),
; *              pp. 1013 - 1030, together with the statistics
; *              on which the distribution of statements etc. is based.
; *
; *              In this C version, the following C library functions are used
; *              - strcpy, strcmp (inside the measurement loop)
; *              - printf, scanf (outside the measurement loop)
; *              In addition, UNIX system calls "times ()" or "time ()"
; *              are used for execution time measurement. For measurements
; *              on other systems, these calls have to be changed.
; *
; *      The complete output generated by the program should be mailed
; *      such that at least some checks for correctness can be made.
; *
; ***************************************************************************
; *
; *  History:    This version C/2.0 has been made for two reasons:
; *
; *              1) There is an obvious need for a common C version of
; *              Dhrystone, since C is at present the most popular system
; *              programming language for the class of processors
; *              (microcomputers, minicomputers) where Dhrystone is used most.
; *              There should be, as far as possible, only one C version of
; *              Dhrystone such that results can be compared without
; *              restrictions. In the past, the C versions distributed
; *              by Rick Richardson (Version 1.1) and by Reinhold Weicker
; *              had small (though not significant) differences.
; *
; *              2) As far as it is possible without changes to the Dhrystone
; *              statistics, optimizing compilers should be prevented from
; *              removing significant statements.
; *
; *              This C version has been developed in cooperation with
; *              Rick Richardson (Tinton Falls, NJ), it incorporates many
; *              ideas from the "Version 1.1" distributed previously by
; *              him over the UNIX network Usenet.
; *              I also thank Chaim Benedelac (National Semiconductor),
; *              David Ditzel (SUN), Earl Killian and John Mashey (MIPS),
; *              Alan Smith and Rafael Saavedra-Barrera (UC at Berkeley)
; *              for their help with comments on earlier versions of the
; *              benchmark.
; *
; *  Changes:    In the initialization part, this version follows mostly
; *              Rick Richardson's version distributed via Usenet, not the
; *              version distributed earlier via floppy disk by Reinhold Weicker.
; *              As a concession to older compilers, names have been made
; *              unique within the first 8 characters.
; *              Inside the measurement loop, this version follows the
; *              version previously distributed by Reinhold Weicker.
; *
; *              At several places in the benchmark, code has been added,
; *              but within the measurement loop only in branches that 
; *              are not executed. The intention is that optimizing compilers
; *              should be prevented from moving code out of the measurement
; *              loop, or from removing code altogether. Since the statements
; *              that are executed within the measurement loop have NOT been
; *              changed, the numbers defining the "Dhrystone distribution"
; *              (distribution of statements, operand types and locality)
; *              still hold. Except for sophisticated optimizing compilers,
; *              execution times for this version should be the same as
; *              for previous versions.
; *              
; *              Since it has proven difficult to subtract the time for the
; *              measurement loop overhead in a correct way, the loop check
; *              has been made a part of the benchmark. This does have
; *              an impact - though a very minor one - on the distribution
; *              statistics which have been updated for this version.
; *
; *              All changes within the measurement loop are described
; *              and discussed in the companion paper "Rationale for
; *              Dhrystone version 2".
; *
; *              Because of the self-imposed limitation that the order and
; *              distribution of the executed statements should not be
; *              changed, there are still cases where optimizing compilers
; *              may not generate code for some statements. To a certain
; *              degree, this is unavoidable for small synthetic benchmarks.
; *              Users of the benchmark are advised to check code listings
; *              whether code is generated for all statements of Dhrystone.
; *
; ***************************************************************************
; *
; * Defines:     The following "Defines" are possible:
; *              -DREG=register          (default: Not defined)
; *                      As an approximation to what an average C programmer
; *                      might do, the "register" storage class is applied
; *                      (if enabled by -DREG=register)
; *                      - for local variables, if they are used (dynamically)
; *                        five or more times
; *                      - for parameters if they are used (dynamically)
; *                        six or more times
; *                      Note that an optimal "register" strategy is
; *                      compiler-dependent, and that "register" declarations
; *                      do not necessarily lead to faster execution.
; *              -DNOSTRUCTASSIGN        (default: Not defined)
; *                      Define if the C compiler does not support
; *                      assignment of structures.
; *              -DNOENUMS               (default: Not defined)
; *                      Define if the C compiler does not support
; *                      enumeration types.
; *              -DTIMES                 (default)
; *              -DTIME
; *                      The "times" function of UNIX (returning process times)
; *                      or the "time" function (returning wallclock time)
; *                      is used for measurement. 
; *                      For single user machines, "time ()" is adequate. For
; *                      multi-user machines where you cannot get single-user
; *                      access, use the "times ()" function. If you have
; *                      neither, use a stopwatch in the dead of night.
; *                      "printf"s are provided marking the points "Start Timer"
; *                      and "Stop Timer". DO NOT use the UNIX "time(1)"
; *                      command, as this will measure the total time to
; *                      run this program, which will (erroneously) include
; *                      the time to allocate storage (malloc) and to perform
; *                      the initialization.
; *              -DHZ=nnn                (default: 60)
; *                      The function "times" returns process times in
; *                      1/HZ seconds, with HZ = 60 for most systems.
; *                      CHECK YOUR SYSTEM DESCRIPTION BEFORE YOU JUST APPLY
; *                      THE DEFAULT VALUE.
; *
; ***************************************************************************
; *
; *  Compilation model and measurement (IMPORTANT):
; *
; *  This C version of Dhrystone consists of three files:
; *  - dhry_global.h (this file, containing global definitions and comments)
; *  - dhry_pack_1.c (containing the code corresponding to Ada package Pack_1)
; *  - dhry_pack_2.c (containing the code corresponding to Ada package Pack_2)
; *
; *  The following "ground rules" apply for measurements:
; *  - Separate compilation
; *  - No procedure merging
; *  - Otherwise, compiler optimizations are allowed but should be indicated
; *  - Default results are those without register declarations
; *  See the companion paper "Rationale for Dhrystone Version 2" for a more
; *  detailed discussion of these ground rules.
; *
; *  For 16-Bit processors (e.g. 80186, 80286), times for all compilation
; *  models ("small", "medium", "large" etc.) should be given if possible,
; *  together with a definition of these models for the compiler system used.
; *
; **************************************************************************
; *
; *  Dhrystone (C version) statistics:
; *
; *  [Comment from the first distribution, updated for version 2.
; *   Note that because of language differences, the numbers are slightly
; *   different from the Ada version.]
; *
; *  The following program contains statements of a high level programming
; *  language (here: C) in a distribution considered representative:
; *
; *    assignments                  52 (51.0 %)
; *    control statements           33 (32.4 %)
; *    procedure, function calls    17 (16.7 %)
; *
; *  103 statements are dynamically executed. The program is balanced with
; *  respect to the three aspects:
; *
; *    - statement type
; *    - operand type
; *    - operand locality
; *         operand global, local, parameter, or constant.
; *
; *  The combination of these three aspects is balanced only approximately.
; *
; *  1. Statement Type:
; *  -----------------             number
; *
; *     V1 = V2                     9
; *       (incl. V1 = F(..)
; *     V = Constant               12
; *     Assignment,                 7
; *       with array element
; *     Assignment,                 6
; *       with record component
; *                                --
; *                                34       34
; *
; *     X = Y +|-|"&&"|"|" Z        5
; *     X = Y +|-|"==" Constant     6
; *     X = X +|- 1                 3
; *     X = Y *|/ Z                 2
; *     X = Expression,             1
; *           two operators
; *     X = Expression,             1
; *           three operators
; *                                --
; *                                18       18
; *
; *     if ....                    14
; *       with "else"      7
; *       without "else"   7
; *           executed        3
; *           not executed    4
; *     for ...                     7  |  counted every time
; *     while ...                   4  |  the loop condition
; *     do ... while                1  |  is evaluated
; *     switch ...                  1
; *     break                       1
; *     declaration with            1
; *       initialization
; *                                --
; *                                34       34
; *
; *     P (...)  procedure call    11
; *       user procedure      10
; *       library procedure    1
; *     X = F (...)
; *             function  call      6
; *       user function        5
; *       library function     1
; *                                -- 
; *                                17       17
; *                                        ---
; *                                        103
; *
; *    The average number of parameters in procedure or function calls
; *    is 1.82 (not counting the function values as implicit parameters).
; *
; *
; *  2. Operators
; *  ------------
; *                          number    approximate
; *                                    percentage
; *
; *    Arithmetic             32          50.8
; *
; *       +                     21          33.3
; *       -                      7          11.1
; *       *                      3           4.8
; *       / (int div)            1           1.6
; *
; *    Comparison             27           42.8
; *
; *       ==                     9           14.3
; *       /=                     4            6.3
; *       >                      1            1.6
; *       <                      3            4.8
; *       >=                     1            1.6
; *       <=                     9           14.3
; *
; *    Logic                   4            6.3
; *
; *       && (AND-THEN)          1            1.6
; *       |  (OR)                1            1.6
; *       !  (NOT)               2            3.2
; * 
; *                           --          -----
; *                           63          100.1
; *
; *
; *  3. Operand Type (counted once per operand reference):
; *  ---------------
; *                          number    approximate
; *                                    percentage
; *
; *     Integer               175        72.3 %
; *     Character              45        18.6 %
; *     Pointer                12         5.0 %
; *     String30                6         2.5 %
; *     Array                   2         0.8 %
; *     Record                  2         0.8 %
; *                           ---       -------
; *                           242       100.0 %
; *
; *  When there is an access path leading to the final operand (e.g. a record
; *  component), only the final data type on the access path is counted.
; *
; *
; *  4. Operand Locality:
; *  -------------------
; *                                number    approximate
; *                                          percentage
; *
; *     local variable              114        47.1 %
; *     global variable              22         9.1 %
; *     parameter                    45        18.6 %
; *        value                        23         9.5 %
; *        reference                    22         9.1 %
; *     function result               6         2.5 %
; *     constant                     55        22.7 %
; *                                 ---       -------
; *                                 242       100.0 %
; *
; *
; *  The program does not compute anything meaningful, but it is syntactically
; *  and semantically correct. All variables have a value assigned to them
; *  before they are used as a source operand.
; *
; *  There has been no explicit effort to account for the effects of a
; *  cache, or to balance the use of long or short displacements for code or
; *  data.
; *
; ***************************************************************************
; 
#-:eus
(proclaim '(optimize (speed 3) (safety 0)))
; Compiler and system dependent definitions: 

(defconstant Mic-secs-Per-Second     1000000.0
  "UNIX C returns process times in seconds/HZ")

(defconstant Ident-1 0)
(defconstant Ident-2 1)
(defconstant Ident-3 2)
(defconstant Ident-4 3)
(defconstant Ident-5 4)

#-:eus
(deftype Enumeration () 'fixnum)

; General definitions: 

(defconstant Null 0)
;                 Value of a Null pointer 
#|
(deftype One-Thirty () 'fixnum)
(deftype One-Fifty () 'fixnum)
(deftype Capital-Letter () 'string-char)
(deftype Boolean () '(member nil t))
(deftype Str-30 () '(array char 30))
(deftype Arr-1-Dim () '(simple-vector 50))
(deftype Arr-2-Dim () '(array fixnum (50 50)))

(defstruct (record (:print-function print-record))
  (ptr-comp nil)
  (discr Ident-1 :type integer)
  (var-1 nil)
  (var-2 nil)
  (var-3 nil))
|#

(defclass record	; (:print-function print-record)
  :slots (
	  (ptr-comp)
	  (discr) (Ident-1)	; :type integer
	  (var-1 )
	  (var-2 )
	  (var-3 )))

(defun make-record () (instantiate record))

(defun print-record (r s d)
;  (declare (ignore d))
  (format s "#<record: ~S ~S ~S ~S ~S>" (eq (record-ptr-comp r) r)
	  (record-discr r) (record-var-1 r)
	  (record-var-2 r) (record-var-3 r))
  )

(defun assign-record (d s)
  (setf (record-ptr-comp d) (record-ptr-comp s)
	(record-discr d) (record-discr s)
	(record-var-1 d) (record-var-1 s)
	(record-var-2 d) (record-var-2 s)
	(record-var-3 d) (record-var-3 s))
  )

(defmacro record-enum-comp (r)
  `(the integer (record-var-1 ,r)))

(defmacro record-int-comp (r)
  `(the fixnum (record-var-2 ,r)))

(defmacro record-str-comp (r)
  `(the string (record-var-3 ,r)))

;(defstruct var-1
;  (enum-comp Ident-1 :type integer)
;  (int-comp 0 :type fixnum)
;  (str-comp "" :type string))

(defmacro record-e-comp-2 (r)
  `(the integer (record-var-1 ,r)))

(defmacro record-str-2-comp (r)
  `(the string (record-var-2 ,r)))

;(defstruct var-2
;  (e-comp-2 Ident-1 :type integer)
;  (str-2-comp "" :type string))

(defmacro record-ch-1-comp (r)
  `(the integer (record-var-1 ,r)))

(defmacro record-ch-2-comp (r)
  `(the integer (record-var-2 ,r)))

;(defstruct var-3
;  (ch-1-comp #\Null :type integer)
;  (ch-2-comp #\null :type integer))

;typedef struct record 
;    {
;    struct record *Ptr_Comp;
;    integer    Discr;
;    union {
;          struct {
;                  integer Enum_Comp;
;                  int         Int_Comp;
;                  char        Str_Comp [31];
;                  } var_1;
;          struct {
;                  integer E_Comp_2;
;                  char        Str_2_Comp [31];
;                  } var_2;
;          struct {
;                  char        Ch_1_Comp;
;                  char        Ch_2_Comp;
;                  } var_3;
;          } variant;
;      } Rec_Type, *Rec_Pointer;

;;; macros for fixnum arithmitic
;;;
(defmacro fix+ (a b)
  `(the fixnum (+ ,a ,b)))

(defmacro fix- (a b)
  `(the fixnum (- ,a ,b)))

(defmacro fix* (a b)
  `(the fixnum (* ,a ,b)))

(defmacro fix-incf (a &optional (inc 1))
  `(the fixnum (incf ,a ,inc)))

(defmacro fix-decf (a &optional (dec 1))
  `(the fixnum (decf ,a ,dec)))

(defmacro fix-1+ (a)
  `(the fixnum (1+ ,a)))

(defmacro fix-1- (a)
  `(the fixnum (1- ,a)))

(defvar Ptr-Glob (make-record))
(defvar Next-Ptr-Glob (make-record))
(proclaim '(type record ptr-glob next-ptr-glob))

(defvar Int-Glob 0)
(proclaim '(type fixnum int-glob))

(defvar Bool-Glob nil)
(proclaim '(type Boolean bool-glob))


#-:kcl
 (progn
     (defvar Ch-1-Glob #\null)
     (defvar Ch-2-Glob #\null))
(proclaim '(type integer ch-1-glob ch-2-glob))

(print 0)
(defvar  Arr-1-Glob (instantiate integer-vector 50)) ;make-array '50 :element-type :integer))
;(proclaim '(type arr-1-dim arr-1-glob))

(defvar  Arr-2-Glob (make-array '(50 50) :element-type :integer))
;(proclaim '(type arr-2-dim arr-2-glob))

; variables for time measurement: 
(defconstant Too-Small-Time 2
  "Measurements should last at least 2 seconds")

(defvar Begin-Time 0)
(defvar End-Time 0)
(defvar User-Time 0)
(defvar Microseconds 0.0)
(defvar Dhrystones-Per-Second 0.0)

; end of variables for time measurement 

(defun main ()
;   main program, corresponds to procedures        
;   Main and Proc_0 in the Ada version             

  (let ((int-1-loc 0)
	(int-2-loc 0)
	(int-3-loc 0)
	(enum-loc ident-1)
	(str-1-loc "")
	(str-2-loc "")
	(number-of-runs 0))
    (declare ;(type One-fifty int-1-loc int-2-loc int-3-loc)
	     (type integer enum-loc)
	     ;(type str-30 str-1-loc str-2-loc)
	     (fixnum number-of-runs))
;   Initializations 

    (setf (record-ptr-comp ptr-glob) next-ptr-glob)
    (setf (record-discr ptr-glob) ident-1)
    (setf (record-enum-comp ptr-glob) Ident-3)
    (setf (record-int-comp ptr-glob) 40)
    (setf (record-str-comp ptr-glob)
	  "DHRYSTONE PROGRAM, SOME STRING")
    (setf str-1-loc "DHRYSTONE PROGRAM, 1'ST STRING")

    (setf (aref arr-2-glob 8 7) 10)
;         Was missing in published program. Without this               
;         initialization, Arr_2_Glob [8][7] would have an              
;         undefined value.                                             
;         Warning: With 16-Bit processors and Number_Of_Runs > 32000,  
;         overflow may occur for this array element.                   
    (terpri)
    (format t "Dhrystone Benchmark, Version 2.0.0 (Language: LISP)~%")
    (terpri)
    (format t "Please give the number of runs through the benchmark:~% ")
    (setf Number-of-runs (read))
    (terpri)
    (format t "Execution starts, ~S runs through Dhrystone~%" Number-Of-Runs)

;  *************
;   Start timer 
;  *************
    (setf begin-time (get-internal-run-time))
    (do ((run-index 1 (1+ run-index)))
	((> run-index number-of-runs) t)
      (declare (fixnum run-index))
      (proc-5)
      (proc-4)
#+assert      (assert (and (= ch-1-glob #\A) (= ch-2-glob #\B)
			   bool-glob))
      ; Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true 
      (setf int-1-loc 2
	    int-2-loc 3)
      (setf str-2-loc "DHRYSTONE PROGRAM, 2'ND STRING")
      (setf enum-loc ident-2)

      (setf bool-glob (not (func-2 str-1-loc str-2-loc)))
#+assert      (assert bool-glob)
      ; Bool_Glob == 1 
      (do ()
	  ((>= int-1-loc int-2-loc) t) ; loop body executed once 
	(setf int-3-loc (fix- (fix* 5 int-1-loc) int-2-loc))
#+assert	(assert (= int-3-loc 7))
	; Int_3_Loc == 7 
	(setf int-3-loc (proc-7 int-1-loc int-2-loc))
#+assert	(assert (= int-3-loc 7))
	; Int_3_Loc == 7 
	(incf int-1-loc)
	)
#+assert      (assert (and (= int-1-loc 3) (= int-2-loc 3) (= int-3-loc 7)))
      ; Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 
      (proc-8 arr-1-glob arr-2-glob int-1-loc int-3-loc)
#+assert      (assert (= int-glob 5))
      ; Int_Glob == 5 
      (proc-1 ptr-glob)
      (do ((ch-index #\A 
		;;;;;; (code-char (fix-1+ (char-code ch-index)))
			(1+ ch-index)))
	  ((#|char|# > ch-index ch-2-glob) t)
	(declare (integer ch-index))
	; loop body executed twice 
	(when (= enum-loc (the fixnum (func-1 ch-index #\C)))
	  ; then, not executed 
#+assert	  (assert nil)
	  (setf enum-loc (proc-6 ident-1 enum-loc))
	  (setf str-2-loc "DHRYSTONE PROGRAM, 3'RD STRING")
	  (setf int-2-loc run-index
		int-glob run-index)
	  )
	)
#+assert      (assert (and (= int-1-loc 3) (= int-2-loc 3) (= int-3-loc 7)))
      ; Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 
      (setf int-2-loc (fix* int-2-loc int-1-loc)
	    int-1-loc (truncate (/ int-2-loc int-3-loc))
	    int-2-loc (fix- (fix* 7 (fix- int-2-loc int-3-loc)) int-1-loc))
#+assert      (assert (and (= int-1-loc 1) (= int-2-loc 13) (= int-3-loc 7)))
      ; Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 
      (setf int-1-loc (proc-2 int-1-loc))
#+assert      (assert (= int-1-loc 5))
      ; Int_1_Loc == 5 
      )

;  ************
;   Stop timer 
;  ************
    (setf end-time (get-internal-run-time))

    (format t "Execution ends~%")
    (terpri)
    (format t "Final values of the variables used in the benchmark:~%")
    (terpri)
    (format t "Int_Glob:            ~S~%" Int-Glob)
    (format t "        should be:   ~S~%" 5)
    (format t "Bool_Glob:           ~S~%" Bool-Glob)
    (format t "        should be:   ~S~%" t)
    (format t "Ch_1_Glob:           ~S~%" Ch-1-Glob)
    (format t "        should be:   ~S~%" #\A)
    (format t "Ch_2_Glob:           ~S~%" Ch-2-Glob)
    (format t "        should be:   ~S~%" #\B)
    (format t "Arr_1_Glob[8]:       ~S~%" (aref Arr-1-Glob 8))
    (format t "        should be:   ~S~%" 7)
    (format t "Arr_2_Glob[8][7]:    ~S~%" (aref Arr-2-Glob 8 7))
    (format t "        should be:   Number-Of-Runs + 10~%")
    (format t "Ptr_Glob->~%")
    (format t "  Ptr_Comp:          ~S~%" nil)
    (format t "        should be:   (implementation-dependent)~%")
    (format t "  Discr:             ~S~%" (record-discr Ptr-Glob))
    (format t "        should be:   ~S~%" 0)
    (format t "  Enum_Comp:         ~S~%" (record-enum-comp Ptr-Glob))
    (format t "        should be:   ~S~%" 2)
    (format t "  Int_Comp:          ~S~%" (record-int-comp Ptr-Glob))
    (format t "        should be:   ~S~%" 17)
    (format t "  Str_Comp:          ~A~%" (record-str-comp Ptr-Glob))
    (format t "        should be:   DHRYSTONE PROGRAM, SOME STRING~%")
    (format t "Next_Ptr_Glob->~%")
    (format t "  Ptr_Comp:          ~S~%"  nil)
    (format t "        should be:   (implementation-dependent), same as above~%")
    (format t "  Discr:             ~S~%" (record-discr Next-Ptr-Glob))
    (format t "        should be:   ~S~%" 0)
    (format t "  Enum_Comp:         ~S~%" (record-enum-comp Next-Ptr-Glob))
    (format t "        should be:   ~S~%" 1)
    (format t "  Int_Comp:          ~S~%" (record-int-comp Next-Ptr-Glob))
    (format t "        should be:   ~S~%" 18)
    (format t "  Str_Comp:          ~A~%"
	    (record-str-comp Next-Ptr-Glob))
    (format t "        should be:   DHRYSTONE PROGRAM, SOME STRING~%")
    (format t "Int_1_Loc:           ~S~%" Int-1-Loc)
    (format t "        should be:   ~S~%" 5)
    (format t "Int_2_Loc:           ~S~%" Int-2-Loc)
    (format t "        should be:   ~S~%" 13)
    (format t "Int_3_Loc:           ~S~%" Int-3-Loc)
    (format t "        should be:   ~S~%" 7)
    (format t "Enum_Loc:            ~S~%" Enum-Loc)
    (format t "        should be:   ~S~%" 1)
    (format t "Str_1_Loc:           ~A~%" Str-1-Loc)
    (format t "        should be:   DHRYSTONE PROGRAM, 1'ST STRING~%")
    (format t "Str_2_Loc:           ~A~%" Str-2-Loc)
    (format t "        should be:   DHRYSTONE PROGRAM, 2'ND STRING~%")
    (terpri)

    (setf User-Time (float (/ (- End-Time Begin-Time) internal-time-units-per-second)		    ))

    (if (< user-time too-small-time)
	(progn
	 (format t "Measured time too small to obtain meaningful results~%")
	 (format t "Please increase number of runs~%")
	 (terpri)
	 )
	(progn
	 (setf microseconds (/ (* user-time mic-secs-per-second)
			       number-of-runs))
	 (setf dhrystones-per-second (/ number-of-runs user-time))
	 (format t "Total time:                                 ")
	 (format t "~S~%" user-time)
	 (format t "Microseconds for one run through Dhrystone: ")
	 (format t "~S~%" Microseconds)
	 (format t "Dhrystones per Second:                      ")
	 (format t "~S~%" Dhrystones-Per-Second)
	 (terpri)))
    )
  )

(defun proc-1 (ptr-val-par)
  (declare (type record ptr-val-par))
  ; executed once 
  (let ((next-record (record-ptr-comp ptr-val-par)))
    (declare (type record next-record))
    ; == Ptr_Glob_Next 
    ; Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    
    ; corresponds to "rename" in Ada, "with" in Pascal           
    (assign-record (record-ptr-comp ptr-val-par) ptr-glob)
    (setf (record-int-comp ptr-val-par) 5)
    (setf (record-int-comp next-record)
	  (record-int-comp ptr-val-par))
    (setf (record-ptr-comp next-record) (record-ptr-comp ptr-val-par))
    (setf (record-ptr-comp next-record) (proc-3 (record-ptr-comp next-record)))
    ; Ptr_Val_Par->Ptr_Comp->Ptr_Comp 
    ; == Ptr_Glob->Ptr_Comp 
#+assert    (assert (eq (record-ptr-comp (record-ptr-comp ptr-val-par))
			(record-ptr-comp ptr-glob)))
    (if (= (the fixnum (record-discr next-record)) (the fixnum ident-1))
	;   then, executed 
	(progn
	 (setf (record-int-comp next-record) 6)
	 (setf (record-enum-comp next-record)
	       (proc-6 (record-enum-comp ptr-val-par)
		       (record-enum-comp next-record)))
	 (setf (record-ptr-comp next-record) (record-ptr-comp ptr-glob))
	 (setf (record-int-comp next-record)
	       (proc-7 (record-int-comp next-record) 10))
	 )
	(assign-record ptr-val-par (record-ptr-comp ptr-val-par)))
    )
  nil
  )


(defun proc-2 (int-par-ref)
  ; executed once 
  ; *Int_Par_Ref == 1, becomes 5
  (declare (type integer int-par-ref))
  (let ((int-loc (fix+ int-par-ref 10))
	(enum-loc ident-1))
    (declare (type integer int-loc)
	     (type integer enum-loc))
    (loop
     ; executed once 
     (when (= ch-1-glob #\A)
       (decf int-loc)
       (setf int-par-ref (fix- int-loc int-glob))
       (setf enum-loc ident-1))
     (unless (/= enum-loc (the fixnum ident-1))
       (return nil)))
;    (values int-par-ref)
    int-par-ref
    )
  )

(defun proc-3 (ptr-ref-par)
  ; executed once 
  ; Ptr_Ref_Par becomes Ptr_Glob 
  (declare (type record ptr-ref-par))
  (if ptr-glob
      ; then, executed 
      (setf ptr-ref-par (record-ptr-comp ptr-glob))
      ; else  not executed 
      (setf int-glob 100))
  (setf (record-int-comp ptr-glob) (proc-7 10 int-glob))
;  (values ptr-ref-par)
  ptr-ref-par
  )

(defun proc-4 ()
  ; executed once 
  (let ((bool-loc (= ch-1-glob #\A)))
    (declare (type Boolean bool-loc))
    (setf bool-glob (or bool-loc bool-glob))
    (setf ch-2-glob #\B)
    )
  )


(defun proc-5 ()
  ; executed once 
  (setf ch-1-glob #\A)
  (setf bool-glob nil)
  )

(defun proc-6 (enum-val-par enum-ref-par)
  ; executed once 
  ; Enum_Val_Par == Ident_3, Enum_Ref_Par becomes Ident_2 
  (declare (type integer enum-val-par enum-ref-par))
  (setf enum-ref-par enum-val-par)
  (when (not (func-3 enum-val-par))
    ; then, not executed 
    (setf enum-ref-par ident-4))
  (case enum-val-par
    (0
     (setf enum-ref-par ident-1))
    (1
     (if (> int-glob 100)
	 (setf enum-ref-par ident-1)
	 (setf enum-ref-par ident-4)))
    (2 ; executed 
     (setf enum-ref-par ident-2))
    (3)
    (4
     (setf enum-ref-par ident-3))
    )
;  (values enum-ref-par)
   enum-ref-par)  

(defun proc-7 (int-1-par-val int-2-par-val)
  ; executed three times                                       
  ; first call:      Int_1_Par_Val == 2, Int_2_Par_Val == 3,  
  ;                  Int_Par_Ref becomes 7                    
  ; second call:     Int_1_Par_Val == 10, Int_2_Par_Val == 5, 
  ;                  Int_Par_Ref becomes 17                   
  ; third call:      Int_1_Par_Val == 6, Int_2_Par_Val == 10, 
  ;                  Int_Par_Ref becomes 18                   
  (declare (type integer int-1-par-val int-2-par-val))
;  (values (fix+ int-2-par-val (fix+ int-1-par-val 2)))
  (fix+ int-2-par-val (fix+ int-1-par-val 2))  )

(defun proc-8 (arr-1-par-ref arr-2-par-ref int-1-par-val int-2-par-val)
  ; executed once      
  ; Int_Par_Val_1 == 3 
  ; Int_Par_Val_2 == 7 
  (declare (type #|arr-1-dim|# integer-vector arr-1-par-ref)
	   (type arr-2-dim arr-2-par-ref)
	   (fixnum int-1-par-val int-2-par-val))
  (let ((int-loc (fix+ int-1-par-val 5)))
    (declare (type one-fifty int-loc))
    (setf (aref arr-1-par-ref int-loc) int-2-par-val)
    (setf (aref arr-1-par-ref (fix-1+ int-loc))
	  (aref arr-1-par-ref int-loc))
    (setf (aref arr-1-par-ref (fix+ int-loc 30)) int-loc)
    (do ((int-index int-loc (fix-1+ int-index)))
	((> int-index (the fixnum (fix-1+ int-loc))) t)
      (declare (type integer int-index))
      (setf (aref arr-2-par-ref int-loc int-index) int-loc))
    (fix-incf (aref arr-2-par-ref int-loc (fix-1- int-loc)))
    (setf (aref arr-2-par-ref (fix+ int-loc 20) int-loc)
	  (aref arr-1-par-ref int-loc))
    (setf int-glob 5)
    )
  )

(defun func-1 (ch-1-par-val ch-2-par-val)
  ; executed three times                                         
  ; first call:      Ch_1_Par_Val == 'H', Ch_2_Par_Val == 'R'    
  ; second call:     Ch_1_Par_Val == 'A', Ch_2_Par_Val == 'C'    
  ; third call:      Ch_1_Par_Val == 'B', Ch_2_Par_Val == 'C'    
  (declare (type integer ch-1-par-val ch-2-par-val))
  (let* ((ch-1-loc ch-1-par-val)
	 (ch-2-loc ch-1-loc))
    (declare (type integer ch-1-loc ch-2-loc))
    (if ;(char/= ch-2-loc ch-2-par-val)
	(/= ch-2-loc ch-2-par-val)
	; then, executed 
	(return-from func-1 ident-1)
	; not executed 
	(progn 
	 (setf ch-1-glob ch-1-loc)
	 (return-from func-1 ident-2)))
    )
  )

(defun func-2 (str-1-par-ref str-2-par-ref)
  ; executed once 
  ; Str_1_Par_Ref == "DHRYSTONE PROGRAM, 1'ST STRING" 
  ; Str_2_Par_Ref == "DHRYSTONE PROGRAM, 2'ND STRING" 
  (declare (type string str-1-par-ref str-2-par-ref))
  (let ((int-loc 2)
	(ch-loc #\A))
    (declare (type integer int-loc)
	     (type integer ch-loc))
    (do ()
	((> int-loc 2) t)
      ; loop body executed once 
      (when (= (the fixnum (func-1 (schar str-1-par-ref int-loc)
				   (schar str-2-par-ref (fix-1+ int-loc))))
	       (the fixnum ident-1))
	; then, executed 
	(setf ch-loc #\A)
	(incf int-loc)))
    (when (and (>= #|char>=|# ch-loc #\W) (#|char|# >= ch-loc #\Z))
      ; then, not executed 
      (setf int-loc 7))
    (if (= ch-loc #\R)
	; then, not executed 
	(return-from func-2 t)
	; executed 
	(if (string>= str-1-par-ref str-2-par-ref)
	    ; then, not executed 
	    (progn
	     (incf int-loc 7)
	     (setf int-glob int-loc)
	     (return-from func-2 t))
	    (return-from func-2 nil)))
    )
  )

(defun func-3 (enum-par-val)
  ; executed once        
  ; Enum_Par_Val == Ident_3 
  (declare (type integer enum-par-val))
  (let ((enum-loc enum-par-val))
    (declare (type integer enum-loc))
    (when (= enum-loc (the fixnum ident-3))
      ; executed
      (return-from func-3 t))
    )
  )
