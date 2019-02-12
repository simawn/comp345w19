#include "Map.h"
#include <vector>
#include <list>
#include <iostream>
#include <string>

struct Node;
struct Edge;

struct Node {
	std::string content;
	std::list<Edge> edgeList;

	Node(std::string content) : content(content) {};

	void addEdge(Edge edge) {
		edgeList.push_back(edge);
	}
};

struct Edge {
	Node to;
	int weight;

	Edge(Node to, int weight) : to(to), weight(weight) {};
};

class Map {
public:
	Map() {};

	void addNode(std::string city) {
		Node node(city);
		nodeList.push_back(node);
	};
private:
	std::list<Node> nodeList;
};

int main() {
	Map map;
	map.addNode("s");
}