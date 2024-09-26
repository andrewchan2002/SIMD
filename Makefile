# sample makefile
all:
	gcc -g -O0 init.c -o init.exe
	gcc -g -O0 simd_t.c -o simd_t.exe
	gcc -g -O0 simd.c -o simd.exe
clean:
	rm *.exe
