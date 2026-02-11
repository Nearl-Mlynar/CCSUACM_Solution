def main():
    import sys
    lines = [line.strip() for line in sys.stdin if line.strip()]
    ptr = 0
    n = int(lines[ptr])
    ptr += 1
    
    a = [[0]*n for _ in range(n)]
    b = [[0]*n for _ in range(n)]
    c = [[0]*n for _ in range(n)]

    for i in range(n):
        line = lines[ptr]
        ptr += 1
        for j in range(n):
            a[i][j] = line[j]
    
    for i in range(n):
        line = lines[ptr]
        ptr += 1
        for j in range(n):
            c[i][j] = line[j]
    
    def fa1():
        for i in range(n):
            for j in range(n):
                b[i][j] = 0
        for i in range(n):
            for j in range(n):
                b[j][n-1 - i] = a[i][j]
        for i in range(n):
            for j in range(n):
                if b[i][j] != c[i][j]:
                    return False
        return True
    
    def fa2():
        for i in range(n):
            for j in range(n):
                b[i][j] = 0
        for i in range(n):
            for j in range(n):
                b[n-1 - i][n-1 - j] = a[i][j]
        for i in range(n):
            for j in range(n):
                if b[i][j] != c[i][j]:
                    return False
        return True
    
    def fa3():
        for i in range(n):
            for j in range(n):
                b[i][j] = 0
        for i in range(n):
            for j in range(n):
                b[n-1 - j][i] = a[i][j]
        for i in range(n):
            for j in range(n):
                if b[i][j] != c[i][j]:
                    return False
        return True
    
    def fa4():
        for i in range(n):
            for j in range(n):
                b[i][j] = 0
        for i in range(n):
            for j in range(n):
                b[i][n-1 - j] = a[i][j]
        for i in range(n):
            for j in range(n):
                if b[i][j] != c[i][j]:
                    return False
        return True
    
    def fa5():
        temp = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                temp[i][j] = a[i][n-1 - j]
        
        flag = True
        for i in range(n):
            for j in range(n):
                if temp[j][n-1 - i] != c[i][j]:
                    flag = False
                    break
            if not flag:
                break
        if flag:
            return True
        
        flag = True
        for i in range(n):
            for j in range(n):
                if temp[n-1 - i][n-1 - j] != c[i][j]:
                    flag = False
                    break
            if not flag:
                break
        if flag:
            return True
        
        flag = True
        for i in range(n):
            for j in range(n):
                if temp[n-1 - j][i] != c[i][j]:
                    flag = False
                    break
            if not flag:
                break
        if flag:
            return True
        
        return False
    
    def fa6():
        for i in range(n):
            for j in range(n):
                if a[i][j] != c[i][j]:
                    return False
        return True
    
    if fa1():
        print(1)
    elif fa2():
        print(2)
    elif fa3():
        print(3)
    elif fa4():
        print(4)
    elif fa5():
        print(5)
    elif fa6():
        print(6) 
    else:
        print(7)  

if __name__ == "__main__":
    main()