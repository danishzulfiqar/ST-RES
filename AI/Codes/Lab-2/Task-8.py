a = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
b = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
c = []

for indrow in range(3):
    c.append([])
    for indcol in range(3):
        c[indrow].append(0)
        for indaux in range(3):
            c[indrow][indcol] += a[indrow][indaux] * b[indcol][indaux]

print(c)
