/*
280
Graph Assignment 1
Thomas Evon && Gunnar Marquardt
*/
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
	ifstream input;
	//istream dinger; 
	string line; 
	char buffChar;
	char comChar;
	char garbage;
	Graph graph = Graph();

	input.open("graphs.txt");
	while (input.is_open()) {
		while (!input.eof()) {
			getline(input, line);
			buffChar = line[0];
			graph.addNode(buffChar);
			for (int i = 5; i < line.size(); i++) {
				if (line[i] != ' ') {
						comChar = line[i];
						graph.addNode(comChar); // initializes everything as zero
						graph.set(buffChar, comChar); // sets the ones
				}
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
			inArg = inputCommand.back(); 
			for (char d : inputCommand) { // convert to ascii
				x = d;
				sum += d;
			}
			switch (sum) { // switch on what command is called in from text file 
			case (667): { // Adjecent
				cout << "Performing ADJ... " << endl;
				graph.ADJ(inArg);
				cout << endl << endl;
				break;
			}
			case (985): { // DFS
				cout << "Performing DFS... " << endl;
				vector <bool> visited(graph.map.size(), false);
				int start = graph.posOf(inArg);
				graph.DFS(start, visited);
				cout << endl << endl;
				break;
			}
			case (1301): { // BFS
				cout << "Performing BFS... " << endl;
				vector <bool> visited(graph.map.size(), false);
				int start = graph.posOf(inArg);
				graph.BFS(start, visited);
				cout << endl << endl; 
				break;
			}
			case (1960): {// Connected
				graph.connected(); 
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
