#
# makefile for cone ( face pointer version )
#
#					Hirohisa HIRUKAWA
#				Intelligent Machine Behavior Section
#				Electrotechnical Laboratory
#				1-1-4 Umezono, Tsukuba, Japan 305
#				E-mail: hirukawa@etl.go.jp
#
#	Version 1.0, Jul.22, 1988.

CFLAGS = -O

OBJ = cone.o ssvdc.o amax1.o max0.o min0.o srot.o srotg.o sdot.o \
      snrm2.o sscal.o sswap.o saxpy.o \
      rank.o mat_mult.o edge.o hash5.o same.o \
      cone_pre.o cone_post.o \
      face_init.o face.o update_edge.o fugo_calc.o \
      cone_inter.o convexconeref.o

$(OBJ) : arith.h

lib: $(OBJ)
	cc -G -o libconvexcone.so $(OBJ)
