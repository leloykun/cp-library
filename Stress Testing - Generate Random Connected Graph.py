import itertools
from . import keep_generated, make_tree, make_graph
def make_connected_graph(n, m, multigraph=False):
    assert m >= n - 1
    edges = set()
    return itertools.chain(
        keep_generated(make_tree(n), edges, unordered_ground_set=True),
        make_graph(n, m - (n - 1), multigraph, edges))
