CCC = g++
CCFLAGS= -O2
LEX = flex
LFLAGS= -8     
YACC= bison 
YFLAGS= -d -t -y
OUT=p4ltlparser

p4ltlparser: p4ltlParser.cpp p4ltlScanner.cpp
	${CCC} -o ${OUT} p4ltlParser.cpp p4ltlScanner.cpp p4ltlast.cpp 

p4ltlParser.cpp: p4ltlparser.ypp
	${YACC} p4ltlparser.ypp

p4ltlScanner.cpp: p4ltllexer.ll
	${LEX} p4ltllexer.ll

run:
	@echo "Running parser. Type in <CTRL + D> to stop."
	./$(OUT)

.PHONY : clean
clean:
	rm -f lex.yy.* y.tab.* *.o stack.hh p4ltlScanner.cpp p4ltlParser.cpp