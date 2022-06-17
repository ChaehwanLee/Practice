x = int(input("단을 입력하세요:"))

print("구구단",x,"단", sep=" ")
print("="*20)

for i in range(1, 9):
    print(x, "x",i, "=",x*i)
    4