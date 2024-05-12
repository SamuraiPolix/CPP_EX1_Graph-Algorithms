# ID:      53036281
# Email:   sam.lazareanu@gmail.com
# @author  Samuel Lazareanu

import numpy as np
import matplotlib.pyplot as plt
import networkx as nx

def visualize_graph(adj_matrix, directed=False):
    # Convert the adjacency matrix to a numpy array
    adj_array = np.array(adj_matrix)

    # Create a directed or undirected graph from the adjacency matrix
    if directed:
        G = nx.DiGraph(adj_array)
    else:
        G = nx.Graph(adj_array)

    # Draw the graph with arrows if directed
    pos = nx.spring_layout(G)  # Position nodes using the Fruchterman-Reingold force-directed algorithm
    if directed:
        nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=800, edge_color='k', linewidths=1, font_size=15, arrows=True)
    else:
        nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=800, edge_color='k', linewidths=1, font_size=15)

    # Add edge weights to the graph
    labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

    # Show the plot
    plt.title("Graph Visualization")
    plt.show()


# Example adjacency matrix
# adj_matrix = [
#     [0, 1, 1, 0, 0],
#     [1, 0, 1, 0, 0],
#     [1, 1, 0, 1, 0],
#     [0, 0, 1, 0, 0],
#     [0, 0, 0, 0, 0]
# ]


adj_matrix = [ [0, 1, 2, 0, 0], [1, 0, 3, 0, 0], [2, 3, 0, 4, 0], [0, 0, 4, 0, 5], [0, 0, 0, 5, 0] ]

# print(is_bipartite(adj_matrix))
# visualize_graph(adj_matrix, False)

def is_bipartite(adj_matrix):
    n = len(adj_matrix)
    colors = [-1] * n  # -1 means no color, 0 and 1 are the two colors

    for i in range(n):
        if colors[i] == -1:  # if not colored yet
            queue = [i]
            colors[i] = 1  # color the first node
            while queue:
                node = queue.pop(0)
                for ind, val in enumerate(adj_matrix[node]):
                    if val != 0:  # if an edge exists
                        if colors[ind] == -1:  # if not colored yet
                            colors[ind] = 1 - colors[node]  # color with the other color
                            queue.append(ind)
                        elif colors[ind] == colors[node]:  # if colored with the same color
                            return False
    return True

print(is_bipartite(adj_matrix))

visualize_graph(adj_matrix, True)
