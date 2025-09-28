#
# idlev.sh,  7 Aug 03

echo "File: gcclev.d"
cat gcc.lev
echo "End File"

echo "File: idsoftlev.d"
cat idsoft.lev
echo "End File"

echo "File: linuxlev.d"
cat linux.lev
echo "End File"

echo "File: postlev.d"
cat postgres.lev
echo "End File"

#

echo "File: gccklev.d"
sort -r gcc-2.95.c.kl
echo "End File"

echo "File: idsoftklev.d"
sort -r idsoftware.c.kl
echo "End File"

echo "File: openafsklev.d"
sort -r openafs-1.2.2a.c.kl
echo "End File"

