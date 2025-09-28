
__PRELUDE

.G1

# esutag.g,  3 Jan 05
# built on: __DATE

frame invis ht __HT wid __WID left solid bot solid

coord x 0,20.5 y 0.9,__MAXY log y

label bot "References to each tag"
label left "Files" ""

ticks bot out at 0, 1 "", 2 "", 3 "", 4 "", 5, 10, 15, 20
__LEFT_TICK_NUM

copy "stag_refs.d" thru {
   times size -1 at $1, $2
}

copy "utag_refs.d" thru {
   square size -2 at $1, $2
}

copy "etag_refs.d" thru {
   bullet size -1 at $1, $2
}

copy "nonvis_tag.d" thru {
   delta size -2 at $1, $2
}

copy "anon_tags.d" thru {
   star size -1 at $1, $2
}

delta at 17,__MAXY
"tag definition not visible in file" ljust at 18, __MAXY
times at 17,__MAXY/2.5
"\fBstruct\fR tags" ljust at 18, __MAXY/2.5
bullet at 17,__MAXY/6
"\fBenum\fR tags" ljust at 18, __MAXY/6
square at 17,__MAXY/15
"\fBunion\fR tags" ljust at 18, __MAXY/15
star at 17,__MAXY/40
"no tag in definition" ljust at 18, __MAXY/40

.G2
