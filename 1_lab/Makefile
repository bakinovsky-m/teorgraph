all: png
	feh my_graph1.png &
	feh my_graph2.png &


png: compile
	./main
	dot -Tpng my_graph1.dot -o my_graph1.png
	dot -Tpng my_graph2.dot -o my_graph2.png

compile:
	g++ main.cpp -o main

clean:
	rm my*
	rm main