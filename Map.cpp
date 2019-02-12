/*
Very likely that I'll rewrite the entire code to be more simple.
I feel like the things I'm using are out of the scope of what we are supposed to learn.
Lots of Googling involved...
*/

#include "Map.h"
#include <iostream>
#include <string>
#include <unordered_set> //.find: avg O(1), worst O(n)

template <typename T> struct Node;
template <typename T> struct Edge;

//Custom Hash and Comparison for unordered_set
//We need that since we are passing user defined objects
namespace std {
	//Custom hash for Node
	template<typename T> struct hash<Node<T>> {
		std::size_t operator()(const Node<T> &obj) const {
			return std::hash<int>()(obj.content);
		}
	};

	//Custom hash for Edge
	template<typename T> struct hash<Edge<T>> {
		std::size_t operator()(const Edge<T> &obj) const {
			return std::hash<int>()(obj.to);
		}
	};


};


template<typename T> struct Node {
	T content;
	std::unordered_set<Edge<T>> edgeList;

	Node(T content) : content(content) {};

	void addEdge(Edge<T> edge) {
		edgeList.insert(edge);
	}
};

template<typename T> struct Edge {
	Node<T> to;
	int weight;

	Edge(Node<T> to, int weight) : to(to), weight(weight) {};
};

template<typename T> class Map {
public:
	Map() {};

	void addNode(T content) {
		Node<T> node(content);
		nodeList.insert(node);
	};

	void displayAllNodes() {
		for (auto iterator = nodeList.begin; iterator != nodeList.end; iterator++) {
			std::cout << *iterator << std::endl;
		}
	}

private:
	std::unordered_set<Node<T>> nodeList;
};

int main() {
	Map<int> map; //Create a map of strings
	map.addNode(9);
	map.addNode(7);
	map.addNode(0);
	map.addNode(34);
	map.addNode(87);
}