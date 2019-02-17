#include "GameMap.h"

Graph::Graph() {}

void Graph::addNode(Node node) {
	adjList.push_back(node);
}

void Graph::displayAllNodes() {

}

Node::Node(City city) : content(city) {}

