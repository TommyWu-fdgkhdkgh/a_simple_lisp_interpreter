bison -d -o c.tab.c c.y
gcc -c -g -I.. c.tab.c
flex -o c.yy.c c.l
gcc -c -g -I.. c.yy.c
gcc -o c c.tab.o c.yy.o -ll
