#!/usr/bin/env python3

import sys
import os
import subprocess
import time

CC = "mips-elf-gcc"

files = []

for arg in sys.argv:
    if ".c" in arg or ".h" in arg:
        files.append(arg)

with open("libc.h", "ab") as fout:
    for fin in files:
        with open(fin, "rb") as fin:
            data = fin.read()
            if b"int main(" not in data:
                fout.write(data)

os.execvp(CC, [CC] + sys.argv[1:])
