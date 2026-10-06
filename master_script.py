import subprocess
import matplotlib.pyplot as plt
result = subprocess.run(['./calculator'], capture_output=True, text=True)
output_data = result.stdout.strip().split()
cx = float(output_data[0])
cy = float(output_data[1])
cz = float(output_data[2])
x_list, y_list = [], []
with open("atoms.txt", "r") as f:
	lines = f.readlines()
for line in lines[1:]:
	parts = line.strip().split()
	x_list.append(float(parts[1]))
	y_list.append(float(parts[2]))
plt.scatter(x_list, y_list, color="blue", label="Atom")
plt.scatter([cx], [cy], color="red", marker="*", s=150, label="center of mass")
plt.xlabel("X Coordinate")
plt.ylabel("Y Coordinate")
plt.title("C++ & python")
plt.legend()
plt.grid(True)
plt.savefig("mixed_plot.png")
print("混合编程完成,图片保存为mixed_plot.png")
