#include "Map.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    /*
    CSV avg_csv("avg_csv.csv"), avg_dijkestra("avg_dijkestra.csv");
    for(int i = 2; i <= 500; i++){
        avg_csv.insert(to_string(i));
    }
    avg_csv.newline();
    for(int i = 2; i <= 500; i++){
        double avg = 0;
        for(int j = 0; j < 10; j++){
            Map map(i);
            avg += map.get_avg__distance();
        }
        avg_csv.insert(to_string(avg / 10.0));
    }

    double avg_dijkstra_heap = 0, avg_dijkstra_array = 0;
    for(int i = 0; i < 10; i++){
        Map map(100);
        int from = 0, to = 0;
        while(from == to){
            from = rand() % 100;
            to = rand() % 100;
        }
        avg_dijkstra_array += map.dijkstra_array(from, to);
        avg_dijkstra_heap += map.dijkstra_heap(from, to);
    }
    avg_dijkestra.insert(to_string(avg_dijkstra_array / 10.0));
    avg_dijkestra.insert(to_string(avg_dijkstra_heap / 10.0));
    */
    Map map(100);
    map.convert_html();
}