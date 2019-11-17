#include "Graph.h"
#include <queue>

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
	int posA = posOf(a);
	int posB = posOf(b);
	adjMat.at(posA).at(posB) = 1;
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
	cout << endl;
}

void Graph::DFS(int start, vector<bool>& visited) {
	char print = map.at(start); // print current node
	cout << print << "->";
	visited[start] = true;
	for (int i = 0; i < map.size(); i++) { // visit if not already visited
		if (adjMat[start][i] == 1 && (!visited[i])) {
			DFS(i, visited);
		}
	}
}

void Graph::DFSutility(int start, vector<bool>& visited) {
	visited[start] = true;
	for (int i = 0; i < map.size(); i++) { // visit if not already visited
		if (adjMat[start][i] == 1 && (!visited[i])) {
			DFS(i, visited);
		}
	}
}

void Graph::ADJ(char vertex) {
	int count = 0;
	for (int i : adjMat.at(posOf(vertex))) {
		if (i == 1) cout << map.at(count) << " ";
		count++;
	}
}

void Graph::BFS(int start, vector<bool>& visited) {
	queue <int> q; // queue 
	visited[start] = true; 
	q.push(start);
	int buffer; 
	while (q.size() != 0) {
		buffer = q.front(); 
		cout << map.at(buffer) << "->"; // print starting node
		q.pop(); // pop off first item in queue
		for (int i = 0; i < map.size(); i++) {
			if (adjMat.at(buffer).at(i) == 1 && !visited.at(i)) {
				visited[i] = true;
				q.push(i);
			}
		}
	} 
}

void Graph::connected() {
	bool isConnected = true;
	for (int i = 0; i < map.size(); i++) {
		vector <bool> v1(map.size(), false);
		DFSutility(i, v1);
		for (bool r : v1) {
			if (r == 1) isConnected = false;
			break;
		}
	}
	if (isConnected) cout << "Graph is connected" << endl;
	else if (!isConnected) cout << "Graph is not connected" << endl; 
}