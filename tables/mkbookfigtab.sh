#
# mkfigtab.sh, 13 Jul 03

awk -f ../../scr*/mkfigtab.awk < ../../book.txt | awk -f upd*.awk > t

