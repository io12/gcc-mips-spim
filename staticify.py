#!/usr/bin/env python3

import sys

def should_static(line):
    return not (
            line[0] == "\n"
            or line.startswith("#")
            or line.startswith("#")
            or line.startswith(" ")
            or line.startswith("\t")
            or line.startswith("}")
            or line.startswith("{")
            or line.startswith("struct")
            or line.startswith("union")
            or line.startswith("enum")
            or line.startswith("extern")
            or line.startswith("static")
            or line.startswith("__extension__")
            or line.startswith("sysctl")
            or ":" in line
            or "typedef" in line
    )

def replace(line):
    line = line.replace("extern char **environ;", "")
    line = line.replace("extern", "static")
    line = line.replace("__attribute__((__nothrow__ , __leaf__))", "")
    line = line.replace("__attribute__((__const__))", "")
    line = line.replace(", nothrow, leaf", "")
    line = line.replace("__attribute__((__const__,__pure__))", "")
    line = line.replace("__attribute__((visibility(\"hidden\")))", "")
    line = line.replace("__attribute__ ((__const__))", "")
    line = line.replace("__attribute__((weak))", "")
    line = line.replace("weak,", "")
    line = line.replace("  __thread ", "")
    line = line.replace("__attribute__ ((__pure__))", "")
    line = line.replace("__attribute__ ((__nonnull__ (1,2)))", "")
    if not ("st_ino" in line
            or "st_size" in line
            or "st_blocks" in line):
        line = line.replace("__extension__ ", "")

    return line

for line in sys.stdin:
    line = replace(line)

    if should_static(line):
        line = "static " + line

    sys.stdout.write(line)
