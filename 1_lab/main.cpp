#include <vector>

#include "graph.h"

using namespace std;

int main(){
	int count = 5;
	vector<int> vi = {0, 1, 0, 3, 3, 4, 2};
	vector<int> vj = {1, 3, 2, 2, 4, 2, 4};

	Graph g = Graph(count, vi, vj);
	g.printToConsole();
	g.printToConsoleTEXTOM();
	g.exportToDot((char*)"build/my_graph1.dot");
	g.add(1, 2);
	g.exportToDot((char*)"build/my_graph2.dot");
	

	return 0;
}