# mktab.sh, 25 Sep 25

source ../config.files

#GEN_DATA=1

function id_counts()
{
awk -v D_FILE="$1.t" -f $EXTRTWOCOLS < all_prog.stdid.h > $LOC_TAB_DIR/$1.h
echo "END_DOT_H" >> $LOC_TAB_DIR/$1.h
awk -v D_FILE="$1.t" -f $EXTRTWOCOLS < all_prog.stdid.c > $LOC_TAB_DIR/$1.c
cat $LOC_TAB_DIR/$1.h $LOC_TAB_DIR/$1.c | $MERGETWOCOL | $SORTLASTCOL | $MKTHREECOL > $GLOB_TAB_DIR/$1
}

if [ $GEN_DATA == 1 ]; then
   zcat $STDID_LIST *.c.id.gz | awk -f std_ident.awk > all_prog.stdid.c
   zcat $STDID_LIST *.h.id.gz | awk -f std_ident.awk > all_prog.stdid.h
   fi

id_counts lim_std_id
id_counts flt_std_id
id_counts predef_macro

./shareid.sh | awk -f sharetab.awk > $GLOB_TAB_DIR/shared_id

