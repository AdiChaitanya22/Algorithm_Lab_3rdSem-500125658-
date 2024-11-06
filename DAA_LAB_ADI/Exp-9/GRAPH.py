import matplotlib.pyplot as plt

# Sample data (replace with actual timing data from your implementations)
problem_sizes = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
backtracking_times = [0.1, 0.4, 1.5, 5.6, 21.3, 60.2, 150.3, 300.7, 600.9, 1200.5]  # Hypothetical times in ms
branch_bound_times = [0.1, 0.3, 1.0, 3.5, 10.0, 25.1, 60.4, 130.6, 250.1, 490.2]
dp_times = [0.1, 0.2, 0.6, 1.0, 2.5, 5.1, 10.3, 19.5, 36.2, 65.8]

# Plotting Execution Time Comparison
plt.figure(figsize=(10, 5))
plt.plot(problem_sizes, backtracking_times, label='Backtracking', marker='o')
plt.plot(problem_sizes, branch_bound_times, label='Branch & Bound', marker='s')
plt.plot(problem_sizes, dp_times, label='Dynamic Programming', marker='^')

plt.xlabel("Number of Items")
plt.ylabel("Execution Time (ms)")
plt.title("0/1 Knapsack Execution Time Comparison")
plt.legend()
plt.grid()
plt.show()
