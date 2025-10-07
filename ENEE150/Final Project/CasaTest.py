# def sumNumbers(a, b):
#     return a + b

# def numberfac(a):
#     x = 1
#     for i in range(a):
#         x = x*(a-i)
#     return x
# print("Hello world!!!!!")
# x = sumNumbers(1,3)
# print(x)
# print(numberfac(x))


def makeWords(UserInput):
    words = UserInput.split()
    return words
prompt = "Enter a sentence: "
UserInput = input(prompt)

wordsBeingSplitUp = makeWords(UserInput)
for i in range(len(wordsBeingSplitUp)):
    print(wordsBeingSplitUp[i])
print("There was", len(wordsBeingSplitUp), "words in the sentence.")