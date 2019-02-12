#include "Map.h"
#include <iostream>
#include <string>
#include <vector>

template<typename T> struct Node;
template<typename T> struct Edge;

template<typename T> struct Node {
	T content;
	std::vector<Edge<T>> edgeList;

	Node(T content) : 
		content(content) 
	{};

	void addEdge(Edge<T> edge) {
		edgeList.push_back(edge);
	}
};

template<typename T> struct Edge {
	Node<T> to;
	int weight;

	Edge(Node<T> &to, int weight) : 
		to(to), weight(weight) 
	{};
};

template<typename T> class Map {
public:
	Map() 
	{};

	void addNode(T content) {
		Node<T> node(content);
		nodeList.push_back(node);
	};

	Node<T> getNode(T content) {
		auto it = std::find(nodeList.begin(), nodeList.end(), content);
		if (it != nodeList.end()) {
			return it->content;
		} else {
			return NULL;
		}
	}
	
	void displayAllNodes() {
		for (auto it = nodeList.begin(); it != nodeList.end(); ++it) {
			std::cout << it->content << std::endl;
		}
	}

private:
	std::vector<Node<T>> nodeList;
};

int main() {
	Map<int> map;
	map.addNode(9);
	map.addNode(7);
	map.addNode(0);
	map.addNode(34);
	map.addNode(87);
	map.displayAllNodes();
	Node<int> find = map.getNode(9);
}