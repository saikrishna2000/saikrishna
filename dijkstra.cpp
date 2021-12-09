#include<bits/stdc++.h>
using namespace std;

void dijkstra(int **edge,int no_of_vertex,int no_of_edge,int source_vertex){
   // array to store distance from each vertex
   int distance[no_of_vertex+1]={0};

   // array to check boolean value whether  a particular edge has been pushed to the set
   bool check_vertex_is_present[no_of_vertex+1]={0};


   // loop for current vertex set
   for(int i=1;i<=no_of_vertex;i++){
      distance[i]=INT_MAX;
      check_vertex_is_present[i]=0;
   }  

   // Source Distance
   distance[source_vertex]=0;
 

   // count to maintain how many edges have been included
   int count_of_vertex =0;
   

   // loop to change distance for each vertx 
   while(count_of_vertex<no_of_vertex-1){
      int index = -1;
      int mini=INT_MAX;
      
      // find the node which has the closet distance till now
      for(int i=1;i<=no_of_vertex;i++){
         if(check_vertex_is_present[i])
            continue;
         if(distance[i]<mini){
            mini=distance[i];
            index = i;
         }
      }

      // mark it as included in our set
      check_vertex_is_present[index]=1;

      // run loop to make the distance minimum if it is possible
      for(int i=1;i<=no_of_vertex;i++){

         // if visited ignore it would be minimum already
         if(check_vertex_is_present[i])
            continue;

         // if there is no edge
         if(edge[index][i]==0)
            continue;

         // if index distance is already max
         if(distance[index]==INT_MAX)
            continue;

         if(distance[index] + edge[index][i]<distance[i]){
            distance[i] = distance[index]+edge[index][i];
         }
      }

      count_of_vertex++;
   }

   // print the array
   cout<<"Final Distance from "<<source_vertex<<endl;
   for(int i=1;i<= no_of_vertex;i++){
      cout<<"from "<<source_vertex<<" to  "<<i<<"  and distance is "<<distance[i]<<endl;
   }
}


int main(){

   // enter no of vertex
   int n;
   cout<<"enter no of vertex"<<endl;
   cin>>n;
   
   // take input of edges
   int **edges;
   edges = new int*[n+1];
   
   for(int i=0;i<=n;i++){
      edges[i] = new int[n+1];
      for(int j=0;j<=n;j++){
         edges[i][j]=0;
      }
   }


   // enter no of edges
   cout<<"enter no of edges"<<endl; 
   int edge;
   cin>>edge;
   cout<<"Enter edges in space seperated way (1 2 3) \n where 1 and 2 is edge and 3 is weight.\n Also start edge from 1 "<<endl;
   for(int i=0;i<edge;i++){
      int a,b,c;
      cin>>a>>b>>c;
      edges[a][b]=c;
      edges[b][a]=c;
   }

   // considering source to be 1
   dijkstra(edges,n,edge,1);
   return 0;
}