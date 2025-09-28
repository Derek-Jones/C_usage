
# doall.sh,  6 May 11

spatch.opt -sp_file params.cocci -use_cache /usr1/expsrc/netscape/ > net.params
#spatch.opt -sp_file params.cocci /usr1/expsrc/gcc-2.95/ > gcc.params
#spatch.opt -sp_file params.cocci /usr1/model/tests/compiler/customer/idsoftware/ > id.params
#spatch.opt -sp_file params.cocci /usr1/linux-2.4.20-8 > linux.params
#spatch.opt -sp_file params.cocci /usr1/expsrc/openafs-1.2.2a/ > afs.params
#spatch.opt -sp_file params.cocci /usr1/expsrc/postgresql-6.5.3/ > post.params
#spatch.opt -sp_file params.cocci /usr1/expsrc/brlcad-7.0/ > brl.params
#spatch.opt -sp_file params.cocci /usr1/expsrc/cinelerra/ > cin.params

