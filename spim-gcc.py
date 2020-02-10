#!/usr/bin/env python3

import sys
import os
import subprocess

for arg in sys.argv:
    if ".c" in arg:
        path = arg
        break

argv = ["mips-elf-gcc", "-S", "-o", "-"] + sys.argv[1:]
pipe = subprocess.Popen(argv, stdout=subprocess.PIPE,
        env=os.environ)
lines = pipe.stdout.readlines()
fout = open(path[:-1] + "s", "w")
for line in lines:
    line = line.decode("utf-8")
    line = line.replace(".string", ".ascii")
    if ".text" in line:
        continue
    if ".data" in line:
        continue
    if ".ident" in line:
        continue
    if ".size" in line:
        continue
    if ".file" in line:
        continue
    if ".section" in line:
        continue
    if ".type" in line:
        continue
    if ".cfi_startproc" in line:
        continue
    if ".previous" in line:
        continue
    if ".nan" in line:
        continue
    if ".module" in line:
        continue
    if "lui" in line and "hi" in line:
        line = line.replace("lui", "la")
        line = line.replace("%hi($", "$")
        line = line.replace(")", "")
    if "%lo($" in line:
        continue
    if line[0] == "$":
        line = ".data\n" + line
    if "main:" in line:
        line = ".text\n" + line
    fout.write(line)
