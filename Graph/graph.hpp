//-------------------------------------------------------------------
//--  ->Algorithm: Graph
//--       ->Undirected Graph Class
//--
//--  ->Language:  C++          (Mingw 8.1)
//--  ->Date:      12/06/2024
//--  ->Reference: Adapted to C++ from Sedgewick's Algorithms 4th Edition
//
//--  ->Applications:
//--    -> BFS
//--    -> DFS
//--    -> ...
//--
//--    ->Notes: This is a undirected graph that uses String. It's possible to create one using Ints or anything you may wish (I might be wrong).
//--
//-------------------------------------------------------------------

#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

class Graph{

    private:
        map<string, vector<string>> graph;          //A Hash Dictionary of Strings that are gonna be used to store our graph
        size_t v, e;                                //Long Long Unsigned Int for Vertices and Edges

        void addToList(string v, string w){         //Private method to add to our graph
            vector<string>& list = graph[v];        //Gets the key from "V" (which means, return to us a Vector containing all edges of V)
            list.push_back(w);                      //Puts W as a edge to this vector
        }

    public:
        Graph(size_t v){            //create a V-vertex graph with no edges
            this->e = 0;            // No Edges
            this->v = v;            // Receives amount of vertices
        }

        Graph(string filename){     // Reads a file and generates a graph from it

            //All Variables that will be used to read the file
            ifstream fp;
            string x;
            string y;
            string line;
            int ignore = 0;

            fp.open(filename, ios::in);
            if(!fp.is_open()){ cerr << "> Error: Couldn't open file" << endl; return; }
            
            //Receives from the first line the V
            fp >> v;

            //Receives from the second line the E
            fp >> e;

            //Then generates the graph in the input "X Y\n" "X Y\n" ... 
		    while(getline(fp, line)) {
			    stringstream ss(line);          //StringStream that receives the line
                ignore++;                       //Ignores the first 2 Lines cause they will be empty (fp >> v and fp >> w)
                if(ignore < 2) continue;

			    getline(ss, x, ' ');            //Insert on X everything before ' '
			    getline(ss, y, ' ');            //Insert on Y the rest of the string until ' '
  	    	    addEdge(x, y);                  // Add edge X , Y
    	    }

            fp.close();                         // Closes the file
        }

        void addEdge(string v, string w){
            addToList(v, w);                //Add to our graph (v , w)
            addToList(w, v);                //Add to our graph (w , v)
            e++;                            //Creates a Edge between two Points
        }

        size_t V(){                        //Return number of Vertices on the Graph
            return v;
        }

        size_t E(){                        //Return number of Edges on the Graph
            return e;
        }

        vector<string> adj(string v){     //Returns a Vector<Int> of vertices adjacents to V
            return graph[v];
        }

        vector<string> getVerts(){                  //Not in the book. Created because of the map
            vector<string> keys;                    // First we create a vector of strings that's going to get all of ours Verts
            for(auto const & element : graph){      // Iterator that runs through all of our graph
                keys.push_back(element.first);      // Insert on our vector the elements
            }
            return keys;
        }

        string toString(){                //String Representation
            stringstream ss;
            ss << V() << " vertices, " << E() << " edges\n";

            for(auto const & vAux :getVerts()){             //Run through all Vertices
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