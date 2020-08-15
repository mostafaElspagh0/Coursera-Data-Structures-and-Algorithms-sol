# Uses python3
import sys

# Return the trie built from patterns
# in the form of a dictionary of dictionaries,
# e.g. {0:{'A':1,'T':2},1:{'C':3}}
# where the key of the external dictionary is
# the node ID (integer), and the internal dictionary
# contains all the trie edges outgoing from the corresponding
# node, and the keys are the letters on those edges, and the
# values are the node IDs to which these edges lead.


def build_trie(patterns):
    tree = dict()
    currentNodeIndex = 0
    for pattern in patterns:
        currentNode = 0
        for i in range(len(pattern)):
            currentSymbol = pattern[i]
            if currentNode not in tree :
                tree[currentNode] = {}
            if currentSymbol in tree[currentNode]:
                currentNode = tree[currentNode][currentSymbol]
            else:
                currentNodeIndex += 1
                tree[currentNode][currentSymbol] = currentNodeIndex
                currentNode = currentNodeIndex
    return tree


if __name__ == '__main__':
    patterns = [input() for i in range(int(input()))]
    tree = build_trie(patterns)
    for node in tree:
        for c in tree[node]:
            print("{}->{}:{}".format(node, tree[node][c], c))
