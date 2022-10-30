CCC = g++
LEX = flex   
YACC= bison 
OUT=example

${OUT}: p4ltlParser.cpp p4ltlScanner.cpp p4ltlast.cpp exampleMain.cpp
	${CCC} -o $@ $^

p4ltlParser.cpp p4ltlParser.hpp: p4ltlparser.ypp
	${YACC} $<

p4ltlScanner.cpp: p4ltllexer.ll p4ltlParser.hpp
	${LEX} $<

run:
	@echo "----- Running example -----"
	./$(OUT)

.PHONY : clean
clean:
	rm -f lex.yy.* y.tab.* *.o stack.hh p4ltlScanner.cpp p4ltlParser.*