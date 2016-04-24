
from random import randint

# 1
def print_skipping():
    for i in range(1,11):
        # if i not in [5,8]:
        if i != 5 and i != 8:
            print(i)


# 2
def find_max():
    length = input("pidr vedi 4islo, eto dlina massiva uebok: ")
    length = int(length)
    print(length)

    numbers = []

    for i in range(length):
        num = input("Enter " + str(i) + "-th number: ")
        numbers.append(int(num))

    print(numbers, 'max: ', max(numbers))


# 3
def histogram():
    symbols = []
    while True:
        symbol = input("Enter symbol or 0 to break: ")
        if symbol == "0":
            break
        else:
            symbols.append(symbol)

    print(symbols)

    D_count = symbols.count('D')
    d_count = symbols.count('d')
    o_count = symbols.count('o') + symbols.count('O')

    print("D=", D_count, "d=", d_count, "o=", o_count)

    print("D=", '*' * D_count)
    print("d=", '*' * d_count)
    print("o=", '*' * o_count)


# 4
def strcomp():

    str_a = input("Enter first string")
    str_b = input("Enter second string")

    # if len(str_a) != len(str_b):
    #     print('String Lengths Not Equal')
    #     return
    #
    # for i in range(len(str_a)):
    #     if str_a[i] != str_b[i]:
    #         print('Not Equal!')
    #         return
    #
    # print('Equal')


    print(str_a == str_b)

# 5
def occurrences():

    text = input("vedi tekst suka")
    print(text.count('m'))

# 6

def random_array():

    n = int(input("vedi 4islo suka"))

    array = [randint(1,46) for i in range(n)]
    print(array)

    array.reverse()
    print(array)

random_array()
