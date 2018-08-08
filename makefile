SingleLLOperations: SingleLL.o OtherFunc.o
		cc -o SingleLLOperations -g SingleLL.o OtherFunc.o -Wall

OtherFunc.o: OtherFunc.c
		cc -c OtherFunc.c

SingleLL.o: SingleLL.c OtherFunc.o
		cc -c SingleLL.c -g OtherFunc.o

clean:
	rm *.o
	rm SingleLLOperations
