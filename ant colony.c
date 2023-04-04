import random
import numpy as np

def create_graph(num_nodes):
    graph = np.zeros((num_nodes, num_nodes))
    for i in range(num_nodes):
        for j in range(num_nodes):
            if i != j and graph[i][j] == 0:
                graph[i][j] = graph[j][i] = random.randint(1, 10)
    return graph

def ant_colony_optimization(graph, start_node, end_node, num_ants=10, alpha=1, beta=2, rho=0.5, Q=1):
    num_nodes = len(graph)
    pheromone = np.ones((num_nodes, num_nodes))
    distances = graph
    shortest_distance = np.inf
    shortest_path = None
    for i in range(100):
        ant_distances = []
        ant_paths = []
        for ant in range(num_ants):
            current_node = start_node
            path = [current_node]
            visited = [current_node]
            distance = 0
            while current_node != end_node:
                unvisited = list(set(range(num_nodes)) - set(visited))
                if not unvisited:
                    break
                probabilities = [((pheromone[current_node][v] * alpha) * ((1 / distances[current_node][v]) * beta)) for v in unvisited]
                probabilities = probabilities / np.sum(probabilities)
                next_node = unvisited[np.argmax(probabilities)]
                path.append(next_node)
                visited.append(next_node)
                distance += distances[current_node][next_node]
                current_node = next_node
            ant_distances.append(distance)
            ant_paths.append(path)
        if min(ant_distances) < shortest_distance:
            shortest_distance = min(ant_distances)
            shortest_path = ant_paths[np.argmin(ant_distances)]
        delta_pheromone = np.zeros((num_nodes, num_nodes))
        for ant, distance in zip(ant_paths, ant_distances):
            for i in range(len(ant) - 1):
                delta_pheromone[ant[i]][ant[i+1]] += Q / distance
        pheromone = (1 - rho) * pheromone + delta_pheromone
    return shortest_path, shortest_distance


num_nodes = 5
graph = create_graph(num_nodes)
start_node = 0
end_node = 4


shortest_path, shortest_distance = ant_colony_optimization(graph, start_node, end_node)


print("Shortest Path:", shortest_path)
print("Shortest Distance:", shortest_distance)