
__PRELUDE

.G1

# numdefine.g, 29 Oct 07
# built on: __DATE

frame invis ht __HT wid __WID*1.5 left solid bot solid

coord x 0,100 y 0.9,__MAXY log y

label bot "\fB#define\fR preprocessing directives"
label left "Source files" ""

ticks bot out at 0, 10, 20 "", 30, 40 "", 50, 60 "", 70, 80 "", 90
#ticks left out at 1, 10, 100, 1000, 3300 "3300"
__LEFT_TICK_NUM

times at 70,__MAXY/4.5
"all \fB#define\fR directives in .c files" ljust at 72,__MAXY/4.5

copy "definecnt.d" thru {
   times size -1 at $1, $2
}

bullet at 70,__MAXY/10
"unique macro names in .c files" ljust at 72,__MAXY/10

copy "defineuniq.d" thru {
   bullet size -1 at $1, $2
}

delta at 70,__MAXY/2
"all \fB#define\fR directives in .h files" ljust at 72,__MAXY/2

copy "definecnt.dh" thru {
   delta size -3 at $1, $2
}

.G2

