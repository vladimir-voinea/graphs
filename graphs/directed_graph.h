//
//  directed_graph.h
//  graphs
//
//  Created by Vladimir Voinea on 27/03/16.
//  Copyright © 2016 Vladimir Voinea. All rights reserved.
//

#ifndef directed_graph_h
#define directed_graph_h

#include <unordered_map>
#include <vector>
#include <utility>

namespace graph {
    template<typename T>
    class directed_graph {
    public:
        typedef T node;
        typedef std::vector<node> destination;
        typedef std::unordered_map<node, destination> _adj_list;
    private:
        _adj_list adj;
    public:
        directed_graph() = default;
        
        inline auto add(const T& from, const T& to) {
            adj[from].push_back(to);
        }
        
        inline auto add_bidirectional(const T& a, const T& b) {
            add(a, b);
            add(b, a);
        }
        
        auto edge_exists(const T& from, const T& to) {
            auto search = adj.find(from);
            if(search != adj.end()) {
                auto from_node = std::find(search.second.begin(), search.second.end(), to);
                return from_node != search.second.end();
            }
            return false;
        }
        
        const auto& adj_list() const {
            return adj;
        }
        
    };
}


#endif /* directed_graph_h */
