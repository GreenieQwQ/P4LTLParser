CCC = g++
CCFLAGS= -O2
LEX = flex
LFLAGS= -8     
YACC= bison 
YFLAGS= -d -t -y
OUT=p4ltlparser

p4ltlparser: y.tab.o lex.yy.o p4ltlast.o
	${CCC} ${CCFLAGS} lex.yy.o y.tab.o p4ltlast.o -o ${OUT}

p4ltlast.o: p4ltlast.cpp p4ltlast.hpp
	${CCC} -c p4ltlast.cpp
y.tab.o: p4ltlparser.ypp
	${YACC} ${YFLAGS} p4ltlparser.ypp
	${CCC} ${CCFLAGS} y.tab.c -c 

lex.yy.o: p4ltllexer.ll
	${LEX} $(LFLAGS) p4ltllexer.ll
	${CCC} ${CCFLAGS} lex.yy.c -c 

run:
	@echo "Running parser. Type in <CTRL + D> to stop."
	./$(OUT)

.PHONY : clean
clean:
	rm -f lex.yy.* y.tab.* *.o stack.hh