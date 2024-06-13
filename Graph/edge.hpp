//-------------------------------------------------------------------
//--  ->Algorithm: Edge
//--       ->Component used on a Weighted Graph
//--
//--  ->Language:  C++          (Mingw 8.1)
//--  ->Date:      12/06/2024
//--  ->Reference: Adapted to C++ from Sedgewick's Algorithms 4th Edition
//
//--  ->Applications:
//--    -> MINIMUM SPANNING TREES
//--    -> ...
//--
//--    ->Notes: Edge that uses a String as value;  
//
//--    ->Visual Representation:
//
//--                     weight
//--        [V]-----------------------[W]
//--
//-------------------------------------------------------------------

#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Edge{
    private:
        string v;               //Either (One vertex)
        string w;               //Other  (Other vertex)
        double weightEdge;      //Weight that will be used on MST
    public:
        Edge(string dv, string dw, double dweight){
            v = dv; w = dw;
            weightEdge = dweight;
        }

        string either(){ return this->v;      }     //Getter for V

        string other(string vertex){         //Getter for other Vertice
             string a = vertex; 
             return(v == a)?w:v;      
        }

        double weight(){ return weightEdge; }       //Getter for Weight

        int compareTo(Edge that){                   //Compare the Weight between two Edges, being "Is this edge heavier then than other? Is it lighter?"
            if(this->weight() < that.weight()) return -1;
            else if(this->weight() > that.weight()) return 1;
            else return 0;
        }

        friend ostream& operator<<(ostream&os, const Edge& obj){        //C++ Operator Overload to make easier to "print" the Edge
            return os << obj.v << " - " << obj.w << " (" << setprecision(3) << obj.weightEdge << ")";
        }
};

#endif