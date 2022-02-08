def attempts_egg_drop(eggs, floors):
    num_eggs = eggs + 1
    print "num_egg",num_eggs
    num_floors = floors + 1
    print "num_floors",num_floors,"\n**"

    T = [[floor if egg == 1 else 0 for floor in range(num_floors)] for egg in range(num_eggs)]

    for egg in range(2, num_eggs):
        for floor in range(1, num_floors):
            T[egg][floor] = min(1 + max(T[egg - 1][k - 1], T[egg][floor - k]) for k in range(1, floor + 1))

    return T[num_eggs - 1][num_floors - 1]


def min_attempts_egg_drop_recursive(eggs, floors):
    if eggs == 1 or floors == 0:
        return floors

    min_value = float("inf")

    for floor in range(1, floors + 1):
        min_value = min(min_value,
                        1 + max(min_attempts_egg_drop_recursive(eggs - 1, floor - 1),
                                min_attempts_egg_drop_recursive(eggs, floors - floor)))

    return min_value


if __name__ == '__main__':
    print attempts_egg_drop(3,100)
    print min_attempts_egg_drop_recursive(3,100)
