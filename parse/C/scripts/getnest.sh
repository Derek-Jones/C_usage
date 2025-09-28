#
# getblock.sh, 10 Mar 08

function stmt_srch()
{
awk -v stmt=$1 -f scripts/stmtfreq.awk < all.bnest > $1.all
}

stmt_srch ES
stmt_srch IF
stmt_srch FO
stmt_srch WH
stmt_srch BR
stmt_srch GO
stmt_srch SW
stmt_srch RE
stmt_srch EL
stmt_srch CO
stmt_srch {_
stmt_srch }_

