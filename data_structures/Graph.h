// By: Gonçalo Leão

#ifndef DA_TP_CLASSES_GRAPH
#define DA_TP_CLASSES_GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "MutablePriorityQueue.h"

#include "VertexEdge.h"

class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const std::string &name) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const std::string &string);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const std::string &sourc, const std::string &dest, double w, const std::string &service);
    bool addBidirectionalEdge(const std::string &sourc, const std::string &dest, double w, const std::string &service);

    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;
    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const std::string &name) const;
    void Graph::testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual);
    bool Graph::findAugmentingPath(Vertex *s, Vertex *t);
    double Graph::findMinResidualAlongPath(Vertex *s, Vertex *t);
    void Graph::augmentFlowAlongPath(Vertex *s, Vertex *t, double f);
    double Graph::edmondsKarp(std::string source, std::string target);
protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);

#endif /* DA_TP_CLASSES_GRAPH */