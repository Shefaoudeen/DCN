import random


def calculate_parity_len(ml):
    p = 1
    while 1:
        if pow(2,p) >= ml+p:
            return p
        p += 1


def print_data(data_list):
    for data in data_list:
        print(data,end="")
    print("")


def find_Cs(pl,ml):
    length = pow(2, pl) - 1
    Cs = []

    for i in range(pl):
        index = pow(2,i)
        c = []
        for j in range(1,pl+ml+1):
            if index & j == index:
                c.append(j)
        Cs.append(c)

    return Cs


def check_parity(bit_list,msg):
    parity = 1
    bit_position = bit_list[0]
    for i in bit_list:
        if i != bit_position:
            parity ^= int(msg[i-1])
    parity = not parity
    if parity:
        return '1'
    return '0'

def error_checking(encoded_msg,Cs):

    error_check = []

    for c_list in Cs:
        ones = 0
        for c_bit in c_list:
            if encoded_msg[c_bit-1] == '1':
                ones += 1
        if ones % 2 == 0:
            error_check.append(0)
        else:
            error_check.append(1)

    error_position = 0

    for i in range(0,len(error_check)):
        error_position += pow(2,i) * error_check[i]

    return error_position

message_data = input("Enter the message data : ")
message_length = len(message_data)

parity_length = calculate_parity_len(message_length)
print(f"Message length : {message_length}")
print(f"Parity length : {parity_length}")

Cs = find_Cs(parity_length,message_length)

# C bit starting
c_starting = []
for c in Cs:
    c_starting.append(c[0])

# encoding message
encoded_array = []
message_index = 0

for i in range (1, message_length+parity_length+1):
    if i in c_starting:
        encoded_array.append("p")
    else:
        encoded_array.append(message_data[message_index])
        message_index += 1

for i in range(parity_length):
    encoded_array[c_starting[i]-1] = check_parity(Cs[i],encoded_array)

print(f"Transmitted message : \n {encoded_array}")

random_position = random.randint(0,parity_length+message_length-1)
random_data = random.randint(0,1)

encoded_array[random_position] = str(random_data)

print(f"Received message : \n {encoded_array}")

error_position = error_checking(encoded_array,Cs)

if error_position:
    print(f"Error at the {error_position} bit position")
else:
    print("No Error in the message")
