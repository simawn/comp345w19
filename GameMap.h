#pragma once
#include "City.h"
#include <vector>

class Graph {
	std::vector<Node> adjList;
public:
	Graph();
	void addNode(Node);
	void displayAllNodes();
};

struct Node {
	std::vector<Edge> edges;
	City content;

	Node(City);
	void addEdge(Edge);
	void removeEdge(Edge);
};

struct Edge {
	Node* toNode;
	int weight;

	Edge(Node, int);
};