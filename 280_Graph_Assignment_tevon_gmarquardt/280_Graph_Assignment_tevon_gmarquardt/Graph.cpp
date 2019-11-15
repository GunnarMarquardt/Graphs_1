#include "Graph.h"

Graph::Graph() {

}

void Graph::addNode(char c) {
	inMap = false;
	for (char d : map) {
		if (d == c) inMap = true;
	}
	if (!inMap) {
		map.push_back(c);
		for (int i = 0; i < adjMat.size(); i++) {
			adjMat.at(i).push_back(0);
		}
		if (adjMat.size() == 0) adjMat.push_back(vector<int>(1, 0));
		else adjMat.push_back(vector<int>(adjMat.back().size(), 0));
		cout << "added " << c << endl;
	}
}

int Graph::posOf(char c) {
	int count = 0;
	for (char d : map) {
		if (d == c) return count;
		count++;
	}
	return -1;
}

void Graph::set(char a, char b) {
	cout << "setting" << endl;
	int posA = posOf(a);
	int posB = posOf(b);
	cout << posA << " " << posB << endl;
	adjMat.at(posA).at(posB) = 1;
	cout << "set " << a << " " << b << endl;
}

void Graph::display() {
	int count = 0;

	cout << "  ";
	for (char c : map) {
		cout << c << " ";
	}
	cout << endl;
	for (vector<int> v : adjMat) {
		cout << map.at(count) << " ";
		for (int i : v) {
			cout << i << " ";
		}
		cout << endl;
		count++;
	}
}
