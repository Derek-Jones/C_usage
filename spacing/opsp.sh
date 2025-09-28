#
# opsp.sh, 28 Oct 07

function find_match
{
echo "$1 $2"
if [ "$cmd_opts" = "wc" ]
then
   egrep $1 < $TMP_FILE | wc -l
else
   egrep $1 < $TMP_FILE
   echo "--------------------------------------------------------"
fi
}

function find_all_matches
{
find -L programs/ -name "*.c" -exec egrep $1  {} \; > $TMP_FILE
}


function find_and_match
{
find_all_matches "\w[[:space:]]*$1[[:space:]]*\w+[[:space:]]*$2[[:space:]]*\w"

find_match "\w$1\w+$2\w" "$1 $2"
find_match "\w[[:space:]]$1[[:space:]]\w+$2\w" "$1 $2"
find_match "\w[[:space:]]$1[[:space:]]\w+[[:space:]]$2[[:space:]]\w" "$1 $2"
find_match "\w$1\w+[[:space:]]$2[[:space:]]\w" " $1$2"
find_match "\w[[:space:]]*$1[[:space:]]*\w+[[:space:]]*$2[[:space:]]*\w" "$1 $2"
}


cmd_opts="$1"
TMP_FILE="tmp.$$"

bin_ops="\+ \- \* \/ \% \& \| \&\* \|\| << >> == \!= > < <= >="

for op1 in $bin_ops
do
   for op2 in $bin_ops
   do
      find_and_match "$op1" "$op2"
   done
done

rm $TMP_FILE
