import random
x = input()
arg = int(x)
stack_a = []
stack_a = random.sample(range(arg), arg)
print(' '.join([str(i) for i in stack_a]))