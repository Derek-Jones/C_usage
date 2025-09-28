# bndpdf.sh, 25 Sep 25

# add a bounding box to a (non-EPS) PS file; convert result into PDF

# need a single input filename to run (output is optional)
# cat to a temp file if you want to read input from a stream
if [ -z "${1-}" -o -n "${3-}" ]; then
	echo "Usage:  $0 input.ps [output.pdf]"
	exit 1
fi

# check if file already has a bounding box
# abort if it does (could just turn this into a warning)
if awk '/^%%[A-Z]/||NR==1{print;next}{exit}' "$1" |\
	grep -s '%%BoundingBox:' 1>/dev/null;
then
#        epstopdf --filter < $1
        ./liftboundingbox.sh < $1 | epstopdf --filter
	exit 0
fi

# redirect into output file if not writing to a pipe
if [ -n "${2-}" ]; then
	# abort if output exists (could just overwrite regardless)
	if [ -w "$2" ]; then
		echo "Output exists. Won't overwrite."
		echo "Aborting."
		exit 2
	fi
	# redirect output of the script
	exec 1>"$2"
fi

(
	# copy first line
	sed 1q "$1"

	# output the bounding box info
	gs -dBATCH -dNOPAUSE -sDEVICE=bbox -q -- "$1" 2>&1

	# copy the remaining lines
	sed 1d "$1"
) | epstopdf --filter

exit 0

