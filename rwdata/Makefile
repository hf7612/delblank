CC=gcc

sample: l.c rwdata.ld
	mkdir -p build
	$(CC) -T rwdata.ld l.c -o build/sample  	

clean:
	rm -r build/