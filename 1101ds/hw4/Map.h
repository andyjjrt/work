#include <vector>
#include <string>
#include "nlohmann/json.hpp"
#include "Heap.h"
#include "Utils.h"
#include <bits/stdc++.h>

using json = nlohmann::json;

enum Type {City, Country};
class Point {
public:
    Point(int _x, int _y, int _id, Type _type){
        x = _x;
        y = _y;
        id = _id;
        type = _type;
    }
    Point(const Point& point){
        x = point.x;
        y = point.y;
        id = point.id;
        type = point.type;
    }
    inline int get_x() const { return x; }
    inline int get_y() const { return y; }
    inline int get_id() const { return id; }
    inline Type get_type() const { return type; }
private:
    int x;
    int y;
    int id;
    Type type;
};

class Route {
public:
    Route(Point _vertex1, Point _vertex2) : vertex1(_vertex1), vertex2(_vertex2) {
        distance = sqrt(pow(double(vertex1.get_x() - vertex2.get_x()), 2.0) + pow(double(vertex1.get_y() - vertex2.get_y()), 2.0));
        if(vertex1.get_type() == City && vertex2.get_type() == City){
            color = "#f44336";
        }else if(vertex1.get_type() == Country && vertex2.get_type() == Country){
            color = "#B0C4DE";
        }else{
            color = "#ff99bb";
        }
    }
    Route(Point _vertex1, Point _vertex2, std::string _color) : vertex1(_vertex1), vertex2(_vertex2) {
        distance = sqrt(pow(double(vertex1.get_x() - vertex2.get_x()), 2.0) + pow(double(vertex1.get_y() - vertex2.get_y()), 2.0));
        color = _color;
    }
    Route(const Route& route) : vertex1(route.vertex1), vertex2(route.vertex2) {
        distance = route.distance;
        color = route.color;
    }
    bool operator==(const Route rhs) const {
        return (rhs.get_vertex1().get_id() == vertex1.get_id() && rhs.get_vertex2().get_id() == vertex2.get_id())
                ||
               (rhs.get_vertex1().get_id() == vertex2.get_id() && rhs.get_vertex2().get_id() == vertex1.get_id());
    }
    inline Point get_vertex1() const { return vertex1; }
    inline Point get_vertex2() const { return vertex2; }
    inline double get_distance() const {return distance; }
    inline std::string get_color() const {return color; }
private:
    Point vertex1;
    Point vertex2;
    double distance;
    std::string color;
};

class Map : public Random, public Timer{
public:
    Map(int size);
    ~Map(){};
    void build_MST(Type type);
    void buid_random_route(Type type, int min_dist, int max_dist, double prob);
    void buid_random_cc_route(int min_dist, int max_dist, double prob);
    void convert_html();
    double dijkstra_heap(int point_id = 0, int to = 0);
    double dijkstra_array(int point_id = 0, int to = 0);
    double get_avg__distance(){ return total_distance / total_count; }

    // for DEBUG
    void print_points();
    void print_routes();
private:
    double** map;
    std::vector<Point> points;
    std::vector<Route> sorted_routes;
    std::vector<Route> routes;
    std::vector<std::list<std::pair<int, double>>> adj_list;
    std::vector<std::vector<double>> adj_matrix;
    int size;
    int range;
    double total_distance;
    int total_count;
    bool is_in_routes(Route route);
    void push_into_adj_list(Route route);
};