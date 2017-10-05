all: png
	feh build/my_graph1.png &
	feh build/my_graph2.png &

png: compile
	build/main
	dot -Tpng build/my_graph1.dot -o build/my_graph1.png
	dot -Tpng build/my_graph2.dot -o build/my_graph2.png

compile: prep
	g++ -g main.cpp -o build/main

prep:
	mkdir -p build

clean:
	rm -rf build