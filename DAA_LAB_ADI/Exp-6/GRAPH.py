import matplotlib.pyplot as plt

# Data for Graph Size and Times
graph_size = [100, 200, 500]  # Example graph sizes
dijkstra_time = [0.00009, 0.00018, 0.00027]
bellman_ford_time = [0.00009, 0.00021, 0.00038]

# Create the plot
plt.figure(figsize=(10, 6))

# Plot the Dijkstra Time vs Graph Size
plt.plot(graph_size, dijkstra_time, label='Dijkstra Time', marker='o', color='blue', linestyle='-', linewidth=2)

# Plot the Bellman-Ford Time vs Graph Size
plt.plot(graph_size, bellman_ford_time, label='Bellman-Ford Time', marker='o', color='red', linestyle='-', linewidth=2)

# Add labels and title
plt.xlabel('Graph Size (Number of Nodes)')
plt.ylabel('Time (seconds)')
plt.title('Performance Comparison: Dijkstra vs Bellman-Ford Algorithm')

# Set logarithmic scale for y-axis for better visualization
plt.yscale('log')

# Add a legend
plt.legend()

# Add grid for better readability
plt.grid(True)

# Display the plot
plt.show()