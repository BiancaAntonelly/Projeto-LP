all: 
	echo "Leu o make"
	g++ -o main main.cpp ./cpps/pessoa.cpp ./cpps/funcionario.cpp ./cpps/asg.cpp  ./cpps/vendedor.cpp  ./cpps/gerente.cpp  ./cpps/empresa.cpp
	./main