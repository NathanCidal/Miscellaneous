//-------------------------------------------------------------------
//--  ->Algorithm: Graph
//--       ->Edge Weighted Graph
//--
//--  ->Language:  C++          (Mingw 8.1)
//--  ->Date:      12/06/2024
//--  ->Reference: Adapted to C++ from Sedgewick's Algorithms 4th Edition
//
//--  ->Applications:
//--    -> MINIMUM SPANNING TREES
//--    -> CIRCUITS
//--    -> ...
//--
//--    ->Notes: ... I GOT NO ENERGY BRUH
//--
//-------------------------------------------------------------------

#ifndef __EWGRAPH_HPP__
#define __EWGRAPH_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include "edge.hpp"

using namespace std;

class EWGraph{ 
    private:
        size_t v, e;                        //Unsigned Long Long Int Vertices and Edges
        map<string, vector<Edge>> graph;    //Graph inside the class
        set<string> vertices;

        void addToList(string v, Edge e){   //Adds To a List
            vector<Edge>& list = graph[v];
            list.push_back(e);
        }

    public:
        EWGraph(size_t dv){                 //Creates a Graph with dv Size (it doesn't actually, only with a set amount of space)
            this->v = dv;
            this->e = 0;
        }

        EWGraph(string filename){           //Creates a Graph through reading a file
            //Implement
        }

        size_t V(){ return this->v; }   //Getter for Vertices
        size_t E(){ return this->e; }   //Getter for Edges

        void addEdge(Edge e){           //Add a Edge to our Graph
            //Implement
            string vA = e.either();
            string vB = e.other(vA);
            addToList(vA, e);
            addToList(vB, e);
            vertices.insert(vA);
            vertices.insert(vB);
            this->e++;
            
        }

        void addEdge(string v, string w, double weight){        //Add a Edge to our Graph
            Edge e(v,w, weight);
            addToList(v, e);
            addToList(w, e);
            vertices.insert(v);
            vertices.insert(w);
            this->e++;
        }

        vector<Edge> adj(string v){     //Return the Adjecents of Vertice V
            return graph[v];
        }

        vector<Edge> all_Edges(){
            vector<Edge> allEdges;
            for (auto const& v : edgesV()) {
                for(auto const &w : adj(v)){
                    allEdges.push_back(w);
                }
            }
            return allEdges;
        }

        set<string> edgesV(){                //Return all edges
            return vertices;
        }
        

        string toString(){                  //Convert to a String
            stringstream ss;
            ss << V() << " vertices, " << E() << " edges\n";
            for(auto const & vAux :edgesV()){             //Run through all Vertices
                ss << vAux << ": ";
                for(auto const & wAux: adj(vAux)){          //Run through all Adjacents of the Vertice vAux
                    ss << wAux << " ";  
                }
                ss << endl;
            }

            return ss.str();
        }
};

#endif