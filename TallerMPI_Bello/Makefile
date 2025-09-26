PROGRAMAS = MPI
MPICC?=mpicc

all: ${PROGRAMAS}

MPI:
	${MPICC} -o $@ $@.c

clean:
	$(RM) ${PROGRAMAS}

run:
	mpirun ./${PROGRAMAS}
