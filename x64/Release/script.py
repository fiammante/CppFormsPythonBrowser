

def run():
    import plotly.graph_objects as go
    import pandas as pd
    import os
    cwd = os.getcwd()
    # Read data from a csv
    z_data = pd.read_csv('https://raw.githubusercontent.com/plotly/datasets/master/api_docs/mt_bruno_elevation.csv')
    fig = go.Figure(data=[go.Surface(z=z_data.values)])
    fig.update_layout(title='Mt Bruno Elevation', autosize=False,width=500, height=500,margin=dict(l=65, r=50, b=65, t=90))
    graph_name='example_graph.html'
    fig.write_html(graph_name)
    # Reading data from file2
    with open(graph_name, encoding="utf-8") as fp:
        graph = fp.read()
    data = '<meta http-equiv="X-UA-Compatible" content="IE=Edge" />\n'
    data += graph 
    with open (graph_name, 'w',encoding="utf-8") as fp:
        fp.write(data)
    path=os.path.join(cwd,graph_name)
    return "file:///"+path