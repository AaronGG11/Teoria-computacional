# Tupla conformada por estados, alfabeto, estado inicial, tabla de transiciones, estados finales

# Obtener linea a linea del archivo
def getLinesFromFile(f):
    lines = []
    for line in f:
        lines.append(line)
        lines[len(lines)-1] = lines[len(lines)-1].strip()

    return lines

# Leer el enunciado del AF
def readSentence(lines):
    sentence = lines[0]

    return sentence

# Leer los estados del AF
def readStates(lines):
    states = []
    for i in lines[1]:
        states.append(i)

    return states

# Leer el alfabeto
def readAlphabet(lines):
    alphabet = []
    for i in lines[2]:
        alphabet.append(i)

    return alphabet

# Leer el estado inicial
def readInitialState(lines):
    return lines[3]

# Leer la matriz de transicion para AFD
def readTransitionTableAFD(lines,states):
    matrix =[]
    index = 4
    for i in range(0,len(states)):
        if(index<len(lines)):
            aux = lines[index]
        index += 1
        matrix.append([])
        for j in range(len(aux)):
            matrix[i].append(aux[j])

    return matrix

# Leer estados finales
def readFinalStates(lines,states):
    final_states = []
    for i in lines[4+len(states)]:
        final_states.append(i)

    return final_states

# Leer la matriz de transicion para AFN
def readTransitionTableAFN(lines,states):
    matrix =[]
    index = 4
    temp = ""

    for i in range(0,len(states)):

        if(index<len(lines)):
            aux = lines[index]
            index += 1

        matrix.append([])
        for j in range(0,len(aux)):
            if((aux[j] != ",") and (j+1 != len(aux))):
                temp += aux[j]
            if(aux[j] == ","):
                matrix[i].append(temp)
                temp = ""
            if((aux[j] != ",") and (j+1 == len(aux))):
                temp += aux[j]
                matrix[i].append(temp)
                temp = ""

    return matrix
