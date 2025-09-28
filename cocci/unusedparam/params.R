#
# params.R  7 May 11

plot_pos=function(np, prog_str)
{
par(col="black")
plot(100*length(np[np == "1_1"])/length(np[np == 1]),
		 xlim=c(1, 8), ylim=c(0, 30), xlab=prog_str, ylab="Percentage")
for (i in 2:8)
   {
   unused=seq(1:i)
   for (j in seq(1:i))
     unused[j]=length(np[np == paste(i, "_", j, sep="")])/length(np[np == i])
   par(new=TRUE)
   par(col=col_tab[1+j %% 4])
   plot(100*unused, type="l", xlim=c(1, 8), ylim=c(0, 30), xlab="", ylab="")
   }
}

col_tab=c("red", "green", "blue", "black")
par(mfcol=c(3,3))
par(mai=c(0.6, 0.5, 0.1, 0.2))
net_p=read.csv("net.params", sep=" ", header=FALSE, fill=TRUE)
total_unused=net_p[,1]
plot_pos(net_p[,1], "Netscape")
net_p=read.csv("gcc.params", sep=" ", header=FALSE, fill=TRUE)
append(total_unused, net_p[,1])
plot_pos(net_p[,1], "gcc 2.95")
net_p=read.csv("linux.params", sep=" ", header=FALSE, fill=TRUE)
append(total_unused, net_p[,1])
plot_pos(net_p[,1], "Linux 2.4.20")
net_p=read.csv("post.params", sep=" ", header=FALSE, fill=TRUE)
append(total_unused, net_p[,1])
plot_pos(net_p[,1], "Postgresql")
net_p=read.csv("id.params", sep=" ", header=FALSE, fill=TRUE)
append(total_unused, net_p[,1])
plot_pos(net_p[,1], "id software")
net_p=read.csv("afs.params", sep=" ", header=FALSE, fill=TRUE)
append(total_unused, net_p[,1])
plot_pos(net_p[,1], "open AFS")
net_p=read.csv("brl.params", sep=" ", header=FALSE, fill=TRUE)
append(total_unused, net_p[,1])
plot_pos(net_p[,1], "BRL")
net_p=read.csv("cin.params", sep=" ", header=FALSE, fill=TRUE)
append(total_unused, net_p[,1])
plot_pos(net_p[,1], "Cinelerra")

plot_pos(total_unused, "All programs")

