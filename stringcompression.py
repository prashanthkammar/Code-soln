# Compression of strings
# Example: 1. Input a, output a;
# 2. Input aaa, Output a3
# 3. Input aaaabcc , Output a4b1c2
# The output string length should be less than input else return original string as in first case


def compression(s):
    sum = 1
    output = ""
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            sum += 1
        else:
            output = output + s[i] + str(sum)
            sum = 1

    output = output + s[len(s) - 1] + str(sum)
    return s if s < output else output


if __name__ == "__main__":
    s = input(str())
    out = compression(s)
    print(out)

