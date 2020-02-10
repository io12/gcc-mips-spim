#!/bin/sh

set -eux

. ./env.sh

build_toolchain() {
	mkdir -p prefix build-gcc build-binutils

	cd build-binutils
	../binutils-gdb/configure \
		--target="$TARGET" \
		--prefix="$PREFIX" \
		--with-sysroot \
		--disable-nls \
		--disable-werror

	make
	make install
	cd ..

	cd gcc
	./contrib/download_prerequisites
	cd ..
	cd build-gcc
	../gcc/configure \
		--target="$TARGET" \
		--prefix="$PREFIX" \
		--disable-nls \
		--enable-languages=c \
		--without-headers \
		--with-gnu-ld \
		--with-gnu-as \
		--disable-shared \
		--disable-threads \
		--disable-libmudflap \
		--disable-libgomp \
		--disable-libssp \
		--disable-libquadmath \
		--disable-libatomic

	make
	make install
	cd ..
}

#build_toolchain

cd dietlibc
make clean
rm -f libc.h
make ARCH=mips CC="$(pwd)/../header-gcc.py" bin-mips/dietlibc.a
mips-elf-gcc -E -I. -I./lib -isystem include libc.h -o libc-cpp.h
../staticify.py < libc-cpp.h > libc-static.h
mv libc-static.h ../libc.h
cd ..
