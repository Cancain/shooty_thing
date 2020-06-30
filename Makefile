OUTFOLDER=./bin
OUTFILE=${OUTFOLDER}/main

build:
	g++ -Wall -std=c++17 -g -Wfatal-errors \
	./src/*.cpp \
	-o ${OUTFILE} \
	-lSDL2;

clean:
	rm -rf ${OUTFOLDER}/*;

run:
	${OUTFILE};

debug: 
	gdb ${OUTFILE};

br:
	make build;
	make run;

bd:
	make build;
	make debug;
