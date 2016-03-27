//
//  graph_util.h
//  graphs
//
//  Created by Vladimir Voinea on 27/03/16.
//  Copyright © 2016 Vladimir Voinea. All rights reserved.
//

#ifndef graph_util_h
#define graph_util_h

#include <algorithm>

namespace graph {
    template<typename G, typename T>
    const std::vector<T>* starts_from(G& graph, const T& from) {
        auto& adj = graph.adj_list();
        auto dest_it = adj.find(from);
        return dest_it != adj.end() ? &dest_it->second : nullptr;
    }
    
    template<typename G, typename T>
    auto edge_exists(const G& graph, const T& from, const T& to) {
        auto d = starts_from(graph, from);
        if(d) {
            return std::find(d->begin(), d->end(), to) != d->end() ? true : false;
        }
        else return false;
    }
}

#endif /* graph_util_h */
