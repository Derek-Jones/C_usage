# Makefile for the comparator/filterator tools
#
# By building with -DLARGEFILES you can go to all 32-byte offsets.
# This increases working-set size by 20% but handles > 65336 lines per file.

VERS=1.6

CODE    = shredtree.c shred.h report.c main.c md5.c md5.h filterator
DOCS    = README NEWS comparator.xml scf-standard.xml COPYING
EXTRAS  = shredtree.py shredcompare.py
TEST    = test
SOURCES = $(CODE) $(DOCS) $(EXTRAS) $(TEST) comparator.spec Makefile
CFLAGS  = -O
LDFLAGS = 

all: comparator comparator.1

main.o: main.c shred.h
	$(CC) -DVERSION=\"$(VERS)\" -c $(CFLAGS) main.c 
shredtree.o: shredtree.c shred.h
	$(CC) -c $(CFLAGS) shredtree.c 
report.o: report.c shred.h
	$(CC) -c $(CFLAGS) report.c 
comparator: main.o shredtree.o md5.o report.o
	$(CC) $(CFLAGS) main.o shredtree.o md5.o report.o $(LDFLAGS) -o comparator

clean:
	rm -f comparator shredtree.o md5.o report.o main.o *~
	rm -f comparator.1 filterator.1 
	rm -f *.dump *.scf

comparator.1: comparator.xml
	xmlto man comparator.xml

comparator.html: comparator.xml
	xmlto html-nochunks comparator.xml

scf-standard.html: scf-standard.xml
	xmlto html-nochunks scf-standard.xml

makeregress:
	@for n in 1 2 3; do \
	    comparator -C -d test test$${n}-a test$${n}-b >test/out$${n}.good;\
	done

regress:
	@for n in 1 2 3; do \
	    comparator -C -d test test$${n}-a test$${n}-b >test/out$${n}.log 2>/dev/null;\
	    if diff -c test/out$${n}.good test/out$${n}.log; \
	    then \
		echo "Test $${n} from trees passed."; \
	    else \
		echo "Test $${n} from trees failed."; \
	    fi; \
	    comparator -C -d test -c test$${n}-a >test$${n}-a.scf 2>/dev/null; \
	    comparator -C -d test -c test$${n}-b >test$${n}-b.scf 2>/dev/null; \
	    comparator -C test$${n}-a.scf test$${n}-b.scf >test/out$${n}.log 2>/dev/null;\
	    rm test$${n}-a.scf test$${n}-b.scf; \
	    if diff -u test/out$${n}.good test/out$${n}.log; \
	    then \
		echo "Test $${n} from SCFs passed."; \
	    else \
		echo "Test $${n} from SCFs failed."; \
	    fi; \
	done

install: comparator.1 uninstall
	install -m 755 -o 0 -g 0 -d $(ROOT)/usr/bin/
	install -m 755 -o 0 -g 0 comparator $(ROOT)/usr/bin/comparator
	install -m 755 -o 0 -g 0 filterator $(ROOT)/usr/bin/filterator
	install -m 755 -o 0 -g 0 -d $(ROOT)/usr/share/man/man1/
	install -m 755 -o 0 -g 0 comparator.1 $(ROOT)/usr/share/man/man1/comparator.1

uninstall:
	rm -f ${ROOT}/usr/bin/comparator 
	rm -f ${ROOT}/usr/bin/filterator 
	rm -f ${ROOT}/usr/share/man/man1/comparator.1

comparator-$(VERS).tar.gz: $(SOURCES) comparator.1
	find $(SOURCES) comparator.1 -type f | sed "s:^:comparator-$(VERS)/:" >MANIFEST
	(cd ..; ln -s comparator comparator-$(VERS))
	(cd ..; tar -czvf comparator/comparator-$(VERS).tar.gz `cat comparator/MANIFEST`)
	(cd ..; rm comparator-$(VERS))

dist: comparator-$(VERS).tar.gz

RPMROOT=/usr/src/redhat
rpm: dist
	rpmbuild --define 'version $(VERS)' -ta comparator-$(VERS).tar.gz
	cp $(RPMROOT)/RPMS/*/comparator-$(VERS)*.rpm .
	cp $(RPMROOT)/SRPMS/comparator-$(VERS)*.src.rpm .
