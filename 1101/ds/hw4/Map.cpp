#include "Map.h"
#include <bits/stdc++.h>
using namespace std;

Map::Map(int N) : Random(), Timer(){
    srand(time(NULL));
    // Initialization
    size = N;
    range = N / 2;
    map = new double*[N];
    adj_list.resize(size);
    adj_matrix.resize(size);

    for(int i = 0; i < size; i++){
        map[i] = new double[size];
        adj_matrix[i].resize(size);
        for(int j = 0; j < size; j++){
            i == j ? adj_matrix[i][j] = 0 : adj_matrix[i][j] = range * range * size;
        }
    }

    int City_count = floor(size * 0.309460224);
    int Country_count = size - City_count;
    int Point_id = 0;

    // Generate points, and push into points vector
    for(int i = 0; i < City_count;){
        int x = rand_num(0, range);
        int y = rand_num(0, range);
        bool exist = false;
        for(Point j : points){
            if(j.get_x() == x && j.get_y() == y){
                exist = true;
                break;
            }
        }
        if(!exist){
            points.push_back(Point(x, y, Point_id, City));
            i++;
            Point_id++;
        }
    }
    for(int i = 0; i < Country_count;){
        int x = rand_num(0, range);
        int y = rand_num(0, range);
        bool exist = false;
        for(Point j : points){
            if(j.get_x() == x && j.get_y() == y){
                exist = true;
                break;
            }
        }
        if(!exist){
            points.push_back(Point(x, y, Point_id, Country));
            i++;
            Point_id++;
        }
    }

    // Fill in the map of distances
    total_distance = 0;
    total_count = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j <= i; j++){
            Route route(points[i], points[j]);
            map[i][j] = route.get_distance();
            map[j][i] = route.get_distance();
            if(route.get_distance() != 0){
                sorted_routes.push_back(route);
                total_distance += route.get_distance();
                total_count++;
            }
        }
    }
    sort(sorted_routes.begin(), sorted_routes.end(), [](const Route& a, const Route& b) -> bool { return a.get_distance() < b.get_distance();});

    build_MST(City);
    build_MST(Country);
    buid_random_route(Country, 0, range / 4, 0.5);
    buid_random_route(City, range / 2, range*range, 0.002);
    buid_random_cc_route(0, range / 4, 0.25);
}

void Map::build_MST(Type type){
    int disjoint_sets[size] = { 0 };
    int set_num = 1;
    int sortedroutes_size = sorted_routes.size();
    for(int i = 0; i < sortedroutes_size; i++){
        Point vertex1(sorted_routes[i].get_vertex1());
        Point vertex2(sorted_routes[i].get_vertex2());
        Route route(vertex1, vertex2);
        if(vertex1.get_type() != type || vertex2.get_type() != type) continue;
        if(disjoint_sets[vertex1.get_id()] != 0 && disjoint_sets[vertex2.get_id()] != 0){
            if(disjoint_sets[vertex1.get_id()] != disjoint_sets[vertex2.get_id()]){
                int change_target = disjoint_sets[vertex2.get_id()];
                int change_to = disjoint_sets[vertex1.get_id()];
                for(int j = 0; j < size; j++){
                    if(disjoint_sets[j] == change_target)
                        disjoint_sets[j] = change_to;
                }
                if(!is_in_routes(route)){
                    routes.push_back(route);
                    push_into_adj_list(route);
                }
            }
        }else if(disjoint_sets[vertex1.get_id()] == 0 && disjoint_sets[vertex2.get_id()] == 0){
            disjoint_sets[vertex1.get_id()] = set_num;
            disjoint_sets[vertex2.get_id()] = set_num;
            set_num++;
            if(!is_in_routes(route)){
                routes.push_back(route);
                push_into_adj_list(route);
            }
            
        }else if(disjoint_sets[vertex1.get_id()] == 0 && disjoint_sets[vertex2.get_id()] != 0){
            disjoint_sets[vertex1.get_id()] = disjoint_sets[vertex2.get_id()];
            if(!is_in_routes(route)){
                routes.push_back(route);
                push_into_adj_list(route);
            }
            
        }else if(disjoint_sets[vertex1.get_id()] != 0 && disjoint_sets[vertex2.get_id()] == 0){
            disjoint_sets[vertex2.get_id()] = disjoint_sets[vertex1.get_id()];
            if(!is_in_routes(route)){
                routes.push_back(route);
                push_into_adj_list(route);
            }
        }
    }

}

void Map::buid_random_route(Type type, int min_dist, int max_dist, double prob){
    for(int i = 0; i < size; i++){
        for(int j = 0; j <= i; j++){
            Route route(points[i], points[j]);
            if(map[i][j] > min_dist && map[i][j] < max_dist && ((double) rand() / (RAND_MAX)) < prob && points[i].get_type() == type && points[j].get_type() == type){
                if(!is_in_routes(route)){
                    routes.push_back(route);
                    push_into_adj_list(route);
                }
            }
        }
    }
}

void Map::buid_random_cc_route(int min_dist, int max_dist, double prob){
    for(int i = 0; i < size; i++){
        for(int j = 0; j <= i; j++){
            Route route(points[i], points[j]);
            if(map[i][j] > min_dist && map[i][j] < max_dist && ((double) rand() / (RAND_MAX)) < prob && points[i].get_type() != points[j].get_type()){
                if(!is_in_routes(route)){
                    routes.push_back(route);
                    push_into_adj_list(route);
                }
            }
        }
    }
}

