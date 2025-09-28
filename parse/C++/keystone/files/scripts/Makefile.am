
bin_SCRIPTS = \
  analyze-key \
  change-name.pl \
  count-classes.pl \
  ih2dot.pl \
  make-visitor.pl \
  process-output.sh \
  regtest.py \
  tc2dot.pl \
  wc.pl

make-visitor.pl: make-visitor.pl.ske
	@sed 's%ac_pkgdatadir%$(pkgdatadir)%' make-visitor.pl.ske > mv-tmp.pl
	@sed 's%ac_pkgincludedir%$(pkgincludedir)%' mv-tmp.pl > $@
	@rm -f mv-tmp.pl

regtest.py: regtest.py.ske
	@sed 's%ac_bin_key%$(prefix)/bin/key%' regtest.py.ske > $@

EXTRA_DIST = \
  analyze-key \
  change-name.pl \
  count-classes.pl \
  ih2dot.pl \
  make-visitor.pl.ske \
  process-output.sh \
  regtest.py.ske \
  tc2dot.pl \
  wc.pl

BUILT_SOURCES = make-visitor.pl regtest.py

CLEANFILES = $(BUILT_SOURCES)

