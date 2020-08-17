# Uses python3

class Node():
    def __init__(self, symbol: str = ""):
        self.symbol = symbol
        self.endOfPattren = False
        self.chidren = {}

    def hasChildWithSymbol(self, symbol: str):
        return symbol in self.chidren

    def addChid(self, node):
        if isinstance(node, Node):
            self.chidren[node.symbol] = node
        else:
            raise TypeError

    def addChidWithSymbol(self, symbol):
        if isinstance(symbol, str):
            self.chidren[symbol] = Node(symbol)
        else:
            raise TypeError

    def __getitem__(self, key: str):
        try:
            return self.chidren[key]
        except KeyError:
            raise KeyError("key {key} doesn't exist")

    def __eq__(self, other):
        if isinstance(other, Node):
            return self.symbol == other.symbol
        else:
            raise TypeError("you can't compare Node with Type:", Type(other))


def add_pattren(pattren, root):
    currentNode = root
    for i in range(len(pattren)):
        currentSymbol = pattren[i]
        if currentNode.hasChildWithSymbol(currentSymbol):
            currentNode = currentNode[currentSymbol]
        else:
            currentNode.addChidWithSymbol(currentSymbol)
            currentNode = currentNode[currentSymbol]
    currentNode.endOfPattren = True


def build_trie(pattrens):
    trie = Node()
    for pattren in pattrens:
        add_pattren(pattren, trie)
    return trie


def match_pattrens(string, root: Node):
    results = []
    for i in range(len(string)):
        currentNode = root
        for j in range(i, len(string)):
            if currentNode.hasChildWithSymbol(string[j]):
                currentNode = currentNode[string[j]]
                if currentNode.endOfPattren:
                    results.append(i)
            else:
                break
    return results


if __name__ == '__main__':
    string = input()
    patterns = [input() for i in range(int(input()))]
    tree = build_trie(patterns)
    results = match_pattrens(string, tree)
    results = sorted(list(dict.fromkeys(results)))

    print(" ".join(map(str, results)))
