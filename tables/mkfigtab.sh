#
# mkfigtab.sh, 13 Jul 03

awk -f ../../scr*/mkfigtab.awk < figtab.txt | awk -f upd*.awk

