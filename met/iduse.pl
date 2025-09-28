#proc areadef
   rectangle: 1 1 3 3
   xrange: 1 2000
   yscaletype: log
   yrange: 1 10000

#proc xaxis:
      label: Rank

#proc yaxis
     label: Occurrences
     stubs: inc 20
     minortics: yes
     minorticinc: 5

#proc getdata
   file: iduse.dat
   filter: ##set rownum = $arith(@@rownum + 1)
           ##print @@rownum @@1

#proc lineplot
   xfield: 1
   yfield: 2

