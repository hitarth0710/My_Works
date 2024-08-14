import matplotlib.pyplot as plt

# Step 2: Define the data
x = [1, 2, 3, 4, 5]
y = [2, 3, 5, 7, 11]

# Step 3: Create the plot
plt.plot(x, y, marker='o')

# Step 4: Add labels and title
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Simple Line Plot')

# Step 5: Display the plot
plt.show()