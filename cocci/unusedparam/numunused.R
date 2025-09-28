#
# numunused.R  8 May 11

par(mfcol=c(1,1))
par(mai=c(0.9, 0.9, 0.1, 0.2))
num_unused=read.csv("unused.number", sep=",", header=FALSE, strip.white=TRUE)
max_y=max(num_unused[,3])
par(col="black")
plot(num_unused[,3], ylim=c(1, max_y), log="y",
		 xlab="Parameters", ylab="Function definitions")
par(new=TRUE)
par(col="red")
plot(num_unused[,2], ylim=c(1, max_y), log="y",
		 xlab="", ylab="")

# Derek's wet-finger fit
par(new=TRUE)
par(col="green")
plot(num_unused[,4], ylim=c(1, max_y), log="y", type="l",
		 xlab="", ylab="")

# A linear regression of the actual data
x=c(1:8)
y=log10(num_unused[,2])
est_lm=lm(y~x)
par(col="blue")
abline(reg=est_lm, lty=1)
