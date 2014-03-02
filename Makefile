SUBDIRS = src 

#
# Dados sobre o grupo e turno frequentado 
# CAMPUS = preencher com A ou T consoante Alameda ou Tagus
# CURSO = indicar o curso do turno frequentado: LEIC ou LERC
# GRUPO = indicar o numero do grupo
# ALUNO1/ALUNO2/ALUNO3 = indicar os numeros dos alunos
#
CAMPUS=A
CURSO=LEIC
GRUPO=062
ALUNO1=75714
ALUNO2=76012

CFLAGS = -g -O0 -Wall 
OUTPUT = project.app
INCLUDE = -I ./include/
OBJECTS = ./src/*.c

export DEFS
export CFLAGS

all: build

build:
	gcc $(CFLAGS) -o $(OUTPUT) $(INCLUDE) $(OBJECTS)

clean_objects:
	cd src;
	rm *.o
	cd ..
	
clean:
	clean_objects
	rm $(OUTPUT)

package: clean zip

zip:
ifndef CAMPUS
	@echo "ERROR: Must setup macro 'CAMPUS' correcly."
else
ifndef CURSO
	@echo "ERROR: Must setup macro 'CURSO' correcly."
else
ifndef GRUPO
	@echo "ERROR: Must setup macro 'GRUPO' correcly."
else
	tar -czf project-$(CAMPUS)-$(CURSO)-$(GRUPO)-$(ALUNO1)-$(ALUNO2).tgz * 
endif
endif
endif
