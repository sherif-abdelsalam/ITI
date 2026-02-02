def incremet_by_one_from_start(length: int, start: int) -> list:

    if not isinstance(length, int) or not isinstance(start, int):
        raise TypeError("length and start must be integers")

    if length < 0:
        raise ValueError("length must be >= 0")
    

    new_list = []

    for i in range(length):
        new_list.append(start + i + 1)

    return new_list


list_nums = incremet_by_one_from_start(4, 4)
print(list_nums)


