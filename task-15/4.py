T = int(input())
for i in range(T):
    N = int(input())
    largest = 0
    limit = N - 1
    for number1 in range(999, 100, -1):
        if number1 % 11:
            starting = min(990, limit // number1 // 11 * 11)
            step = -11
        else:
            starting = min(999, limit // number1)
            step = -1
        for number2 in range(starting, number1, step):
            product = number1 * number2
            if product <= largest:
                break
            product_str = str(product)
            if product_str == product_str[::-1]:
                largest = product
                break
    print(largest)
