Summary: fast comparison of large source-code trees
Name: comparator
Version: %{version}
Release: 1
License: GPL
Group: Utilities
URL: http://www.catb.org/~esr/comparator/
Source0: %{name}-%{version}.tar.gz
#BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-buildroot
%undefine __check_files

%description
comparator and filterator are a pair of tools for rapidly finding common
code segments in large source trees.  They can be useful as tools for 
detecting copyright infringement.

%prep
%setup -q

%build
make

%install
rm -rf $RPM_BUILD_ROOT
make install

%clean
rm -rf $RPM_BUILD_ROOT
make uninstall

%files
%defattr(-,root,root,-)
%doc README comparator.1
/usr/bin/comparator
/usr/bin/filterator
/usr/share/man/man1/comparator.1

%changelog
* Sun Sep  7 2003 Eric S. Raymond <esr@snark.thyrsus.com> 
- Initial build.


