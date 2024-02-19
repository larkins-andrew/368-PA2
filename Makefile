pa2:
	gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic *.c -o pa2

pa2D:
	gcc -g -std=c99 -Wall -Wshadow -Wvla -DDEBUG -pedantic -fsanitize=address *.c -o pa2

clean:
	-rm pa2
	-rm *.po
	-rm *.pck
	-rm *.dim

fresh: clean
	$(MAKE) pa2