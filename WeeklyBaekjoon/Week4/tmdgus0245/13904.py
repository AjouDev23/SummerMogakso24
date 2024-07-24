import sys
N = int(sys.stdin.readline().rstrip())
assignments = [0 for _ in range(N)]
grades=0
for i in range(N):
    d, w = map(int,sys.stdin.readline().rstrip().split())
    assignments[i] = (d,w)
assignments.sort(key = lambda x:-x[1])
for day in range(max(assignments,key = lambda x: x[0])[0],0,-1):
    for assignment in assignments:
        if assignment[0]>=day:
            grades += assignment[1]
            assignments.remove(assignment)
            break
print(grades)