import matplotlib.pyplot as plt

# Energy levels in eV
n_values = [1, 2, 3, 4]
energies = [7.49, 29.97, 67.4, 119.8]

# Create the plot
plt.figure(figsize=(4, 6))
for n, E in zip(n_values, energies):
    plt.hlines(E, 0.9, 1.1, colors='blue', linewidth=2)
    plt.text(1.12, E, f'n = {n}\n{E:.2f} eV', va='center', fontsize=10)

# Formatting the plot
plt.xlim(0.8, 1.5)
plt.ylim(0, 130)
plt.xticks([])
plt.ylabel('Energy (eV)')
plt.title('Energy Levels of an Electron\nin a 1D Box (L = 0.562 nm)')
plt.grid(True, axis='y', linestyle='--', alpha=0.6)

plt.tight_layout()
plt.show()
