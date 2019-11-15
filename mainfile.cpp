/*
280
Graph Assignment 1
Thomas Evon && Gunnar Marquardt
*/
#include <iostream>
#include <fstream>
#include <string>
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
		while (!input.eof()) {
			input >> buffChar;
			graph.addNode(buffChar);
			input >> garbage;
			input >> comChar;
			while (comChar != ';') {
				graph.addNode(comChar); // initializes everything as zero
				graph.set(buffChar, comChar); // sets the ones
				input >> comChar;
			}
		}
		input.close();
	}
	graph.display();

	ifstream inCommand;
	string inputCommand;
	char inArg; 
	int x;
	int sum = 0;
	
	inCommand.open("commands.txt");
	while (inCommand.is_open()) {
		while (!inCommand.eof()) {
			getline(inCommand, inputCommand);
			cout << inputCommand << endl;
			inArg = inputCommand.back(); 
			cout << inArg << endl;

			for (char d : inputCommand) { // convert to ascii
				x = d;
				sum += d;
			}

			cout << sum << endl; 

			switch (sum) {
			case (667): { // Adjecent
				cout << "call graphs::adjecent function " << endl;
				break;
			}
			case (985): { // DFS
				cout << "Performing DFS... " << endl;
				vector <bool> visited(5, false);
				int start = graph.posOf(inArg);
				graph.DFS(start, visited);
				cout << endl;
				break;
			}
			case (1301): { // BFS
				cout << "call graphs::BFS function " << endl;
				break;
			}
			case (1960): {// Connected
				cout << "call graphs::Connected function " << endl;
			}
			default: {
				exit(0); 
				break;
			}
			}
		}
		inCommand.close(); 
	}

}