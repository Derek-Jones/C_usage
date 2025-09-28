#
# functree.awk, 14 Mar 05

function pr_tree(num_ident, leaf_str)
{
if (leaf_str == "")
   return
for (ni=1; ni <= num_ident; ni++)
   printf(" ")
print leaf_str
}

NF == 7 {
	lev_4[$3 " " $4 " " $5]=lev_4[$3 " " $4 " " $5] "|" $6 " " $7
	next
	}

NF == 6 {
	lev_3[$3 " " $4]=lev_3[$3 " " $4] "|" $5 " " $6
	next
	}

NF == 5 {
	lev_2[$2 " " $3]=lev_2[$2 " " $3] "|" $4 " " $5
	next
	}

NF == 4 {
	lev_1[$2]=lev_1[$2] "|" $3 " " $4
	next
	}

$2 == "FD" {
	next
	}

	{
	next
	}

END {
	split(lev_1["FD"], child_1, "|")
	for (parent_1 in child_1)
	   {
	   pr_tree(0, child_1[parent_1])
	   split(child_1[parent_1], t_1)
	   split(lev_2["FD" " " t_1[1]], child_2, "|")
	   for (parent_2 in child_2)
	      {
	      pr_tree(4, child_2[parent_2])
	      split(child_2[parent_2], t_2)
	      split(lev_3[t_1[1] " " t_2[1]], child_3, "|")
	      for (parent_3 in child_3)
	         {
	         pr_tree(8, child_3[parent_3])
	         split(child_3[parent_3], t_3)
	         split(lev_4[t_1[1] " " t_2[1] " " t_3[1]], child_4, "|")
	         for (parent_4 in child_4)
	            {
	            pr_tree(12, child_4[parent_4])
	            #split(child_4[parent_4], t_4)
	            }
	         }
	      }
	   }
	}

