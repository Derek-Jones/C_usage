# binoperands.awk, 10 Apr 07

BEGIN {
   op_name["+"]="PL"
   op_name["-"]="MI"
   op_name["*"]="TI"
   op_name["/"]="DI"
   op_name["%"]="RE"
   op_name["|"]="BO"
   op_name["&"]="BA"
   op_name["||"]="LO"
   op_name["&&"]="LA"
   op_name["<"]="LT"
   op_name[">"]="GT"
   op_name["<="]="LE"
   op_name[">="]="GE"
   op_name["=="]="EQ"
   op_name["!="]="NE"
   op_name["<<"]="LS"
   op_name[">>"]="RS"
   }

# only output lines for which at least one of the operands
# has not been encountered before in combination with the operator.

#(substr($0, 1, 1) != " ") && \
#(substr($0, 1, 1) != "\t") {

(length($0) < 30) && \
(op_name[$1] != "") {
   if (binop[$1 " " $2] == 0)
      {
      binop[$1 " " $2]=1
      binop[$1 " " $3]=1
      print op_name[$1] "  " $0
      next
      }
   else
      binop[$1 " " $2]++
   if (binop[$1 " " $3] == 0)
      {
      binop[$1 " " $3]=1
      print op_name[$1] "  " $0
      }
   else
      binop[$1 " " $3]++
   next
   }

END {
   for (b in binop)
      if (binop[b] > 9)
         print binop[b] "  " b
   }