void Map::convert_html(){
    json data;
    json datasets;

    // Points
    json Cities, Countries;
    json City_points, Country_points;
    for(int i = 0; i < size; i++){
        json point;
        point["x"] = points[i].get_x();
        point["y"] = points[i].get_y();
        if(points[i].get_type() == City)
            City_points.push_back(point);
        else
            Country_points.push_back(point);
    }
    Cities["label"] = "City";
    Cities["data"] = City_points;
    Cities["backgroundColor"] = "#f44336";

    Countries["label"] = "Country";
    Countries["data"] = Country_points;
    Countries["backgroundColor"] = "#B0C4DE";

    datasets.push_back(Cities);
    datasets.push_back(Countries);

    // Routes
    int route_size = routes.size();
    for(int i = 0; i < route_size; i++){
        json Route_data, route, vertex1, vertex2;
        vertex1["x"] = routes[i].get_vertex1().get_x();
        vertex1["y"] = routes[i].get_vertex1().get_y();
        vertex2["x"] = routes[i].get_vertex2().get_x();
        vertex2["y"] = routes[i].get_vertex2().get_y();
        route.push_back(vertex1);
        route.push_back(vertex2);

        Route_data["pointRadius"] = 0;
        Route_data["data"] = route;
        Route_data["borderColor"] = routes[i].get_color();
        Route_data["showLine"] = true;
        if(routes[i].get_color() == "#000000"){
            Route_data["order"] = 1;
        }else{
            Route_data["order"] = 2;
        }
        datasets.push_back(Route_data);
    }

    data["datasets"] = datasets;

    ofstream html("data.html");
    html << "<html> <head> <title>DsHw4</title> </head> <body> <div> <canvas id='myChart'></canvas> </div><script src='https://cdn.jsdelivr.net/npm/chart.js'></script> <script>const data=" << data << "; const config={type: 'scatter', data: data, aspectRatio: 1, options:{plugins:{legend:{display: false}, tooltip:{enabled: true}}}}; const myChart=new Chart( document.getElementById('myChart'), config ); </script> </body></html>";
    html.close();
}

double Map::dijkstra_heap(int point_id, int to_id){
    start();

    vector<int> predecessor;
    vector<double> distance;
    vector<bool> visited;

    // Initialize table;
    distance.resize(size);
    predecessor.resize(size);
    visited.resize(size, false);

    for (int i = 0; i < size; i++) {
        distance[i] = range * range * size;
        predecessor[i] = -1;
    }
    distance[point_id] = 0;

    Heap minHeap(size);
    minHeap.BuildMinHeap(distance);

    while (!minHeap.IsHeapEmpty()) {
        int u = minHeap.ExtractMin();
        for (list<pair<int, double>>::iterator itr = adj_list[u].begin(); itr != adj_list[u].end(); itr++) {
            int from = u;
            int to = (*itr).first;
            double _distance = (*itr).second;
            if (distance[to] > distance[from] + _distance) {
                distance[to] = distance[from] + _distance;
                predecessor[to] = from;
                minHeap.DecreaseKey(to, distance[to]);
            }
        }
    }
    stop();

    int vertex2_id = to_id;
    int vertex1_id = predecessor[vertex2_id];
    while(vertex1_id != -1){
        routes.push_back(Route(points[vertex1_id], points[vertex2_id], "#000000"));
        vertex2_id = vertex1_id;
        vertex1_id = predecessor[vertex2_id];
    }

    return get_time();
}

double Map::dijkstra_array(int point_id, int to_id){
    start();
    vector<double> dis = adj_matrix[point_id];
    vector<bool> visited;
    visited.resize(size, false);
    visited[point_id] = true;

    for(int i = 0; i < size; i++){
        double min = range * range * size;
        int node;
        for(int j = 0; j < size; j++){
            if(!visited[j] && dis[j] < min){
                min = dis[j];
                node = j;
            }
        }
        visited[node] = true;
        for(int j = 0; j < size; j++){
            if(adj_matrix[node][j] < range * range * size && dis[j] > dis[node] + adj_matrix[node][j]){
                dis[j] = dis[node] + adj_matrix[node][j];
            }
        }
    }

    stop();
    return get_time();
}

void Map::print_points(){
    int points_size = points.size();
    for(int i = 0; i < points_size; i++){
        cout << (i+1) <<  ". x: " << points[i].get_x() << ", y: " << points[i].get_y() << ", type: ";
        if(points[i].get_type() == City){
            cout << "City ";
        }else if(points[i].get_type() == Country){
            cout << "Country ";
        }
        cout << points[i].get_id();
        cout << endl;
    }
}

void Map::print_routes(){
    int routes_size = routes.size();
    for(int i = 0; i < routes_size; i++){
        cout << (i+1) << ". ";
        cout << "x: " << routes[i].get_vertex1().get_x() << " y: " << routes[i].get_vertex1().get_y();
        cout << " ";
        cout << "x: " << routes[i].get_vertex2().get_x() << " y: " << routes[i].get_vertex2().get_y();
        cout << " ";
        cout << "dis: " << routes[i].get_distance();
        cout << " ";
        cout << "color: " << routes[i].get_color();
        cout << endl;
    }
}

bool Map::is_in_routes(Route route){
    return find(routes.begin(), routes.end(), route) != routes.end();
}

void Map::push_into_adj_list(Route route){
    adj_list[route.get_vertex1().get_id()].push_back(make_pair(route.get_vertex2().get_id(), route.get_distance()));
    adj_list[route.get_vertex2().get_id()].push_back(make_pair(route.get_vertex1().get_id(), route.get_distance()));
    adj_matrix[route.get_vertex1().get_id()][route.get_vertex2().get_id()] = route.get_distance();
    adj_matrix[route.get_vertex2().get_id()][route.get_vertex1().get_id()] = route.get_distance();
}