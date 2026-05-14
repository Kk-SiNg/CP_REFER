#include <iostream>
#include <vector>
#include <array>

using namespace std;

//logic:- 1. if we run dfs from a node then all of it's connected compoents will become visited
//        2. so simply go through all nodes and if that node is unvisited then simply call dfs in that node and number of dfs calls is
//           the number of connected components(CC's).

const int N = 10e3+5;
bool visited_array[N];
vector <vector<int>> list_of_all_connected_components;  // to store all CC
vector<int> temp_comoponet_list;    // to temporarly store a connected component


//feel that orignal DFS struct is untouched.
void dfs(array <vector<int>, N> graph2, int vertex){

    visited_array[vertex] = 1;
    temp_comoponet_list.push_back(vertex);

    for(int child : graph2[vertex]){

        if(visited_array[child]) continue;
        dfs(graph2, child);
    }
}


int main(){

    int number_of_nodes, number_of_edges;
    cin >> number_of_nodes >> number_of_edges;
    int x, y;
    
    array <vector<int>, N> graph2;
    for(int i = 0; i < number_of_edges; i++){
        cin >> x >> y;
        graph2[y].push_back(x);
        graph2[x].push_back(y);
    }

    int count = 0;

    for(int i = 1; i <= number_of_nodes; i++){
        
        if(visited_array[i] == true) continue;    //this if() ensures that all connected components are visited exactly once

        temp_comoponet_list.clear();
        dfs(graph2, i);
        list_of_all_connected_components.push_back(temp_comoponet_list);
        count ++;
    }

    cout << count << "\n";
    for(int i = 0; i < count; i++){
        for(int j: list_of_all_connected_components[i]){
            cout << j <<" ";
        }
        cout << endl;
    }
    return 0;
}