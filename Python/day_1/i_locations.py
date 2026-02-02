def find_char_indexes(text, target):
    indexes = []

    for index, c in enumerate(text):
        if c == target:
            indexes.append(index)

    return indexes

