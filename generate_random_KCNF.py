import random
import os


def clause_to_string(clause):
    clause.sort()
    return " ".join([str(literal) for literal in clause])

#Retruns a CNF clause
def generate_random_k_CNF(literals_per_clause, total_clauses, total_symbol):
    clauses = []
    generated_clauses = set()
    symbols = []
    for i in range(1,total_symbol+1):
        symbols.append(i)

    while total_clauses > 0:
        clause =[]
        random.shuffle(symbols)
        for s in symbols[:literals_per_clause]:
            if (random.random() < 0.5):
                clause.append(s)
            else:
                clause.append(-1*s)

        str_clause = clause_to_string(clause)

        if str_clause not in generated_clauses:
            clauses.append(clause)
            generated_clauses.add(str_clause)
            total_clauses = total_clauses - 1

    return clauses, symbols

if __name__ == "__main__":
    literals_per_clause = 3
    num_clauses = 20000
    num_variables = 10000
    cwd = os.getcwd()
    filename = "randomly_generetaed_kCNF_" + str(literals_per_clause) +"_" + str(num_clauses) + "_" + str(num_variables) + "_.txt"
    clauses, symbols = generate_random_k_CNF(literals_per_clause, num_clauses, num_variables)

    #create random generate file
    file = open(filename, 'w+')
    file.write("c " + "auto-generated SAT problem\n") #header
    file.write("p " + "cnf " + str(len(symbols)) + " " + str(len(clauses)) + "\n")
    for clause in clauses:
        clause = [str(literal) for literal in clause]
        file.write(" ".join(clause) + " 0\n")
    file.close()