#
# namedparam.R  7 May 11

plot_pos=function(np, prog_str)
{
par(col="black")
plot(unused_p[1, 4],
		 xlim=c(1, 8), ylim=c(60, 100), xlab=prog_str, ylab="Percentage")
offset=1
for (i in 2:8)
   {
   offset=offset+i-1
   perc=seq(1:i)
   for (j in seq(1:i))
     perc[j]=unused_p[offset+j-1, 4]
   par(new=TRUE)
   par(col=col_tab[1+j %% 4])
   plot(perc, type="l", xlim=c(1, 8), ylim=c(60, 100), xlab="", ylab="")
   }
}

col_tab=c("red", "green", "blue", "black")
par(mfcol=c(1,1))
par(mai=c(0.9, 0.9, 0.1, 0.2))
unused_p=read.csv("unused.names", sep=",", header=FALSE, strip.white=TRUE)
plot_pos(net_p[,1], "Parameter")
