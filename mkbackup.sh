#
# mktar.sh, 28 Jan 04

tar -zc -f cusage.tgz *.{c,h,sh} {met,decls,idents,prepro,statements,tables,duplicates}/*.{awk,g,sh} idents/*.{mkt,lev} bldtab bldgra idents/src third_party parse diagrams scripts tables  -T mk_distrib
tar -zc -f cusdata.tgz {met,decls,idents,prepro,statements,tables}/all_prog*
