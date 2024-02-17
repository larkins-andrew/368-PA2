pa2:
	gcc -03 -std=c99 -Wall -Wshadow -Wvla -pedantic *.c -o pa2

paD:
	gcc -g -std=c99 -Wall -Wshadow -Wvla -DDEBUG -pedantic *.c -o pa2

clean:
	rm pa2

fresh: clean
	$(MAKE) pa2