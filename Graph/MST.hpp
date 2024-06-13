//-------------------------------------------------------------------
//--  ->Algorithm: Minimum Spanning Tree
//--       ->Utilizes Graphs and Edges
//--
//--  ->Language:  C++          (Mingw 8.1)
//--  ->Date:      12/06/2024
//--  ->Reference: Adapted to C++ from Sedgewick's Algorithms 4th Edition
//
//--  ->Applications:
//--    -> ...
//--
//--    ->Notes: ...
//
//-------------------------------------------------------------------

#ifndef __MST_HPP__
#define __MST_HPP__

#include "EWGraph.hpp"

//Utilizes Edge Weight Graph

class MST{
    private:
        EWGraph g = EWGraph(0); //Only for constructor
    public:
        MST(EWGraph gExt){
            g = gExt;
        }

        vector<Edge> edges(){
            return g.all_Edges();    
        }

        double weight(){
            double totalWeight = 0;
            for(auto & element : edges()){
                totalWeight += element.weight();
            }
            return (totalWeight/2);
        }
};


#endif