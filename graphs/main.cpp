//
//  main.cpp
//  graphs
//
//  Created by Vladimir Voinea on 27/03/16.
//  Copyright © 2016 Vladimir Voinea. All rights reserved.
//

#include <string>
#include <iostream>
#include <memory>
#include "directed_graph.h"
#include "graph_util.h"


int main() {
    using namespace graph;
    typedef std::shared_ptr<std::string> str;
    
    directed_graph<str> g;
    
    auto a = std::make_shared<std::string>("a");
    auto b = std::make_shared<std::string>("b");
    auto d = std::make_shared<std::string>("d");
    
    g.add_bidirectional(a, b);
    g.add(d,a);
    
    std::cout << std::boolalpha << "a to b: " << edge_exists(g, a, b) << "\nb to a: " << edge_exists(g, b, a) <<
    "\nd to a: " << edge_exists(g, d, a) << std::endl;
    
    return 0;
}