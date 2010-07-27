;;; winston.l
;;;
(defun ADDR (REGISTER VALUE) (SETR REGISTER (CONS VALUE (GETR REGISTER))))
(defun ASK-WHERE NIL
   (PROG (SIT) (MATCH '(* (AT IN) * >SIT) (READ)) (RETURN SIT)))
(defun ATOMCAR (A) (CAR (EXPL A)))
(defun ATOMCDR (A) (CAR (IMPL (CDR (EXPL A)))))
(defun ATTACH (C P)
   (PUT C P 'PARENT)
   (PUT P (APPEND (GET P 'CHILDREN) (LIST C)) 'CHILDREN))
(defun BLUEP (OBJECT) (EQUAL (GET OBJECT 'COLOR) 'BLUE))
(defun BOARD-PRI   (PROG (SIZE) (SETQ SIZE (LENGTH BOARD)) (BOARD-PRINT-AUX BOARD)))
(defun BOARD-PRINT-AUX (BOARD)
   (TERPRI)
   (COND
      ((NULL BOARD))
      (T
         (BOARD-PRINT-SUB (CADAR BOARD) 1)
         (BOARD-PRINT-AUX (CDR BOARD)))))
(defun BOARD-PRINT-SUB (COLUMN N)
   (COND
      ((> N SIZE))
      (T
         (COND ((EQUAL COLUMN N) (PRIN1 'Q)) (T (PRIN1 '^.)))
         (SPACES 1)
         (BOARD-PRINT-SUB COLUMN (1+ N)))))
(defun COMBINE (A L)
   (COND
      ((NULL L) NIL)
      ((OR
          (EQUAL A (CAR L))
          (EQUAL (INVERT A) (CAR L))
          (MEMBER (CAR L) (CDR L)))
         (COMBINE A (CDR L)))
      (T (CONS (CAR L) (COMBINE A (CDR L))))))
(defmacro COMPL (&rest DESCRIPTION)
   (PROG (NAME BODY PROGRAM BEGINNING MIDDLE END)
      (SETQ NAME (CAR DESCRIPTION))
      (SETQ BODY (CDR DESCRIPTION))
      (SETQ
         BEGINNING (SUBST
                      NAME
                      'REPLACE
                      '(PROG (THIS-NODE HOLD)
                         (SETQ HOLD REMAINING-WORDS)
                         (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
                         (SETQ THIS-NODE (GENSYM 'REPLACE)))))
      (SETQ
         MIDDLE (APPLY
                   'APPEND
                   (MAPC
                      '(EXPR (STATE)
                         (LIST
                            (CAR STATE)
                            (CONS
                               'COND
                               (APPEND
                                  (MAPC
                                     '(EXPR (CLAUSE)
                                        (APPEND
                                           (LIST (CADR CLAUSE))
                                           (COND
                                              ((NTHCDR 4 CLAUSE)
                                                 (NTHCDR 5 CLAUSE)))
                                           (LIST
                                              (LIST 'GO (NTH 3 CLAUSE)))
))
                                     (CDR STATE))
                                  '((T (GO LOSE)))))))
                      BODY)))
      (SETQ
         END '(WIN
                (COND ((NOT (TESTF THIS-NODE FEATURES)) (GO LOSE)))
                (ATTACH THIS-NODE PARENT-NODE)
                (SETQ LAST-PARSED THIS-NODE)
                (RETURN THIS-NODE)
                LOSE
                (SETQ REMAINING-WORDS HOLD)
                (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
                (RETURN NIL)))
      (SETQ PROGRAM (APPEND BEGINNING MIDDLE END))
      (RETURN (LIST 'DEFUN NAME '(PARENT-NODE FEATURES) PROGRAM))))
(SETQ CONCLUSION '(AND (OR (NOT P) (NOT U))))
(defun CONFLICT (N M BOARD)
   (COND
      ((NULL BOARD) NIL)
      ((OR
          (THREAT N M (CAAR BOARD) (CADAR BOARD))
          (CONFLICT N M (CDR BOARD))))))
(defun DEDUCE NIL
   (PROG (PROGRESS)
      LOOP
      (COND ((STEPFORWARD) (SETQ PROGRESS T)) (T (RETURN PROGRESS)))
      (GO LOOP)))
(defun DELETE (ITEM TARGET)
   (PROG (RESULT)
      LOOP
      (AND (ATOM TARGET) (RETURN TARGET))
      (COND
         ((EQUAL ITEM (CAR TARGET))
            (SETQ TARGET (CDR TARGET))
            (GO LOOP)))
      (SETQ RESULT TARGET)
      (WHILE
         (CDR TARGET)
         (COND
            ((EQUAL (CADR TARGET) ITEM) (RPLACD TARGET (CDDR TARGET)))
            (T (SETQ TARGET (CDR TARGET)))))
      (RETURN RESULT)))
(defun DIAGNOSE NIL
   (PROG (POSSIBILITIES ASKED)
      (SETQ POSSIBILITIES HYPOTHESES)
      LOOP
      (COND
         ((NULL POSSIBILITIES)
            (P "No hypotheses can be confirmed.")
            (RETURN NIL))
         ((VERIFY (CAR POSSIBILITIES))
            (P "Hypothesis" (CAR POSSIBILITIES) "is true.")
            (RETURN (CAR POSSIBILITIES))))
      (SETQ POSSIBILITIES (CDR POSSIBILITIES))
      (GO LOOP)))
(SETQ
   FACTS '((ANIMAL IS CHEETAH)
            (ANIMAL HAS DARK SPOTS)
            (ANIMAL HAS TAWNY COLOR)
            (ANIMAL IS CARNIVORE)
            (ANIMAL EATS MEAT)
            (ANIMAL IS MAMMAL)
            (ANIMAL HAS HAIR)))
(defun FASK NIL
   (PROG (FRAME SLOT FACET VALUE)
      NEXT-FRAME
      (PRINT " ")
      (SETQ FRAME (READLINE "frame:"))
      (OR FRAME (RETURN *FRAMES*))
      (SETQ FRAME (CAR FRAME))
      (OR FRAME (RETURN *FRAMES*))
      (SETQ SLOT (CAR (READLINE "slot :")))
      (SETQ FACET (CAR (READLINE "facet:")))
      (MAPC '(EXPR (X) (FPUT+ FRAME SLOT FACET X)) (READLINE "value:"))
      (GO NEXT-FRAME)))
(defun FASSOC (KEY A-LIST)
   (COND
      ((ASSOC KEY (CDR A-LIST)))
      (T (CADR (RPLACD (LAST A-LIST) (LIST (LIST KEY)))))))
(defun FCHECK (FRAME SLOT FACET VALUE)
   (COND ((MEMBER VALUE (FGET FRAME SLOT FACET)) T) (T NIL)))
(defun FCLAMP (FRAME1 FRAME2 SLOT)
   (RPLACD
      (FASSOC SLOT (FGETFRAME FRAME1))
      (CDR (FASSOC SLOT (FGETFRAME FRAME2)))))
(defmacro FDUMP (dbfile &rest fs)
   (OPEN (CAR DBFILE) 'EXPR 'INOUT)
   (ENSURE
      '(EXPR NIL (CLOSE DBFILE))
      (MAPC
         '(EXPR (F)
            (PUTDB
               (CAR (LAST DBFILE))
               (APPEND
                  '(PUT)
                  (LIST (LIST 'QUOTE F))
                  (LIST (LIST 'QUOTE (GET F 'FRAME)))
                  '('FRAME))
               F))
         (COND
            ((CDDR DBFILE) (REVERSE (CDR (REVERSE (CDR DBFILE)))))
            (T *FRAMES*))))
   T)
(Defmacro FEATURES (&rest L)
   (LIST
      'PUT
      (LIST 'QUOTE (CAR L))
      (LIST 'QUOTE (CDR L))
      (LIST 'QUOTE 'FEATURES)))

(defun FGET (FRAME SLOT FACET)
   (MAPC
      'CAR
      (CDR (ASSOC FACET (CDR (ASSOC SLOT (CDR (GET FRAME 'FRAME))))))))
(defun FGET-I (FRAME SLOT)
   (PROG (CLASSES RESULT)
      (SETQ CLASSES (FGETCLASSES FRAME))
      LOOP
      (COND
         ((NULL CLASSES) (RETURN NIL))
         ((SETQ RESULT (FGET (CAR CLASSES) SLOT 'VALUE))
            (RETURN RESULT))
         (T (SETQ CLASSES (CDR CLASSES)) (GO LOOP)))))
(defun FGET-N (FRAME SLOT)
   (PROG (CLASSES RESULT)
      (SETQ CLASSES (FGETCLASSES FRAME))
      LOOP1
      (COND
         ((NULL CLASSES) (SETQ CLASSES (FGETCLASSES FRAME)) (GO LOOP2))
         ((SETQ RESULT (FGET (CAR CLASSES) SLOT 'VALUE))
            (RETURN RESULT))
         (T (SETQ CLASSES (CDR CLASSES)) (GO LOOP1)))
      LOOP2
      (COND
         ((NULL CLASSES) (SETQ CLASSES (FGETCLASSES FRAME)) (GO LOOP3))
         ((SETQ RESULT (FGET (CAR CLASSES) SLOT 'DEFAULT))
            (RETURN RESULT))
         (T (SETQ CLASSES (CDR CLASSES)) (GO LOOP2)))
      LOOP3
      (COND
         ((NULL CLASSES) (RETURN NIL))
         ((SETQ
             RESULT (MAPCN
                       '(EXPR (E) (APPLY E NIL))
                       (FGET (CAR CLASSES) SLOT 'IF-NEEDED)))
            (RETURN RESULT))
         (T (SETQ CLASSES (CDR CLASSES)) (GO LOOP3)))))
(defun FGET-V-D (FRAME SLOT)
   (COND ((FGET FRAME SLOT 'VALUE)) ((FGET FRAME SLOT 'DEFAULT))))
(defun FGET-V-D-F (FRAME SLOT)
   (COND
      ((FGET FRAME SLOT 'VALUE))
      ((FGET FRAME SLOT 'DEFAULT))
      (T
         (MAPCN '(EXPR (E) (APPLY E NIL)) (FGET FRAME SLOT 'IF-NEEDED)))
))
(defun FGET-Z (FRAME SLOT)
   (PROG (CLASSES RESULT)
      (SETQ CLASSES (FGETCLASSES FRAME))
      LOOP
      (COND
         ((NULL CLASSES) (RETURN NIL))
         ((SETQ
             RESULT (OR
                       (FGET-V-D (CAR CLASSES) SLOT)
                       (MAPCN
                          '(EXPR (E) (APPLY E NIL))
                          (FGET (CAR CLASSES) SLOT 'IF-NEEDED))))
            (RETURN RESULT))
         (T (SETQ CLASSES (CDR CLASSES)) (GO LOOP)))))
(defun FGETCLASSES (FRAME)
   (PROG (QUEUE PROGENY CLASSES)
      (SETQ QUEUE (LIST FRAME))
      TRYAGAIN
      (COND
         ((NULL QUEUE) (RETURN (REVERSE CLASSES)))
         ((NULL (MEMBER (CAR QUEUE) CLASSES))
            (SETQ CLASSES (CONS (CAR QUEUE) CLASSES))))
      (SETQ QUEUE (APPEND (CDR QUEUE) (FGET (CAR QUEUE) 'AKO 'VALUE)))
      (GO TRYAGAIN)))
(defun FGETFRAME (FRAME)
   (COND ((GET FRAME 'FRAME)) (T (PUT FRAME (LIST FRAME) 'FRAME))))
(defun FIRST-HALF (L) (HEAD L (/ (LENGTH L) 2)))
(defun FPRINT (FRAME) (PP (GET FRAME 'FRAME)))
(defun FPUT (FRAME SLOT FACET VALUE)
   (COND
      ((NOT (MEMBER FRAME *FRAMES*))
         (SETQ *FRAMES* (NCONC *FRAMES* (LIST FRAME)))))
   (COND
      ((MEMBER VALUE (FGET FRAME SLOT FACET)) NIL)
      (T
         (FASSOC VALUE (FASSOC FACET (FASSOC SLOT (FGETFRAME FRAME))))
         VALUE)))
(defun FPUT+ (FRAME SLOT FACET VALUE)
   (COND
      ((FPUT FRAME SLOT FACET VALUE)
         (MAPC
            '(EXPR (E)
               (MAPC '(EXPR (F) (APPLY F NIL)) (FGET E SLOT 'IF-ADDED)))
            (FGETCLASSES FRAME))
         VALUE)))
(defun FREMOVE (FRAME SLOT FACET &rest VALUE)
   (PROG (SLOTS FACETS VALUES TARGET)
      (SETQ SLOTS (FGETFRAME FRAME))
      (SETQ FACETS (ASSOC SLOT (CDR SLOTS)))
      (SETQ VALUES (ASSOC FACET (CDR FACETS)))
      (COND
         (VALUE
            (SETQ TARGET (ASSOC (CAR VALUE) (CDR VALUES)))
            (DELETE TARGET VALUES))
         (T (SETQ TARGET (ASSOC FACET (CDR FACETS)))))
      (COND
         ((OR (NULL (CDR VALUES)) (NULL VALUE)) (DELETE VALUES FACETS)))
      (COND ((NULL (CDR FACETS)) (DELETE FACETS SLOTS)))
      (RETURN (NULL (NULL TARGET)))))
(defun FREMOVE+ (FRAME SLOT FACET VALUE)
   (COND
      ((FREMOVE FRAME SLOT FACET VALUE)
         (MAPC
            '(EXPR (E)
               (MAPC
                  '(EXPR (F) (APPLY F NIL))
                  (FGET E SLOT 'IF-REMOVED)))
            (FGETCLASSES FRAME))
         VALUE)))
(defun FREPLACE (FRAME SLOT FACET VALUE)
   (OR
      (MEMQ FRAME *FRAMES*)
      (SETQ *FRAMES* (NCONC *FRAMES* (LIST FRAME))))
   (COND
      ((MEMBER VALUE (FGET FRAME SLOT FACET)) NIL)
      (T
         (CADR
            (RPLACD
               (FASSOC FACET (FASSOC SLOT (FGETFRAME FRAME)))
               (LIST (LIST VALUE)))))))
(defun FREPLACE+ (FRAME SLOT FACET VALUE)
   (MAPC
      '(EXPR (X) (FREMOVE+ FRAME SLOT FACET X))
      (FGET FRAME SLOT FACET))
   (FPUT+ FRAME SLOT FACET VALUE))
(defun GCD (X Y) (COND ((= X) Y) (T (GCD (mod Y X) X))))
(defun GETF (X) (GET X 'FEATURES))
(defun GETR (REGISTER) (GET THIS-NODE REGISTER))
(defun GRASP (OBJECT)
   (PROG (KRUFT)
      (COND ((EQUAL OBJECT (GET 'HAND 'GRASPING)) (RETURN NIL)))
      (COND ((GET OBJECT 'DIRECTLY-SUPPORTS) (CLEARTOP OBJECT)))
      (COND ((SETQ KRUFT (GET 'HAND 'GRASPING)) (GETRIDOF KRUFT)))
      (MOVEHAND (TOPCENTER OBJECT))
      (PUT 'HAND OBJECT 'GRASPING)
      (SETQ PLAN (CONS (LIST 'GRASP OBJECT) PLAN))))
(defun HEAD (L N)
   (COND ((= N) NIL) (T (CONS (CAR L) (HEAD (CDR L) (1- N))))))
(defun HOW (FACT)
   (PROG (POSSIBILITIES SUCCESS)
      (SETQ POSSIBILITIES RULESUSED)
      LOOP
      (COND
         ((NULL POSSIBILITIES)
            (COND
               (SUCCESS (RETURN T))
               ((RECALL FACT) (P FACT "was given.") (RETURN T))
               (T (P FACT "is not established.") (RETURN NIL))))
        ((THENP FACT (CAR POSSIBILITIES))
            (SETQ SUCCESS T)
            (P FACT "demonstrated by:")
            (MAPC '(EXPR (A) (P A)) (CDAR (CDDR (CAR POSSIBILITIES))))))
      (SETQ POSSIBILITIES (CDR POSSIBILITIES))
      (GO LOOP)))
(SETQ
   HYPOTHESES '((ANIMAL IS ALBATROSS)
                 (ANIMAL IS PENGUIN)
                 (ANIMAL IS OSTRICH)
                 (ANIMAL IS ZEBRA)
                 (ANIMAL IS GIRAFFE)
                 (ANIMAL IS TIGER)
                 (ANIMAL IS CHEETAH)))
(defun IFP (FACT RULE) (MEMBER FAC (CADDR RULE)))
(defun INIF (FACT)
   (MAPCAN '(EXPR (R) (COND ((IFP FACT R) (LIST R)))) RULES))
(defun INTERPRET (NETWORK PARENT-NODE FEATURES)
   (PROG (NEWSTATE OLDSTATE STATE-DESCRIPTION RULE HOLD THIS-NODE)
      (SETQ HOLD REMAINING-WORDS)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (SETQ THIS-NODE (GENSYM (CAR NETWORK)))
      (SETQ NETWORK (CDR NETWORK))
      (SETQ NEWSTATE (CAAR NETWORK))
      GET-STATE-DESCRIPTION
      (COND
         ((EQUAL NEWSTATE 'WIN) (GO WIN))
         ((EQUAL NEWSTATE 'LOSE) (GO LOSE))
         (T (SETQ STATE-DESCRIPTION (ASSOC NEWSTATE NETWORK))))
      TEST-TRANSITION-RULE
      (COND
         ((SETQ STATE-DESCRIPTION (CDR STATE-DESCRIPTION))
            (SETQ RULE (CAR STATE-DESCRIPTION)))
         (T
            (SETQ OLDSTATE NEWSTATE)
            (SETQ NEWSTATE 'LOSE)
            (GO GET-STATE-DESCRIPTION)))
      (COND
         ((EVAL (CADR RULE))
            (SETQ OLDSTATE NEWSTATE)
            (SETQ NEWSTATE (NTH 3 RULE))
            (COND ((NTHCDR 4 RULE) (MAPC 'EVAL (NTHCDR 5 RULE))))
            (GO GET-STATE-DESCRIPTION))
         (T (GO TEST-TRANSITION-RULE)))
      WIN
      (COND ((NOT (TESTF THIS-NODE FEATURES)) (GO LOSE)))
      (ATTACH THIS-NODE PARENT-NODE)
      (SETQ LAST-PARSED THIS-NODE)
      (RETURN THIS-NODE)
      LOSE
      (SETQ REMAINING-WORDS HOLD)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (RETURN NIL)))
(defun INTHEN (FACT)
   (MAPCAN '(EXPR (R) (COND ((THENP FACT R) (LIST R)))) RULES))
(defun INVERT (X) (COND ((ATOM X) (LIST 'NOT X)) (T (CADR X))))
(defun LARGEP (OBJECT) (EQUAL (GET OBJECT 'SIZE) 'LARGE))
(defun LAST-HALF (L) (TAIL L (/ (LENGTH L) 2)))
(defun LONGP (OBJECT) (> (OR (GET OBJECT 'LENGTH) 0) 5))
(defun MAKE-DICTIONARY NIL
   (FEATURES A DETERMINER INDEFINITE SINGULAR)
   (FEATURES THE DETERMINER DEFINITE)
   (FEATURES LARGE ADJECTIVE)
   (FEATURES RED ADJECTIVE)
   (FEATURES LONG ADJECTIVE)
   (FEATURES SCREWDRIVER NOUN SINGULAR)
   (FEATURES SCREWDRIVERS NOUN PLURAL)
   (PUT 'SCREWDRIVERS 'SCREWDRIVER 'SINGULAR-FORM)
   (FEATURES BOOK NOUN SINGULAR)
   (FEATURES THAT DETERMINER PRONOUN DEFINITE)
   (FEATURES WHITE ADJECTIVE)
   (FEATURES BLUE ADJECTIVE)
   (PUT 'LARGE 'LARGEP 'ADJECTIVE-FUNCTION)
   (PUT 'SMALL 'SMALLP 'ADJECTIVE-FUNCTION)
   (PUT 'RED 'REDP 'ADJECTIVE-FUNCTION)
   (PUT 'LONG 'LONGP 'ADJECTIVE-FUNCTION)
   (FEATURES HAMMER NOUN SINGULAR)
   (FEATURES HAMMERS NOUN PLURAL)
   (PUT 'HAMMERS 'HAMMER 'SINGULAR-FORM)
   (FEATURES BOOKS NOUN)
   (PUT 'BOOKS 'BOOK 'SINGULAR-FORM)
   (FEATURES SAW NOUN SINGULAR)
   (FEATURES SAWS NOUN PLURAL))
(defun MAKE-SRCH-PROG (NODE)
   (APPEND
      (SUBST
         (PROG (NOUN)
            (SETQ NOUN (GET NODE 'NOUN))
            (RETURN
               (COND
                  ((MEMBER 'PLURAL (GET NOUN 'FEATURES))
                     (GET NOUN 'SINGULAR-FORM))
                  (T NOUN))))
         'NOUN
         '(PROG (OBJECTS) (SETQ OBJECTS (GET 'NOUN 'INSTANCE))))
      (MAPC
         '(EXPR (ADJECTIVE)
            (SUBST
               (GET ADJECTIVE 'ADJECTIVE-FUNCTION)
               'PREDICATE
               '(SETQ
                  OBJECTS (MAPCAN
                             '(EXPR (CANDIDATE)
                                (COND
                                   ((PREDICATE CANDIDATE)
                                      (LIST CANDIDATE))
                                   (T NIL)))
                             OBJECTS))))
         (GET NODE 'ADJECTIVES))
      (SUBST
         (PROG (DETERMINER NUMBER)
            (SETQ DETERMINER (GET NODE 'DETERMINER))
            (SETQ NUMBER (GET NODE 'NUMBER))
            (RETURN
               (COND
                  ((EQUAL DETERMINER 'DEFINITE)
                     (COND
                        ((EQUAL NUMBER 'SINGULAR)
                           '(EQUAL (LENGTH OBJECTS) 1))
                        ((EQUAL NUMBER 'PLURAL)
                           '(> (LENGTH OBJECTS) 1))))
                  ((EQUAL DETERMINER 'INDEFINITE)
                     (COND
                        ((EQUAL NUMBER 'SINGULAR)
                           '(> (LENGTH OBJECTS) 0))))
                  ((NUMP NUMBER) (LIST '> '(LENGTH OBJECTS) NUMBER)))))
         'TEST
         '((COND (TEST (RETURN OBJECTS)) (T (RETURN NIL)))))))
(defun MAKE-WORLD NIL
   (PUT 'TOOL '(HAMMER SCREWDRIVER SAW WRENCH) 'INSANCE)
   (PUT 'HAMMER '(H1) 'INSTANCE)
   (PUT 'SCREWDRIVER '(S1 S2 S3 S4 S5) 'INSTANCE)
   (PUT 'SAW '(SAW1) 'INSTANCE)
   (PUT 'WRENCH '(W1 W2) 'INSTANCE)
   (PUT 'S1 'LARGE 'SIZE)
   (PUT 'S2 'LARGE 'SIZE)
   (PUT 'S3 'LARGE 'SIZE)
   (PUT 'S4 'SMALL 'SIZE)
   (PUT 'S5 'SMALL 'SIZE)
   (PUT 'S1 'RED 'COLOR)
   (PUT 'S2 'BLUE 'COLOR)
   (PUT 'S3 'RED 'COLOR)
   (PUT 'S1 7 'LENGTH))
(defun MAPCAN (F ARG)
   (COND
      ((NULL ARG) NIL)
      ((LET
          ((RESULT (APPLY F (LIST (CAR ARG)))))
          (COND
             ((ATOM RESULT) (MAPCAN F (CDR ARG)))
             (T (NCONC RESULT (MAPCAN F (CDR ARG)))))))))
(defun MATCH (P D)
   (COND
      ((AND (NULL P) (NULL D)) T)
      ((OR (NULL P) (NULL D)) NIL)
      ((AND
          (LISTP (CAR P))
          (EQUAL (CAAR P) 'RESTRICT)
          (EQUAL (CADAR P) '>)
          (TEST (CDDAR P) (CAR D)))
         (MATCH (CDR P) (CDR D)))
      ((AND
          (LISTP (CAR P))
          (EQUAL (CAAR P) 'RESTRICT)
          (EQUAL (ATOMCAR (CADAR P)) '>)
          (TEST (CDDAR P) (CAR D))
          (MATCH (CDR P) (CDR D)))
         (SET (ATOMCDR (CADAR P)) (CAR D))
         T)
      ((AND
          (LISTP (CAR P))
          (MEMQ (CAR D) (CAR P))
          (MATCH (CDR P) (CDR D))))
      ((OR (EQUA (CAR P) '>) (EQUAL (CAR P) (CAR D)))
         (MATCH (CDR P) (CDR D)))
      ((AND (EQUAL (ATOMCAR (CAR P)) '>) (MATCH (CDR P) (CDR D)))
         (SET (ATOMCDR (CAR P)) (CAR D))
         T)
      ((EQUAL (CAR P) '*)
         (COND
            ((MATCH (CDR P) (CDR D)))
            ((MATCH P (CDR D)))
            ((MATCH (CDR P) D))))
      ((EQUAL (ATOMCAR (CAR P)) '*)
         (COND
            ((MATCH (CDR P) (CDR D))
               (SET (ATOMCDR (CAR P)) (LIST (CAR D)))
               T)
            ((MATCH P (CDR D))
               (SET
                  (ATOMCDR (CAR P)) (CONS
                                       (CAR D)
                                       (EVAL (ATOMCDR (CAR P)))))
               T)
            ((MATCH (CDR P) D) (SET (ATOMCDR (CAR P)) NIL))))))
(defun MERGE (A B)
   (COND
      ((NULL A) B)
      ((NULL B) A)
      ((< (CAAR A) (CAAR B)) (CONS (CAR A) (MERGE (CDR A) B)))
      (T (CONS (CAR B) (MERGE A (CDR B))))))
(defun MOVEOBJECT (OBJECT NEWPLACE)
   (REMOVESUPPORT OBJECT)
   (MOVEHAND (NEWTOPCENTER OBJECT NEWPLACE))
   (PUT OBJECT NEWPLACE 'POSITION)
   (ADDSUPPORT OBJECT NEWPLACE)
   (SETQ PLAN (CONS (LIST 'MOVEOBJECT OBJECT NEWPLACE) PLAN)))
(defun NUMEXPL (N)
   (COND
      ((< N 0) (CONS '^- (NUMEXPL (^- N))))
      ((< N 10) (CONS (CHR (^+ N 48)) NIL))
      (T (NCONC (NUMEXPL (/ N 10)) (NUMEXPL (// N 10))))))
(defun P (&rest L) (MAPC '(EXPR (L) (TY L) (SPACES 1)) L))
(defun PARSE-COMMAND (PARENT-NODE FEATURES)
   (PROG (THIS-NODE HOLD)
      (SETQ HOLD REMAINING-WORDS)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (SETQ THIS-NODE (GENSYM 'PARSE-COMMAND))
      S1
      (COND
         ((AND (EQUAL CURRENT-WORD 'COUNT) (PARSE-WORD THIS-NODE 'NIL))
            (SETR 'COMMAND 'COUNT)
            (GO S2))
         ((AND
             (EQUAL CURRENT-WORD 'IDENTIFY)
             (PARSE-WORD THIS-NODE 'NIL))
            (SETR 'COMMAND 'ENUMERATE)
            (GO S2))
         (T (GO LOSE)))
      S2
      (COND
         ((AND (PARSE-NOUN-GROUP THIS-NODE NIL) (NULL REMAINING-WORDS))
            (SETR 'NOUN-GROUP LAST-PARSED)
            (GO WIN))
         (T (GO LOSE)))
      WIN
      (COND ((NOT (TESTF THIS-NODE FEATURES)) (GO LOSE)))
      (ATTACH THIS-NODE PARENT-NODE)
      (SETQ LAST-PARSED THIS-NODE)
      (RETURN THIS-NODE)
      LOSE
      (SETQ REMAINING-WORDS HOLD)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (RETURN NIL)))
(defun PARSE-NOUN-GROUP (PARENT-NODE FEATURES)
   (PROG (THIS-NODE HOLD)
      (SETQ HOLD REMAINING-WORDS)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (SETQ THIS-NODE (GENSYM 'PARSE-NOUN-GROUP))
      S1
      (COND
         ((PARSE-WORD THIS-NODE 'DETERMINER)
            (SETR
               'NUMBER
               (SELECT '(SINGULAR PLURAL) (GETF LAST-PARSED)))
            (SETR
               'DETERMINER
               (SELECT '(DEFINITE INDEFINITE) (GETF LAST-PARSED)))
            (GO S2A))
         (T (GO S2A))
         (T (GO LOSE)))
      S2A
      (COND
         ((PARSE-WORD THIS-NODE 'NUMBER)
            (COND
               ((EQUAL 'SINGULAR (GETR 'NUMBER))
                  (PRINT 'TILT-DETERMINER-NUMBER)))
            (SETR 'NUMBER (GET LAST-PARSED 'NUMBER))
            (GO S2))
         (T (GO S2))
         (T (GO LOSE)))
      S2
      (COND
         ((AND
             REMAINING-WORDS
             (SELECT '(ADJECTIVE NOUN) (GETF (CADR REMAINING-WORDS)))
             (PARSE-WORD THIS-NODE 'ADJECTIVE))
            (ADDR 'ADJECTIVES LAST-PARSED)
            (GO S2))
         ((PARSE-WORD THIS-NODE 'NOUN)
            (COND
               ((EQUAL
                   (LENGTH
                      (INTERSEQ
                         '(SINGULAR PLURAL)
                         (CONS (GETR 'NUMBER) (GETF LAST-PARSED))))
                   2)
                  (PRINT 'TILT-DETERMINER-NOUN))
               ((AND
                   (NUMP (GETR 'NUMBER))
                   (MEMBER 'SINGULAR (GETF LAST-PARSED)))
                  (PRINT 'TILT-NUMBER-NOUN)))
            (COND
               ((NOT (NUMP (GETR 'NUMBER)))
                  (SETR
                     'NUMBER
                     (SELECT '(SINGULAR PLURAL) (GETF LAST-PARSED)))))
            (SETR 'NOUN LAST-PARSED)
            (GO WIN))
         (T (GO LOSE)))
      WIN
      (COND ((NOT (TESTF THIS-NODE FEATURES)) (GO LOSE)))
      (ATTACH THIS-NODE PARENT-NODE)
      (SETQ LAST-PARSED THIS-NODE)
      (RETURN THIS-NODE)
      LOSE
      (SETQ REMAINING-WORDS HOLD)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (RETURN NIL)))
(defun PARSE-WORD (PARENT-NODE FEATURES)
   (PROG (THIS-NODE HOLD)
      (SETQ HOLD REMAINING-WORDS)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (SETQ THIS-NODE (GENSYM 'PARSE-WORD))
      S1
      (COND
         (T
            (SETQ THIS-NODE CURRENT-WORD)
            (SETQ REMAINING-WORDS (CDR REMAINING-WORDS))
            (COND
               (REMAINING-WORDS
                  (SETQ CURRENT-WORD (CAR REMAINING-WORDS)))
               (T (SETQ CURRENT-WORD NIL)))
            (GO WIN))
         (T (GO LOSE)))
      WIN
      (COND ((NOT (TESTF THIS-NODE FEATURES)) (GO LOSE)))
      (ATTACH THIS-NODE PARENT-NODE)
      (SETQ LAST-PARSED THIS-NODE)
      (RETURN THIS-NODE)
      LOSE
      (SETQ REMAINING-WORDS HOLD)
      (SETQ CURRENT-WORD (CAR REMAINING-WORDS))
      (RETURN NIL)))
(SETQ
   PNG '(COMPL
          PARSE-NOUN-GROUP
          (S1
             (IF
                (PARSE-WORD THIS-NODE 'DETERMINER)
                ^-->C
                S2A
                AFTER
                (SETR
                   'NUMBER
                   (SELECT '(SINGULAR PLURAL) (GETF LAST-PARSED)))
                (SETR
                   'DETERMINER
                   (SELECT '(DEFINITE INDEFINITE) (GETF LAST-PARSED))))
             (IF T ^--> S2A))
          (S2A
             (IF
                (PARSE-WORD THIS-NODE 'NUMBER)
                ^-->
                S2
                AFTER
                (COND
                   ((EQUAL 'SINGULAR (GETR 'NUMBER))
                      (PRINT 'TILT-DETERMINER-NUMBER)))
                (SETR 'NUMBER (GET LAST-PARSED 'NUMBER)))
             (IF T ^--> S2))
          (S2
             (IF
                (AND
                   REMAINING-WORDS
                   (SELECT
                      '(ADJECTIVE NOUN)
                      (GETF (CADR REMAINING-WORDS)))
                   (PARSE-WORD THIS-NODE 'ADJECTIVE))
                ^-->
                S2
                AFTER
                (ADDR 'ADJECTIVES LAST-PARSED))
             (IF
                (PARSE-WORD THIS-NODE 'NOUN)
                ^-->
                WIN
                AFTER
                (COND
                   ((EQUAL
                       (LENGTH
                          (INTERSEQ
                             '(SINGULAR PLURAL)
                             (CONS (GETR 'NUMBER) (GETF LAST-PARSED))))
                       2)
                      (PRINT 'TILT-DETERMINER-NOUN))
                   ((AND
                       (NUMP (GETR 'NUMBER))
                       (MEMBER 'SINGULAR (GETF LAST-PARSED)))
                      (PRINT 'TILT-NUMBER-NOUN)))
                (COND
                   ((NOT (NUMP (GETR 'NUMBER)))
                      (SETR
                         'NUMBER
                         (SELECT '(SINGULAR PLURAL) (GETF LAST-PARSED)))
))
                (SETR 'NOUN LAST-PARSED)))))
(defun PP-FRAME (F) (PP (GET F 'FRAME)))
(defun PP-FRAMES (F)
   (OPEN F 'SEQ 'OUT)
   (MAPC '(EXPR (FRAME) (PP (GET FRAME 'FRAME) F)) *FRAMES*)
   (CLOSE F))
(defun PPF (OBJ &rest FILE)
   (COND (FILE (SETQ FILE (CAR FILE))) (T (SETQ FILE T)))
   (OPEN FILE 'SEQ 'OUT)
   (MAPC 'PPP OBJ)
   (CLOSE FILE))
(defun PPP (X) (PP (CDR X) FILE))
(SETQ
   PREMISE '(AND
              (OR Q (NOT P))
              (OR R (NOT Q))
              (OR S (NOT R))
              (OR (NOT U) (NOT S))))
(defun PROVE (PREMISE NEGATION)
   (PROG (FIRST REST REMAINDER RESOLVENT CLAUSES)
      (SETQ CLAUSES (APPEND (CDR PREMISE) (CDR NEGATION)))
      FIND-CLAUSE
      (SETQ REMAINDER CLAUSES)
      TRY-NEXT-X-CLAUSE
      (COND ((NULL REMAINDER) (RETURN '(Theorem not proved))))
      (SETQ FIRST (CAR REMAINDER))
      (SETQ REST (CDR REMAINDER))
      TRY-NEXT-Y-CLAUSE
      (COND
         ((NULL REST)
            (SETQ REMAINDER (CDR REMAINDER))
            (GO TRY-NEXT-X-CLAUSE)))
      (SETQ RESOLVENT (RESOLVE FIRST (CAR REST)))
      (COND
         ((OR
             (EQUAL RESOLVENT 'NO-RESOLVENT)
             (MEMBER RESOLVENT CLAUSES))
            (SETQ REST (CDR REST))
            (GO TRY-NEXT-Y-CLAUSE))
         ((NULL (CDR RESOLVENT))
            (PRINT (APPEND '(The clause) (LIST FIRST)))
            (PRINT (APPEND '(and the clause) (LIST (CAR REST))))
            (PRINT '(produce the empty resolvent))
            (RETURN '(Theorem proved)))
         (T
            (SETQ CLAUSES (CONS RESOLVENT CLAUSES))
            (PRINT (APPEND '(The clause) (LIST FIRST)))
            (PRINT (APPEND '(and the clause) (LIST (CAR REST))))
            (PRINT (APPEND '(produce a resolvent :) (LIST RESOLVENT)))
            (GO FIND-CLAUSE)))))
(defun PUTAT (OBJECT PLACE)
   (GRASP OBJECT)
   (MOVEOBJECT OBJECT PLACE)
   (UNGRASP OBJECT))
(defun PUTON (OBJECT SUPPORT)
   (PROG (PLACE PLAN)
      (COND
         ((SETQ PLACE (FINDSPACE SUPPORT OBJECT)) (PUTAT OBJECT PLACE))
         ((SETQ PLACE (MAKESPACE SUPPORT OBJECT)) (PUTAT OBJECT PLACE)))
      (RETURN (REVERSE PLAN))))
(defun Q-A NIL
   (PROG (QUESTION)
      Q-A
      (SETQ QUESTION (READLINE 'Q-A>))
      (AND (EQUAL QUESTION '(END)) (RETURN T))
      (APPLY 'REQUEST* QUESTION)
      (GO Q-A)))
(defun QUEEN (SIZE)
   (PROG (N M BOARD COUNT)
      (SETQ COUNT 1)
      (SETQ N 1)
      LOOP-N
      (SETQ M 1)
      LOOP-M
      (COND ((CONFLICT N M BOARD) (GO UN-DO-M)))
      (SETQ BOARD (CONS (LIST N M) BOARD))
      (COND
         ((> (SETQ N (1+ N)) SIZE)
            (PRIN1 'NO.)
            (PRIN1 COUNT)
            (SETQ COUNT (1+ COUNT))
            (BOARD-PRINT (REVERSE BOARD))
            (TERPRI)
            (PRINT " ")))
      (GO LOOP-N)
      UN-DO-N
      (COND
         ((NULL BOARD) (RETURN 'FINISHED))
         (T
            (SETQ M (CADAR BOARD))
            (SETQ N (CAAR BOARD))
            (SETQ BOARD (CDR BOARD))))
      UN-DO-M
      (COND ((> (SETQ M (1+ M)) SIZE) (GO UN-DO-N)) (T (GO LOOP-M)))))
(defun RECALL (FACT) (COND ((MEMBER FACT FACTS) FACT) (T NIL)))
(defmacro RECORD (&rest X)
   (PUT (CAR X) X 'NETWORK)
   (EVAL
      (SUBST
         (CAR X)
         'NAME
         '(DEFUN
            NAME
            (PARENT-NODE FEATURES)
            (INTERPRET (GET 'NAME 'NETWORK) PARENT-NODE FEATURES))))
   T)
(defun REDP (OBJECT) (EQUAL (GET OBJECT 'COLOR) 'RED))

(defun REMEMBER (NEW)
   (COND
      ((MEMBER NEW FACTS) NIL)
      (T (SETQ FACTS (CONS NEW FACTS)) NEW)))
(defmacro REQUEST*  (&rest REMAINING-WORDS)
   (PROG (TREE PROGRAM RESULTS NOUN-GROUP)
      (SETQ TREE (PARSE-COMMAND (GENSYM) NIL))
      (SETQ PROGRAM (MAKE-SRCH-PROG (GET TREE 'NOUN-GROUP)))
      (SETQ RESULTS (EVAL PROGRAM))
      (COND
         ((EQUAL (GET TREE 'COMMAND) 'COUNT)
            (COND
               ((CDR RESULTS) (P '(THERE ARE) (LENGTH RESULTS)))
               (RESULTS (P '(THERE IS) 1))
               (T (P '(SORRY THE REQUEST AND DATA BASE CLASH)))))
         ((EQUAL (GET TREE 'COMMAND) 'ENUMERATE)
            (COND
               ((CDR RESULTS) (P '(THE RESULTS ARE ) RESULTS))
               (RESULTS (P '(THE RESULT IS) RESULTS))
               (T (P '(SORRY THE REQUEST AND DATA-BASE CLASH))))))))
(defun RESOLVE (X Y)
   (PROG (REST-X REST-Y)
      (SETQ REST-X (CDR X))
      (SETQ REST-Y (CDR Y))
      LOOP
      (COND
         ((NULL REST-X) (RETURN 'NO-RESOLVENT))
         ((MEMBER (INVERT (CAR REST-X)) REST-Y)
            (RETURN
               (CONS
                  'OR
                  (COMBINE (CAR REST-X) (APPEND (CDR X) (CDR Y)))))))
      (SETQ REST-X (CDR REST-X))
      (GO LOOP)))
(defun REWRITE (INFILE OUTFILE)
   (OPEN INFILE 'SEQ)
   (OPEN OUTFILE 'SEQ 'OUT)
   (LET
      ((R (READ INFILE)))
      (UNTIL
         (EQ R ^$EOF$)
         (PP
            (LIST (CAR R) (CADR R) (CADR (CADDR R)) (CADDR (CADDR R)))
            OUTFILE)
         (SETQ R (READ INFILE))))
   (CLOSE INFILE)
   (CLOSE OUTFILE))
(SETQ
   RULES '((RULE ID1 (IF (ANIMAL HAS HAIR)) (THEN (ANIMAL IS MAMMAL)))
            (RULE
               ID2
               (IF (ANIMAL GIVES MILK))
               (THEN (ANIMAL IS MAMMAL)))
            (RULE
               ID3
               (IF (ANIMAL HAS FEATHERS))
               (THEN (ANIMAL IS BIRD)))
            (RULE
               ID4
               (IF (ANIMAL FLIES) (ANIMAL LAYS EGGS))
               (THEN (ANIMAL IS BIRD)))
            (RULE
               ID5
               (IF (ANIMAL EATS MEAT))
               (THEN (ANIMAL IS CARNIVORE)))
            (RULE
               ID6
               (IF
                  (ANIMAL HAS POINTED TEETH)
                  (ANIMAL HAS CLAWS)
                  (ANIMAL HAS FORWARD EYES))
               (THEN (ANIMAL IS CARNIVORE)))
            (RULE
               ID7
               (IF (ANIMAL IS MAMMAL) (ANIMAL HAS HOOFS))
               (THEN (ANIMAL IS UNGULATE)))
            (RULE
               ID8
               (IF (ANIMAL IS MAMMAL) (ANIMAL CHEWS CUD))
               (THEN (ANIMAL IS UNGULATE) (EVEN TOED)))
            (RULE
               ID9
               (IF
                  (ANIMAL IS MAMMAL)
                  (ANIMAL IS CARNIVORE)
                  (ANIMAL HAS TAWNY COLOR)
                  (ANIMAL HAS DARK SPOTS))
               (THEN (ANIMAL IS CHEETAH)))
            (RULE
               ID10
               (IF
                  (ANIMAL IS MAMMAL)
                  (ANIMAL IS CARNIVORE)
                  (ANIMAL HAS TAWNY COLOR)
                  (ANIMAL HAS BLACK STRIPES))
               (THEN (ANIMAL IS TIGER)))
            (RULE
               ID11
               (IF
                  (ANIMAL IS UNGULATE)
                  (ANIMAL HAS LONG NECKS)
                  (ANIMAL HAS LONG LEGS)
                  (ANIMAL HAS DARK SPOTS))
               (THEN (ANIMAL IS GIRAFFE)))
            (RULE
               ID12
               (IF (ANIMAL IS UNGULATE) (ANIMAL HAS BLACK STRIPES))
               (THEN (ANIMAL IS ZEBRA)))
            (RULE
               ID13
               (IF
                  (ANIMAL IS BIRD)
                  (ANIMAL DOES NOT FLY)
                  (ANIMAL HAS LONG NECK)
                  (ANIMAL HAS LONG LEGS)
                  (ANIMAL IS BLACK AND WHITE))
               (THEN (ANIMAL IS OSTRICH)))
            (RULE
               ID14
               (IF
                  (ANIMAL IS BIRD)
                  (ANIMAL DOES NOT FLY)
                  (ANIMAL SWIMS)
                  (ANIMAL IS BLACK AND WHITE))
               (THEN (ANIMAL IS PENGUIN)))
            (RULE
               ID15
               (IF (ANIMAL IS BIRD) (ANIMAL FLYS WELL))
               (THEN (ANIMAL IS ALBATROSS)))))
(defun SELECT (X Y)
   (COND
      ((NULL X) NIL)
      ((MEMBER (CAR X) Y) (CAR X))
      (T (SELECT (CDR X) Y))))
(defun SETR (REGISTER VALUE) (PUT THIS-NODE VALUE REGISTER) VALUE)
(defun SMALLP (OBJECT) (EQUAL (GET OBJECT 'SIZE) 'SMALL))
(defun SORT (S PREDICATE)
   (COND
      ((NULL S) NIL)
      (T (SPLICEIN (CAR S) (SORT (CDR S) PREDICATE) PREDICATE))))
(defun SORT-MERGE (L)
   (COND
      ((NULL (CDR L)) L)
      (T
         (MERGE (SORT-MERGE (FIRST-HALF L)) (SORT-MERGE (LAST-HALF L))))
))
(defun SPLICEIN (ELEMENT S PREDICATE)
   (COND
      ((NULL S) (LIST ELEMENT))
      ((APPLY PREDICATE (LIST ELEMENT (CAR S))) (CONS ELEMENT S))
     (T (CONS (CAR S) (SPLICEIN ELEMENT (CDR S) PREDICATE)))))
(defun STEPFORWARD NIL
   (PROG (RULELIST)
      (SETQ RULELIST RULES)
      LOOP
      (COND
         ((NULL RULELIST) (RETURN NIL))
         ((TRYRULE (CAR RULE)) (RETURN T)))
      (SETQ RULELIST (CDR RULELIST))
      (GO LOOP)))
(defun TAIL (L N) (NTHCDR N L))
(defun TESTF (NODE FEATURES)
   (COND
      ((NULL FEATURES))
      ((ATOM FEATURES) (SETQ FEATURES (LIST FEATURES))))
   (EQUAL (LENGTH FEATURES) (LENGTH (INTERSEQ FEATURES (GETF NODE)))))
(defun TESTIF (RULE)
   (PROG (IFS)
      (SETQ IFS (CDR (CADDR RULE)))
      LOOP
      (COND
         ((NULL IFS) (RETURN T))
         ((RECALL (CAR IFS)))
         (T (RETURN NIL)))
      (SETQ IFS (CDR IFS))
      (GO LOOP)))
(defun TESTIF+ (RULE)
   (PROG (IFS)
      (SETQ IFS (CDAR (CDDR RULE)))
      LOOP
      (COND
         ((NULL IFS) (RETURN T))
         ((VERIFY (CAR IFS)))
         (T (RETURN NIL)))
      (SETQ IFS (CDR IFS))
      (GO LOOP)))
(defun THENP (FACT RULE) (MEMBER FACT (CAR (CDDDR RULE))))
(defun THREAT (I J A B)
   (OR
      (EQUAL I A)
      (EQUAL J B)
      (EQUAL (^- I J) (^- A B))
      (EQUAL (^+ I J) (^+ A B))))
(defun TRYRULE (RULE)
   (COND
      ((AND (TESTIF RULE) (USETHEN RULE))
         (SETQ RULESUSED (CONS RULE RULESUSED))
         T)))
(defun TRYRULE+ (RULE)
   (COND
      ((AND (TESTIF+ RULE) (USETHEN RULE))
         (SETQ RULESUSED (CONS RULE RULESUSED))
         T)))
(defun USEDP (RULE)
   (PROG (POSSIBILITIES)
      (SETQ POSSIBILITIES RULESUSED)
      LOOP
      (COND
         ((NULL POSSIBILITIES) (RETURN NIL))
         ((EQUAL RULE (CADAR POSSIBILITIES)) (RETURN T)))
      (SETQ POSSIBILITIES (CDR POSSIBILITIES))
      (GO LOOP)))
(defun USETHEN (RULE)
   (PROG (THENS SUCCESS)
      (SETQ THENS (CDAR (CDDDR RULE)))
      LOOP
      (COND
         ((NULL THENS) (RETURN SUCCESS))
         ((REMEMBER (CAR THENS))
            (P "Rule" (CADR RULE) "deduces" (CAR THENS))
            (SETQ SUCCESS T)))
      (SETQ THENS (CDR THENS))
      (GO LOOP)))
(defun VERIFY (FACT)
   (PROG (RELEVANT1 RELEVANT2)
      (COND ((RECALL FACT) (RETURN T)))
      (SETQ RELEVANT1 (INTHEN FACT))
      (SETQ RELEVANT2 RELEVANT1)
      (COND
         ((NULL RELEVANT1)
            (COND
               ((MEMBER FACT ASKED) (RETURN NIL))
               ((AND (P "Is this true?" FACT) (EQ (READ) 'YES))
                  (REMEMBER FACT)
                  (RETURN T))
               (T (SETQ ASKED (CONS FACT ASKED)) (RETURN NIL)))))
      LOOP1
      (COND
         ((NULL RELEVANT1) (GO LOOP2))
         ((TRYRULE (CAR RELEVANT1)) (RETURN T)))
      (SETQ RELEVANT1 (CDR RELEVANT1))
      (GO LOOP1)
      LOOP2
      (COND
         ((NULL RELEVANT2) (GO EXIT))
         ((TRYRULE+ (CAR RELEVANT2)) (RETURN T)))
      (SETQ RELEVANT2 (CDR RELEVANT2))
      (GO LOOP2)
      EXIT
      (RETURN NIL)))
(defun WATER-CROCK (A B C)
   (COND
      ((AND (> C A) (> C B)) 'C-TOO-LARGE)
      ((NOT (= (mod C (GCD A B)))) 'C-NOT-POSSIBLE)
      (T (WATER-MAKE 0 0))))
(defun WATER-MAKE (X Y)
   (COND
      ((EQUAL X C) '((CORRECT AMOUNT IN A)))
      ((EQUAL Y C) '((CORRECT AMOUNT IN B)))
      ((EQUAL X A) (CONS '(EMPTY A) (WATER-MAKE 0 Y)))
      ((EQUAL Y 0) (CONS '(FILL B) (WATER-MAKE X B)))
      ((> (^- A X) Y) (CONS '(EMPTY B INTO A) (WATER-MAKE (^+ X Y) 0)))
      (T (CONS '(FILL A FROM B) (WATER-MAKE A (^- Y (^- A X)))))))
(defun WHY (FACT)
   (PROG (POSSIBILITIES SUCCESS)
      (SETQ POSSIBILITIES RULESUSED)
      LOOP
      (COND
         ((NULL POSSIBILITIES)
            (COND
               (SUCCESS (RETURN T))
               ((RECALL FACT) (P FACT "was hypothesis.") (RETURN T))
               (T (P FACT "is not established.") (RETURN NIL))))
         ((IFP FACT (CAR POSSIBILITIES))
            (SETQ SUCCESS T)
            (P FACT "needed to show:")
            (MAPC '(EXPR (A) (P A)) (CDADR (CDDAR POSSIBILITIES)))))
      (SETQ POSSIBILITIES (CDR POSSIBILITIES))
      (GO LOOP)))

