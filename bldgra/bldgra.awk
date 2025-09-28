# bldgra.awk,  9 Jul 03

BEGIN {
	maxY=maxy*2.0
	power10=int(log(maxY)/2.3)
	ten_valu=1.0
	start_tick="ticks left out at"
	pow_num[1]="10"
	pow_str[1]="10"
	pow_num[2]="100"
	pow_str[2]="100"
	pow_num[3]="1000"
	pow_str[3]="1,000"
	pow_num[4]="10000"
	pow_str[4]="10,000"
	pow_num[5]="100000"
	pow_str[5]="100,000"
	pow_num[6]="1000000"
	pow_str[6]="1,000,000"
	pow_num[7]="10000000"
	pow_str[7]="10,000,000"
	pow_num[8]="100000000"
	pow_str[8]="100,000,000"
	pow_num[9]="1000000000"
	pow_str[9]="1,000,000,000"
	left_tick_num=start_tick " 1"
	left_tick=start_tick " 1 \"\""
	for (p=1; p <= power10; p++) {
	   left_tick_num=left_tick_num ", " pow_num[p] " \"" pow_str[p] "\""
	   left_tick=left_tick ", " pow_num[p] " \"\""
	   ten_valu=ten_valu*10.0
	   }
   }

/__LEFT_TICK_LIN_NUM/ {
   gsub(/__LEFT_TICK_LIN_NUM/, "ticks left out", $0)
   print $0
   next
   }

/__LEFT_TICK_NUM/ {
   gsub(/__LEFT_TICK_NUM/, left_tick_num, $0)
   print $0
   next
   }

/__LEFT_TICK_LIN/ {
   gsub(/__LEFT_TICK_LIN/, "ticks left out", $0)
   print $0
   next
   }

/__LEFT_TICK/ {
   gsub(/__LEFT_TICK/, left_tick, $0)
   print $0
   next
   }

/__MAXY/ {
   gsub(/__MAXY/, maxY, $0)
   print $0
   next
   }

/__MAXy/ {
   gsub(/__MAXy/, maxy, $0)
   print $0
   next
   }

/__POWER10/ {
   gsub(/__POWER10/, ten_valu, $0)
   print $0
   next
   }

/__HT/ ||
/__WID/ {
   gsub(/__HT/, ENVIRON["gra_ht"], $0)
   gsub(/__WID/, ENVIRON["gra_wid"], $0)
   print $0
   next
   }

/__PRELUDE/ {
   gsub(/__PRELUDE/, ENVIRON["gra_prelude"], $0)
   print $0
   next
   }

/__DATE/ {
   gsub(/__DATE/, ENVIRON["gra_date"], $0)
   print $0
   next
   }

   {
   print $0
   next
   }

