#include "graph.hpp"
#include "MST.hpp"

int main(){
    EWGraph ewg(10);
    ewg.addEdge("a", "b", 2.5);
    ewg.addEdge("d", "c", 0.25); 
    cout << "Algo saira 1: " << ewg.toString() << endl;
    MST mst(ewg);
    cout << "Algo saira 1.5: " << endl;   
    cout << "Algo saira 2: " << endl << mst.weight();

    return 0;
}