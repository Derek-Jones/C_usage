# 19 Aug 12

# Force make on windows to use a useful shell
SHELL=sh

# Some directories
BIN_DIR=bin

#CC=gcc
CC=/usr1/expsrc/xgcc-4.0.2/objdir/gcc/xgcc -B/usr1/expsrc/xgcc-4.0.2/objdir/gcc/ -fbounds-checking -DVALGRIND

CFLAGS=-I/usr/local/include -Wall -DFULL_POSIX -g
LFLAGS=
LIBS=-lm  -L/usr/local/lib -lgmp -lgmp -larchive

E_OBJ = parsefile.o    \
	canal.o   \
	count.o   \
	dispexp.o \
	parser.o  \
	stgrep.o  \
	analyse.o \
	lex.o     \
	print.o   \
        options.o \
        global.o \
        errors.o \
        utils.o \
        arccomp.o \
        singlefile.o \
        chkfiles.o \
        isprop.o

all: $(E_OBJ)
	$(CC) $(LFLAGS) $(LIBS) -g -o canal $(E_OBJ)

cbook.tab.c: cbook.y
	bison cbook.y -v

clean:
	rm *.o

# Use make options=-MM to get gcc to generate a list of dependencies
.c.o:
	$(CC) -c $(CFLAGS) $(options) $<

parsefile.o: 
	$(CC) $(CFLAGS) $(options) -c -g -DYYERROR -DYYDEBUG=1 parsefile.c


parsefile.o: parsefile.c cbook.tab.c global.h ../config.h lex.h parser.h count.h \
 print.h dispexp.h stgrep.h analyse.h parsefile.h cbook.tab.c
canal.o: global.h ../config.h options.h singlefile.h chkfiles.h
count.o: count.c global.h ../config.h lex.h parser.h count.h
dispexp.o: dispexp.c global.h ../config.h lex.h parser.h dispexp.h
parser.o: parser.c global.h ../config.h lex.h parser.h
stgrep.o: stgrep.c global.h ../config.h lex.h parser.h stgrep.h
analyse.o: analyse.c global.h ../config.h parser.h count.h dispexp.h \
 stgrep.h analyse.h
lex.o: lex.c global.h ../config.h parser.h lex.h
print.o: print.c global.h ../config.h parser.h count.h print.h
options.o: options.c global.h ../config.h errors.h utils.h arccomp.h \
 singlefile.h chkfiles.h parser.h stgrep.h count.h lex.h dispexp.h \
 parsefile.h options.h
global.o: global.c global.h ../config.h
errors.o: errors.c global.h ../config.h
utils.o: utils.c global.h ../config.h errors.h utils.h
arccomp.o: arccomp.c global.h ../config.h errors.h isprop.h utils.h \
 singlefile.h chkfiles.h arccomp.h
singlefile.o: singlefile.c global.h ../config.h errors.h isprop.h utils.h \
 arccomp.h parsefile.h singlefile.h
chkfiles.o: chkfiles.c global.h ../config.h errors.h isprop.h arccomp.h \
 singlefile.h chkfiles.h
isprop.o: isprop.c global.h ../config.h isprop.h
