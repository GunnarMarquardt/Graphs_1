/*
280
Graph Assignment 1
Thomas Evon && Gunnar Marquardt
*/
#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int main()
{
	ifstream input;
	char buffChar;
	char comChar;
	char garbage;
	Graph graph = Graph();

	input.open("graphs.txt");
	while (input.is_open()) {
		cout << "opened file" << endl;
		while (!input.eof()) {
			input >> buffChar;
			graph.addNode(buffChar);
			input >> garbage;
			input >> comChar;
			while (comChar != ';') {
				graph.addNode(comChar);
				cout << buffChar << comChar << endl;
				graph.set(buffChar, comChar);
				input >> comChar;
			}
		}
		input.close();
		cout << "closed file" << endl;
	}

	graph.display();
}