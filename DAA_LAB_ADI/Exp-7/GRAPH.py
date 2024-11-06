import matplotlib.pyplot as plt

# Data for Dataset Sizes and Times
dataset_size = [5, 10, 20, 30, 50]  # Example dataset sizes
greedy_time = [0.000002, 0.000002, 0.000003, 0.000006, 0.000015]
dynamic_time = [0.000005, 0.000008, 0.000020, 0.000026, 0.000041]

# Create the plot
plt.figure(figsize=(10, 6))

# Plot the Greedy Time vs Dataset Size
plt.plot(dataset_size, greedy_time, label='Greedy Time', marker='o', color='blue', linestyle='-', linewidth=2)

# Plot the Dynamic Programming Time vs Dataset Size
plt.plot(dataset_size, dynamic_time, label='Dynamic Programming Time', marker='o', color='red', linestyle='-', linewidth=2)

# Add labels and title
plt.xlabel('Dataset Size (Number of Items)')
plt.ylabel('Time (seconds)')
plt.title('Performance Comparison: Greedy vs Dynamic Programming Algorithm')

# Set logarithmic scale for y-axis for better visualization
plt.yscale('log')

# Add a legend
plt.legend()

# Add grid for better readability
plt.grid(True)

# Display the plot
plt.show()