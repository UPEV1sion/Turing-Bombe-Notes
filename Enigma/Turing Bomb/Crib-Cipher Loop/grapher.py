import matplotlib.pyplot as plt

with open("data.txt") as file:
    lines = file.read().splitlines()
    fig, ax = plt.subplots()
    fig.set_dpi(250)
    
    y_axis_graph = []
    y_axis_force = []
    
    for line in lines:
        split_line = line.split(", ")
        graph_num = float(split_line[0])
        force_num = float(split_line[1])
        y_axis_graph.append(graph_num)
        y_axis_force.append(force_num)
        
    x_axis = [i + 2 for i in range(len(y_axis_graph))]
    
    ax.plot(x_axis, y_axis_graph, label="Graph approach")
    ax.plot(x_axis, y_axis_force, label="\"Force\" approach")
    ax.set_xlabel("Crib/Ciphertext length")
    ax.set_ylabel("Runtime (seconds)")
    ax.set_title("Runtime Graph vs Force (1000 * 1000 passes per length)")
    ax.legend()
    ax.grid()
    
    plt.savefig("Runtime Graph Graph vs Force.svg", format="svg")
    plt.savefig("Runtime Graph Graph vs Force.png", format="png")