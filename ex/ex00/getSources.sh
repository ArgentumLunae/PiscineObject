echo -n "SRC_FILES := " > sources.mk
find . -type f | grep ".cpp" | sed -e 's/$/ \\/' >> sources.mk