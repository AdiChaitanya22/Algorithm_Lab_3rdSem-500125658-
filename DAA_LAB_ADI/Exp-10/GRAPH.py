import matplotlib.pyplot as plt
import numpy as np

# Execution times in seconds.
naive_times = [0.000003, 0.000003, 0.000003, 0.000003, 0.000004]
kmp_times = [0.000001, 0.000002, 0.000001, 0.000001, 0.000001]
rabin_karp_times = [0.000001, 0.000001, 0.000002, 0.000001, 0.000002]
test_cases = ["Test Case 1", "Test Case 2", "Test Case 3", "Test Case 4", "Test Case 5"]

bar_width = 0.2
x = np.arange(len(test_cases))

# Creating the bar graph
plt.bar(x - bar_width, naive_times, width=bar_width, label='Naive Search', color='lightblue')
plt.bar(x, kmp_times, width=bar_width, label='KMP Search', color='orange')
plt.bar(x + bar_width, rabin_karp_times, width=bar_width, label='Rabin-Karp Search', color='lightgreen')

plt.xlabel('Test Cases')
plt.ylabel('Time (seconds)')
plt.title('Comparison of String Matching Algorithms')
plt.xticks(x, test_cases)
plt.legend()

# To Display the graph
plt.tight_layout()
plt.show()