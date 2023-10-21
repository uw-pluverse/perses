# Check Terminal Condition
def CheckCondition(elements):
    for i in len(elements):
        if e[i][1] != 0.0 or e[i][1] != 1.0: # If neither 0 nor 1, terminal condition is false (= 0).
            return 0
    
    return 1

# "elements" is the list of elements to be reduced.
# "targets" is the list of element indices that are excluded subsequence.
# "result" is the test outcome if it satisfied the test or not with exclusion.
def AdjustProbs(elements, targets, result):

    if result == 1:
        for i in targets:
            elements[i][0] = 0
            elements[i][1] = 0
    elif result == 0:
        product = 1.0
        for j in targets:
            product *= ((1.0-elements[j][1]))
        for i in targets:
            if elements[i][0] == 0:
                continue
            elements[i][1] /= (1 - product)

def probDD(sequence, test_function):
    # probabilities of each element in the optimal solution
    probabilities = sequence.copy()
    # current optimal solution
    next_test_sequence = sequence.copy()

    while CheckCondition(elements) == 0:
        # calculate gain and find the next test to run

        # run the test

        # modify probabilities based on test result

    
    # return the elements with probability 1


