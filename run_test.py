import subprocess
import re
from time import time
import sys

sizes = [10, 20, 50, 100, 200, 500, 1000]

# Print the table header
print("| N             | Elapsed Time  | Memory Usage   |")
print("|---------------|---------------|----------------|")

for size in sizes:
    time_total = 0
    generate_map_output = subprocess.check_output(["python", "generate_map.py", str(size)], universal_newlines=True)
    check_output_params = {
        'input': generate_map_output
    }

    for _ in range(5):
        start_time = time()
        dijkstras_output = subprocess.check_output(["src/dijkstras"], input=generate_map_output, universal_newlines=True)
        time_total += (time() - start_time)

    valgrind_output = subprocess.check_output(["valgrind", "--leak-check=full", "src/dijkstras"], input=generate_map_output, stderr=subprocess.STDOUT, universal_newlines=True)
    bytes_allocated_match = re.search(r"([\d,]+) bytes allocated", valgrind_output)
    bytes_allocated = int(bytes_allocated_match.group(1).replace(',', ''))

    time_avg = f"{time_total / 5:.4f}s"

    # Print the table row with the results
    print(f"| {size:<13} | {time_avg:<13} | {bytes_allocated:<14} |")

# Print the table footer
print("|---------------|---------------|----------------|")
