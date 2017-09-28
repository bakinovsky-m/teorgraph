#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>
#include <stdio.h>

class Graph{
public:
	Graph(int count, std::vector<int> vi, std::vector<int> vj);

	void printToConsole() const;
	void printToConsoleTEXTOM() const;
	void add(int i, int j);
	void exportToDot(char *) const;
private:
	void computeHL();
	std::vector<int> IJ, H, L;
	int count = 0;
};

Graph::Graph(int _count, std::vector<int> vi, std::vector<int> vj){
	count = _count;
	IJ.reserve(vj.size() * 2);
	H.reserve(count);
	L.reserve(vi.size() * 2);
	for(int i = 0; i < vi.size(); i++){
		IJ.push_back(vi[i]);
	}
	for(int i = 0; i < vj.size(); i++){
		IJ.push_back(vj[vj.size() - 1 - i]);
	}
	for(int i = 0; i < count; i++){
		H.push_back(-1);
	}
	for(int i = 0; i < IJ.size(); i++){
		L.push_back(-1);
	}

	computeHL();
}

void Graph::add(int i, int j){
	IJ.insert(IJ.begin() + IJ.size() / 2, i);
	IJ.insert(IJ.begin() + (IJ.size() + 1) / 2, j);
	computeHL();
}

void Graph::computeHL(){
	for(int i = 0; i < IJ.size(); i++){
		int k = IJ[i];
		L[i] = H[k];
		H[k] = i;
	}
}

void Graph::printToConsole() const{
	for(int i = 0; i < IJ.size() / 2; i++){
		std::cout << IJ[i] << " ";
	}

	std::cout << std::endl;

	for(int i = 0; i < IJ.size() / 2; i++){
		std::cout << IJ[IJ.size() - 1 - i] << " ";
	}
	std::cout << std::endl;

	for(int i = 0; i < H.size(); i++){
		std::cout << (H[i]) << " ";
	}

	std::cout << std::endl;
	for(int i = 0; i < L.size(); i++){
		std::cout << (L[i]) << " ";
	}
	std::cout << std::endl;
}

void Graph::printToConsoleTEXTOM() const{
	for (int i = 0; i < H.size(); i++){
		std::vector<int> v;

		for(int k = H[i]; k != -1;){
			v.push_back(k);
			k = L[k];
		}

		std::cout << "from " << i << ": ";
		for(int i = 0; i < v.size(); i++){
			std::cout << v[i] << ", ";
		}
		std::cout << std::endl;
	}
}

void Graph::exportToDot(char * filename) const{
	FILE *out;
	out = fopen(filename, "w");
	fprintf(out, "graph gr {\n");
	for(int i = 0; i < count; i++){
		fprintf(out, "  %d;\n", i);
	}
	for(int i = 0; i < IJ.size() / 2; i++){
		fprintf(out, "  %d -- %d;\n", IJ[i], IJ[IJ.size() - 1 - i]);
	}
	fprintf(out, "}\n");
	fclose(out);
}

#endif // GRAPH_H