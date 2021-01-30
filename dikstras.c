void shortestPath(int source){           //any vertex can act as a source node
    int intNode;
    for(int i=0; i<MAX_NODES; ++i){
            visited[i]=false;              //initially we dont know the nearest distance to each node therefore we initialize it to false
            distance[i]=cost[source][i];   //we take up one row corresponding each source.source remain constant i keeps on changing this is the current main distance from the source
    }
    visited[source]=true;   //distance from source to itself is discovered and is true
    for(int nodes=0;nodes< MAX_NODES;++nodes){
        intNode=_choose_nearest_();       //returns which vertex is nearer to the source.
        visited[intNode]=true;  //once we get the shortest vertex the intermediate node that is visited will be true.
        for(int dest=0;dest<MAX_NODES;++dest){      //the inner for loop tries to find new paths from intermediate node to the other destinations
            if(!visited[dest]){   //if minimum distance to the destination node is not obtained then enter the loop
                if(distance[intNode]+cost[intNode][dest]<distance[dest]){      //distance[intNode] represents distance from source to intermediate node &  cost[intNode][dest]  distance from intermediate node to destination.If the LHS term is less than current minimum distance(RHS) then we have to update distance
                    distance[dest]=distance[intNode]+cost[intNode][dest];
                }
            }
        }
    }


    static int _choose_nearest_(void){
    int minWeight=INT_MAX;
    int nearestVertex=-1; //initializing vertex with -1
    for(int i=0;i<MAX_NODES;++i){
        if(distance[i]<minWeight  &&  !visited[i]){   //if distance to vertex i is less tham min weight which infinite (INT_MAX)
            minWeight=distance[i];   //note down minimum distance and nearest vertex
            nearestVertex=i;
        }
    }
    return nearestVertex;//acts like a intermediate node
    }
