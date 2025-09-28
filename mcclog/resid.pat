_:A.*			cs_any_use	any
__.*			cs_any_use	any
_.*			cs_ident_tag	identifier file scope
_.*			cs_ident_tag	tag file  
is:a.*			cs_mac_id_fut	macro_ident		included ctype.h
to:a.*			cs_mac_id_fut	macro_ident		included ctype.h
is:a.*			cs_ident_fut	identifier external 
to:a.*			cs_ident_fut	identifier external 
E:N.*			cs_macro_fut	res_macro		included errno.h
LC_:A.*			cs_macro_fut	res_macro		included locale.h
SIG_.*			cs_macro_fut	res_macro		included signal.h
SIG:A.*			cs_macro_fut	res_macro		included signal.h
str:a.*			cs_mac_id_fut	macro_ident		included stdlib.h
str:a.*			cs_ident_fut	define identifier external 
str:a.*			cs_mac_id_fut	macro_ident		included string.h
str:a.*			cs_ident_fut	define identifier external 
mem:a.*			cs_mac_id_fut	macro_ident		included string.h
wcs:a.*			cs_mac_id_fut	macro_ident		included string.h
mem:a.*			cs_ident_fut	define identifier external 
wcs:a.*			cs_ident_fut	define identifier external 

