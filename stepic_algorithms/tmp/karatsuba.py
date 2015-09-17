def karatsuba(x, y):

    # print("Multiply: x(%s), y(%s)" % (x, y))
    x_len = len(x)
    y_len = len(y)

    if max(x_len, y_len) <= 2: 
        
        # print("! Return result(%s, %s): %s" % (x, y, int(x) * int(y)))
        return str(int(x) * int(y))
    
    x_mid = x_len // 2
    x_left, x_right = x[:x_mid], x[x_mid:]

    y_mid = y_len // 2
    y_left, y_right = y[:y_mid], y[y_mid:]

    p_1 = str(karatsuba(x_left, y_left))
    print("Result p_1(%s,%s) = %s" % (x_left, y_left, p_1))
    p_2 = str(karatsuba(x_right, y_right))
    print("Result p_2(%s,%s) = %s" % (x_right, y_right, p_2))

#    print(x_left, x_right)
#    print(y_left, y_right)
    a_1 = add(x_left, x_right)
    print("Result adding a_1(%s,%s) = %s" % (x_left, x_right, a_1))
    a_2 = add(y_left, y_right)
    print("Result adding a_2(%s,%s) = %s" % (y_left, y_right, a_2))
    p_3 = str(karatsuba(a_1, a_2))
    print("Result p_3(%s,%s) = %s" % (a_1, a_2, p_3))
    s_1 = sub(p_3, p_1)
    print("Result sub s_1(%s,%s) = %s" % (p_3, p_1, s_1))

    s_2 = sub(s_1, p_2)
    print("Result sub s_2(%s,%s) = %s" % (s_1, p_2, s_2))

    d = max(len(x_right),len(y_right))

    temp = add(add_zeroes(p_1, d**2), add_zeroes(s_2, d))
    print("Temp result = %s" % temp)
    
    temp = add(temp, p_2)

    print("Temp result = %s" % temp)

    print("Before return %s" % temp)

    

    return temp

def add_zeroes(x, count):
    return x + '0'*count

def sub(x, y):
    x_r = x[::-1]
    y_r = y[::-1]

    x_len = len(x)
    y_len = len(y)
    c = False
    out = ''

    for i in range(0, max(x_len, y_len)):
        x_cur = int(x_r[i]) if i < x_len else 0
        y_cur = int(y_r[i]) if i < y_len else 0

        if c:
            if x_cur > 0:
                x_cur -= 1
                c = False
            else:
                x_cur = 9

        if x_cur < y_cur:
            x_cur += 10
            c = True

        out += str(x_cur-y_cur)
    
    n = out[::-1]
    i = 0
    while n[i] == '0':
        i +=1

    if i:
        return n[i:]
    else:
        return n

def add(x, y):
    x_r = x[::-1]
    y_r = y[::-1]
    x_len = len(x)
    y_len = len(y)
    out = ''
    c = False

    for i in range(0, max(x_len, y_len)):
        if i > x_len - 1:
            temp = int(y_r[i])
        elif i > y_len - 1:
            temp = int(x_r[i])
        else:
            temp = int(x_r[i]) + int(y_r[i])

        if c:
            temp += 1
            c = False

        if temp >= 10:
            temp = temp % 10
            c = True

        out += str(temp)

    if c:
        out += '1'

    return out[::-1]
    

if __name__ == "__main__":
    '''    
    x = input()
    y = input()
    result = karatsuba(x, y)
    '''
    x = '239030239030566179'
    y = '56617956617923930'


    x = '920432'
    y = '631212'


    result = karatsuba(x, y)

    print(result)
    print(len(result))
    

    '''
    result = sub('1243254', '33234')
    print(result)

    result = sub('1243254', '300334')
    print(result)

    result = sub('12432540', '9933234')
    print(result)
    '''
