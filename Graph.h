#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

class Graph {
private:
	bool inMap;
	vector <vector <int> > adjMat;
public:
	vector <char> map;
	Graph();
	void addNode(char);
	int posOf(char);
	void set(char, char);
	void display();
	void DFS(int, vector<bool>&);
	void BFS(int, vector<bool>&);
	void ADJ(char);
};

#endif
