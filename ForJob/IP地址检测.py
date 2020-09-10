def tackle(address: str)->str:
    if isIPv4(address):
        return 'IPv4'
    elif len(a) < 6:
        return 'IPv6'
    else:
        return 'Neither'


def isIPv6(address)->bool:
    a = address.split(':')
    if len(a) != 8:
        return False
    for i in a:
        print(i)
        if int(i) > 255 or int(i) < 0:
            return False
    return True


def isIPv4(address)->bool:
    a = address.split('.')
    if len(a) != 4:
        return False
    for i in a:
        if int(i) > 255 or int(i) < 0:
            return False
    return True


# address = input()
# print(address)
a = isIPv4('192.300.199.2')
print(a)
