all:
	@nasm -f macho64 libasm.s
	@gcc -arch x86_64 main.c libasm.o -fno-pie
