 +(plus  *x *y *z)-(eval (+ *x *y) *z)\.
 +(minus *x *y *z)-(eval (- *x *y) *z)\.
 +(lt.or.eq *x *y)-(eval (<= *x *y) t)\. 
 +(gt.or.eq *x *y)-(eval (>= *x *y) t)\.


+(boat 0 1)\.
+(boat 1 0)\.
+(boat 1 1)\.
+(boat 2 0)\.
+(boat 0 2)\.
+(state 3 3 1)\.
+(state *x *y 0)-(unique *x *y 0)
;		-(print (*x *y 0))
		-(boat *m *c)
;		-(print (boat0 *m *c))
		-(plus *x *m *m1)
                -(lt.or.eq *m1 3)
		-(plus *y *c *c1)
		-(lt.or.eq *c1 3)
                -(safe *m1 *c1)
		-(state *m1 *c1 1)
		-(print (state *m1 *c1 1))\.
+(state *x *y 1)-(unique *x *y 1)
;		-(print (*x *y 1))
		-(boat *m *c)
;		-(print (boat1 *m *c))
		-(minus *x *m *m1)
                -(gt.or.eq *m1 0)
		-(minus *y *c *c1)
		-(gt.or.eq *c1 0)
                -(safe *m1 *c1)
		-(state *m1 *c1 0)
		-(print (state *m1 *c1 0))\.
+(unique *m *c *b)- (not (onceuponatime *m *c *b))
                  -(assert (onceuponatime *m *c *b))\.
+(safe 0 *c)\.
+(safe 3 *c)\.
+(safe *m *m)\.
 


