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
        y_axis_graph.append(graph_num * 1000)
        y_axis_force.append(force_num * 1000)
        
    x_axis = [i + 2 for i in range(len(y_axis_graph))]
    
    ax.plot(x_axis, y_axis_graph, label="\"Graphen\" Ansatz")
    ax.plot(x_axis, y_axis_force, label="\"Naiver\" Ansatz")
    ax.set_xlabel("Crib/Geheimtext Länge")
    ax.set_ylabel("Laufzeit (Sekunden)")
    ax.set_title("Laufzeit-Graph Menü-Algorithmus(1000 * 1000 Durchgänge pro Länge)")
    ax.legend()
    ax.grid()
    
    plt.savefig("Runtime Graph Graph vs Force.svg", format="svg")
    plt.savefig("Runtime Graph Graph vs Force.png", format="png")