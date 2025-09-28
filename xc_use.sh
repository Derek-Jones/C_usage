(cat c_idents.txt ; find programs -follow -name "*.c" -exec findexec.sh {} \;) | xngram

